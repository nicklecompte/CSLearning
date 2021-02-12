/*

A MIX emulator and MIXAL interpreter, based on the TAoCP text. The intent is for
the C code to be explicit and readable, versus being well-optimized. By design 
many of the implementations are quite "clunky." However, any modern general-
purpose computer should be able to actually compute any legal MIX program, 
despite the obvious inefficiencies.

Users who wish for a reliable, performant, well-tested free implementation of 
MIX are strongly advised to use another tool - for example, the GNU MDK, 
available at https://www.gnu.org/software/mdk/. There are certainly other good
options.  But my advice to students is to write your own version, as I did. It 
is a very good way to actually learn the MIX opcodes!


**** DISCLAIMER FOR STUDENTS AND HOBBYISTS ****
While this program has been written carefully for correctness, it was written by
an amateur C programmer (albeit experienced in garbage-collected languages), and
in particular an amateur whose sole use case for this program was pedagogical.

Therefore:

- THIS PROGRAM IS NOT SUITABLE FOR ANY SERIOUS INVESTIGATIONS INTO A MIX COMPUTER
OR THE MIXAL ASSEMBLY LANGUAGE.
- STUDENTS ARE STRONGLY ADVISED TO NOT USE THIS PROGRAM AS AN EMULATOR FOR MIX
PROGRAMS, E.G. TO TEST A SOLUTION TO AN EXERCISE.
- ASSUME ANY ANSWER NOT VERIFIED BY HAND IS POSSIBLY WRONG.

Please see LICENSE for more legally serious details.
*/

#include<stdbool.h>
#include<stdio.h>
#include "mix.h"




/////////////////////////////////////////////////////////////////////////////////
/////////////////////     MixByte - structs and helpers    //////////////////////
/////////////////////////////////////////////////////////////////////////////////


void mixByteToString(MixByte mb,char *out) {
  sprintf(out,"%i%i%i%i%i%i",mb.bit1,mb.bit2,mb.bit3,mb.bit4,mb.bit5,mb.bit6);
}

unsigned short mixByteToShort(MixByte mb) {
  return 1*mb.bit6 + 2*mb.bit5 + 4*mb.bit4 + 8*mb.bit3 + 16*mb.bit2 + 32*mb.bit1;
}

unsigned short mixByteDecimalToShort(MixByteDecimal mb) {
  return mb.bit2 + 10*(mb.bit1);
}

MixByteDecimal mixbyteDecimalFromShort(unsigned short s) {
  return (MixByteDecimal) {.bit1 = s / 10, .bit2 = s % 10};
}

MixByte mixbytefromMBDecimal(MixByteDecimal m) {
  unsigned short intval = mixByteDecimalToShort(m);
  bool bit1 = intval & 32;
  bool bit2 = intval & 16;
  bool bit3 = intval & 8;
  bool bit4 = intval & 4;
  bool bit5 = intval & 2;
  bool bit6 = intval & 1;
  return (MixByte) {.bit1=bit1,.bit2=bit2,.bit3=bit3,.bit4=bit4,.bit5=bit5,.bit6=bit6};
}

MixByteDecimal mixbyteDecimalFromMixByte(MixByte m) {
  return mixbyteDecimalFromShort(mixByteToShort(m));
};

void fromUChar(unsigned char c, MixByte* mb);
char toChar(MixByte mb);
short toShort(MixByte mb);
MixByte *fromUint(unsigned short s, MixByte* mb);
MixByte *fromFloat(float f);

/////////////////////////////////////////////////////////////////////////////////
///////////////////////  Registers - structs and helpers ////////////////////////
/////////////////////////////////////////////////////////////////////////////////





/////////////////////////////////////////////////////////////////////////////////
/////////////////////  MIX Operations - structs and helpers /////////////////////
/////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////     Main    //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void main() {
  int l = LENGTH(DECIMAL_REGISTER_OUTLINE)
  for (int i = 0; i < l; i++) {
    printf("%s\n",DECIMAL_REGISTER_OUTLINE[i]);
  }
  int lb = LENGTH(BINARY_REGISTER_OUTLINE)
  for (int i = 0; i < lb; i++) {
    printf("%s\n",BINARY_REGISTER_OUTLINE[i]);
  }
  MixByteDecimal mb = (MixByteDecimal) {.bit1 = 2, .bit2 = 8};
  printf("%i\n",mixByteDecimalToShort(mb));
  char form[6];
  mixByteToString(mixbytefromMBDecimal(mb),form);
  printf("%s",form);
  
}
