#include "funcoes.c"
#define MAX_CAM 100

int main(){

    int opcao;
    char caminho_entrada[MAX_CAM];
    char caminho_saida[MAX_CAM];

    // 1. Configuração de arquivos
    printf("Digite o caminho do arquivo de entrada: ");
    scanf("%255[^\n]", caminho_entrada);

    FILE *arq = fopen(caminho_entrada, "r");
    if (arq == NULL) {
        printf("Erro: Arquivo '%s' nao encontrado.\n", caminho_entrada);
        return 1;
    }

    printf("Escolha o destino da saida: \nTerminal (1)\nArquivo (2)\nOpcao: ");
    scanf("%d", &opcao);

    FILE *arq_saida = stdout; // Padrão é o terminal

    fflush(stdin);
    
    if (opcao == 2) {
        printf("Digite o caminho do arquivo de saida: ");
        scanf("%255[^\n]", caminho_saida);
        arq_saida = fopen(caminho_saida, "w");
        if (arq_saida == NULL) {
            printf("Erro ao criar arquivo. Usando terminal por padrao.\n");
            arq_saida = stdout;
        }
    }

    // 2. Loop de tradução
    char operacao[10], termo1[10], termo2[10], termo3[10];
    char linha[100];

    while(fgets(linha, sizeof(linha), arq)){

        int n = sscanf(linha, "%s %[^,], %[^,], %s", operacao, termo1, termo2, termo3);
        
        if (n < 4) {
            sscanf(linha, "%s %[^,], %s", operacao, termo1, termo2);
        }

        if (strcmp(operacao, "sub") == 0){
            ImprimirBinario(arq_saida, funct7("sub"), 7);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo3), 5);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo2), 5);
            ImprimirBinario(arq_saida, funct3("sub"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("sub"), 7);
            printf("\n");
        }
        if (strcmp(operacao, "and") == 0){
            ImprimirBinario(arq_saida, funct7("and"), 7);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo3), 5);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo2), 5);
            ImprimirBinario(arq_saida, funct3("and"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("and"), 7);
            printf("\n");
        }
        if (strcmp(operacao, "srl") == 0){
            ImprimirBinario(arq_saida, funct7("srl"), 7);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo3), 5);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo2), 5);
            ImprimirBinario(arq_saida, funct3("srl"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("srl"), 7);
            printf("\n");
        }
        if (strcmp(operacao, "ori") == 0){
            ImprimirBinario(arq_saida, Imediato(termo3), 12);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo2), 5);
            ImprimirBinario(arq_saida, funct3("ori"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("ori"), 7);
            printf("\n");
        }
        if (strcmp(operacao, "lb") == 0){
            int imm = ImediatoMemoria(termo2);
            int rs1 = RegMemoria(termo2);

            ImprimirBinario(arq_saida, imm, 12);
            ImprimirBinario(arq_saida, rs1, 5);
            ImprimirBinario(arq_saida, funct3("lb"), 3);
            ImprimirBinario(arq_saida, NumeroRegistrador(termo1), 5);
            ImprimirBinario(arq_saida, opcode("lb"), 7);
            printf("\n");
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
            printf("\n");
        }
        if (strcmp(operacao, "beq") == 0){
            int rs1 = NumeroRegistrador(termo1);
            int rs2 = NumeroRegistrador(termo2);
            int imm = Imediato(termo3); // O valor do salto/label

            ImprimirBinario(arq_saida, (imm >> 12) & 0x01, 1);
            ImprimirBinario(arq_saida, (imm >> 5) & 0x3F, 6);
            ImprimirBinario(arq_saida, rs2, 5);
            ImprimirBinario(arq_saida, rs1, 5);
            ImprimirBinario(arq_saida, funct3("beq"), 3);
            ImprimirBinario(arq_saida, (imm >> 1) & 0x0F, 4);
            ImprimirBinario(arq_saida, (imm >> 11) & 0x01, 1);
            ImprimirBinario(arq_saida, opcode("beq"), 7);
            printf("\n");
        }
    }
}