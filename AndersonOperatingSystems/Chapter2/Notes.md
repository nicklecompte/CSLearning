# Chapter 2 - The Kernel Abstraction

The operating system kernel is the lowest level of software running on a system. It has full access to all the machine hardware and is trusted to do anything with it. Everything else (untrusted software; user applications and so on) is run in a restricted environment with less access to the hardware.

Likewise, applications themselves need to execute untrusted code (browser executing embedded JavaScript, 3rd-party C DLL, etc).

A *process* is the executon of an application program with restricted machine-level rights. it is an abstraction for protected execution provided (and monitored) by the operating system kernel.

## The Process Abstraction

- A compiler converts text code into a seires of machine instructions and static data, bundled into an executable image.
- The OS copies the instructions and data from the image on disk into memory.
- The OS sets aside a memory region, the *execution stack*, for local variables during procedure calls, and the *heap* for dynamically-allocated data structures the program might need.
- Note the OS is itself loaded into memory, with its own stack and heap.
- Once the program is loaded into memory, the OS can start it by setting the stack pointer and jumping to the program's first instruction.
- To run multiple copies of a program, an OS typically makes one copy of the instructions, and multiple separate copies of the programs data, heaps, and stacks. To keep things simple we'll consider the case that the instructions are also copied.
- OS needs a data structure, the *process control block* (PCB), which keeps track of the various processes on the computer.
- PCB contains info like where process is in memory, where the image is on disk, what user asked it to execute, etc
- For simplicity we'll consider simple single-threaded processes with their own instruction counter, code, data, heap, and stack

