#include <stdio.h>
#include <stdlib.h>

char *binary_seq[99999];
int it = 0;
char *inverse;

typedef union {
    int character;
    struct bitFields {
        _Bool bit0 : 1;
        _Bool bit1 : 1;
        _Bool bit2 : 1;
        _Bool bit3 : 1;
        _Bool bit4 : 1;
        _Bool bit5 : 1;
        _Bool bit6 : 1;
        _Bool bit7 : 1;
    } bits;
} character;

void processChar(char ch) {
    // setup the char union
    character cha;
    // convert it to ASCII integer
    int e = ch;
    // set into the union
    cha.character = e;
    // print the character and its ASCII equivalent
    printf("%c = %d = ", ch, cha.character);
    // print the value in bits
    printf ("%d ", cha.bits.bit7);
    printf ("%d ", cha.bits.bit6);
    printf ("%d ", cha.bits.bit5);
    printf ("%d ", cha.bits.bit4);
    printf ("%d ", cha.bits.bit3);
    printf ("%d ", cha.bits.bit2);
    printf ("%d ", cha.bits.bit1);
    printf ("%d ", cha.bits.bit0);
    printf ("\n") ;

    binary_seq[it++] = cha.bits.bit7 ? "1" : "0";
    binary_seq[it++] = cha.bits.bit6 ? "1" : "0";
    binary_seq[it++] = cha.bits.bit5 ? "1" : "0";
    binary_seq[it++] = cha.bits.bit4 ? "1" : "0";
    binary_seq[it++] = cha.bits.bit3 ? "1" : "0";
    binary_seq[it++] = cha.bits.bit2 ? "1" : "0";
    binary_seq[it++] = cha.bits.bit1 ? "1" : "0";
    binary_seq[it++] = cha.bits.bit0 ? "1" : "0";
}

char *readFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    char *string;
    size_t n = 0;
    int c;

    if (file == NULL)
        return NULL; //could not open file

    string = malloc(1000);
    while ((c = fgetc(file)) != EOF) {
        string[n++] = (char) c;
        processChar(c);
    }

    // terminate with the null character
    string[n] = '\0';

    fclose(file);

    return string;
}

void putOnFile(char *fileName){
    FILE *file = fopen(fileName, "w");
    for (int i = 0; i < it; i++) {
        fputs(binary_seq[i], file );
    }
    fclose(file);
}

void invertArray(char *data) {
    int n = 11;
    for (int i = 1; i < 12; i++) {
        inverse[i] = data[n--];
    }
}

int main () {
    /*
     * 1) Lê o arquivo
     * 2) guarda transforma os caracteres em bits usando unions
     * 3) preenche o vetor binary_seq com a sequência de bits correspondente
     */
    char *string = readFile("teste.txt");

    // Mostra a string lida
    if (string != NULL)
        printf("String lida: %s\n", string);

    // Mostra o vetor binary_seq
    printf("\nVetor binary_seq: \n");
    for (int i = 0; i < it; i++) {
        printf("%s", binary_seq[i]);
    }

    // Coloca o binary_seq num arquivo
    putOnFile("string.txt");

    // Lê o arquivo string.txt e guarda no vetor data
    // todo: verificar o malloc de data, porque deve ser ali que tá dando problema
    // todo: afinal, o malloc é 12 mas o vetor data é muito maior que isso
    FILE * fptr = fopen("string.txt", "r");
    if (fptr == NULL) {
        printf("\n Erro ao abrir arquivo \n");
        return -1;
    }
    char *data;
    int c;
    size_t n = 0;
    data = malloc(12);
    printf("\n\nVetor data[]:\n");
    // Mostra/constroi o vetor data
    while ((c = fgetc(fptr)) != EOF) {
        data[n++] = (char) c;
        printf("%c", c);
    }
    printf("\n\n");

    // Aqui imprime a sequência de 11 em 11 bits, mas se sobrar alguma coisa
    // ele não imprime o que sobrou
    int j;
    int i;
    int a = 0;
    char *data_2;
    for (j = 1; j <= it/11; j++) {
        // Imprime 11 Bits
        // printf("\n11 bits: ");
        data_2 = malloc(12);
        a = 1;
        for (i = (j-1)*11; i < j*11; i++) {
            printf("%c",(int) data[i]);
            data_2[a++] = data[i];
        }
        printf("\n");
        // Imprime o resultado da transferência para data_2
//        printf("\nTransferência para data_2: ");
//        for (a = 1; a < 12; a++) {
//            printf("%c", (int)data_2[a]);
//        }

        // Inverte os 11 bits da iteração
        inverse = malloc(11);
        invertArray(data_2);
        //printf("\n11 bits invertidos: ");
        for (a = 1; a < 12; a++) {
            printf("%c", (int)inverse[a]);
        }
        // todo: aqui chama o encode hamming

        printf("\n\n");
        free(data_2);
        free(inverse);
    }
    printf("\nValor de i = %d", i);
    /*
     *  Tratar rebarba;
     *  1) completa com zeros até fechar 11 bits
     *  2) inverte eles
     *  3) envia pra codificação como se nada tivesse acontecido
     */
    printf("\nRebarba:\n");
    for (i = i; i < n; i++) {
        printf("%c", (int) data[i]);
    }

    //teoricamente, aqui eu envio o inverse[] para codificador hamming
    // todo: buffer que vai lendo de 11 em 11, invertendo, e mandando pra codificação
    // todo: uma biblioteca para armazenas as funções e os tipos, .h e .c
    // todo: arrumar o repositório do Git e commitar no remote

    return 0 ;
}