#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int lcount=0;
int shift[20]={0};
int postcount[20]={0};
int pc_label[20]={0};
int programcount=-4;

int hexToBinary(char hex, char* binary) {
    if(hex=='0'){strcpy(binary, "0000");}
    else if(hex=='1'){strcpy(binary, "0001");}
    else if(hex=='2'){strcpy(binary, "0010");}
    else if(hex=='3'){strcpy(binary, "0011");}
    else if(hex=='4'){strcpy(binary, "0100");}
    else if(hex=='5'){strcpy(binary, "0101");}
    else if(hex=='6'){strcpy(binary, "0110");}
    else if(hex=='7'){strcpy(binary, "0111");}
    else if(hex=='8'){strcpy(binary, "1000");}
    else if(hex=='9'){strcpy(binary, "1001");}
    else if(hex=='a'){strcpy(binary, "1010");}
    else if(hex=='b'){strcpy(binary, "1011");}
    else if(hex=='c'){strcpy(binary, "1100");}
    else if(hex=='d'){strcpy(binary, "1101");}
    else if(hex=='e'){strcpy(binary, "1110");}
    else if(hex=='f'){strcpy(binary, "1111");}
    else {
        printf("Invalid hex digit: %c\n", hex);
        return 0; // Return 0 to indicate failure
    }
    
    return 1; // Return 1 to indicate success
}

int binaryToDecimal(char* binary){
     int i=0,decimal=0;
     while(binary[i]!='\0'){
            decimal=(decimal*2)+(binary[i]-'0');
            i++;
     }
     return decimal;
}

int binaryToDecimalsigned(char* binary){
     int i=1,decimal;
     decimal=-(binary[0]-'0');
     while(binary[i]!='\0'){
            decimal=(decimal*2)+(binary[i]-'0');
            i++;
     }
     return decimal;
}

int rFormat(char* binaryString){
   // printf("Hello\n");
   char fun7[8];
   char rs2[6];
   char rs1[6];
   char fun3[4];
   char rd[6];
   int src1,src2,dest,f3,f7;
   
   for(int i=0;i<7;i++){
        fun7[i]=binaryString[i];  
   }
   fun7[7]='\0';
   
   for(int i=0;i<5;i++){
        rs2[i]=binaryString[7+i];
   }
   rs2[5]='\0';
   
   for(int i=0;i<5;i++){
        rs1[i]=binaryString[12+i];
   }
   rs1[5]='\0'; 
   
   for(int i=0;i<3;i++){
        fun3[i]=binaryString[17+i];
   }
   fun3[3]='\0';
   
   for(int i=0;i<5;i++){
        rd[i]=binaryString[20+i];
   }
   rd[5]='\0';
   
   src1=binaryToDecimal(rs1);
   src2=binaryToDecimal(rs2);
   dest=binaryToDecimal(rd);
   f3=binaryToDecimal(fun3);
   f7=binaryToDecimal(fun7);
   if((f3==0)&&(f7==0)){
          printf("add x%d,x%d,x%d\n",dest,src1,src2);
   }
   else if((f3==0)&&(f7==32)){
          printf("sub x%d,x%d,x%d\n",dest,src1,src2);
   }
   else if((f3==4)&&(f7==0)){
          printf("xor x%d,x%d,x%d\n",dest,src1,src2);
   }
   else if((f3==6)&&(f7==0)){
          printf("or x%d,x%d,x%d\n",dest,src1,src2);
   }
   else if((f3==7)&&(f7==0)){
          printf("and x%d,x%d,x%d\n",dest,src1,src2);
   }
   else if((f3==1)&&(f7==0)){
          printf("sll x%d,x%d,x%d\n",dest,src1,src2);
   }
   else if((f3==5)&&(f7==0)){
          printf("srl x%d,x%d,x%d\n",dest,src1,src2);
   }
   else if((f3==5)&&(f7==32)){
          printf("sra x%d,x%d,x%d\n",dest,src1,src2);
   }
   else if((f3==2)&&(f7==0)){
          printf("slt x%d,x%d,x%d\n",dest,src1,src2);
   }
   else if((f3==3)&&(f7==0)){
          printf("sltu x%d,x%d,x%d\n",dest,src1,src2);
   }
   return 0;
}

