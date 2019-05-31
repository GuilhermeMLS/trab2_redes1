#include <stdio.h>
#include <stdlib.h>

char *binary_seq[99999];
int it = 0;

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

int main () {
    char *string = readFile("teste.txt");

    if (string != NULL)
        printf("String lida: %s\n", string);

    printf("\nAqui vai o binary_seq:\n");
    for (int i = 0; i < it; i++) {
        printf("%s", binary_seq[i]);
    }

    //coloca o binary_seq num arquivo:
    putOnFile("string.txt");

    //pega de 11 em 11
    FILE * fptr = fopen("string.txt", "r");
    if (fptr != NULL) {

        char *data;
        int c;
        size_t n = 0;
        data = malloc(12);

        printf("\n\nVetor data[]:\n");
        while ((c = fgetc(fptr)) != EOF) {
            data[n++] = (char) c;
            printf("%c", c);
        }

        printf("\n");

        printf("\nAqui vai os 11 primeiros bits: ");
        for (int i = 0; i < 11; i++) {
            printf("%c",(int) data[i]);
        }
    } else {
        printf("\nerro\n");
    }




    return 0 ;
}