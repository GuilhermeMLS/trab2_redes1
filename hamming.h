#ifndef __HAMMING__
#define __HAMMING__

/*Código Hamming genérico baseado no algoritimo(pseudo-código) encontrado em https://pt.wikipedia.org/wiki/C%C3%B3digo_de_Hamming#Algoritmo . (30/05/2019)*/

#define SIZE (15)
#define DATA_SIZE (11)
unsigned int size, data_size;

/*O codigo foi feito para aceitar outros formatos de hamming,
**para usar o especificado para o trabalho basta usar fazer 'setHamming(SIZE,DATA_SIZE).
**É necessário utilizar essa função antes de inicar as demais funções
**/
int setHamming(unsigned int initial_data_size, unsigned int total_size);

// encodeHamming -> Codifica dados em dados com bits de paridade conforme hamming
/*
 *Padrão de entrada
 * Ambos os vetores de entrada devem ser alocados e inicializados antes de chamar a função;
 * 
 *	data-> vetor tamanho inicial de dados +1(initial_data_size+1) onde : a primeira posição sera desconsiderada, o bit menos significante fica na posição 1 e o mais significante fica em   tamanho inicial de dados
 *			  exemplo "00011001" -> data[initial_data_size+1]= { ? ,1, 0, 0, 1, 1, 0, 0, 0 }
 *	out	-> vetor de tamanho total +1(size+1) mesclando os dados com os bits de paridade
 *
 */
void encodeHamming(char *data, char *out);

//decodeHamming -> Decodifica hamming (in) devolvendo o dado(data)corrigido se necessário, e retorna a posição do bit errado em hamming
/*Padrão de entrada
 * Ambos os vetores de entrada devem ser alocados e inicializados antes de chamar a função;
 * 
 *	in	-> vetor de tamanho total +1(size+1) mesclando os dados com os bits de paridade
 *	data-> vetor tamanho inicial de dados +1(initial_data_size+1) onde : a primeira posição sera desconsiderada, o bit menos significante fica na posição 1 e o mais significante fica em   tamanho inicial de dados
 *			  exemplo data[initial_data_size+1]= { ? ,1, 0, 0, 1, 1, 0, 0, 0 } -> "00011001" 
 *  retorno -> inteiro referente a posição do bit errado (desconsiderando bit 0)
 */
int decodeHamming(char *in, char *data);

#endif
