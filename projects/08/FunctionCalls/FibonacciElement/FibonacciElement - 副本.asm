@261
D=A
@SP
M=D
//function Sys.init 0
(Sys.init)
//push constant 4
@4
D=A
@SP
AM=M+1
A=A-1
M=D
//call Main.fibonacci 1   // computes the 4'th fibonacci element
///push constant RTN_Sys.init
@RTN_Sys.init
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
@Main.fibonacci
0;JMP
(RTN_Sys.init)
//label WHILE
(label_WHILE)
//goto WHILE              // loops infinitely
@label_WHILE
0;JMP

//function Main.fibonacci 0
(Main.fibonacci)
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
//push constant 2
@2
D=A
@SP
AM=M+1
A=A-1
M=D

//lt                     // checks if n<2
@SP
AM=M-1
D=M
@SP
A=M-1
A=M
D=A-D
@if_true_5
D;JLT
D=0
@store_5
0;JMP
(if_true_5)
D=-1
(store_5)
@SP
A=M-1
M=D
//if-goto IF_TRUE
@SP
AM=M-1
D=M
@label_IF_TRUE
D;JNE

//goto IF_FALSE
@label_IF_FALSE
0;JMP
//label IF_TRUE          // if n<2, return n
(label_IF_TRUE)

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

//label IF_FALSE         // if n>=2, returns fib(n-2)+fib(n-1)
(label_IF_FALSE)

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
//push constant 2
@2
D=A
@SP
AM=M+1
A=A-1
M=D

//sub
@SP
AM=M-1
D=M
@SP
A=M-1
M=M-D

//call Main.fibonacci 1  // computes fib(n-2)
///push constant RTN_Sys.init
@RTN_FIB_1
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
@Main.fibonacci
0;JMP
(RTN_FIB_1)
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
//push constant 1
@1
D=A
@SP
AM=M+1
A=A-1
M=D

//sub
@SP
AM=M-1
D=M
@SP
A=M-1
M=M-D


//call Main.fibonacci 1  // computes fib(n-1)
///push constant RTN_Sys.init
@RTN_FIB_2
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
@Main.fibonacci
0;JMP
(RTN_FIB_2)
//add                    // returns fib(n-1) + fib(n-2)
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
