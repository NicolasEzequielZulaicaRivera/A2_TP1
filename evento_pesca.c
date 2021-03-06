#include <stdlib.h>
#include <string.h>
#include "evento_pesca.h"

#define MAX_STRING_SIZE 51
typedef char string [MAX_STRING_SIZE];
const string FORMATO_LECTURA_POKEMON = "%50[^;];%i;%i;%50[^\n]\n";

const pokemon_t POKEMON_INVALIDO = {
  .especie = "",
  .velocidad = -1,
  .peso = -1,
  .color = ""
};

/// DECLARACIONES PRIVADAS

// Lee un pokemon de un archivo formateado scsv correctamente
// Devuelve el estado de la lectura ( 0 = Error )
int leer_pokemon( FILE* archivo, pokemon_t* pokemon );

// Agrega un pokemon a un acuario
// Devuelve 0 si falla
int agregar_pokemon( acuario_t* acuario, pokemon_t pokemon );

// Devuelve si es in pokemon valido
bool pokemon_valido( pokemon_t pokemon );

// Elimina los pokemones invalidos del arrecife y lo achica
// Devuelve 0 si falla
int limpiar_invalidos( arrecife_t* arrecife );

/// IMPLEMENTACIONES PUBLICAS

arrecife_t* crear_arrecife(const char* ruta_archivo){

  FILE* archivo = fopen(ruta_archivo, "r");
  if( !archivo )
    return NULL;

  size_t i = 0;
  pokemon_t pokemon_i;

  arrecife_t* nuevo_arrecife = malloc( sizeof(arrecife_t) );
  nuevo_arrecife->pokemon = NULL;

  while ( leer_pokemon( archivo, &pokemon_i ) ) {

    void* aux = realloc( nuevo_arrecife->pokemon, sizeof(pokemon_t)*(i+1) );
    if(!aux){
      liberar_arrecife(nuevo_arrecife);
      return NULL;
    }

    nuevo_arrecife->pokemon= aux;
    nuevo_arrecife->pokemon[i] = pokemon_i;
    i++;
  }
  nuevo_arrecife->cantidad_pokemon = (int)i;
  fclose(archivo);

  if( !i ){
    liberar_arrecife(nuevo_arrecife);
    return NULL;
  }

  return nuevo_arrecife;
}

acuario_t* crear_acuario(){

  acuario_t* nuevo_acuario = malloc( sizeof(acuario_t) );
  if(!nuevo_acuario) return NULL;

  nuevo_acuario->pokemon = NULL;
  nuevo_acuario->cantidad_pokemon = 0;

  return nuevo_acuario;

}

int trasladar_pokemon(arrecife_t* arrecife, acuario_t* acuario, bool (*seleccionar_pokemon) (pokemon_t*), int cant_seleccion){

  if( !arrecife || !arrecife->pokemon || !acuario )
    return -1;
  
  size_t i, seleccionados=0;
  size_t seleccion [cant_seleccion];
  pokemon_t pokemon_i;

  for( i=0; i < arrecife->cantidad_pokemon; i++)
    if( seleccionados<cant_seleccion && pokemon_valido(arrecife->pokemon[i]) && seleccionar_pokemon( &(arrecife->pokemon[i]) ) )
      seleccion[ seleccionados++ ] = i;

  if( seleccionados == cant_seleccion ){

    for( i=0; i<seleccionados; i++ ){
      pokemon_i = arrecife->pokemon[ seleccion[i] ];

      if( ! agregar_pokemon( acuario, pokemon_i) ){
        return -1;
      };

      arrecife->pokemon[ seleccion[i] ] = POKEMON_INVALIDO;
    }

    limpiar_invalidos( arrecife );
  } else {
    return -1;
  }
  return 0;
}

void censar_arrecife(arrecife_t* arrecife, void (*mostrar_pokemon)(pokemon_t*)){

  if( !arrecife || !arrecife->pokemon)
    return;

  int i, pokemones = 0;
  for( i=0; i < arrecife->cantidad_pokemon; i++ ){
    if( pokemon_valido(arrecife->pokemon[i]) ){
      mostrar_pokemon( & (arrecife->pokemon[i]) );
      pokemones++;
    }
  }

  return;
}

int guardar_datos_acuario(acuario_t* acuario, const char* nombre_archivo){

  if( !acuario )
    return -2;

  FILE* archivo = fopen( nombre_archivo, "w" );
  if( !archivo )
    return -1;

  int i;
  pokemon_t pokemon_i;

  if( acuario->pokemon && acuario->cantidad_pokemon ){
    for( i=0; i < acuario->cantidad_pokemon; i++ ){
      pokemon_i = acuario->pokemon[i];
      fprintf(archivo,"%s;%i;%i;%s\n",pokemon_i.especie, pokemon_i.velocidad, pokemon_i.peso, pokemon_i.color );
    }
  }

  fclose( archivo );

  return 0;
}

void liberar_acuario(acuario_t* acuario){

  if( !acuario )
    return;

  if( acuario->pokemon )
    free( acuario->pokemon );

  free( acuario );
  return;
}

void liberar_arrecife(arrecife_t* arrecife){

  if( !arrecife )
    return;

  if( arrecife->pokemon )
    free( arrecife->pokemon );

  free( arrecife );
  return;
}

/// IMPLEMENTACIONES PRIVADAS

int leer_pokemon( FILE* archivo, pokemon_t* pokemon ){

  return fscanf( archivo, FORMATO_LECTURA_POKEMON, pokemon->especie, &pokemon->velocidad, &pokemon->peso, pokemon->color ) == 4
    && !strchr( pokemon->especie, '\n' )
    && !strchr( pokemon->color, ';' );
}

bool pokemon_valido( pokemon_t pokemon ){

  return  strcmp(pokemon.especie,POKEMON_INVALIDO.especie)  ||
          strcmp(pokemon.color,POKEMON_INVALIDO.color)      ||
          pokemon.velocidad != POKEMON_INVALIDO.velocidad   ||
          pokemon.peso != POKEMON_INVALIDO.peso;
}

int agregar_pokemon( acuario_t* acuario, pokemon_t pokemon ){

  void* aux = realloc( acuario->pokemon, sizeof(pokemon_t)*(size_t)( acuario->cantidad_pokemon +1) );
  if(!aux) return 0;
  acuario->pokemon = aux;
  acuario->pokemon[acuario->cantidad_pokemon ++] = pokemon;

  return 1;
}

int limpiar_invalidos( arrecife_t* arrecife ){

  size_t i=0,j=0;
  pokemon_t pokemon_i;

  for( i=0; i< arrecife->cantidad_pokemon; i++ ){

    pokemon_i = arrecife->pokemon[i];
    if( pokemon_valido(pokemon_i) )
      arrecife->pokemon[ j++ ] = pokemon_i;

  }

  if( arrecife->cantidad_pokemon != (int)j ){
    arrecife->cantidad_pokemon = (int)j;
    void* aux = realloc( arrecife->pokemon , sizeof(pokemon_t)*j );
    if( !aux && j ) return 0;

    arrecife->pokemon = aux;
    if( !j ) arrecife->pokemon = NULL;
  }

  return 1;
}
