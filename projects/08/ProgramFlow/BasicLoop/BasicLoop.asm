@0
D=A
@SP
AM=M+1
A=A-1
M=D

@LCL
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

(label_LOOP_START)

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

@SP
AM=M-1
D=M
@SP
A=M-1
M=M+D

@LCL
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
@label_LOOP_START
D;JNE

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

