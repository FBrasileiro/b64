#ifndef B64_H
#define B64_H

char *b64_encode(char *input);

int* get_indexes(char* input, int len);

char * b64_decode(char *input);

#endif
