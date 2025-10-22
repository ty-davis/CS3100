/*
 * This program creates a given number of child process that each call the minmax program
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    if (argc < 3) {
	printf("Usage: %s <numChildren> <inputFile>\n", argv[0]);
	return -1;
    }
    // make sure that the number is between 1 and 4
    int numChildren = atoi(argv[1]);
    if (numChildren < 1 || numChildren > 4) {
	printf("Invalid number of children, should be 1 - 4.\n");
	return -1;
    }

    printf("Welcome! My name is Ty Davis, running %d processes.\n", numChildren);

    for (int i = 0; i < numChildren; i++) {
	int cp[2];     // integer array for the pipes
	int pid = 0;   // process id of this proccess
	
	if (pipe(cp) < 0) {
	    printf("didn't work, couldn't not establish pipe.\n");
	    return -1;
	}

	pid = fork();

	if (pid == 0) {
	    close(1);       //close stdout
	    dup2(cp[1], 1); //move stdout to pipe of cp[1]
	    close(0);       //close stdin
	    close(cp[0]);   //close pipe in 
	    //note: All the arguments in exec have to be strings.
	    // with an extra null string to end the args
	    char *args[4]; // used to pass command line args for execv function
	    args[0] = "minmax";
	    char childIndex[15];
	    snprintf(childIndex, sizeof(childIndex), "%d", i);
	    args[1] = childIndex;
	    args[2] = argv[2];
	    args[3] = (char *) 0;
	    execv("minmax", args);  
	    printf("execv failed");
	    exit(1);
	} else {
	    close(cp[1]); // if you don't close this part of the pipe 
			  // then the while loop (three lines down) will never return
	    char ch;       // character read from the pipe
	    while( read(cp[0], &ch, 1) == 1) {
		printf("%c",ch);
	    }
	    close(cp[0]);
	}

    }

    return 0;
}
