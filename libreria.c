//implementar librerias
#include "libreria.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int head (int N){
  int i = 0;
  char linea[1024];
  
  while ((i<N) && (fgets(linea, 1024, stdin) != NULL)) {
    //Comprobar si se alcanza el final del fichero antes de N lineas
    if(feof(stdin) && i < N){
      fprintf(stderr, "La entrada no tiene %d lineas. No son suficientes", N);
      return 1;
    }
    fprintf(stdout, "%s", linea);
    i++;
  }
  return 0;
}

int tail (int N){
  //Variables
  int i = 0;
  char linea[1024];
  //Array que almacena las lineas
  char **arr = (char**)malloc(N * sizeof(char *));
  if (arr == NULL) {
    fprintf(stderr, "Error al asignar memoria.\n");
    return 1;
  }
  
  //Bucle que almacena las lineas
  while (fgets(linea, 1024, stdin) != NULL){
    arr[i] = strdup(linea);
    if (arr[i] == NULL){
      fprintf(stderr, "Error al asignar memoria para una línea.\n");
      for(int j = 0;j<i; j++){
        free(arr[j]);
      }
      free(arr);
      return 1;
    }
    i = (i + 1) % N;
  }
  //Imprimir por salida estandar
  for (int k = i; k<N + i; k++){
    printf("%s", arr[k % N]);  
  }  
 
  //Liberar memoria
  for (int m=0;m<N; m++){
    free(arr[m]);
  } 
  free(arr);
  
  return 0;
}
int longlines (int N){
  
}
