(function_SimpleFunction.test)
@SP
D=M
@LCL
M=D
@2
D=A
@SP
M=M+D

@LCL
D=M
@0
D=D+A
A=D
D=M
@SP
M=M+1
A=M-1
M=D

@LCL
D=M
@1
D=D+A
A=D
D=M
@SP
M=M+1
A=M-1
M=D

@SP
AM=M-1
D=M
@SP
A=M-1
M=M+D

@SP
A=M-1
M=!M

@ARG
D=M
@0
D=D+A
A=D
D=M
@SP
M=M+1
A=M-1
M=D

@SP
AM=M-1
D=M
@SP
A=M-1
M=M+D

@ARG
D=M
@1
D=D+A
A=D
D=M
@SP
M=M+1
A=M-1
M=D

@SP
AM=M-1
D=M
@SP
A=M-1
M=M-D

@ARG
D=M
@R15
M=D
@SP
AM=M-1
D=M
@R13
M=D
@LCL
D=M
@SP
M=D
@SP
AM=M-1
D=M
@THAT
M=D
@SP
AM=M-1
D=M
@THIS
M=D
@SP
AM=M-1
D=M
@ARG
M=D
@SP
AM=M-1
D=M
@LCL
M=D
@SP
AM=M-1
D=M
@R14
M=D
@R15
D=M
@SP
M=D
@R13
D=M
@SP
AM=M+1
A=A-1
M=D
@R14
A=M
0;JMP
