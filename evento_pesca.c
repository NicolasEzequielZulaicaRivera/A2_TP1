#include <stdlib.h>
#include "evento_pesca.h"

#define MAX_STRING_SIZE 50
typedef char string [MAX_STRING_SIZE];
const string FORMATO_LECTURA_POKEMON = "%[^;];%i;%i;%[^\n]\n";
//const string FORMATO_ESCRITURA_POKEMON = "%s;%i;%i;%s\n";

/// DECLARACIONES PRIVADAS

// Lee un pokemon de un archivo formateado scsv correctamente
// Devuelve el estado de la lectura ( 0 = Error )
int leer_pokemon( FILE* archivo, pokemon_t* pokemon );

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

  return nuevo_arrecife;
}

acuario_t* crear_acuario(){

  acuario_t* nuevo_acuario = malloc( sizeof(acuario_t) );
  if(!nuevo_acuario) return NULL;

  nuevo_acuario->pokemon = NULL;
  nuevo_acuario->cantidad_pokemon = 0;

  return nuevo_acuario;

}

/*
 * Función que deberá sacar del arrecife a todos los pokémon que satisfagan la
 * condición dada por el puntero a función (que devuelvan true) y trasladarlos
 * hacia el acuario. El parámetro cant_seleccion especifica la cantidad máxima
 * de pokémon que serán trasladados. En caso de que haya menos pokémon trasladables en el
 * arrecife que los pedidos, no se deberá mover ninguno para conservar los pocos existentes.
 * El vector de pokemones del arrecife quedará solo con aquellos que no fueron
 * trasladados (su tamaño se ajustará luego de cada traslado).
 * El vector de pokemones del acuarió quedará con aquellos que fueron
 * trasladados esta vez más los que ya había en el
 * acuario (su tamaño se ajustará luego de cada traslado).
 * Devuelve -1 en caso de error o 0 en caso contrario.
 */
int trasladar_pokemon(arrecife_t* arrecife, acuario_t* acuario, bool (*seleccionar_pokemon) (pokemon_t*), int cant_seleccion){

  size_t i, seleccionados=0;
  size_t seleccion [cant_seleccion];
  pokemon_t pokemon_i;

  for( i=0; i < arrecife->cantidad_pokemon; i++)
    if( seleccionados<cant_seleccion && seleccionar_pokemon( &(arrecife->pokemon[i]) ) )
      seleccion[ seleccionados++ ] = i;

  if( seleccionados == cant_seleccion ){

    for( i=0; i<seleccionados; i++ ){
      pokemon_i = arrecife->pokemon[ seleccion[i] ];

      void* aux = realloc( acuario->pokemon, sizeof(pokemon_t)*(size_t)( acuario->cantidad_pokemon +1) );
      if(!aux)
        return -1;

      acuario->pokemon = aux;
      acuario->pokemon[acuario->cantidad_pokemon ++] = pokemon_i;

    }
  }

  return 0;
}

void censar_arrecife(arrecife_t* arrecife, void (*mostrar_pokemon)(pokemon_t*)){

  if( !arrecife || !arrecife->pokemon)
    return;

  int i;
  for( i=0; i < arrecife->cantidad_pokemon; i++ ){
    mostrar_pokemon( & (arrecife->pokemon[i]) );
  }
  printf("\n-El arrecife contiene %i pokemones \n\n", i );

  return;
}

int guardar_datos_acuario(acuario_t* acuario, const char* nombre_archivo){

  if( !acuario || !acuario->pokemon)
    return -2;

  FILE* archivo = fopen( nombre_archivo, "w" );
  if( !archivo )
    return -1;

  int i;
  pokemon_t pokemon_i;

  for( i=0; i < acuario->cantidad_pokemon; i++ ){
    pokemon_i = acuario->pokemon[i];
    fprintf(archivo,"%s;%i;%i;%s\n",pokemon_i.especie, pokemon_i.velocidad, pokemon_i.peso, pokemon_i.color );
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

  return fscanf( archivo, FORMATO_LECTURA_POKEMON, pokemon->especie, &pokemon->velocidad, &pokemon->peso, pokemon->color ) == 4 ;
}
