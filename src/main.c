#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./includes/b64.h"

int main(int argc, char** argv) {
  char * input = (char*)malloc(sizeof(char)*2049);
  char *b64;
  char *txt;
  for(int i = 0; i < 5; i++){
    memset(input, '\x00', sizeof(char)*2048);
    scanf("%2048s", input);
    fflush(stdin);
    b64 = b64_encode(input);
    printf("ENCODED: %s\n", b64);
    txt = b64_decode(b64);
    size_t len = strlen(b64);
    int j = 0;
    for(int i = 0; i< len; i++){
      if(b64[i] == '=') j++;
    }
    printf("DECODED: %s\n", txt);
    free(b64);
    free(txt);
  }
  free(input);
  return 0;
}
