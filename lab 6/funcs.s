@ write your arm code below:
        .global         _Z3maxiii
        .global         _Z3sumii
        .global         _Z7oddProdii
        .global         _Z9sumDoublePii
        .global         _Z5sumSqPii

_Z3maxiii:
        cmp             r0,  r1
        movlt   r0,  r1
        cmp             r0,  r2
        movlt   r0,  r2
        bx              lr

_Z3sumii:
        cmp     r0,  r1
        beq             2f
    mov         r2,  r0
1:
        add             r2,  #1
        add             r0,  r2
        cmp             r2,  r1
        blt             1b
2:
        bx              lr

_Z7oddProdii:
        cmp             r0,  r1
        beq             2f
        mov     r2,  r0
1:
        add             r2,  #2
        mul     r0,  r2
        cmp             r2,  r1
        blt             1b
2:
        bx              lr
_Z9sumDoublePii:
        mov     r2,  #0
1:
        ldr             r3,     [r0]
        add             r3,    r3
        add             r2,     r3
        add             r0,     #4
        sub             r1,     #1
        cmp             r1,     #0
        bne             1b

        mov             r0,   r2
        bx              lr

_Z5sumSqPii:
        mov             r2,   #0
1:
        ldr             r3,   [r0]
        mul             r3,   r3
        add             r2,   r3
        add             r0,     #4
        sub             r1,   #1
        cmp             r1,   #0
        bne             1b

        mov             r0,   r2
        bx              lr