int iFormat(char* binaryString,char* opcode){
   char imm[13];
   char rs[6];
   char fun3[4];
   char rd[6];
   int imd,src,f3,dest,f6,imd2;
   char fun6[7];
   char imm2[7];
   
   for(int i=0;i<12;i++){
        imm[i]=binaryString[i];
   }
   imm[12]='\0';
   
   for(int i=0;i<5;i++){
       rs[i]=binaryString[12+i];
   }
   rs[5]='\0';
   
   for(int i=0;i<3;i++){
       fun3[i]=binaryString[17+i];
   }
   fun3[3]='\0';
   
   for(int i=0;i<5;i++){
       rd[i]=binaryString[20+i];
   }
   rd[5]='\0';
   
   src=binaryToDecimal(rs);
   dest=binaryToDecimal(rd);
   f3=binaryToDecimal(fun3);
   if((strcmp(opcode,"0010011")==0)){
        if((f3==1)||(f3==5)){
             for(int i=0;i<6;i++){
                 fun6[i]=imm[i];
             }
             fun6[6]='\0';
             for(int i=0;i<6;i++){
                 imm2[i]=imm[6+i];
             } 
             imm2[6]='\0';
             f6=binaryToDecimal(fun6);
             imd2=binaryToDecimal(imm2);
             
             if(f3==1){
                  printf("slli x%d,x%d,%d\n",dest,src,imd2);
             }
             else if((f3==5)&&(f6==0)){
                  printf("srli x%d,x%d,%d\n",dest,src,imd2);
             }
             else if((f3==5)&&(f6==16)){
                  printf("srai x%d,x%d,%d\n",dest,src,imd2);
             }
        }
   }
   imd=binaryToDecimalsigned(imm);
   //imdu=binayToDecimal(imm);
   //printf("rd:%d\nrs:%d\nimm:%d\n",dest,src,imd);
   if(strcmp(opcode,"0010011")==0){
   if(f3==0){
        printf("addi x%d,x%d,%d\n",dest,src,imd);
   }
   else if(f3==4){
        printf("xori x%d,x%d,%d\n",dest,src,imd);
   }
   else if(f3==6){
        printf("ori x%d,x%d,%d\n",dest,src,imd);
   }
   else if(f3==7){
        printf("andi x%d,x%d,%d\n",dest,src,imd);
   }
   else if(f3==2){
        printf("slti x%d,x%d,%d\n",dest,src,imd);
   }
   else if(f3==3){
        printf("sltiu x%d,x%d,%d\n",dest,src,imd);
   }
   }
   else if(strcmp(opcode,"0000011")==0){
   if(f3==0){
        printf("lb x%d,%d(x%d)\n",dest,imd,src);
   }
   else if(f3==1){
        printf("lh x%d,%d(x%d)\n",dest,imd,src);
   }
   else if(f3==2){
        printf("lw x%d,%d(x%d)\n",dest,imd,src);
   }
   else if(f3==3){
        printf("ld x%d,%d(x%d)\n",dest,imd,src);
   }
   else if(f3==4){
        printf("lbu x%d,%d(x%d)\n",dest,imd,src);
   }
   else if(f3==5){
        printf("lhu x%d,%d(x%d)\n",dest,imd,src);
   }
   else if(f3==6){
        printf("lwu x%d,%d(x%d)\n",dest,imd,src);
   }
   
   }
   else if(strcmp(opcode,"0000011")==1100111){
   printf("jalr x%d,%d(x%d)\n",dest,imd,src);
   }
   return 0;
}

int sFormat(char* binaryString){
   char imm[13];
   char rs2[6];
   char rs1[6];
   char fun3[4];
   int src1,src2,imd,f3;
   
   for(int i=0;i<7;i++){
       imm[i]=binaryString[i];
   }
   for(int i=0;i<5;i++){
       imm[7+i]=binaryString[20+i];
   }
   imm[12]='\0';
   
   for(int i=0;i<5;i++){
       rs2[i]=binaryString[7+i];
   }
   rs2[5]='\0';
   
   for(int i=0;i<5;i++){
       rs1[i]=binaryString[12+i];
   }
   rs1[5]='\0';

   for(int i=0;i<3;i++){
       fun3[i]=binaryString[17+i];
   }
   fun3[3]='\0';
   
   src1=binaryToDecimal(rs1);
   src2=binaryToDecimal(rs2);
   f3=binaryToDecimal(fun3);
   imd=binaryToDecimalsigned(imm);
   
   if(f3==0){
        printf("sb x%d,%d(x%d)\n",src2,imd,src1);
   }
   else if(f3==1){
        printf("sh x%d,%d(x%d)\n",src2,imd,src1);
   }
   else if(f3==2){
        printf("sw x%d,%d(x%d)\n",src2,imd,src1);
   }
   else if(f3==3){
        printf("sd x%d,%d(x%d)\n",src2,imd,src1);
   }
   return 0;  
}

