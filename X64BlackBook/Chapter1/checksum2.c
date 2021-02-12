/* Program to perform the 64-bit checksum of all bytes in a specified file.
Obtains the bytes one at a time via read(),

*/
#include <stdio.h>

void main(int argc, char *argv[]) {

  FILE *handle;
  unsigned char inbyte[8];
  unsigned long checksum;
  size_t readlength;

  if (argc != 2) {
    printf("Error : usage is checksum [filename]\n");
    exit(1);
  }
  if ( (handle = fopen(argv[1], "rb")) == NULL) {
    printf("Can't open file: %s\n", argv[1]);
    exit(1);
  }

  checksum = 0;

  while (fread(&inbyte,sizeof(inbyte),8,handle) > 0) {
    checksum += *((unsigned long*)inbyte);
  }
  fclose(handle);
  printf("The checksum is %ul\n",checksum);
  
  exit(0);
};

