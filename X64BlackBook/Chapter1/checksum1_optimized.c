/* Program to perform the 64-bit checksum of all bytes in a specified file.
Obtains the bytes all at once via an (inefficient) assembly call in checksum1.asm

*/
#include <stdio.h>
#include <fcntl.h>

void main(int argc, char *argv[]) {

  int handle;
  unsigned long int checksum = 0L;

  if (argc != 2) {
    printf("Error : usage is checksum [filename]\n");
    exit(1);
  }
  if ( (handle = open(argv[1], O_RDONLY | O_BINARY)) == -1) {
    printf("Can't open file: %s\n", argv[1]);
    exit(1);
  }

  if (!Checksum(handle, &checksum)) {
    printf("Error reading file: %s\n", argv[1]);
    exit(1);
  }
  printf("The checksum is %ul\n",checksum);
  exit(0);
};

