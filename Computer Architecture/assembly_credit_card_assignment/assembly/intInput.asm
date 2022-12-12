.data
	prompt: .asciiz "Enter your age: "
	prompt2: .asciiz "Your age is "

.text
	li $v0, 4
	la $a0, prompt
	syscall
	
	li $v0, 5
	syscall
	
	move $t0, $v0
	
	li $v0, 4
	la $a0, prompt2
	syscall
	
	li $v0, 1
	move $a0, $t0
	syscall