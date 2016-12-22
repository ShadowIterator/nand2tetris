// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

(start)
@2
M=0
@1
D=M
@seg
D;JGE
@1
M=-M
@0
M=-M
(seg)
@1
D=M
@end
D;JLE
@0
D=M
@2
M=D+M
@1
M=M-1
@seg
0;JMP
(end)