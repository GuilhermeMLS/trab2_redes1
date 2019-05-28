#include <stdio.h>
#include <stdlib.h>



#define SIZE (15)
#define DATA_SIZE 11
unsigned int size, data_size;
int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		size = atoi(argv[1]);
		data_size = atoi(argv[2]);
	}
	else
	{
		size = SIZE;
		data_size = DATA_SIZE;
	}

	unsigned int d;
	unsigned int *aux_array = calloc(size + 1, sizeof(unsigned int)); //ignorar bit 0
	unsigned int *data = calloc(size + 1, sizeof(unsigned int));

	printf("Digite um decimal de até 11 bits\n");
	scanf("%u", &d);

	//Preenche o vetor auxiliar com os valor lido em bits
	int i = 0, j = 0, nextPot = 4;
	for (i = 1; i < size; i++)
	{
		aux_array[i] = (d >> (i - 1)) % 2;
	}
	//Colocando os dados no array final
	int dp = 3;
	for (i = 1, nextPot = 4; dp < SIZE; i++, dp++)
	{
		data[dp] = aux_array[i];
		if (nextPot == (dp + 1))
		{
			dp++;
			nextPot = nextPot << 1;
		}
	}
#ifdef DEBUG
	printf("\nArray sem paridade\n");
	int qt = 0;

	for (qt = 15; qt > 0; qt--)
	{
		// printf("i->%d   ",qt);
		printf("%u", array[qt]);
	}
