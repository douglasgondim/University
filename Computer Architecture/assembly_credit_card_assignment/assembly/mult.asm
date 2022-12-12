.data

.text
	addi $s0, $zero, 3000
	addi $s1, $zero, 10
	
	mult $s0, $s1
	
	mflo $s3
	
	li $v0, 1
	move $a0, $s3
	syscall