.section .data
	msg:
		.asciz "Refrigerated"
	
	
.section .text
	.global is_refrigerated


is_refrigerated:
	movq (%rdi, %rsi, 12), %rdi
	movq (%rdi, %rdx, 8), %rdi
	movq (%rdi, %rcx, 4), %rdi
	
	addq $88, %rdi
	movl (%rdi), %ebx
	
	movl msg(%rip), %r8d
	
	cmpq %r8d, %ebx
	je refrigerated
	
not_refrigerated:
	movl $0, %eax
	jmp fim

refrigerated:
	movl $1, %eax
	
fim:
	ret
