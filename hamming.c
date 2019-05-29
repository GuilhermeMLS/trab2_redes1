#include <stdio.h>
#include <stdlib.h>
#include "hamming.h"

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
	char *data = calloc(size + 1, sizeof(char));

	printf("Digite um decimal de até 11 bits\n");
	for (int i = size; i > 0; i--)
	{
		scanf("%c", data + i);
	}
	for (int i = size; i > 0; i--)
	{
		if (data[i] == '0')
		{
			data[i] = 0;
		}
		else
		{
			data[i] = 1;
		}
	}
	char *out;
	decodeHamming(data, out);
	for (int i = size; i > 0; i--)
	{
		// printf("\nbit %d   ",i);
		printf("%d", data[i]);
	}
	printf("\n");

	return 0;
}
int encodeHamming(char *data, char *out)
{
	int dp = 3, i, nextPot;
	for (int i = 1, nextPot = 4; dp < SIZE; i++, dp++)
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
		printf("%u", out[qt]);
	}
#endif
	//Calculo dos bits de paridade
	int pot;
	for (int i = 0, pot = 1; (1 << i) < size; i++)
	{
		pot = 1 << i;
		for (int j = 0; j < size; j++)
		{
			if ((((j - pot) ^ (j)) == pot) && (j > pot))
			{
				out[pot] = out[pot] ^ out[j];
			}
		}
	}
}

int decodeHamming(char *in, char *data)
{
	//bits de paridade
	int pbits = size - data_size;
	char *c = calloc((pbits + 1), sizeof(char));

	//Calculo dos bits de paridade
	int pot;
	for (int i = 0, pot = 1; (1 << i) < size; i++)
	{
		pot = 1 << i;
		for (int j = 0; j < size; j++)
		{
			if ((((j - pot) ^ j) == pot) && j >= pot)
			{
				c[i + 1] = c[i + 1] ^ in[j];
				// if (in[j])
				// 	printf("pot=%d\nj=%d\nin[j]=%d\nc[i+1]=%d\n", pot, j, in[j], c[i + 1]);
			}
			// printf("\n");
		}
	}
	for (int i = 1; i <= pbits; i++)
	{
		c[0] += c[pbits - i + 1] * (1 << (i - 1));
	}

	if (c[0] == 0)
	{
		printf("\n Nenhum erro encontrado\n");
	}
	else
	{
		int posi = 0;
		printf("\n Foi encontrado um erro: resultado->");
		for (int i = 1; i <= pbits; i++)
		{
			if (c[i])
				posi += 1 << i - 1;
			printf("%d ", c[i]);
		}
		printf("erro na posição %d\n ",posi);
		in[posi]= in[posi]^1;
	}

	// printf("\n\nEnter received data bits one by one\n");
	// for(i=0;i<7;i++)
	//     scanf("%d",&dataatrec[i]);

	// c1=dataatrec[6]^dataatrec[4]^dataatrec[2]^dataatrec[0];
	// c2=dataatrec[5]^dataatrec[4]^dataatrec[1]^dataatrec[0];
	// c3=dataatrec[3]^dataatrec[2]^dataatrec[1]^dataatrec[0];
	// c=c3*4+c2*2+c1 ;

	// if(c==0) {
	// 	printf("\nNo error while transmission of data\n");
	// }
	// else {
	// 	printf("\nError on position %d",c);

	// 	printf("\nData sent : ");
	//     for(i=0;i<7;i++)
	//     	printf("%d",data[i]);

	// 	printf("\nData received : ");
	//     for(i=0;i<7;i++)
	//     	printf("%d",dataatrec[i]);

	// 	printf("\nCorrect message is\n");

	// 	//if errorneous bit is 0 we complement it else vice versa
	// 	if(dataatrec[7-c]==0)
	// 		dataatrec[7-c]=1;
	//     else
	// 		dataatrec[7-c]=0;

	// 	for (i=0;i<7;i++) {
	// 		printf("%d",dataatrec[i]);
	// 	}
	// }
}