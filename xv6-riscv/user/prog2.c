#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(void) {
  printf("Hi there. My name is Ty Davis and I am new here. Would you please let me know what you would like saved into the bob.txt file?\n>> ");

  char text[200] = {0};
  gets(text, 200);


  printf("Writing to bob.txt...\n");
  int fd = open("bob.txt", O_WRONLY | O_CREATE | O_TRUNC);
  write(fd, text, strlen(text));
  close(fd);
  printf("All finished!\n");
}
