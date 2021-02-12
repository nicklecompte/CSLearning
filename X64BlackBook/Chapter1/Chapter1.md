# Chapter 1 - The Best Optimizer Is Between Your Ears

We start with a somewhat contrived example to illustrate two concepts:

1) on the qualitative hand, the importance of careful design *within* the
language (bad C is slower than good Python)
2) on the quantitative hand, illustrate with specific benchmarks the gains from
micro-optimizations in x64 assembly

The problem at hand: compute a 64-bit checksum. Specifically: convert a file (as
an array of bytes) into an array of unsigned longs, sum this array up, and
return the value.

# Listing 1 - `read` and the Universal CRT

The `fcntl.h` procedure `read` is defined in the Universal CRT, provided by
Microsoft for cross-platform

`checksum1.c` presents this naive implementation.

TODO: Check what's going on with Windows 10 using debugger.

There is possibly some overhead and slowness in the compiled C code that casts
the file stream to an unsigned long, so we also include `checksum1_optimized.c`
and `checksum1_optimized.asm` (written for MASM), which slightly optimizes some
of these x64 edges. However, it is still making a call to `read` from `fcntl.h.`

# Listing2 - `fread`

