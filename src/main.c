#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./includes/b64.h"

int main(int argc, char** argv) {
  char * example = (char*)malloc(sizeof(char)*1024);
  char *b64;
  char *txt;
  while(1){
    scanf("%s", example);
    fflush(stdin);
    b64 = b64_encode(example);
    memset(example, '\x00', sizeof(char)*1024);
    printf("%s\n", b64);
    txt = b64_decode(b64);
    printf("%s\n", txt);
    free(txt);
    free(b64);
  }
  return 0;
}
