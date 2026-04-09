#include "funcoes.h"
#define MAX_CAM 100

int main(){

    int opcao_saida, opcao_entrada;
    char caminho_entrada[MAX_CAM];
    char caminho_saida[MAX_CAM];
    char operacao[10], termo1[10], termo2[10], termo3[10];
    char linha[100];
    FILE *arq_entrada = stdin; // a entrada padrão é o terminal
    FILE *arq_saida = stdout; // a saída padrão é o terminal

    printf("Escolha a SAIDA: \nTerminal (1)\nArquivo (2)\nOpcao: ");
    scanf("%d", &opcao_saida);

    if (opcao_saida == 2) {
        printf("Digite o caminho do arquivo de saida: ");
        scanf(" %255[^\n]", caminho_saida);
        arq_saida = fopen(caminho_saida, "w");
    }

    printf("\nEscolha a ENTRADA: \nTerminal (1)\nArquivo (2)\nOpcao: ");
    scanf("%d", &opcao_entrada);

    if(opcao_entrada == 2){
        printf("Digite o caminho do arquivo de entrada: ");
        scanf(" %255[^\n]", caminho_entrada);
        arq_entrada = fopen(caminho_entrada, "r");
    }

    else{
        printf("Digite as instrucoes (ou 'sair' para finalizar):\n");
    }

    while(fgets(linha, sizeof(linha), arq_entrada)){

        if (strncmp(linha, "sair", 4) == 0) break; // compara as primeiras 4 letras da linha e de "sair", se igual da break

        int n = sscanf(linha, "%s %[^,], %[^,], %s", operacao, termo1, termo2, termo3); // n é a quantidade de itens armazenados
        if (n < 1){
            continue; // pula linha vazia
        }
        
        if (n < 4) {
            sscanf(linha, "%s %[^,], %s", operacao, termo1, termo2); // lw, lb, sw, sb
        }

        if (strcmp(operacao, "sub") == 0){
            ImprimirBinario(arq_saida, funct7("sub"), 7);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo3), 5);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo2), 5);
            ImprimirBinario(arq_saida, funct3("sub"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("sub"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "and") == 0){
            ImprimirBinario(arq_saida, funct7("and"), 7);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo3), 5);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo2), 5);
            ImprimirBinario(arq_saida, funct3("and"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("and"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "add") == 0){
            ImprimirBinario(arq_saida, funct7("add"), 7);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo3), 5);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo2), 5);
            ImprimirBinario(arq_saida, funct3("add"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("add"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "or") == 0){
            ImprimirBinario(arq_saida, funct7("or"), 7);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo3), 5);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo2), 5);
            ImprimirBinario(arq_saida, funct3("or"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("or"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "xor") == 0){
            ImprimirBinario(arq_saida, funct7("xor"), 7);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo3), 5);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo2), 5);
            ImprimirBinario(arq_saida, funct3("xor"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("xor"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "sll") == 0){
            ImprimirBinario(arq_saida, funct7("sll"), 7);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo3), 5);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo2), 5);
            ImprimirBinario(arq_saida, funct3("sll"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("sll"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "srl") == 0){
            ImprimirBinario(arq_saida, funct7("srl"), 7);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo3), 5);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo2), 5);
            ImprimirBinario(arq_saida, funct3("srl"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("srl"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "ori") == 0){
            ImprimirBinario(arq_saida, Imediato(termo3), 12);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo2), 5);
            ImprimirBinario(arq_saida, funct3("ori"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("ori"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "addi") == 0){
            ImprimirBinario(arq_saida, Imediato(termo3), 12);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo2), 5);
            ImprimirBinario(arq_saida, funct3("addi"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("addi"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "andi") == 0){
            ImprimirBinario(arq_saida, Imediato(termo3), 12);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo2), 5);
            ImprimirBinario(arq_saida, funct3("andi"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("andi"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "lb") == 0){
            int imm = ImediatoMemoria(termo2);
            int rs1 = RegMemoria(termo2);

            ImprimirBinario(arq_saida, imm, 12);
            ImprimirBinario(arq_saida, rs1, 5);
            ImprimirBinario(arq_saida, funct3("lb"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("lb"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "lh") == 0){
            int imm = ImediatoMemoria(termo2);
            int rs1 = RegMemoria(termo2);

            ImprimirBinario(arq_saida, imm, 12);
            ImprimirBinario(arq_saida, rs1, 5);
            ImprimirBinario(arq_saida, funct3("lh"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("lh"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "lw") == 0){
            int imm = ImediatoMemoria(termo2);
            int rs1 = RegMemoria(termo2);

            ImprimirBinario(arq_saida, imm, 12);
            ImprimirBinario(arq_saida, rs1, 5);
            ImprimirBinario(arq_saida, funct3("lw"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("lw"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "sb") == 0){
            int rs2 = NumeroRegistrador(termo1);
            int imm = ImediatoMemoria(termo2);
            int rs1 = RegMemoria(termo2);

            ImprimirBinario(arq_saida, (imm >> 5) & 0x7F, 7);
            ImprimirBinario(arq_saida, rs2, 5);
            ImprimirBinario(arq_saida, rs1, 5);
            ImprimirBinario(arq_saida, funct3("sb"), 3);
            ImprimirBinario(arq_saida, imm & 0x1F, 5);
            ImprimirBinario(arq_saida, opcode("sb"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "sh") == 0){
            int rs2 = NumeroRegistrador(termo1);
            int imm = ImediatoMemoria(termo2);
            int rs1 = RegMemoria(termo2);

            ImprimirBinario(arq_saida, (imm >> 5) & 0x7F, 7);
            ImprimirBinario(arq_saida, rs2, 5);
            ImprimirBinario(arq_saida, rs1, 5);
            ImprimirBinario(arq_saida, funct3("sh"), 3);
            ImprimirBinario(arq_saida, imm & 0x1F, 5);
            ImprimirBinario(arq_saida, opcode("sh"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "sw") == 0){
            int rs2 = NumeroRegistrador(termo1);
            int imm = ImediatoMemoria(termo2);
            int rs1 = RegMemoria(termo2);

            ImprimirBinario(arq_saida, (imm >> 5) & 0x7F, 7);
            ImprimirBinario(arq_saida, rs2, 5);
            ImprimirBinario(arq_saida, rs1, 5);
            ImprimirBinario(arq_saida, funct3("sw"), 3);
            ImprimirBinario(arq_saida, imm & 0x1F, 5);
            ImprimirBinario(arq_saida, opcode("sw"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "beq") == 0){
            int rs1 = NumeroRegistrador(termo1);
            int rs2 = NumeroRegistrador(termo2);
            int imm = Imediato(termo3);

            ImprimirBinario(arq_saida, (imm >> 12) & 0x01, 1);
            ImprimirBinario(arq_saida, (imm >> 5) & 0x3F, 6);
            ImprimirBinario(arq_saida, rs2, 5);
            ImprimirBinario(arq_saida, rs1, 5);
            ImprimirBinario(arq_saida, funct3("beq"), 3);
            ImprimirBinario(arq_saida, (imm >> 1) & 0x0F, 4);
            ImprimirBinario(arq_saida, (imm >> 11) & 0x01, 1);
            ImprimirBinario(arq_saida, opcode("beq"), 7);
            fprintf(arq_saida, "\n");
        }
        if (strcmp(operacao, "bne") == 0){
            int rs1 = NumeroRegistrador(termo1);
            int rs2 = NumeroRegistrador(termo2);
            int imm = Imediato(termo3);

            ImprimirBinario(arq_saida, (imm >> 12) & 0x01, 1);
            ImprimirBinario(arq_saida, (imm >> 5) & 0x3F, 6);
            ImprimirBinario(arq_saida, rs2, 5);
            ImprimirBinario(arq_saida, rs1, 5);
            ImprimirBinario(arq_saida, funct3("bne"), 3);
            ImprimirBinario(arq_saida, (imm >> 1) & 0x0F, 4);
            ImprimirBinario(arq_saida, (imm >> 11) & 0x01, 1);
            ImprimirBinario(arq_saida, opcode("bne"), 7);
            fprintf(arq_saida, "\n");
        }
    }
}
