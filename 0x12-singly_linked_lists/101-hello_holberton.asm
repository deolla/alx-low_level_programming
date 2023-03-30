section .data
	msg db "Hello, Holberton",0xA
	len equ $-msg

section .text
	global main

main:
	mov eax, 4	; system call for write
	mov ebx, 1	; file descriptor for stdout
	mov ecx, msg	; pointer to string to write
	mov edx, len	; lenght of string to write
	int 0x80	; call kernel
	mov eax, 1	; system call for exit
	xor ebx, ebx	; return code
	int 0x80	; call the kernel
