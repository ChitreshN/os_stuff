#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define buffer_max 128
#define bits 16

struct jump{
    const char* nothing;
    const char* JGT;
    const char* JEQ;
    const char* JGE;
    const char* JLT;
    const char* JNE;
    const char* JLE;
    const char* JMP;
};

struct jump const jmp = {
    .nothing = "000",
    .JGT = "001",
    .JEQ = "010",
    .JGE = "011",
    .JLT = "100",
    .JNE = "101",
    .JLE = "110",
    .JMP = "111",
};

struct dest{
    const char* nothing;
    const char* M;
    const char* D;
    const char* MD;
    const char* A;
    const char* AM;
    const char* AD;
    const char* AMD;
};

struct dest const dest_adr= {
    .nothing = "000",
    .M = "001",
    .D = "010",
    .MD = "011",
    .A = "100",
    .AM = "101",
    .AD = "110",
    .AMD = "111",
};

struct comp{
    const char* _0;
    const char* _1;
    const char* _neg_1;
    const char* D;
    const char* A;
    const char* not_D;
    const char* not_A;
    const char* neg_D;
    const char* neg_A;
    const char* D_p_1;
    const char* A_p_1;
    const char* D_m_1;
    const char* A_m_1;
    const char* D_p_A;
    const char* D_m_A;
    const char* A_m_D;
    const char* D_and_A;
    const char* D_or_A;
};

struct comp const comp_code = {
    ._0 = "101010",
    ._1 = "111111",
    ._neg_1 = "111010",
    .D = "001100",
    .A = "110000",
    .not_D = "001101",
    .not_A = "110001",
    .neg_D = "001111",
    .neg_A = "110011",
    .D_p_1 = "011111",
    .A_p_1 = "110111",
    .D_m_1 = "001110",
    .A_m_1 = "110010",
    .D_p_A = "000010",
    .D_m_A = "010011",
    .A_m_D = "000111",
    .D_and_A = "000000",
    .D_or_A = "010101",
};

char* process_line(char code[bits],int n, char line[n+1]){
     
    for (int i = 0;i < bits;i++){
        code[i] = '0';
    }
    // check for = or ; in line
    int eq = -1;
    for(int i = 0;i < n;i++){
        if (line[i] == '='){
            eq = 1;
            break;
        }
        else if(line[i] == ';'){
            eq = 0;
            break;
        }
        else if(line[i] == '@'){
            eq = 2;
            break;
        }
    }

    // if eq = 1 then the line is a computation
    // if eq = 0 then it's a jump statement
    // if eq = 2 then it's a @value type instruction
    
    return code;
}


int main(int argc, char* argv[argc+1]){
   // FILE* progfile = fopen("max/MaxL.asm","r");
    char buffer[buffer_max] = {0};
    //if (progfile){
    //    while(fgets(buffer, buffer_max, progfile)){
    //        if(buffer[0] != '/' && !isspace(buffer[0]))  fputs(buffer, stdout);
    //    }
    //    fclose(progfile);
    //}
    char code[bits];
    char* processed = process_line(code, 3, "==12");
    printf("%s",processed);
    return 0;
}
 
