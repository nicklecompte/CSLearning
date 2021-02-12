BITS 64
default rel

segment .data
	msg db "Hello, world!", 0xd, 0xa, 0

segment .text
global main
extern _ExitProcess
extern _CRT_INIT
	
extern _printf

main:
	push 	rbp
	mov	rbp, rsp
	sub	rsp, 32

	call 	_CRT_INIT 
	
	lea 	rcx, [msg]
	call	_printf

	xor	rax, rax
	call	_ExitProcess
