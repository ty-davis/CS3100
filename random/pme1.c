#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	printf("hello (pid:%d)\n", (int) getpid());
	execlp("./p1", "nada", NULL);
}
