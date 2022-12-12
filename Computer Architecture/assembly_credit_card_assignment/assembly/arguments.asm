.data

.text
	main:
	addi $a1, $zero, 40
	addi $a2, $zero, 12
	
	jal addNumbers
	
	li $v0, 1
	move $a0, $v1
	syscall
	
	li $v0, 10
	syscall
	
	addNumbers:
	add $v1, $a1, $a2
	
	jr $ra