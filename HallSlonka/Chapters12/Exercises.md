# Chapters 1/2 - Exercises

## Chapter 1 - Short answer

x86 and IBM 370 are examples of processor architectures (or families? I think both refer to both but that's not true across the board).
Assembly language statements have a one-one(ish) relationship with machine language statements. (Technically this should also be many-many?)
A high-level language has one-many relationship with machine language statements (in a less cutesy way - optimization, compilation targets, etc)
Translating between language layers has two forms: interpreting and compiling.
x86 and x86_64 are examples of complex instruction set architecture.
A "word" is 16 bits, in terms of x86 architecture.
Binary is the fundamental blah blah reliability.
$floor[log_2 n] + 1$ is the formula for calculating the number of bits needed to store a given positive integer.
0 to 2^8 - 1 is the numeric range for an unsigned byte.
When converting from hex to binary, each hex digit is represented by 4 bits.
On x86 processors, a most significant digit of 1 indicates the number is negative.
In a two's complement system, a hexidecimal value with a leading 7 would indicate the number is positive.
-2^7 - 2^7 - 1 is the range for a signed byte.
Character storage is acheived via the use of character maps and associated standards.
XOR is the bool = false if both inputs are true.
An overflow condition when computed result goes beyond numeric range of storage.

## Chapter 1, TF
1) Assembly is portable across processor families (F)
2) Two's complement has the problem of two zeros (F)
3) The x86_64 architecture is not synonymous with IA-64 (T)
4) An assembler encodes high-level statements into object code (F)
5) A CPU inherently understands whether an integer is positive or negative (F but OK...)

