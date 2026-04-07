#include "stdio.h"
#include "string.h"

int funct7(char operacao[]);
int funct3(char operacao[]);
int opcode(char operacao[]);
int NumeroRegistrador(char termo[]);
void ImprimirBinario(FILE *arq, int valor, int bits);
int Imediato(char termo[]);
int ImediatoMemoria(char termo[]);
int RegMemoria(char termo[]);