.section .data
	.global matrix_ptr
	.global num_elements

.section .text
	.global occupied_slots
	
	
occupied_slots:
	pushq %rbx
	pushq %rsi
	pushq %rdi
	
	movq matrix_ptr(%rip), %rbx		# coloca o pointer matrix_vec em rbx
	movl num_elements(%rip), %esi		# coloca número de elementos do vetor em esi
	
	movl $0, %eax				# coloca o contador de occupied_slots em eax
	
ciclo: 
	cmpl $0, %esi				# compara o valor em esi com 0
	je fim					# se for menor que 0 salta para o fim
	
	movq (%rbx), %edx			# coloca o apontado por rbx em edx
	cmpl $0, %edx				# compara o valor em edx com 0
	jg occupied_slots			# se for maior que 0 salta para o occupied_slots
	
	jmp continuar				# salta diretamente para o continuar se não saltar para o occupied_slots
	
occupied_slots:
	addl $1, %eax				# adiciona 1 ao contador de occupied slots em eax
	
continuar:
	addq $4, %rbx				# vai para a posição seguinte do pointer matrix_vec em rbx
	decl %esi				# decrementa o numero de elementos que faltam ver em esi
	jmp ciclo 				# salta para o ciclo
	
fim:
	popq %rdi
	popq %rsi
	popq %rbx
	ret
