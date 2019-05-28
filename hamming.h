#ifndef __HAMMING__
#define __HAMMING__


#define SIZE (15)
#define DATA_SIZE (11)
unsigned int size, data_size;


int encodeHamming(char* data, char* out);
int decodeHamming(char* in, char* data);

#endif
