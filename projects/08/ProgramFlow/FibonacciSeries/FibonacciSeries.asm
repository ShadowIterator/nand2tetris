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
@4
M=D

@0
D=A
@SP
AM=M+1
A=A-1
M=D

@THAT
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

@1
D=A
@SP
AM=M+1
A=A-1
M=D

@THAT
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

@ARG
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

(label_MAIN_LOOP_START)

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
@label_COMPUTE_ELEMENT
D;JNE

@label_END_PROGRAM
0;JMP

(label_COMPUTE_ELEMENT)

@THAT
D=M
@0
D=D+A
A=D
D=M
@SP
M=M+1
A=M-1
M=D

@THAT
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

@THAT
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

@4
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
M=M+D

@SP
AM=M-1
D=M
@4
M=D

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

@ARG
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

@label_MAIN_LOOP_START
0;JMP

(label_END_PROGRAM)

