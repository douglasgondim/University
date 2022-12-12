.data
	prompt: .asciiz "Enter the value of pi: "
	zeroAsFloat: .float   0.0
	prompt2: .asciiz "pi = "

.text
	lwc1 $f4, zeroAsFloat
	
	li $v0, 4
	la $a0, prompt
	syscall
	
	li $v0, 6
	syscall
	
	
	li $v0, 4
	la $a0, prompt2
	syscall
	
	li $v0, 2
	add.s $f12, $f0, $f4
	syscall