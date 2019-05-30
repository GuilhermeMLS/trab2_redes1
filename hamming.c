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
	for (int i = 1, nextPot = 4, dp=3; dp < size; i++, dp++)
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
	int error_possition = 0;
	//bits de paridade
	int pbits = size - data_size;
	char *c = calloc((pbits + 1), sizeof(char));

	//Calculo dos bits de paridade
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
	for (int i = 1, nextPot = 4, dp=size; dp < size; i++, dp++)
	{
		out[dp] = data[i];
		if (nextPot == (dp + 1))
		{
			dp++;
			nextPot = nextPot << 1;
		}
	}}

int setHamming(unsigned int initial_data_size, unsigned int total_size)
{
	int range = total_size + 1;
	int pbits = total_size - data_size;
	if (range != 1 << (pbits))
	{
		return -1;
	}
	else
	{
		data_size = initial_data_size;
		size = total_size;
		return pbits;
	}
}