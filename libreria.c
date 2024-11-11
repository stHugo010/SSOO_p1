//Hugo Sanchez Torres
//Miguel Pradillo Bartolome
//implementar librerias
#include "libreria.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

////////////////////////////////////////////////
///////////////////// HEAD ////////////////////
///////////////////////////////////////////////

int head (int N){
  //Variable indice para bucles
  int i = 0;
  //Estructura que almacena la frase
  char linea[1024];
  
  while ((i<N) && (fgets(linea, 1024, stdin) != NULL)) {
    //Comprobar si se alcanza el final del fichero antes de N lineas
    if(feof(stdin) && i < N){
      printf("La entrada no tiene suficientes lineas.");
      return 1;
    }
    //Imprimir por salida estandar
    fprintf(stdout, "Linea(%d) -> %s", i+1, linea);
    i++;
  }
  return 0;
}

////////////////////////////////////////////////
///////////////////// TAIL ////////////////////
///////////////////////////////////////////////

int tail (int N){
  //Variables indice para bucles
  int i = 0;
  int k, j;
  //Estructura que almacena la linea
  char linea[1024];
  
  //Estructura que almacena las lineas
  char **arr = (char**)malloc(N * sizeof(char *));
  if (arr == NULL) {
    fprintf(stderr, "Error al asignar memoria.\n");
    return 1;
  }
  
  //Bucle que almacena las lineas
  while (fgets(linea, 1024, stdin) != NULL){
    arr[i] = strdup(linea); //Guarda linea en arr
    if (arr[i] == NULL){
      fprintf(stderr, "Error al asignar memoria para una línea.\n");
      for(j = 0;j<i; j++){
        free(arr[j]);
      }
      free(arr);
      return 1;
    }
    i = (i + 1) % N;
  }
  //Imprimir por salida estandar
  for (k = i; k<N + i; k++){
    printf("Linea(%d) -> %s", k+1, arr[k % N]);  
  }  
 
  //Liberar memoria
  for (int m=0;m<N; m++){
    free(arr[m]);
  } 
  free(arr);
  
  return 0;
}

////////////////////////////////////////////////
////////////////// LONGLINES //////////////////
///////////////////////////////////////////////

int longlines(int N) {
    //Indices para bucles
    int i, j;
    //Puntero 
    char** arr = NULL; 
    //Estructura que almacena la linea
    char linea[1024]; 
    //Contador
    int lc = 0;

    while (fgets(linea, 1024, stdin)) {
        //Aumentamos memoria del array
        arr = realloc(arr, (lc + 1) * sizeof(char*)); 
        //Asignamos memoria
        arr[lc] = malloc(strlen(linea) + 1);
        //Copiamos linea
        strcpy(arr[lc], linea);
        lc++; // Incrementamos el contador de líneas.
    }
	
    // Ordenamiento por burbuja.
    for (i = 0; i < lc; i++) {
        for (j = i + 1; j < lc; j++) {
            // Si linea j > linea i las cambiamos entre sí.
            if (strlen(arr[j]) > strlen(arr[i])) {
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    // Imprimir las N líneas más largas
    for (i = 0; i < N; i++) {
        printf("Linea(%d) -> %s", i+1, arr[i]);
        free(arr[i]);  // Liberar la memoria de cada línea
    }

    // Liberar memoria
    free(arr);
    return 0;
}
