/* 
* When using two CPUs and running this program multiple times very close back-to-back
* I was able to see output similar to what was shown on Canvas. Sometimes, the first
* two numbers were 3 and 6 instead of 0 and 3. 
*
* The problem must have come from a race condition when the two processes were being
* scheduled near each other and the scheduler switch which CPU was running which
* process. Because the 'magic' number is per CPU, the value persists with the CPU,
* not with the process.
*
*/
#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(int argc, char *argv[]){
    int magic; // variable to store the magic number

    magic = getMagic();
    printf("current magic number is the following: %d\n",magic);

    incMagic(3);  // increment the magic number by 3

    magic = getMagic();
    printf("current magic number is the following: %d\n",magic);

    // now check the system calls for process name
    printf("current process name:");

    getProcName();  // getProcName should print the name to the screen

    printf("\n");  // still need a new line

    modProcName("newName");  // now change the proc name to newName

    printf("The process name is now: ");
    getProcName();
    printf("\n");

    magic = getMagic();
    printf("current magic number is the following: %d\n",magic);

    // Now change the magic number back to what is was by incrementing
    // by -3
    incMagic(-3);

    magic = getMagic();
    printf("current magic number is the following: %d\n",magic);

    exit(0);
}