#endif
	//Calculo dos bits de paridade
	int pot;
	for (i = 0, pot = 1; (1 << i) < size; i++)
	{
		pot = 1 << i;
		for (j = 0; j < size; j++)
		{
			if ((((j - pot) ^ (j)) == pot) && (j != pot))
			{
				data[pot] = data[pot] ^ data[j];
			}
		}
	}
	//Print do resultado
	printf("\nCRC para o dado inserido\n");


	for (i = size; i > 0; i--)
	{
		// printf("\nbit %d   ",i);
		printf("%u", data[i]);
	}
	printf("\n");
	// printf("\n\nEnter received data bits one by one\n");
	// for (i = 0; i < 7; i++)
	// 	scanf("%15.0d", &dataatrec[i]);

	// c1 = dataatrec[6] ^ dataatrec[4] ^ dataatrec[2] ^ dataatrec[0];
	// c2 = dataatrec[5] ^ dataatrec[4] ^ dataatrec[1] ^ dataatrec[0];
	// c3 = dataatrec[3] ^ dataatrec[2] ^ dataatrec[1] ^ dataatrec[0];
	// c = c3 * 4 + c2 * 2 + c1;

	// if (c == 0)
	// {
	// 	printf("\nNo error while transmission of data\n");
	// }
	// else
	// {
	// 	printf("\nError on position %d", c);

	// 	printf("\nData received : ");
	// 	for (i = 0; i < 7; i++)
	// 		printf("%d", dataatrec[i]);

	// 	printf("\nCorrect message is\n");

	// 	//if errorneous bit is 0 we complement it else vice versa
	// 	if (dataatrec[7 - c] == 0)
	// 		dataatrec[7 - c] = 1;
	// 	else
	// 		dataatrec[7 - c] = 0;

	// 	for (i = 0; i < 7; i++)
	// 	{
	// 		printf("%d", dataatrec[i]);
	// 	}
	// }
	//
	// 	printf("\nData received : ");
	// 	for (i = 0; i < 7; i++)
	// 		printf("%d", dataatrec[i]);

	// 	printf("\nCorrect message is\n");

	// 	//if errorneous bit is 0 we complement it else vice versa
	// 	if (dataatrec[7 - c] == 0)
	// 		dataatrec[7 - c] = 1;
	// 	else
	// 		dataatrec[7 - c] = 0;

	// 	for (i = 0; i < 7; i++)
	// 	{
	// 		printf("%d", dataatrec[i]);
	// 	}
	// } 	printf("\nData sent : ");
	//
	// 	printf("\nData received : ");
	// 	for (i = 0; i < 7; i++)
	// 		printf("%d", dataatrec[i]);

	// 	printf("\nCorrect message is\n");

	// 	//if errorneous bit is 0 we complement it else vice versa
	// 	if (dataatrec[7 - c] == 0)
	// 		dataatrec[7 - c] = 1;
	// 	else
	// 		dataatrec[7 - c] = 0;

	// 	for (i = 0; i < 7; i++)
	// 	{
	// 		printf("%d", dataatrec[i]);
	// 	}
	// } 	for (i = 0; i < 7; i++)
	//
	// 	printf("\nData received : ");
	// 	for (i = 0; i < 7; i++)
	// 		printf("%d", dataatrec[i]);

	// 	printf("\nCorrect message is\n");

	// 	//if errorneous bit is 0 we complement it else vice versa
	// 	if (dataatrec[7 - c] == 0)
	// 		dataatrec[7 - c] = 1;
	// 	else
	// 		dataatrec[7 - c] = 0;

	// 	for (i = 0; i < 7; i++)
	// 	{
	// 		printf("%d", dataatrec[i]);
	// 	}
	// } 		printf("%d", data[i]);

	// 	printf("\nData received : ");
	// 	for (i = 0; i < 7; i++)
	// 		printf("%d", dataatrec[i]);

	// 	printf("\nCorrect message is\n");

	// 	//if errorneous bit is 0 we complement it else vice versa
	// 	if (dataatrec[7 - c] == 0)
	// 		dataatrec[7 - c] = 1;
	// 	else
	// 		dataatrec[7 - c] = 0;

	// 	for (i = 0; i < 7; i++)
	// 	{
	// 		printf("%d", dataatrec[i]);
	// 	}
	// }
	//
	// 	printf("\nData received : ");
	// 	for (i = 0; i < 7; i++)
	// 		printf("%d", dataatrec[i]);

	// 	printf("\nCorrect message is\n");

	// 	//if errorneous bit is 0 we complement it else vice versa
	// 	if (dataatrec[7 - c] == 0)
	// 		dataatrec[7 - c] = 1;
	// 	else
	// 		dataatrec[7 - c] = 0;

	// 	for (i = 0; i < 7; i++)
	// 	{
	// 		printf("%d", dataatrec[i]);
	// 	}
	// } 	printf("\nData received : ");
	// 	for (i = 0; i < 7; i++)
	// 		printf("%d", dataatrec[i]);

	// 	printf("\nCorrect message is\n");

	// 	//if errorneous bit is 0 we complement it else vice versa
	// 	if (dataatrec[7 - c] == 0)
	// 		dataatrec[7 - c] = 1;
	// 	else
	// 		dataatrec[7 - c] = 0;

	// 	for (i = 0; i < 7; i++)
	// 	{
	// 		printf("%d", dataatrec[i]);
	// 	}
	// }
	return 0;
}
int encodeHamming(char* data, char* out){
	int dp = 3, i, nextPot;
	for (i = 1, nextPot = 4; dp < SIZE; i++, dp++)
	{
		out[dp] = data[i];
		if (nextPot == (dp + 1))
		{
			dp++;
			nextPot = nextPot << 1;
		}
	}
#ifdef DEBUG
	printf("\nArray sem paridade\n");
	int qt = 0;

	for (qt = size; qt > 0; qt--)
	{
		// printf("i->%d   ",qt);
		printf("%u", array[qt]);
	}
#endif
	//Calculo dos bits de paridade
	int pot;
	for (i = 0, pot = 1; (1 << i) < size; i++)
	{
		pot = 1 << i;
		for (j = 0; j < size; j++)
		{
			if ((((j - pot) ^ (j)) == pot) && (j != pot))
			{
				out[pot] = out[pot] ^ out[j];
			}
		}
	}
}

int decodeHamming(char* in, char* data){
	
}