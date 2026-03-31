#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "funcoes.h"

int funct7(char operacao[]){
    if (strcmp(operacao, "sub") == 0){
        return 0x20;
    }
    
    if (strcmp(operacao, "and") == 0){
        return 0x00;
    }
    
    if (strcmp(operacao, "srl") == 0){
        return 0x00;
    }
    return -1;
}

int opcode(char operacao[]) {
    if (strcmp(operacao, "sub") == 0 || strcmp(operacao, "and") == 0 || strcmp(operacao, "srl") == 0){
        return 0x33; // 0110011
    }
    if (strcmp(operacao, "ori") == 0){
        return 0x13; // 0010011
    }
    if (strcmp(operacao, "lb") == 0){
        return 0x03; // 0000011
    }
    if (strcmp(operacao, "sb") == 0){
        return 0x23; // 0100011
    }
    if (strcmp(operacao, "beq") == 0){
        return 0x63; // 1100011
    }
    return 0;
}

int funct3(char operacao[]) {
    if (strcmp(operacao, "sub") == 0){
        return 0x0;
    }
    if (strcmp(operacao, "and") == 0){
        return 0x7;
    }
    if (strcmp(operacao, "srl") == 0){
        return 0x5;
    } 
    if (strcmp(operacao, "ori") == 0){
        return 0x6;
    } 
    if (strcmp(operacao, "lb") == 0){
        return 0x0;
    }  
    if (strcmp(operacao, "sb") == 0){
        return 0x0;
    }  
    if (strcmp(operacao, "beq") == 0){
        return 0x0;
    } 
    return 0;
}

int NumeroRegistrador(char termo[]) {
    if (termo[0] == 'x') {
        return atoi(&termo[1]); //converte string pra inteiro
    }
    return 0; // x0 por padrão
}

void imprimir_binario(int valor, int bits) {
    for (int i = bits - 1; i >= 0; i--){
        int bit = (valor >> i) & 1;
        printf("%d", bit);
    }
}