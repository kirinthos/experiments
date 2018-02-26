# exit program
global start

section .text

start:
	mov 		rdi, 1
	mov 		rsi, str
	mov 		rdx, strlen
	mov 		rax, 0x2000004
	;syscall

	; stash 12 choose 4
	mov 		r10, 12
	mov 		r11, 4
	mov 		r14, r10
	sub 		r14, r11

	mov 		rax, 1
domul2:
	;denominator
	mul 		r11
	sub 		r11, 1
	cmp 		r11, 1
	jg domul2
	mov 		r12, rax ; store result in r12

	mov 		rax, 1
domul:
	;numerator
	mul 		r10
	sub 		r10, 1
	cmp 		r10, r14
	jg domul
	
	;div 		r12
	mov 		r15, rax
	
	mov 		rax, 0x2000001
	mov 		rdi, r15
	syscall

section .data
str: db `whatup doe\n`
strlen equ $ - str
