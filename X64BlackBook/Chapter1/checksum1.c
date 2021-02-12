/* Program to perform the 64-bit checksum of all bytes in a specified file.
Obtains the bytes one at a time via read(),

*/
#include <stdio.h>
#include <fcntl.h>

void main(int argc, char *argv[]) {

  int handle;
  unsigned char inbyte[8];
  unsigned long checksum = 0L;
  int readlength;

  if (argc != 2) {
    printf("Error : usage is checksum [filename]\n");
    exit(1);
  }
  if ( (handle = open(argv[1], O_RDONLY | O_BINARY)) == -1) {
    printf("Can't open file: %s\n", argv[1]);
    exit(1);
  }

  while ( (readlength = read(handle, &inbyte, 8)) > 0) {
    checksum += *((unsigned long*)inbyte);
  }
  if ( readlength == -1) {
    printf("Error reading file: %s\n", argv[1]);
    exit(1);
  }
  printf("The checksum is %ul\n",checksum);
  exit(0);
};

