// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.
//i = 1
@i
M = 1
//pdt = 0
@pdt
M = 0

(LOOP)
// R1 iterations
//
    @i
    D = M
    @R1
    D = D - M
    @STOP
    D ; JGT
    @R0
    D = M
    @pdt
    M = M + D
    @i
    M = M+1
    @LOOP
    0;JMP

(STOP)
    @pdt
    D = M
    @R2
    M = D

(END)
    @END
    0 ; JMP

