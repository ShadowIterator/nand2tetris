@17
D=A
@SP
AM=M+1
A=A-1
M=D
@17
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
@if_true_2
D;JEQ
D=0
@store_2
0;JMP
(if_true_2)
D=-1
(store_2)
@SP
A=M-1
M=D
@17
D=A
@SP
AM=M+1
A=A-1
M=D
@16
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
@if_true_5
D;JEQ
D=0
@store_5
0;JMP
(if_true_5)
D=-1
(store_5)
@SP
A=M-1
M=D
@16
D=A
@SP
AM=M+1
A=A-1
M=D
@17
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
D;JEQ
D=0
@store_8
0;JMP
(if_true_8)
D=-1
(store_8)
@SP
A=M-1
M=D
@892
D=A
@SP
AM=M+1
A=A-1
M=D
@891
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
@if_true_11
D;JLT
D=0
@store_11
0;JMP
(if_true_11)
D=-1
(store_11)
@SP
A=M-1
M=D
@891
D=A
@SP
AM=M+1
A=A-1
M=D
@892
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
@if_true_14
D;JLT
D=0
@store_14
0;JMP
(if_true_14)
D=-1
(store_14)
@SP
A=M-1
M=D
@891
D=A
@SP
AM=M+1
A=A-1
M=D
@891
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
@if_true_17
D;JLT
D=0
@store_17
0;JMP
(if_true_17)
D=-1
(store_17)
@SP
A=M-1
M=D
@32767
D=A
@SP
AM=M+1
A=A-1
M=D
@32766
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
@if_true_20
D;JGT
D=0
@store_20
0;JMP
(if_true_20)
D=-1
(store_20)
@SP
A=M-1
M=D
@32766
D=A
@SP
AM=M+1
A=A-1
M=D
@32767
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
@if_true_23
D;JGT
D=0
@store_23
0;JMP
(if_true_23)
D=-1
(store_23)
@SP
A=M-1
M=D
@32766
D=A
@SP
AM=M+1
A=A-1
M=D
@32766
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
@if_true_26
D;JGT
D=0
@store_26
0;JMP
(if_true_26)
D=-1
(store_26)
@SP
A=M-1
M=D
@57
D=A
@SP
AM=M+1
A=A-1
M=D
@31
D=A
@SP
AM=M+1
A=A-1
M=D
@53
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
@112
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
@SP
A=M-1
M=-M
@SP
AM=M-1
D=M
@SP
A=M-1
M=M&D
@82
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
M=M|D
@SP
A=M-1
M=!M
