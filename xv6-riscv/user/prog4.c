#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(void) {
  printf("Hi there. My name is Ty Davis and I am new here. Would you please let me know what you would like saved into the bob.txt file?\n>> ");

  // getMagic first
  printf("Magic: %d\n", getMagic());

  incMagic(5);
  printf("Magic: %d\n", getMagic());


  printf("Now doing the process name stuff\n");

  printf("Current name: ");
  getProcName();
  printf("\n");

  printf("Setting to a new name\n");
  char *newName = "prog4 new";
  modProcName(newName);
  
  printf("New name: ");
  getProcName();

  printf("\nExiting...\n");
}
