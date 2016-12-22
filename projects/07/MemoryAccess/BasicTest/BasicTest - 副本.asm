//push constant 10
@10
D=A
@SP
A=M
M=D
@SP
M=M+1
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
//@TARGET_ADDR
//M=D
//@DATA
//D=M
//@TARGET_ADDR
//A=M
//M=D

//How to improve this?
@LCL
D=A
@0
D=D+A
@TARGET_ADDR
M=D
@SP
AM=M-1
D=M
@TARGET_ADDR
A=M
M=D

//push constant 21
@21
D=A
@SP
A=M
M=D
@SP
M=M+1
//push constant 22
@22
D=A
@SP
A=M
M=D
@SP
M=M+1
//pop argument 2
@SP
M=M-1
A=M
D=M
@DATA
M=D

@R2
D=M
@2
D=D+A
@TARGET_ADDR
M=D
@DATA
D=M
@TARGET_ADDR
A=M
M=D

//pop argument 1
@SP
M=M-1
A=M
D=M
@DATA
M=D

@R2
D=M
@1
D=D+A
@TARGET_ADDR
M=D
@DATA
D=M
@TARGET_ADDR
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
@SP
A=M-1
D=M
@DATA
M=D
@SP
M=M-1

@R3
D=M
@6
D=D+A
@TARGET_ADDR
M=D
@DATA
D=M
@TARGET_ADDR
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
@SP
A=M-1
D=M
@DATA
M=D
@SP
M=M-1

@R4
D=M
@5
D=D+A
@TARGET_ADDR
M=D
@DATA
D=M
@TARGET_ADDR
A=M
M=D
//pop that 2
@SP
A=M-1
D=M
@DATA
M=D
@SP
M=M-1

@R4
D=M
@2
D=D+A
@TARGET_ADDR
M=D
@DATA
D=M
@TARGET_ADDR
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
A=M-1
D=M
@11
M=D
@SP
M=M-1
//push local 0
@R1
D=M
@0
D=D+A
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1
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
A=M-1
D=M
@SP
M=M-1
A=M-1
A=M
D=D+A
@SP
A=M-1
M=D
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
A=M-1
D=M
@SP
M=M-1
A=M-1
A=M
D=A-D
@SP
A=M-1
M=D

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
A=M-1
D=M
@SP
M=M-1
A=M-1
A=M
D=D+A
@SP
A=M-1
M=D
//sub
@SP
A=M-1
D=M
@SP
M=M-1
A=M-1
A=M
D=A-D
@SP
A=M-1
M=D
//push temp 6
@11
D=M
@SP
A=M
M=D
@SP
M=M+1
//add
@SP
A=M-1
D=M
@SP
M=M-1
A=M-1
A=M
D=D+A
@SP
A=M-1
M=D