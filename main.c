#include "funcoes.c"
int main(){

    if (strcmp(operacao, "sub") == 0){
        printf("%c", funct7(sub));
        printf("%c", NumeroRegistrador(3termo));
        printf("%c", NumeroRegistrador(2termo));
        printf("%c", funct3(sub));
        printf("%c", NumeroRegistrador(1termo));
        printf("%c", opcode(sub));
    }
    if (strcmp(operacao, "and") == 0){
        printf("%c", funct7(and));
        printf("%c", NumeroRegistrador(3termo));
        printf("%c", NumeroRegistrador(2termo));
        printf("%c", funct3(and));
        printf("%c", NumeroRegistrador(1termo));
        printf("%c", opcode(and));
    }
    if (strcmp(operacao, "srl") == 0){
        printf("%c", funct7(srl));
        printf("%c", NumeroRegistrador(3termo));
        printf("%c", NumeroRegistrador(2termo));
        printf("%c", funct3(srl));
        printf("%c", NumeroRegistrador(1termo));
        printf("%c", opcode(srl));
    }
    if (strcmp(operacao, "ori") == 0){
        printf("%c", imm());
        printf("%c", NumeroRegistrador(2termo));
        printf("%c", funct3(ori));
        printf("%c", NumeroRegistrador(1termo));
        printf("%c", opcode(ori));
    }
    if (strcmp(operacao, "lb") == 0){
            printf("%c", imm());
            printf("%c", NumeroRegistrador(2termo));
            printf("%c", funct3(lb));
            printf("%c", NumeroRegistrador(1termo));
            printf("%c", opcode(lb));
    if (strcmp(operacao, "sb") == 0){
        printf("%c", imm());
        printf("%c", NumeroRegistrador(3termo));
        printf("%c", NumeroRegistrador(2termo));
        printf("%c", funct3(add));
        printf("%c", imm());
        printf("%c", opcode(add));
    }
    if (strcmp(operacao, "beq") == 0){
        printf("%c", imm());
        printf("%c", imm());
        printf("%c", NumeroRegistrador(3termo));
    }
}