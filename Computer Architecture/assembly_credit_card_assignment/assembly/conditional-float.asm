.data
    message: .asciiz "Equal Values"
    message1: .asciiz "Different Values"
    num1: .float 10.7
    num2: .float 8.3
.text
    main:
        lwc1 $f0, num1
        lwc1 $f2, num2
    
        c.eq.s $f0, $f2
        #c.le.s
    
        bc1t exit
        
        li $v0, 4
        la $a0, message1
        syscall
    
    
    
    li $v0, 10
    syscall
    
    
    exit:
        li $v0, 4
        la $a0, message
        syscall