/*
 * This is a sample program, showing how to read the file.  
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char * argv[]) {
    const char * filename;  // name of file to read
    FILE * ft;  // file handle for the file
    int pid,    // process id of this process
	num,    // the number of integer values in the file
	i,      // loop control variable for reading values
	temp=0; // used to store each value read from the file
    long size;  // size in bytes of the input file
    /*********************************************************************/

    if (argc<3) {  // not enough arguments, need output file name
	printf("Usage: readfile <filename>\n");
	return 1;
    }

    int childnum = atoi(argv[1]);
    filename = argv[2];  // read the file named on the command line

    ft= fopen(filename, "rb") ;
    if (ft) {
	int minVal = 99999999;
	int maxVal = 0;
	pid = getpid();
	fseek (ft,0,SEEK_END); //go to end of file
	size = ftell(ft);      //what byte in file am I at?
	fseek (ft,0,SEEK_SET); //go to beginning of file
	num = (int)size / (int)sizeof(int); // number of integer values
	for(i = 0; i < num; i++){
	    fread(&temp,sizeof(int),1,ft);
	    if (temp < minVal) {
		minVal = temp;
	    } else if (temp > maxVal) {
		maxVal = temp;
	    }
	}
	fclose(ft);  // close the file now that we're done
	printf("child #: %d | pid:  %d | min: %d | max: %d\n", childnum, pid, minVal, maxVal);
    }
    printf("\n");  // only have a tab on last line so newline
    return 0;
}
