
    .syntax unified
    .text


    .global inner_prod_asm
    .func inner_prod_asm, inner_prod_asm
    .thumb_func
inner_prod_asm:
 //initialize the variables in registers
 /*  
 Assume
            R0 = h
            R1 = x
            R2 = n
            R3 = sum
            R4 = i
            R5 = temp
            R6 = temp2

//end*/

//set registers to 0 
    
    PUSH    {R4,R5,R6}      //Stores regs to the top of the stack
    MOV     R3, #0          //sum = 0
    MOV     R4, #0          //i=0
    
  
   B test
   
loop:  
    
    ADD     R0, R0, R4          //h[i]
    ADD     R1, R1, R4          //x[i]
    MUL     R5, R0, R1      //h[i]*x[i]
    ADD     R3, R3, R5      //sum= sum + (h[i]*x[i])
    ADD     R4, R4, #1       //i++
    STR     R4, [R4]
    STR     R3, [R3]
    B test
    
    
test:
    CMP     R4, R2          //i < n
    BLT     loop
    ASR     R3, #16         //shift right by 16
    MOV     R0, R3          //r0=sum
    POP   { R4, R5, R6} 
    SXTH    R0, R3
    BX      LR
//end
    .endfunc


    .end


