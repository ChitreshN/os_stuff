(LOOP)
    @KBD
    D = M
    @WORK
    D;JNE
    @LOOP
    0;JMP
(WORK)
    @i
    M = 1
    //pdt = 0
    @R2
    M = 0
    @256
    D = A
    @R0
    M = D
    @32
    D = A
    @R1
    M = D

(LOOP1)
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
    @R2
    M = M + D
    @i
    M = M+1
    @LOOP1
    0;JMP
(STOP)
@j
M = 1
@SCREEN
D = A
@curword
M = D

(DARK)
    @j
    D = M
    @R2
    D = D - M
    @LOOP
    D;JGT
    @curword
    D = M
    @j
    D = D + M
    A = D
    M = -1
    @j
    M = M + 1
    @DARK
    0;JMP

(END)
    @END
    0 ; JMP

















