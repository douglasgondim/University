.data
    num1:  .float 2.05
    num2:  .float 3.14

.text
    main:
    
    lwc1 $f2, num1
    lwc1 $f4, num2
    
    add.s $f12, $f2, $f4
    
    li $v0, 2
    syscall
    
    
    
    
    li $v0, 10
    syscall