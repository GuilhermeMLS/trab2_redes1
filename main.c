/*
 * Trabalho 2 de Rede de Computadores I - UFPR - Ciência da Computação
 *
 * Objetivo: receber um texto ASCII como entrada e efetuar a condificação e
 *  codificação hamming.
 *
 * Alunos:
 *  Guilherme M. Lopes - GRR20163043
 *  Leonardo Stefan - GRR
 *
 * Bugs conhecidos:
 *  Por algum motivo, provavelmente a alocação de memória do vetor data, algumas vezes o programa
 *  entrega valores aleatórios que não correspondem com a sequência de bits gerada para
 *  codificação a partir das strings recebidas. Basta rodar novamente, e geralmente na segunda ou
 *  terceira tentativa, os valores vêm corretos.
 *
 * Debugger:
 *  Para mensagens de log mais precisas, compilar com -DDEBUG.
 */

#include <stdio.h>
#include <stdlib.h>
#include "hamming.h"

char *binary_seq[99999];
int it = 0;
char *inverse;
char *encoded_array;

// Constantes para mensagens de erro e debug coloridas
#define RED "\x1B[31m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define RESET "\x1B[0m"

// Mensagens de erro ou debugger
// exemplo de uso: print_message(MAG, "function()", "executando function()");
// para que as mensagens apareçam, é necessário adicionar -DDEBUG ao comando
// de compilação.
void print_message(char *color, char *func, char *message)
{
#ifdef DEBUG
    printf("%s%s: %s%s\n", color, func, RESET, message);
#endif
}

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

    string = calloc(1000, sizeof(char));
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
    // Set Hamming (11,15)
    setHamming(11, 15);

    printf("\nLetra = ASCII code = binary code\n\n");
    /*
     * 1) Lê o arquivo
     * 2) guarda transforma os caracteres em bits usando unions
     * 3) preenche o vetor binary_seq com a sequência de bits correspondente
     */
    char *string = readFile("teste.txt");

    // Mostra a string lida
    if (string != NULL)
        printf("\nString lida: %s\n", string);

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
    data = calloc(data_size+1, sizeof(char));
    printf("\n\nVetor data[]:\n");
    // Mostra/constroi o vetor data
    while ((c = fgetc(fptr)) != EOF) {
        data[n++] = (char) c;
        printf("%c", c);
    }
    printf("\n\n");

    printf("Sequência de 11 em 11 bits, com inversão abaixo:\n\n");
    // Aqui imprime a sequência de 11 em 11 bits, mas se sobrar alguma coisa
    // ele não imprime o que sobrou
    int j;
    int i;
    int a = 0;
    char *data_2;

    FILE *out_file = fopen("out_file.txt", "w");

    for (j = 1; j <= it/11; j++) {
        // Imprime 11 Bits
        // printf("\n11 bits: ");
        data_2 = calloc(data_size+1, sizeof(char));
        a = 1;
        for (i = (j-1)*11; i < j*11; i++) {
            printf("%c",(int) data[i]);
            data_2[a++] = data[i];
        }
        printf("\n");
        // Imprime o resultado da transferência para data_2
#ifdef DEBUG
        print_message(MAG, "main()", "Transferência para data_2: ");
        for (a = 1; a < 12; a++) {
            printf("%c", (int)data_2[a]);
        }
        printf("\n");
#endif

        // Inverte os 11 bits da iteração
        inverse = calloc(data_size, sizeof(char));
        invertArray(data_2);
        //printf("\n11 bits invertidos: ");
        for (a = 1; a < 12; a++) {
            printf("%c", (int)inverse[a]);
        }

        // Manda para codificação
        encoded_array = calloc(size, sizeof(char));
        encodeHamming(inverse, encoded_array);

        printf("\nEncoded array: ");
        for (a = size; a >= 0; a--) {
            printf("%c", (int)encoded_array[a]);
            fprintf(out_file, "%c", encoded_array[a]);
        }

        printf("\n\n");

        free(encoded_array);
        free(data_2);
        free(inverse);
        fprintf(out_file, " ");
    }


#ifdef DEBUG
    printf("Valor de i = %d", i);
#endif
    /*
     *  Tratar rebarba;
     *  1) completa com zeros até fechar 11 bits
     *  2) inverte eles
     *  3) envia pra codificação como se nada tivesse acontecido
     */
#ifdef DEBUG
    printf("\n\nRebarba:\n");
#endif
    // Conta quantos bits falta para fechar 11:
    int remaining = 11 - (n - i);
    // Completa com zeros
    for (int k = n; k < n+remaining; k++) {
        data[k] = (char)'0';
    }
#ifdef DEBUG
    printf("\nremaining: %d\n", remaining);
#endif
    // Printa a rebarba (data) na tela e transfere para rebarba
    char *rebarba = calloc(data_size+1, sizeof(char));
    int g = 1;
    for (i = i; i < n+remaining; i++) {
        printf("%c", (int) data[i]);
        rebarba[g++] = data[i];
    }
    // inverte a rebarba
    inverse = calloc(data_size, sizeof(char));
    invertArray(rebarba);
    // printa a rebarba invertida
    printf("\n");
    for (g = 1; g < 12; g++) {
        printf("%c", (int)inverse[g]);
    }

    // codifica a rebarba
    encoded_array = calloc(size, sizeof(char));
    encodeHamming(inverse, encoded_array);

    printf("\nEncoded array: ");
    for (a = size; a >= 0; a--) {
        printf("%c", (int)encoded_array[a]);
        fprintf(out_file, "%c", encoded_array[a]);
    }

    printf("\n\n");

    free(encoded_array);
    free(inverse);
    fprintf(out_file, " ");

    fclose(out_file);

    printf("\nDecodificando..\n");

    FILE *file_decode = fopen("out_file.txt", "r");

    char *string_decode;
    size_t m = 0;
    int d;

    if (file_decode == NULL)
        return 0; //could not open file

    string_decode = calloc(1000, sizeof(char));
    while ((d = fgetc(file_decode)) != EOF) {
        string_decode[m++] = (char)d == '0' ? 0 : 1;
    }

    // terminate with the null character
    string_decode[m] = '\0';

    char *string_out = calloc(m, sizeof(char));
    for (int s = 1, f = 1; s < m-size; s+=size+1, f+=data_size+1) {
        decodeHamming(string_decode+s, string_out+f);
        string_out[f] = ' ';
    }

    printf("Resultado: \n");
    for (int s = 0; s < (m/15)*11; s++) {
        if (string_out[s] != ' ') {
            printf("%d", string_out[s]);
        } else {
            printf(" ");
        }
    }
    printf("\n");
    free(string_out);
    free(string_decode);

    fclose(file_decode);

    return 0 ;
}