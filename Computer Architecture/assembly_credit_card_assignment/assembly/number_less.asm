.data
	prompt:  .asciiz "The first number is less than the other"
.text
	main:
	addi $t0, $zero, 25
	addi $t1, $zero, 5
	
	slt $s0, $t0, $t1
	bne $s0, $zero, printPrompt
	
	li $v0, 10
	syscall
	
	printPrompt:
		li $v0, 4
		la $a0, prompt
		syscall