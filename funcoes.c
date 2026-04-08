#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "funcoes.h"

int funct7(char operacao[]){
    if (strcmp(operacao, "sub") == 0){
        return 0x20; // 0100000
    }
    
    if ((strcmp(operacao, "and") == 0) ||
        (strcmp(operacao, "srl") == 0) ||
        (strcmp(operacao, "add") == 0) ||
        (strcmp(operacao, "or") == 0) ||
        (strcmp(operacao, "xor") == 0) ||
        (strcmp(operacao, "sll") == 0)){
        return 0x00; // 0000000
    }

    return -1;
}

int funct3(char operacao[]){
    if ((strcmp(operacao, "sub") == 0) ||
        (strcmp(operacao, "lb") == 0) ||
        (strcmp(operacao, "sb") == 0) ||
        (strcmp(operacao, "beq") == 0) ||
        (strcmp(operacao, "add") == 0) ||
        (strcmp(operacao, "addi") == 0)){
        return 0x0; // 000
    }

    if ((strcmp(operacao, "and") == 0) ||
        (strcmp(operacao, "andi") == 0)){
        return 0x7; // 111
    }

    if (strcmp(operacao, "srl") == 0){
        return 0x5; // 101
    }

    if ((strcmp(operacao, "ori") == 0) ||
        (strcmp(operacao, "or") == 0)){
        return 0x6; // 110
    }  

    if ((strcmp(operacao, "lh") == 0) ||
        (strcmp(operacao, "sh") == 0) ||
        (strcmp(operacao, "bne") == 0) ||
        (strcmp(operacao, "sll") == 0)){
        return 0x1; // 001
    }

    if ((strcmp(operacao, "lw") == 0) ||
        (strcmp(operacao, "sw") == 0)){
        return 0x2; // 010
    }

    if (strcmp(operacao, "xor") == 0){
        return 0x4; // 100
    }

    return 0;
}

int opcode(char operacao[]){
    if ((strcmp(operacao, "sub") == 0) || 
        (strcmp(operacao, "and") == 0) ||
        (strcmp(operacao, "srl") == 0) ||
        (strcmp(operacao, "add") == 0) ||
        (strcmp(operacao, "or") == 0) ||
        (strcmp(operacao, "xor") == 0) ||
        (strcmp(operacao, "sll") == 0)){
        return 0x33; // 0110011
    }
    if ((strcmp(operacao, "ori") == 0) ||
        (strcmp(operacao, "addi") == 0) ||
        (strcmp(operacao, "andi") == 0)){
        return 0x13; // 0010011
    }
    if ((strcmp(operacao, "lb") == 0) ||
        (strcmp(operacao, "lh") == 0) ||
        (strcmp(operacao, "lw") == 0)){
        return 0x03; // 0000011
    }
    if ((strcmp(operacao, "sb") == 0) ||
        (strcmp(operacao, "sh") == 0) ||
        (strcmp(operacao, "sw") == 0)){
        return 0x23; // 0100011
    }
    if ((strcmp(operacao, "beq") == 0) ||
        (strcmp(operacao, "bne") == 0)){
        return 0x63; // 1100011
    }
    return 0;
}

int NumeroRegistrador(char termo[]){
    if (termo[0] == 'x') {
        return atoi(&termo[1]); //converte string pra inteiro
    }
    return 0;
}

void ImprimirBinario(FILE *arq, int valor, int bits){
    for (int i = bits - 1; i >= 0; i--) {
        int bit = (valor >> i) & 1;
        fprintf(arq, "%d", bit); 
    }
}

int Imediato(char termo[]){
    return atoi(termo);
}

int ImediatoMemoria(char termo[]){
    return atoi(termo);
}

int RegMemoria(char termo[]){
    char *ptr = strchr(termo, 'x');  // acha o "x" e cria um ponteiro apontando para ele
    if (ptr != NULL) {
        return atoi(ptr + 1);
    }
    return 0;
}