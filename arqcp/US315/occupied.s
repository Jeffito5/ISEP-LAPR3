.section .data
	.global percorrer
	.global ptrvec
	.global tamanho
	
.section .text
	.global occupied			    #void occupied(void)
	
start:
	#prologue
	pushl %ebp    
	movl %ebp 
	
	pushl %esi
	pushl %ebx
		
#-----------------------------------------------------------------------
	
	movl ptrvec, %esi					#coloca pointer ptrvec em esi
	movl tamanho, %ebx					#coloca tamanho em ebx
	movl percorrer, %edx				#coloca o percorrer(localizaçao) em edx
	
verify:
	
	movl (%esi), %edx					#coloca o apontado por esi em eax
	cmpl $0, %edx						#compara o valor em eax com 0
	jle occupied						#se for menor ou igual que zero, salta para 'occupied'
	jg fim								#se for maior que zero, salta para 'fim'

occupied:

	popl %esi				
	popl %ebx				
	movl %ebp
	popl %ebp
	
	movl $0,eax       					#retorna 0  
	ret

#-----------------------------------------------------------------------
fim:
	popl %esi				
	popl %ebx				
	movl %ebp
	popl %ebp
	
	movl $1,eax        					#retorna 1
	ret
