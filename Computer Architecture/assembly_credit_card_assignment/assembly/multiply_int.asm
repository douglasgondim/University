.data
	n1: .word 2
	n2: .word 8

.text
	lw $t0, n1
	lw $t1, n2
	
	mul $t2, $t0, $t1
	
	li $v0, 1
	move $a0, $t2
	syscall