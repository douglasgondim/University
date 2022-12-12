.data
	message:  .asciiz "The numbers are different."
	message1: .asciiz "Nothing happened."
.text
	main:
		addi $t0, $zero, 20
		addi $t1, $zero, 20
	
		bne $t0, $t1, different
		# beq and bne
		
	
	
	
		li $v0, 10
		syscall
	
	different:
		li $v0, 4
		la $a0, message
		syscall
