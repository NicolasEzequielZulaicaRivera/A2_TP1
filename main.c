#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "evento_pesca.h"

#define MAX_STRING_SIZE 50
typedef char string [MAX_STRING_SIZE];

const string ARCHIVO_ARRECIFE_DEFAULT = "arrecife.txt";
const string ARCHIVO_ACUARIO_DEFAULT = "acuario.txt";

const string ESTILOS [] = { "\e[1;108m", "\e[1;100m", "\e[1;103m" };
const string RESET = "\e[0m";

/// DECLARACIONES

//FUNCIONES DE SELECCION

bool seleccionar_todos( pokemon_t* pokemon );
bool seleccionar_velocez( pokemon_t* pokemon );
bool seleccionar_pesados( pokemon_t* pokemon );
bool seleccionar_fuertes( pokemon_t* pokemon );
bool seleccionar_dorados( pokemon_t* pokemon );

// FUNCIONES DE VISUALIZACION

void tabla_pokemon( pokemon_t* pokemon );
void datos_pokemon( pokemon_t* pokemon );


/// MAIN

int main(int argc, char const *argv[]) {

  srand( (unsigned int) time(NULL) );

  arrecife_t* arrecife = crear_arrecife( ARCHIVO_ARRECIFE_DEFAULT );
  acuario_t* acuario = crear_acuario();
  if( !arrecife || !acuario ){
    liberar_arrecife( arrecife );
    liberar_acuario( acuario );
    return -1;
  }

  censar_arrecife( arrecife, datos_pokemon );

  trasladar_pokemon( arrecife, acuario, seleccionar_todos, 20);
  censar_arrecife( arrecife, tabla_pokemon );

  trasladar_pokemon( arrecife, acuario, seleccionar_velocez, 20);
  censar_arrecife( arrecife, datos_pokemon );

  trasladar_pokemon( arrecife, acuario, seleccionar_pesados, 20);
  censar_arrecife( arrecife, datos_pokemon );

  trasladar_pokemon( arrecife, acuario, seleccionar_fuertes, 20);
  censar_arrecife( arrecife, datos_pokemon );

  trasladar_pokemon( arrecife, acuario, seleccionar_dorados, 20);
  censar_arrecife( arrecife, tabla_pokemon );

  guardar_datos_acuario( acuario, ARCHIVO_ACUARIO_DEFAULT);

  liberar_arrecife( arrecife );
  liberar_acuario( acuario );

  return 0;
}

/// IMPLEMENTACIONES

//FUNCIONES DE SELECCION

bool seleccionar_todos( pokemon_t* pokemon ){
  return true;
}
bool seleccionar_velocez( pokemon_t* pokemon ){
  return pokemon->velocidad > 50;
}
bool seleccionar_pesados( pokemon_t* pokemon ){
  return pokemon->peso > 50;
}
bool seleccionar_fuertes( pokemon_t* pokemon ){
  return seleccionar_velocez(pokemon) && seleccionar_pesados(pokemon);
}
bool seleccionar_dorados( pokemon_t* pokemon ){
  return !strcmp(pokemon->color,"Dorado");
}

// FUNCIONES DE VISUALIZACION

void datos_pokemon( pokemon_t* pokemon ){

  printf("%s", ESTILOS[ !strcmp( pokemon->especie, "Kyogre" ) %2 *2 ] );
  printf("\t %s " , pokemon->especie);
  printf("%s", RESET );

  printf("%s", ESTILOS[ (pokemon->velocidad%100)*(pokemon->velocidad%100) / 4000  ] );
  printf("\t%im/s" , pokemon->velocidad);
  printf("%s", RESET );

  printf("%s", ESTILOS[ (pokemon->peso%100)*(pokemon->peso%100) / 4000 ] );
  printf("\t%ikg" , pokemon->peso);
  printf("%s", RESET );

  printf("%s", ESTILOS[ !strcmp( pokemon->color, "Dorado" ) %2 *2 ] );
  printf("\t %s " , pokemon->color );
  printf("%s", RESET );

  printf(" \n");
  return;
}

void tabla_pokemon( pokemon_t* pokemon ){

  static int n_fondo = 0;
  n_fondo = (n_fondo+1)%2;

  string fondo;
  strcpy(fondo, ESTILOS[n_fondo]);

  printf("%s", fondo );
  printf("\t %s \t %i \t %i \t %s " , pokemon->especie, pokemon->velocidad, pokemon->peso, pokemon->color );
  printf("%s \n", RESET );
  return;
}

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

/*
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
*/
