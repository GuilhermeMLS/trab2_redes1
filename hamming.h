#ifndef __HAMMING__
#define __HAMMING__


#define SIZE (15)
#define DATA_SIZE (11)
unsigned int size, data_size;

// "011001" -> data[1]=1 , data[2]=0  data[3]=0 1 1 0 
int encodeHamming(char* data, char* out);
//Decodifica hamming (in) devolvendo o dado(data)corrigido se necessário, e retorna a posição do bit errado em hamming
int decodeHamming(char* in, char* data);

#endif
