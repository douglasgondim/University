.data
    message:  .asciiz "Hi, how are you?"
.text
    main:
        addi $t0, $zero, 5
        addi $t1, $zero, 12
	
	blt $t0, $t1, displayHi
		
		
    li $v0, 10
    syscall
		
    displayHi:
        li $v0, 4
        la $a0, message
        syscall
 		
	