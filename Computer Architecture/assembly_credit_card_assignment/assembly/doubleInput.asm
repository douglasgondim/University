.data
	prompt: .asciiz  "Enter the vallue of e: "
.text
	main:
	li $v0, 4
	la $a0, prompt
	syscall
	
	li $v0, 7
	syscall
	
	li $v0, 3
	add.d $f12, $f0, $f10
	syscall