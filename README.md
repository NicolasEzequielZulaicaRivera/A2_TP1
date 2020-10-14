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
  
  **Importante :** Las funciones implementadas reservan *memoria dinamica* para la utilizacion de las estructuras, 
  por lo que es imperativo que esta se libere antes de finalizar el programa. 
  Esto se realiza mediante el uso de las funciones `liberar_acuario` y `liberar_arrecife` 
  para *todos* los acuarios y arrecifes creados en su programa.
  
  Se añade el archivo **main.c** como ejemplo de implementacion de la libreria.

## Compilacion y Ejecution

  Habiendo incluido la libreria en su programa o descargado el main.c proveido, 
  puede compilarlo con la siguiente linea en la terminal :
  
  ` gcc *.c -Wall -Werror -Wconversion -std=c99 -o nombre_programa `
  > usaremos el compilador gcc nativo a cualquier distribucion linux para compilar todos los archivos c (\*.c)
    en el directorio, empleando diversos *flags* para prevenir errores, 
    queda a discrecion del usuario elegir el nombre del programa
    
  Luego puede ejecutar el programa con la siguiente linea:
  
  `./nombre_programa`
  
  Cabe aclarar que la terminal debe encontrarse en el directorio donde se encuentran los archivos del programa
  para poder llevar su compilacion y ejecucion a cabo.
  
  Se recomienda  emplear un **makefile** para agilizar estas tareas. 
  Se añade en los archivos un makefile que nos permitira usar la linea `make run`
  que compilara (de ser necesario) y ejecutara el programa.

## Conceptos
  
  ### Punteros
    Lorem ipsum dolor sit amet, consectetur adipiscing elit. 
    Aenean gravida tincidunt mi. Aliquam erat volutpat. 
    Quisque finibus mattis ligula, at tristique ipsum finibus sed.
    
  ### Aritmetica de punteros
    Lorem ipsum dolor sit amet, consectetur adipiscing elit. 
    Aenean gravida tincidunt mi. Aliquam erat volutpat. 
    Quisque finibus mattis ligula, at tristique ipsum finibus sed.
    
  ### Punteros a funciones
    Lorem ipsum dolor sit amet, consectetur adipiscing elit. 
    Aenean gravida tincidunt mi. Aliquam erat volutpat. 
    Quisque finibus mattis ligula, at tristique ipsum finibus sed.
