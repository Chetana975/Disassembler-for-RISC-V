.data
.dword 0x00000000fcd1866f
.text
lui x3,0x10000
ld x4,0(x3)
#loading instruction in last 32bits of register x4
andi x4,x4,127
#extracting the last 7 bits of x4 i.e the opcode part
#now x4 only contains opcode 
#The opcode of each format is stored in x5
addi x5,x0,19
beq x4,x5,L1
addi x5,x0,3
beq x4,x5,L1
addi x5,x0,103
beq x4,x5,L1
addi x5,x0,115
beq x4,x5,L1
#if the opcode of the given instruction matches with the above values then it is I format
#So we are taking it to label L1 and storing corresponding decimal value in x10
addi x5,x0,51
beq x4,x5,L2
#if the opcode of the given instruction matches with the above value then it is R format
#So we are taking it to label L2 and storing corresponding decimal value in x10
addi x5,x0,35
beq x4,x5,L3
#if the opcode of the given instruction matches with the above value then it is S format
#So we are taking it to label L3 and storing corresponding decimal value in x10
addi x5,x0,99
beq x4,x5,L4
#if the opcode of the given instruction matches with the above value then it is B format
#So we are taking it to label L4 and storing corresponding decimal value in x10
addi x5,x0,111
beq x4,x5,L5
#if the opcode of the given instruction matches with the above value then it is J format
#So we are taking it to label L5 and storing corresponding decimal value in x10
addi x5,x0,23
beq x4,x5,L6
addi x5,x0,55
beq x4,x5,L6
#if the opcode of the given instruction matches with the above values then it is U format
#So we are taking it to label L6 and storing corresponding decimal value in x10
L1:addi x10,x0,2
beq x0,x0,Exit
L2:addi x10,x0,1
beq x0,x0,Exit
L3:addi x10,x0,4
beq x0,x0,Exit
L4:addi x10,x0,3
beq x0,x0,Exit
L5:addi x10,x0,5
beq x0,x0,Exit
L6:addi x10,x0,6
beq x0,x0,Exit
Exit:add x0,x0,x0