// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

(start)
@8192
D=A
@i
M=D
@SCREEN
D=  A
@  j
M=  D
@2  4576
D= M
@nonps
D;JEQ
@press
0;JMP
(press)
@k
M=-1
@crend
0;JMP
(nonps)
@k
M=0
@crend
0;JMP
(crend)
@k
D=M
@j
A=M
M=D
@j
M=M+1
@i
M=M-1
D=M
@crend
D;JGT
@start
0;JMP
(end)
