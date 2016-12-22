//push constant 10
@10
D=A
@SP
AM=M+1
A=A-1
M=D
//pop local 0  WRONG?
//@SP
//M=M-1
//A=M
//D=M
//@DATA
//M=D

//@R1
//D=M
//@0
//D=D+A
//@R13
//M=D
//@DATA
//D=M
//@R13
//A=M
//M=D

//How to improve this?
@R1
D=M
@0
D=D+A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//push constant 21
@21
D=A
@SP
AM=M+1
A=A-1
M=D
//push constant 22
@22
D=A
@SP
AM=M+1
A=A-1
M=D
//pop argument 2

@R2
D=M
@2
D=D+A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//pop argument 1

@R2
D=M
@1
D=D+A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//push constant 36
@36
D=A
@SP
A=M
M=D
@SP
M=M+1
//pop this 6
@R3
D=M
@6
D=D+A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
//push constant 42
@42
D=A
@SP
A=M
M=D
@SP
M=M+1
//push constant 45
@45
D=A
@SP
A=M
M=D
@SP
M=M+1
//pop that 5
@R4
D=M
@5
D=D+A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
//pop that 2
@R4
D=M
@2
D=D+A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
//push constant 510
@510
D=A
@SP
A=M
M=D
@SP
M=M+1
//pop temp 6
@SP
AM=M-1
D=M
@11
M=D
//push local 0
@R1
D=M
@0
D=D+A
A=D
D=M
@SP
M=M+1
A=M-1
M=D
//@SP
//A=M
//M=D
//@SP
//M=M+1
//push that 5
@R4
D=M
@5
D=D+A
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1
//add
@SP
AM=M-1
D=M
@SP
A=M-1
M=M+D
//push argument 1
@R2
D=M
@1
D=D+A
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1

//sub
@SP
AM=M-1
D=M
@SP
A=M-1
M=M-D

//push this 6
@R3
D=M
@6
D=D+A
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1
//push this 6
@R3
D=M
@6
D=D+A
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1
//add
@SP
AM=M-1
D=M
@SP
A=M-1
A=M
D=D+A
@SP
A=M-1
M=D
//sub
@SP
AM=M-1
D=M
@SP
A=M-1
M=M-D
//push temp 6
@11
D=M
@SP
M=M+1
A=M-1
M=D
//add
@SP
AM=M-1
D=M
@SP
A=M-1
M=M+D
