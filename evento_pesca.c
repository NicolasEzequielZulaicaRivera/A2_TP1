#include "evento_pesca.h"

/*
 * Función que dado un archivo carga los pokémon que viven en el arrecife
 * reservando la memoria necesaria para el mismo. Se debe intentar leer la mayor
 * cantidad posible de registros del archivo. Al encontrar el primer registro
 * erróneo (o al llegar al final del archivo) se deben finalizar la lectura y
 * crear el arrecife con los pokémon leídos exitosamente. En caso de no
 * encontrar ningún registro con el formato correcto, se debe devolver error.
 * Devuelve un puntero a un arrecife válido o NULL en caso de error.
 * Es importante notar que tanto
 */
arrecife_t* crear_arrecife(const char* ruta_archivo){

  return NULL;
}

/*
 * Función que crea un acuario vacío reservando la memoria necesaria para el mismo.
 * Devuelve el acuario o NULL en caso de error.
 */
acuario_t* crear_acuario(){
  return NULL;
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
  return 0;
}

/*
 * Procedimiento que dado un arrecife deberá mostrar por pantalla a todos los pokemon que contiene.
 */
void censar_arrecife(arrecife_t* arrecife, void (*mostrar_pokemon)(pokemon_t*)){


  for( int i=0; i < arrecife->cantidad_pokemon; i++ ){
    mostrar_pokemon( & (arrecife->pokemon[i]) );
    printf("---- %i / %i\n",i,arrecife->cantidad_pokemon);
  }

  return;
}

/*
 * Función que dado un acuario guarda en un archivo de texto a los pokemones que contiene.
 * Devuelve 0 si se realizo con éxito o -1 si hubo algun problema para guardar el archivo.
 */
int guardar_datos_acuario(acuario_t* acuario, const char* nombre_archivo){
  return 0;
}

/*
 * Libera la memoria que fue reservada para el acuario.
 */
void liberar_acuario(acuario_t* acuario){
  return;
}

/*
 * Libera la memoria que fue reservada para el arrecife.
 */
void liberar_arrecife(arrecife_t* arrecife){
  return;
}
