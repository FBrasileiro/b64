#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "./includes/b64.h"

char *b64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
char *b64_encode(char *input){
  size_t len = strlen(input);
  size_t nlen = len;
  size_t b64_len;
  if(len % 3){
    nlen += (3 - len % 3);
  }
  b64_len = nlen + (nlen/3);

  char *b64 = (char*)malloc(sizeof(char)*b64_len+1);
  memset(b64, '\x0', b64_len);

  for(int i = 0, cont = 0; i < nlen; i+=3, cont+=4){

    b64[cont] = b64_chars[((input[i] & 0xfc) >> 2)];
    b64[cont+1] = b64_chars[((input[i] & 0x03) << 4) + ((input[i+1] & 0xf0) >> 4)];
    b64[cont+2] = b64_chars[((input[i+1] & 0x0f) << 2) + ((input[i+2] & 0xc0) >> 6)];
    b64[cont+3] = b64_chars[input[i+2] & 0x3f];
  }

  for(int i = b64_len - (nlen-len) ; i < b64_len; i++) b64[i] = '=';
  b64[b64_len] = '\x00';
  return b64;
}

int* get_indexes(char* input, int len){
  int *indexes = (int*)malloc(sizeof(int)*len);
  memset(indexes, -1, len);
  for(int i = 0; i < len; i++){
    for(int j = 0; j < 64; j++) {
      if(b64_chars[j] == input[i]) {
        indexes[i] = j;
        break;
      }
    }
  }
  return indexes;
}

char * b64_decode(char *input){
  size_t len = strlen(input);
  int j = 0;
  for(int i = len-2, j = 0; i < len; i++){
    if(input[i] == '=') {
      j++;
    }
  }
  size_t index_len = len-j;

  char buf[4];
  int *indexes;
  indexes = get_indexes(input, index_len);

  len = len-(len/4)-j; // Get txt length

  char *txt = (char*)malloc(len+1);
  memset(txt, '\x0', len);
  size_t total = 0;
  for(int i = 0 ; i < len; i+=4){
     buf[0] = (indexes[i] << 2) + ((indexes[i+1] & 0x30) >> 4);
     buf[1] = indexes[i+1] != -1 ? ((indexes[i+1] & 0xf) << 4) + ((indexes[i+2] & 0x3c) >> 2) : '\x0';
     buf[2] = indexes[i+2] != -1 ? ((indexes[i+2] & 0x3) << 6) + indexes[i+3] : '\x0';
     strncat(txt, buf, (len - total >= 3 ? 3 : len - total));
     total+=3;
     memset(buf, '\x0', 4);
  }
  free(indexes);
  return txt;
}
