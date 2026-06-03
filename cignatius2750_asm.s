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
    push {r4, lr}
    add r4, r0, r1
    ldr r0, =0xFFFFFF
    bl busy_delay
    mov r0, r4
    pop {r4, pc}


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
