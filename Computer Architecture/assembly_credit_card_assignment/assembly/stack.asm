.data   # variable stored in RAM
	newLine: .asciiz "\n"

.text
	main:
	addi $s0, $zero, 10 # adds 10 to $s0
	
	jal changeRegister  # calls function changeRegister
	
	# prints newLine
	li, $v0, 4
	la $a0, newLine
	syscall
	
	# prints value of $s0 before function
	jal printsS0
	
	# ends main function
	li $v0, 10
	syscall
	
	# declaring funtions
	changeRegister:
		addi $sp, $sp, -8   # creates an 8 byte stack
		sw $s0, 0($sp)      # stores $s0 in first position of stack
		sw $ra, 4($sp)	    # stores $ra in second positio of stack
 	
		addi $s0, $s0, 35
		
		jal printsS0
		
		lw $s0, 0($sp)      # puts into $s0 whats on 1st position of stack
		lw $ra, 4($sp)
		addi $sp, $sp, 8    # deletes stack
	
		jr $ra              # jump back to main function
		
	printsS0:
		li $v0, 1
		move $a0, $s0
		syscall
		
		jr $ra
	
