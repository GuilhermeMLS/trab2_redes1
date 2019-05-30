#include <stdio.h>
#include <stdlib.h>
#include "hamming.h"

/*
 *Flags de debug: 
 *	DEBUG -> Prints de debug da execução do códiho  
 * 	DEBUGEXE -> função main de testes
 */


#ifdef DEBUGEXE
#include <time.h>
int main(int argc, char *argv[])
{
	srand(time(NULL));
	if (argc == 3)
	{
		setHamming(atoi(argv[2]), atoi(argv[1]));
	}
	else
	{
		setHamming(DATA_SIZE, SIZE);
	}

	char *data = calloc(size + 1, sizeof(char));

	printf("Digite um decimal de até %d bits\n", data_size);
	for (int i = data_size; i > 0; i--)
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
	char *out = calloc(size + 1, sizeof(char));
	encodeHamming(data, out);
	printf("Saida gerada\n");

	for (int i = size; i > 0; i--)
	{
		// printf("\nbit %d   ",i);
		printf("%d", out[i]);
	}
	printf("\n");

	int r = (rand() % size) + 1;
	// printf("\nEstragando o bit %d",r);
	// out[r]^=1;

	char *end = calloc(data_size + 1, sizeof(char));

	r = decodeHamming(out, end);
	printf("\nSaida interpretada, encontrado erro em %d\n", r);
	for (int i = data_size; i > 0; i--)
	{
		// printf("\nbit %d   ",i);
		printf("%d", end[i]);
	}
	printf("\n");
}
#endif
void encodeHamming(char *data, char *out)
{
	for (int i = 1, nextPot = 4, dp = 3; dp <= size; i++, dp++)
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

	for (qt = size+1; qt > 0; qt--)
	{
		// printf("i->%d   ",qt);
		printf("%u", out[qt]);
	}
	printf("\n");
#endif
		//Calculo dos bits de paridade

		for (int i = 0, pot = 1; (1 << i) < size; i++)
	{
		pot = 1 << i;
		for (int j = 0; j <= size; j++)
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
	int error_possition = 0;
	//bits de paridade
	int pbits = size - data_size;
	char *c = calloc((pbits + 1), sizeof(char));

	//Calculo dos bits de paridade
	for (int i = 0, pot = 1; (1 << i) <= size; i++)
	{
		pot = 1 << i;
		for (int j = 0; j <= size; j++)
		{
			if ((((j - pot) ^ j) == pot) && j >= pot)
			{
				c[i + 1] = c[i + 1] ^ in[j];

#ifdef DEBUG
				if (in[j])
					printf("pot=%d\nj=%d\nin[j]=%d\nc[i+1]=%d\n", pot, j, in[j], c[i + 1]);
#endif
			}
			// printf("\n");
		}
	}
	for (int i = 1; i <= pbits; i++)
	{
		c[0] += c[pbits - i + 1] * (1 << (i - 1));
	}

	if (c[0] != 0)
	{
#ifdef DEBUG
		printf("\n Foi encontrado um erro: resultado->");
#endif
		for (int i = 1; i <= pbits; i++)
		{
			if (c[i])
				error_possition += 1 << (i - 1);
#ifdef DEBUG
			printf("%d ", c[i]);
#endif
		}
#ifdef DEBUG
		printf("erro na posição %d\n ", error_possition);
#endif
		in[error_possition] = in[error_possition] ^ 1;
	}
	else
	{
#ifdef DEBUG
		printf("\n Nenhum erro encontrado\n");
#endif
	}
#ifdef DEBUG
	printf("\nArrumando saida\n");
#endif

	for (int i = 1, nextPot = 4, dp = 3; i <= data_size; i++, dp++)
	{
#ifdef DEBUG
		printf("\n out[%d]<-in[%d]=%d\n", i, dp, in[dp]);
#endif
		data[i] = in[dp];

		if (nextPot == (dp + 1))
		{
			dp++;
#ifdef DEBUG
			printf("\n in[%d] pulou(bit de paridade)\n", dp);
#endif
			nextPot = nextPot << 1;
		}
	}
	return error_possition;
}

int setHamming(unsigned int initial_data_size, unsigned int total_size)
{
	int range = total_size + 1;
	int pbits = (total_size - initial_data_size);
	data_size = initial_data_size;
	size = total_size;
	if (range != 1 << (pbits))
	{
		printf("range:%d	data_size=%d	total_size=%d	pbits=%d\n", range, data_size, size, pbits);
		return -1;
	}
	else
	{

		return pbits;
	}
}