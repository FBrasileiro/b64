#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *b64_encode(char *input){
  char *b64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  size_t len = strlen(input);
  size_t nlen = len;
  size_t b64_len;
  if(len % 3){
    nlen += (3 - len % 3);
  }
  b64_len = nlen + (nlen/3);

  char *b64= (char*)malloc(sizeof(char)*b64_len+1);
  memset(b64, '\x0', b64_len);

  for(int i = 0, cont = 0; i < nlen; i+=3, cont+=4){

    b64[cont] = b64_chars[((input[i] & 0xfc) >> 2)];
    b64[cont+1] = b64_chars[((input[i] & 0x03) << 4) + ((input[i+1] & 0xf0) >> 4)];
    b64[cont+2] = b64_chars[((input[i+1] & 0x0f) << 2) + ((input[i+2] & 0xc0) >> 6)];
    b64[cont+3] = b64_chars[input[i+2] & 0x3f];
  }

  for(int i = b64_len - (nlen-len) ; i < b64_len; i++) b64[i] = '=';
  return b64;
}




int main(int argc, char** argv) {

  char * example = (char*)malloc(sizeof(char)*1024);
  char *b64;
  while(1){
    scanf("%s", example);
    fflush(stdin);
    b64 = b64_encode(example);
    memset(example, '\x00', 1024);
    printf("%s\n", b64);
    free(b64);
  }
  return 0;
}
