@ cignatius2750_asm.s Data section - initialized values
.data
.align 3

huge:   .octa 0xAABBCCDDDDCCBBFF
big:    .word 0xAAEEBBFF
num:    .byte 0xAB
str2:   .asciz "Guten Tag!"
count:  .word 12345

@ End of new data section




@ Test code for my own new function called from C

    .code   16
    .text

    .align  2
    .syntax unified
    .global cignatius2750_add_test
    .code   16
    .thumb_func
    .type   cignatius2750_add_test, %function

@ Function Declaration : int cignatius2750_add_test (int x, int y)
@
@ Input: r0, r1 (i.e. r0 holds x, r1 holds y)
@ Returns: r0




cignatius2750_add_test:
    push {r4, r5, lr}

    ldr r0, =num
    ldr r0, =big
    ldr r0, =huge
    ldr r0, =str2

    ldr r2, =str2
    ldrb r0, [r2]

    ldr r2, =str2
    ldr r0, [r2]

    ldr r2, =num
    ldrb r0, [r2]

    ldr r2, =big
    ldr r0, [r2]

    ldr r2, =huge
    ldrd r0, r1, [r2]

    bkpt

    add r4, r0, r1
    mov r5, r2
    mov r0, r5
    bl busy_delay
    mov r0, r4
    pop {r4, r5, pc}


.align  2               @ Code alignment is 2^n alignment (n=2)
    .syntax unified         @ Sets the instruction set to the unified ARM + THUMB
    .global cignatius2750_a2   @ Make the symbol name for the function visible to the linker
    .code   16              @ 16bit THUMB code (BOTH .code and .thumb_func are required)
    .thumb_func             @ Specifies that the following symbol is the name of a THUMB
    .type   cignatius2750_a2, %function

@ Function Declaration : int cignatius2750_a2 (int num, int wait)
@
@ Input: r0 (num), r1 (wait)
@ Returns: r0 (total number of LED toggles performed)
@
cignatius2750_a2:
    @ Fill in the necessary logic here
    bx lr
    .size   cignatius2750_a2, .- cignatius2750_a2


@ Function Declaration : int busy_delay(int cycles)
@
@ Input: r0 (i.e. r0 holds number of cycles to delay)
@ Returns: r0
@ 

@ Here is the actual function. DO NOT MODIFY THIS FUNCTION.
busy_delay:

    push {r6}

    mov r6, r0

delay_label:
    subs r6, r6, #1

    bge delay_label

    mov r0, #0                      @ Always return zero (success)

    pop {r6}

    bx lr                           @ Return (Branch eXchange) to the address in the link register (lr)


.end
