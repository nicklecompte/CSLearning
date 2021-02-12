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

Please see LICENSE for more legally serious details - there aren't many, it's 
MIT :).
*/
#ifndef _MIXH
#define _MIXH
#include<stdbool.h>
#include<stdio.h>

#define LENGTH(ar) sizeof(ar)/sizeof(ar[0]);

typedef struct MixByte {
	  bool bit1;
	  bool bit2;
	  bool bit3;
	  bool bit4;
	  bool bit5;
	  bool bit6;
} MixByte;

void mixByteToString(MixByte mb, char *out);
unsigned short mixByteToShort(MixByte mb);

typedef struct MixByteDecimal {
  unsigned short bit1;
  unsigned short bit2;
} MixByteDecimal;

unsigned short mixByteDecimalToShort(MixByteDecimal mb);
/*
WARNING: This overflows for values > 100.
*/
MixByteDecimal mixbyteDecimalFromShort(unsigned short s);
/*
WARNING: This overflows for values > 64.
*/
MixByte mixbytefromMBDecimal(MixByteDecimal m);
MixByteDecimal mixbyteDecimalFromMixByte(MixByte m);
void fromUChar(unsigned char c, MixByte* mb);
char toChar(MixByte mb);
short toUShort(MixByte mb);
// C chars are guaranteed to fit in 2 MixBytes
void fromChar(char c, MixByte *mb1, MixByte *mb2);
void fromUShort(unsigned short s, MixByte *mb, size_t *arsize);
void fromFloat(float f, MixByte *mb, size_t *arsize);

/////////////////////////////////////////////////////////////////////////////////
///////////////////////  Registers - structs and helpers ////////////////////////
/////////////////////////////////////////////////////////////////////////////////

typedef enum {Plus,Minus} MixSign;

typedef struct RegisterA {
  MixSign sgn;
  MixByte A1;
  MixByte A2;
  MixByte A3;
  MixByte A4;
  MixByte A5;
} RegisterA;

typedef struct MixWord {
  MixSign sgn;
  MixByte byte1;
  MixByte byte2;
  MixByte byte3;
  MixByte byte4;
  MixByte byte5;
} MixWord;

/*
MixWords used for instructions have the following form
0 | 1 | 2 | 3 | 4 | 5
s | A | A | I | F | C

+/AA = memory address
I = index specification (offset from address)
F = modification of opcode (may be a field specification)
C = opcode
*/

typedef struct MixAddress {
  MixSign sgn;
  MixByte byte1;
  MixByte byte2;
} MixAddress;

typedef struct MixJump {
  MixByte byte1;
  MixByte byte2;
} MixJump;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////  MIX Operations - structs and helpers /////////////////////
/////////////////////////////////////////////////////////////////////////////////

typedef enum {
	       LDA = 8,
	       LDX = 15,
	       LDI1 = 9,
	       LDI2 = 10,
	       LDI3 = 11,
	       LDI4 = 12,
	       LDI5 = 13,
	       LDI6 = 14,
	       LDAN = 16,
	       LDXN = 23,
	       LDI1N = 17,
	       LDI2N = 18,
	       LDI3N = 19,
	       LDI4N = 20,
	       LDI5N = 21,
	       LDI6N = 22,
	       STA = 24,
} MixInstructionName;

typedef struct MixInstruction {
  MixAddress Address;
  MixByte Index;
  MixByte Modification;
  MixByte Opcode;
  MixInstructionName Name;
}

typedef struct MixComputer {
  MixWord RegisterA;
  MixWord RegisterX;
  MixIndex I1;
  MixIndex I2;
  MixIndex I3;
  MixIndex I4;
  MixIndex I5;
  MixIndex I6;
  MixJump J;
  MixWord Memory[4000];
} MixComputer;

#endif
