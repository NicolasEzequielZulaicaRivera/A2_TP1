#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "evento_pesca.h"

typedef char string [50];

const string ARCHIVO_ARRECIFE_DEFAULT = "arrecife.txt";

/*
void pokreate( int n ){
  string pknames [] = { "Magikarp","Gyarados","Tentacool","Tentacruel","Goldeen","Seaking","Wailmer","Wailord","Kyogre" };
  string colors [] = { "Rojo", "Azul", "Amarillo", "Verde", "Naranja", "Violeta", "Blanco", "Negro", "Dorado" };

  FILE* arrecife_f = fopen( "arrecife.txt", "w" );

  if( !arrecife_f )
    return;

  for( int i = 0; i<n; i++  )
    fprintf(arrecife_f, "%s;%i;%i;%s\n",pknames[rand()%9],rand()%100,rand()%100,colors[rand()%9]);

  fclose(arrecife_f);
}
*/

void datos_pokemon( pokemon_t* pokemon ){

  printf("%s , %i , %i , %s \n", pokemon->especie, pokemon->velocidad, pokemon->peso, pokemon->color );
  return;
}

void test_arrecife(){

  string pknames [] = { "Magikarp","Gyarados","Tentacool","Tentacruel","Goldeen","Seaking","Wailmer","Wailord","Kyogre" };
  string colors [] = { "Rojo", "Azul", "Amarillo", "Verde", "Naranja", "Violeta", "Blanco", "Negro", "Dorado" };

  arrecife_t tst;
  pokemon_t pkm [10];

  for( int i = 0; i<10; i++  ){

    pokemon_t aux;
    strcpy(aux.especie, pknames[rand()%9]);
    aux.velocidad = rand()%100;
    aux.peso = rand()%100;
    strcpy(aux.color, colors[rand()%9]);

    pkm[i]=aux;
    printf("%i - ",i);
    datos_pokemon(&aux);

  }

  tst.cantidad_pokemon = 10;
  tst.pokemon = pkm;

  printf("\n");
  censar_arrecife( &tst, datos_pokemon );

}



int main(int argc, char const *argv[]) {

  srand( (unsigned int) time(NULL) );
  //arrecife_t* arrecife = NULL;

  /*arrecife = crear_arrecife( ARCHIVO_ARRECIFE_DEFAULT );

  censar_arrecife( arrecife, datos_pokemon );

  liberar_arrecife( arrecife);*/

  test_arrecife();

  return 0;
}
