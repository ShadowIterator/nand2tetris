@261
D=A
@SP
M=D
(function_Sys.init)
@SP
D=M
@LCL
M=D
@0
D=A
@SP
M=M+D

@4
D=A
@SP
AM=M+1
A=A-1
M=D

@rtn_2
D=A
@SP
AM=M+1
A=A-1
M=D
@LCL
D=M
@SP
AM=M+1
A=A-1
M=D
@ARG
D=M
@SP
AM=M+1
A=A-1
M=D
@THIS
D=M
@SP
AM=M+1
A=A-1
M=D
@THAT
D=M
@SP
AM=M+1
A=A-1
M=D
@SP
D=M
@6
D=D-A
@ARG
M=D
@function_Main.fibonacci
0;JMP
(rtn_2)

(label_WHILE)

@label_WHILE
0;JMP

(function_Main.fibonacci)
@SP
D=M
@LCL
M=D
@0
D=A
@SP
M=M+D

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

@2
D=A
@SP
AM=M+1
A=A-1
M=D

@SP
AM=M-1
D=M
@SP
A=M-1
A=M
D=A-D
@if_true_8
D;JLT
D=0
@store_8
0;JMP
(if_true_8)
D=-1
(store_8)
@SP
A=M-1
M=D

@SP
AM=M-1
D=M
@label_IF_TRUE
D;JNE

@label_IF_FALSE
0;JMP

(label_IF_TRUE)

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

(label_IF_FALSE)

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

@2
D=A
@SP
AM=M+1
A=A-1
M=D

@SP
AM=M-1
D=M
@SP
A=M-1
M=M-D

@rtn_18
D=A
@SP
AM=M+1
A=A-1
M=D
@LCL
D=M
@SP
AM=M+1
A=A-1
M=D
@ARG
D=M
@SP
AM=M+1
A=A-1
M=D
@THIS
D=M
@SP
AM=M+1
A=A-1
M=D
@THAT
D=M
@SP
AM=M+1
A=A-1
M=D
@SP
D=M
@6
D=D-A
@ARG
M=D
@function_Main.fibonacci
0;JMP
(rtn_18)

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

@1
D=A
@SP
AM=M+1
A=A-1
M=D

@SP
AM=M-1
D=M
@SP
A=M-1
M=M-D

@rtn_22
D=A
@SP
AM=M+1
A=A-1
M=D
@LCL
D=M
@SP
AM=M+1
A=A-1
M=D
@ARG
D=M
@SP
AM=M+1
A=A-1
M=D
@THIS
D=M
@SP
AM=M+1
A=A-1
M=D
@THAT
D=M
@SP
AM=M+1
A=A-1
M=D
@SP
D=M
@6
D=D-A
@ARG
M=D
@function_Main.fibonacci
0;JMP
(rtn_22)

@SP
AM=M-1
D=M
@SP
A=M-1
M=M+D

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

