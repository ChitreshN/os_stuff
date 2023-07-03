#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

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

struct jump const jmp_adr = {
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

#define buffer_max 128


int main(int argc, char* argv[argc+1]){
    FILE* logfile = fopen("mylog.txt", "a");
    FILE* progfile = fopen("max/MaxL.asm","r");
    char buffer[buffer_max] = {0};
    if (progfile){
        while(fgets(buffer, buffer_max, progfile)){
            if(buffer[0] != '/' && !isspace(buffer[0]))  fputs(buffer, stdout);
        }
        fclose(progfile);
    }
    return 0;
}
 
