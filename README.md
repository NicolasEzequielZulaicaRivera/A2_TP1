# ¡Gran pesca Pokémon!

![image](https://images-wixmp-ed30a86b8c4ca887773594c2.wixmp.com/f/4fd9f2ad-e10f-43d5-83c4-4a1014d767af/d9a9dfy-26411b0a-f9bc-472a-aab9-eeab31048385.jpg/v1/fill/w_800,h_451,q_75,strp/pokemon_fishing_by_kafel88_d9a9dfy-fullview.jpg?token=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJzdWIiOiJ1cm46YXBwOiIsImlzcyI6InVybjphcHA6Iiwib2JqIjpbW3siaGVpZ2h0IjoiPD00NTEiLCJwYXRoIjoiXC9mXC80ZmQ5ZjJhZC1lMTBmLTQzZDUtODNjNC00YTEwMTRkNzY3YWZcL2Q5YTlkZnktMjY0MTFiMGEtZjliYy00NzJhLWFhYjktZWVhYjMxMDQ4Mzg1LmpwZyIsIndpZHRoIjoiPD04MDAifV1dLCJhdWQiOlsidXJuOnNlcnZpY2U6aW1hZ2Uub3BlcmF0aW9ucyJdfQ.8qiwRMe1N6plT2YnLTMLVbScHyD2j5zp_6Yhi_4Y5vc)

## Funcionamiento

  Se crea la libreria **evento_pesca.h** con el objetivo de simular el translado de pokemones de un arrecife a un acuario.

  Para ello se implementan las siguientes estructuras :
  * `Pokemon`
  * `Arrecife`
  * `Acuario`

  Y las siguientes funcionalidades:
  * `crear_arrecife` : reserva memoria para el arrecife y carga los pokemones de un archivo dado
  * `crear_acuario` : reserva memoria para el acuario
  * `transladar_pokemon` : trasnlada los pokemones que cumplan un criterio dado de un arrecife a un acuario
  * `censar_arrecife` : muestra los pokemon contenidos en un arrecife
  * `guardar_datos_acuario` : exporta un listado de pokemones de un acuario
  * `liberar_acuario` : libera la memoria reservada para un acuario
  * `liberar_arrecife` :  libera la memoria reservada para un arrecife

  Queda a libertad del usuario crear las funciones de *visualizacion* y *seleccion* de pokemones.

  **Importante :** Las funciones implementadas reservan *memoria dinamica* para la utilizacion de las estructuras, por lo que es imperativo que esta se libere antes de finalizar el programa.
  Esto se realiza mediante el uso de las funciones `liberar_acuario` y `liberar_arrecife` para *todos* los acuarios y arrecifes creados en su programa.

  Se añade el archivo **main.c** como ejemplo de implementacion de la libreria.

## Compilacion y Ejecution

  Habiendo incluido la libreria en su programa o descargado el main.c proveido, puede compilarlo con la siguiente linea en la terminal :

  ` gcc *.c -Wall -Werror -Wconversion -std=c99 -o nombre_programa `
  > usaremos el compilador gcc nativo a cualquier distribucion linux para compilar todos los archivos c (\*.c)
    en el directorio, empleando diversos *flags* para prevenir errores,
    queda a discrecion del usuario elegir el nombre del programa

  Luego puede ejecutar el programa con la siguiente linea:

  `./nombre_programa`

  Cabe aclarar que la terminal debe encontrarse en el directorio donde se encuentran los archivos del programa para poder llevar su compilacion y ejecucion a cabo.

  Se recomienda  emplear un **makefile** para agilizar estas tareas.
  Se añade en los archivos un makefile que nos permitira usar la linea `make run` que compilara (de ser necesario) y ejecutara el programa.

## Conceptos

  ### Punteros
  Es un tipo de dato nativo de C que almcena posiciones de memoria.
  Esto nos permite "apuntar" a variables o estructuras para acceder y/o modificar su informacion.
  ( Posterioemente se explica punteros a funciones )

  *Ejemplo:*

   ```C
   int numero = 0;
   int* puntero_a_numero = &numero;

   *puntero_a_numero = 1;
   printf("%i", numero ); // mostrara 1
   ```

  ### Aritmetica de punteros
  Es el empleo de las operaciones de suma y resta en punteros.
  Esto hara que la posicion de memoria a la que "apunta" el puntero afectado incremente ( o decremente ) una cantidad de bytes dada como : el numero sumado multiplicado por el tamaño del tipo de dato al que apunta el puntero.
  El funcionamiento de la aritmetca de punteros es analogo a la operacion con notacion de  arreglos.

  *Ejemplo:*

  ```C
  char abecedario [] = "abcdefghijklmopqrstuvwxyz";
  char* puntero = abecedario;

  for( int i=0; i<10; i++ )
    printf( "%c", *(puntero+i) ); // mostrara abcdefghij

  // Es equivalente a

  for( int i=0; i<10; i++ )
    printf( "%c", puntero[i] ); // mostrara abcdefghij
  ```

  ### Punteros a funciones
  De manera similar a como podemos referenciar variables, podemos referenciar funciones mediante el uso de punteros void ( `void* ` ).
  Podemos entonces tener funciones "variables" en nuestro flujo que pueden ser asignadas mediante punteros o pasadas por parametro.
  Estos punteros requieren una firma y solo se les podra asignar funciones que cumplan dicha firma.

  *Ejemplo:*
  ```C
  int sumar( int a, int b ) return a + b;
  int restar( int a, int b ) return a - b;

  int * operacion (int,int);

  operacion = suma;
  printf( "%i", operacion(2,1) );//muestra 3

  operacion = resta;
  printf( "%i", operacion(2,1) );//muestra 1
  ```

  ### Malloc y Realloc
  Estas funciones de C estan incluidas en la libreria `stdlib`

  `void *malloc(size_t size)`

   Reserva `size` bytes de memoria dinamica y devuelve un puntero que apunta a esta memoria.
   En caso de fallar devolvera NULL;

  `void *realloc(void *ptr, size_t size)`

  Cambia el tamaño del bloque de memoria al que apunta el puntero `ptr` a `size` bytes
  sin cambiar su contenido y devuelve la nueva posicion del bloque ( en caso de que halla cambiado ), liberando la anterior.
  En caso de fallar devolvera NULL y no liberara memoria.

  ---

  ![image](https://pbs.twimg.com/media/EjCB_tLX0AQ0MJq.jpg)