int bFormat(char* binaryString){
   char imm[13];
   char rs2[6];
   char rs1[6];
   char fun3[4];
   int src1,src2,imd,f3;
   imm[0]=binaryString[0];
   imm[1]=binaryString[24];
   for(int i=0;i<6;i++){
        imm[i+2]=binaryString[i+1];
   }
   for(int i=0;i<4;i++){
        imm[i+8]=binaryString[i+20];
   }
   imm[12]='\0';

   for(int i=0;i<5;i++){
        rs2[i]=binaryString[i+7];
   }
   rs2[5]='\0';
   
   for(int i=0;i<5;i++){
        rs1[i]=binaryString[i+12];
   }
   rs1[5]='\0';
   
   for(int i=0;i<3;i++){
        fun3[i]=binaryString[i+17];
   }
   fun3[3]='\0';
   src1=binaryToDecimal(rs1);
   src2=binaryToDecimal(rs2);
   f3=binaryToDecimal(fun3);
   imd=binaryToDecimalsigned(imm);
   imd=imd*2;
   int k=0,l=0,i=1;
   while(i<=lcount){
              if((programcount+imd)==pc_label[i]){k=1;l=i;break;}
              i++;
   }
   if(k==0){lcount++;l=lcount;pc_label[lcount]=programcount+imd;} 
   if(f3==0){
       printf("beq x%d,x%d,L%d\n",src1,src2,l);
   }
   else if(f3==1){
       printf("bne x%d,x%d,L%d\n",src1,src2,l);
   }
   else if(f3==4){
       printf("blt x%d,x%d,L%d\n",src1,src2,l);
   }
   else if(f3==5){
       printf("bge x%d,x%d,L%d\n",src1,src2,l);
   }
   else if(f3==6){
       printf("bltu x%d,x%d,L%d\n",src1,src2,l);
   }
   else if(f3==7){
       printf("bgeu x%d,x%d,L%d\n",src1,src2,l);
   }
   return 0;
}

int jFormat(char* binaryString){
   char imm[21];
   char rd[6];
   int imd,dest;
   imm[0]=binaryString[0];
   imm[9]=binaryString[11];
   for(int i=0;i<10;i++){
        imm[10+i]=binaryString[i+1];
   }
   for(int i=0;i<8;i++){
        imm[1+i]=binaryString[12+i];
   }
   imm[20]='\0';
   for(int i=0;i<5;i++){
        rd[i]=binaryString[20+i];
   }
   rd[5]='\0';
   imd=binaryToDecimalsigned(imm);
   dest=binaryToDecimal(rd);
   imd=imd*2;
   int k=0,l=0,i=1;
   while(i<=lcount){
              if((programcount+imd)==pc_label[i]){k=1;l=i;break;}
              i++;
   }
   if(k==0){lcount++;l=lcount;pc_label[lcount]=programcount+imd;} 
   printf("jal x%d,L%d\n",dest,l);
   return 0;
}

int uFormat(char* binaryString){
   char imm[21];
   char rd[6];
   int imd,dest;
   for(int i=0;i<20;i++){
        imm[i]=binaryString[i];
   }
   imm[20]='\0';
   for(int i=0;i<5;i++){
        rd[i]=binaryString[20+i];
   }
   rd[5]='\0';
   imd=binaryToDecimal(imm);
   dest=binaryToDecimal(rd);
   printf("lui x%d,%d\n",dest,imd);
   return 0;  
}

int main() {

    FILE *file=fopen("input2.txt","r");
    char line[100];
    while(fgets(line, sizeof(line), file) != NULL){
    if(line!=NULL){
    programcount=programcount+4;
    if(lcount>0){
           int lc=1;
           while(lc<=lcount){
                 if(programcount==pc_label[lc]){
                        printf("L%d:",lc);
                 }
                 lc++;
           }
                
    }
    char hexString[9];
    strncpy(hexString,line,8);
    hexString[8]='\0';
    char binaryString[33];
    char opcode[8];
    for (int i = 0; i < 8; i++) {
        if (hexToBinary(hexString[i], binaryString + i * 4) == 0) {
            return 1; // Exit with an error code if an invalid hex digit is encountered
        }
    }
    
    binaryString[32] = '\0'; // Null-terminate the binary string
    for(int i=0;i<8;i++){
        opcode[i]=binaryString[25+i];
    }
    //printf("opcode: %s\n",opcode);
    char ropcode[]="0110011";
    char i1opcode[]="0010011";
    char i2opcode[]="0000011";
    char i3opcode[]="1100111";
    char sopcode[]="0100011";
    char bopcode[]="1100011";
    char jopcode[]="1101111";
    char uopcode[]="0110111";
    if(strcmp(opcode,ropcode)==0){
        rFormat(binaryString);
    }
    else if((strcmp(opcode,i1opcode)==0)||(strcmp(opcode,i2opcode)==0)||(strcmp(opcode,i3opcode)==0)){       
        iFormat(binaryString,opcode);
    }
    else if(strcmp(opcode,sopcode)==0){
        sFormat(binaryString);
    }
    else if(strcmp(opcode,bopcode)==0){
        
        //lcount++;
        bFormat(binaryString);
    }
    else if(strcmp(opcode,jopcode)==0){
       // lcount++;
        jFormat(binaryString);
    }
    else if(strcmp(opcode,uopcode)==0){
        uFormat(binaryString);
    }
    }
    }
    
    fclose(file);
    //printf("Hex: %s, Binary: %s\n", hexString, binaryString);
    
    return 0;
}

