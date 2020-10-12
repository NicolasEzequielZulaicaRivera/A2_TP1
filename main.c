#include <stdio.h>
#include <stdlib.h>
#include "evento_pesca.h"

int main(int argc, char const *argv[]) {

  FILE* arrecife_f = fopen( "arrecife.txt", "w" );
  fclose(arrecife_f);

  return 0;
}
