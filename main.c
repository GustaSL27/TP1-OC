#include "funcoes.c"
int main(){

    if (strcmp(operacao, "sub") == 0){
        imprimir_binario(funct7("sub"), 7);
        imprimir_binario(NumeroRegistrador(termo3), 5);
        imprimir_binario(NumeroRegistrador(termo2), 5);
        imprimir_binario(funct3("sub"), 3);
        imprimir_binario(NumeroRegistrador(termo1), 5);
        imprimir_binario(opcode("sub"), 7);
    }
    if (strcmp(operacao, "and") == 0){
        imprimir_binario(funct7("and"), 7);
        imprimir_binario(NumeroRegistrador(termo3), 5);
        imprimir_binario(NumeroRegistrador(termo2), 5);
        imprimir_binario(funct3("and"), 3);
        imprimir_binario(NumeroRegistrador(termo1), 5);
        imprimir_binario(opcode("and"), 7);
    }
    if (strcmp(operacao, "srl") == 0){
        imprimir_binario(funct7("srl"), 7);
        imprimir_binario(NumeroRegistrador(termo3), 5);
        imprimir_binario(NumeroRegistrador(termo2), 5);
        imprimir_binario(funct3("srl"), 3);
        imprimir_binario(NumeroRegistrador(termo1), 5);
        imprimir_binario(opcode("srl"), 7);
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
    }
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