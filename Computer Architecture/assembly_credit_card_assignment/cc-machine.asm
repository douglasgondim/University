.data
    # variables stored in RAM
    zeroAsFloat: .float 0.0
    newLine: .asciiz "\n"
    
    prompt1: .asciiz "Enter 1 for Debit or 2 for Credit: "
    prompt2: .asciiz "Enter 1-VISA/2-Master/3-ELO: "
    prompt3: .asciiz "Amount: $ "
    prompt4: .asciiz "Card Number: "
    prompt5: .asciiz "Password: "
    prompt6: .asciiz "Number of Installments: "
   
    
    visaMessage: .asciiz "VISA"
    masterMessage: .asciiz "MASTER"
    eloMessage: .asciiz "ELO"
    
    debitMessage: .asciiz "-DEBIT"
    creditMessage: .asciiz "-CREDIT"
    
    message1: .asciiz "You chose to pay with: "
    message2: .asciiz "Total: $"
    message3: .asciiz "To be paid in "
    message4: .asciiz " X $"
    
    cardNumber: .space 17
    
    
    

.text    
    main:    # main function.
    
        lwc1 $f4, zeroAsFloat    # stores the value 0.0 in $f4.
        
        # prints "Enter 1 for Debit or 2 for Credit: ".
        li $v0, 4
        la $a0, prompt1
        syscall
        
        jal readInteger    # reads Payment Form (1-Debit or 2-Credit).
        move $t0, $v0      # moves the integer stored in $v0 to $t0.
        
        # prints "Enter 1-VISA/2-Master/3-ELO: ".
        li $v0, 4
        la $a0, prompt2
        syscall
        
        jal readInteger    # reads Card Flag Code.
        move $t1, $v0      # moves the integer stored in $v0 to $t1.
        
        # prints "Amount: $ ".
        li $v0, 4
        la $a0, prompt3
        syscall
        
        # reads a float. (Amount $).
        li $v0, 6
        syscall
        
        add.s $f2, $f4, $f0  # stores in $f2 the float that's in $f0.
        
        # debit or credit
        beq $t0, 2, installments
        return2:
        
        
        # prints "Card Number: ".
        li $v0, 4
        la $a0, prompt4
        syscall
        
        # reads Card Number.
        li $v0, 8
        la $a0, cardNumber
        li $a1, 18
        syscall
        
       
        
        # prints "Password: ".
        li $v0, 4
        la $a0, prompt5
        syscall
        
        jal readInteger # reads Password.
        move $t3, $v0   # moves to register $t3 what's stored in $v0.
        
        jal printNewLine
        
        # prints "You chose to pay with ".
        li $v0, 4
        la $a0, message1
        syscall
        
        # conditionals for user's input(payment form).       
        beq $t1, 1, visa
        beq $t1, 2, master
        beq $t1, 3, elo
        return:
        
        beq $t0, 1, debit
        beq $t0, 2, credit
        return1:
        
        
        jal printNewLine
        
        # prints "Total: $ "
        li $v0, 4
        la $a0, message2
        syscall
        
        # prints Total Amount (float)
        li $v0, 2
        add.s $f12, $f4, $f2
        syscall
        
        # debit or credit
        beq $t0, 2, ifCredit
        return3:
        
        jal printNewLine
        
        # prints "Card Number: "
        li $v0, 4
        la $a0, prompt4
        syscall
        
        # prints card number.
        li $v0, 4
        la $a0, cardNumber
        syscall
        
    # ends main function.  
    li $v0, 10
    syscall
    
    # function to read a float.
    readInteger:
        li $v0, 5
        syscall
        
        jr $ra   # jumps back to main function.
        
    printNewLine:
        li $v0, 4
        la $a0, newLine
        syscall
        
        jr $ra
    
    visa:
        li $v0, 4
        la $a0, visaMessage
        syscall
        
        j return # unconditional jump to variable return
    
    master:
        li $v0, 4
        la $a0, masterMessage
        syscall
        
        j return
    
    
    elo:
        li $v0, 4
        la $a0, eloMessage
        syscall
        
        j return
        
    debit:
        li $v0, 4
        la $a0, debitMessage
        syscall
        
        j return1
    
    
    credit:
        li $v0, 4
        la $a0, creditMessage
        syscall
        
        j return1
       
    installments:
        # prints "Number of installments: "
        li $v0, 4
        la $a0, prompt6
        syscall
        
        # reads number of installments
        li $v0, 5
        syscall
        
        move $t4, $v0
        
        mtc1 $t4, $f8
        cvt.s.w $f8, $f8
        
       
        div.s $f10, $f2, $f8
        
        j return2
        
        
    ifCredit:
        jal printNewLine
        
        # prints "To be paid in "
        li $v0, 4
        la $a0, message3
        syscall
        
        # prints number of installments
        li $v0, 1
        move $a0, $t4
        syscall
        
        # prints "X"
        li $v0, 4
        la $a0, message4
        syscall
        
        # prints value of each installment
        li $v0, 2
        mov.s $f12, $f10
        syscall
        
        j return3
     
