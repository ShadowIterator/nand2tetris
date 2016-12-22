//function Sys.init 0
(Sys.init)

//call Sys.main 0
///push constant RTN_Sys.init
@RTN_Sys.init_1
D=A
@SP
AM=M+1
A=A-1
M=D
///push LCL
@LCL
D=M
@SP
AM=M+1
A=A-1
M=D
///push ARG
@ARG
D=M
@SP
AM=M+1
A=A-1
M=D
///push THIS 
@THIS
D=M
@SP
AM=M+1
A=A-1
M=D
///push THAT
@THAT
D=M
@SP
AM=M+1
A=A-1
M=D

///ARG=SP-arg_num+5
@SP
D=M
@5
D=D-A
@ARG
M=D




@Sys.main
0;JMP
(RTN_Sys.init_1)
 
//pop temp 1
@SP
AM=M-1
D=M
@6
M=D
//label LOOP
(label_LOOP)
//goto LOOP
@label_LOOP
0;JMP

//function Sys.main 0
(Sys.main)
///LCL=SP
@SP
D=M
@LCL
M=D
///SP=SP+lcl_num
@0
D=A
@SP
M=M+D
//push constant 123
@123
D=A
@SP
AM=M+1
A=A-1
M=D
//call Sys.add12 1
///push constant RTN_Sys.main
@RTN_Sys.main
D=A
@SP
AM=M+1
A=A-1
M=D
///push LCL
@LCL
D=M
@SP
AM=M+1
A=A-1
M=D
///push ARG
@ARG
D=M
@SP
AM=M+1
A=A-1
M=D
///push THIS 
@THIS
D=M
@SP
AM=M+1
A=A-1
M=D
///push THAT
@THAT
D=M
@SP
AM=M+1
A=A-1
M=D
///ARG=SP-arg_num+5
@SP
D=M
@6
D=D-A
@ARG
M=D



@add12
0;JMP
(RTN_Sys.main)

//pop temp 0
@SP
AM=M-1
D=M
@5
M=D

//push constant 246
@246
D=A
@SP
AM=M+1
A=A-1
M=D
//return
///pop ->R13
@SP
AM=M-1
D=M
@R13
M=D
///SP=SP-lcl_num
@0
D=A
@SP
M=M-D
///pop THAT
@SP
AM=M-1
D=M
@THAT
M=D
///pop THIS
@SP
AM=M-1
D=M
@THIS
M=D
///pop ARG
@SP
AM=M-1
D=M
@ARG
M=D
///pop LCL
@SP
AM=M-1
D=M
@LCL
M=D
///pop R14
@SP
AM=M-1
D=M
@R14
M=D
///SP=SP-arg_num
@0
D=A
@SP
M=M-D
///push R13
@R13
D=M
@SP
AM=M+1
A=A-1
M=D

@R14
A=M
0;JMP


//function Sys.add12 3
(add12)
///LCL=SP
@SP
D=M
@LCL
M=D
///SP=SP+lcl_num
@3
D=A
@SP
M=M+D
//push argument 0
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
//push constant 12
@12
D=A
@SP
AM=M+1
A=A-1
M=D
//add
@SP
AM=M-1
D=M
@SP
A=M-1
M=M+D
//return
///pop ->R13
@SP
AM=M-1
D=M
@R13
M=D
///SP=SP-lcl_num
@3
D=A
@SP
M=M-D
///pop THAT
@SP
AM=M-1
D=M
@THAT
M=D
///pop THIS
@SP
AM=M-1
D=M
@THIS
M=D
///pop ARG
@SP
AM=M-1
D=M
@ARG
M=D
///pop LCL
@SP
AM=M-1
D=M
@LCL
M=D
///pop R14
@SP
AM=M-1
D=M
@R14
M=D
///SP=SP-arg_num
@1
D=A
@SP
M=M-D
///push R13
@R13
D=M
@SP
AM=M+1
A=A-1
M=D

@R14
A=M
0;JMP

