#include "funcoes.c"

int main(){

    FILE *arq = fopen("entrada.asm", "r");

    if (arq == NULL) {
        printf("Arquivo 'entrada.asm' nao encontrado\n");
        return 1;
    }

    char operacao[10], termo1[10], termo2[10], termo3[10];

    while(fscanf(arq, "%s %[^,], %[^,], %s", operacao, termo1, termo2, termo3) != EOF){

        if (strcmp(operacao, "sub") == 0){
            ImprimirBinario(funct7("sub"), 7);
            ImprimirBinario(NumeroRegistrador(termo3), 5);
            ImprimirBinario(NumeroRegistrador(termo2), 5);
            ImprimirBinario(funct3("sub"), 3);
            ImprimirBinario(NumeroRegistrador(termo1), 5);
            ImprimirBinario(opcode("sub"), 7);
            printf("\n");
        }
        if (strcmp(operacao, "and") == 0){
            ImprimirBinario(funct7("and"), 7);
            ImprimirBinario(NumeroRegistrador(termo3), 5);
            ImprimirBinario(NumeroRegistrador(termo2), 5);
            ImprimirBinario(funct3("and"), 3);
            ImprimirBinario(NumeroRegistrador(termo1), 5);
            ImprimirBinario(opcode("and"), 7);
            printf("\n");
        }
        if (strcmp(operacao, "srl") == 0){
            ImprimirBinario(funct7("srl"), 7);
            ImprimirBinario(NumeroRegistrador(termo3), 5);
            ImprimirBinario(NumeroRegistrador(termo2), 5);
            ImprimirBinario(funct3("srl"), 3);
            ImprimirBinario(NumeroRegistrador(termo1), 5);
            ImprimirBinario(opcode("srl"), 7);
            printf("\n");
        }
        if (strcmp(operacao, "ori") == 0){
            ImprimirBinario(Imediato(termo3), 12);
            ImprimirBinario(NumeroRegistrador(termo2), 5);
            ImprimirBinario(funct3("ori"), 3);
            ImprimirBinario(NumeroRegistrador(termo1), 5);
            ImprimirBinario(opcode("ori"), 7);
            printf("\n");
        }
        if (strcmp(operacao, "lb") == 0){

            int imm = imediatoMemoria(termo2);
            int rs1 = RegMemoria(termo2);
            ImprimirBinario(imm, 12);
            ImprimirBinario(termo1, 5);
            ImprimirBinario(get_funct3("lb"), 3);
            ImprimirBinario(NumeroRegistrador(termo1), 5);
            ImprimirBinario(get_opcode("lb"), 7);
            printf("\n");
        }
        if (strcmp(operacao, "sb") == 0){
            int rs2 = NumeroRegistrador(termo1);
            int imm = get_imediato_memoria(termo2);
            int rs1 = get_reg_memoria(termo2);

            ImprimirBinario((imm >> 5) & 0x7F, 7);
            ImprimirBinario(rs2, 5);
            ImprimirBinario(rs1, 5);
            ImprimirBinario(funct3("sb"), 3);
            ImprimirBinario(imm & 0x1F, 5);
            ImprimirBinario(opcode("sb"), 7);
            printf("\n");
        }
        if (strcmp(operacao, "beq") == 0){
            int rs1 = NumeroRegistrador(termo1);
            int rs2 = NumeroRegistrador(termo2);
            int imm = Imediato(termo3); // O valor do salto/label

            ImprimirBinario((imm >> 12) & 0x01, 1);
            ImprimirBinario((imm >> 5) & 0x3F, 6);
            ImprimirBinario(rs2, 5);
            ImprimirBinario(rs1, 5);
            ImprimirBinario(funct3("beq"), 3);
            ImprimirBinario((imm >> 1) & 0x0F, 4);
            ImprimirBinario((imm >> 11) & 0x01, 1);
            ImprimirBinario(opcode("beq"), 7);
            printf("\n");
        }
    }
}