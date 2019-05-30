#ifndef __HAMMING__
#define __HAMMING__


#define SIZE (15)
#define DATA_SIZE (11)
unsigned int size, data_size;

/*O codigo foi feito para aceitar outros formatos de hamming,
**para usar o especificado para o trabalho basta usar fazer 'setHamming(SIZE,DATA_SIZE).
**É necessário utilizar essa função antes de inicar as demais funções
**/
int setHamming(unsigned int initial_data_size, unsigned int total_size);

/*Padrão de entrada
 * Ambos os vetores de entrada devem ser alocados e inicializados antes de chamar a função;
 * 
 *	data-> vetor tamanho inicial de dados +1(initial_data_size+1) onde : a primeira posição sera desconsiderada, o bit menos significante fica na posição 1 e o mais significante fica em   tamanho inicial de dados
 *			  exemplo "00011001" -> data[1]=1 , data[2]=0, data[3]=0, data[4]=1, data[5]=1, data[6]=0, data[7]=0, data[8]=0 
 *	out	-> vetor de tamanho total(total_size) 
 *
 * 
 * 
 * 
 */


int encodeHamming(char* data, char* out);
//Decodifica hamming (in) devolvendo o dado(data)corrigido se necessário, e retorna a posição do bit errado em hamming
int decodeHamming(char* in, char* data);

#endif
