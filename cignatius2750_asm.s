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
    add r0, r0, r1
    bx lr
    .size   cignatius2750_add_test, .-cignatius2750_add_test

.end