//implementar librerias
#include "libreria.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int head (int N){
  int i = 0;
  char linea[1024];
  
  while ((i<N) && (fgets(linea, 1024, stdin) != NULL)) {
    fprintf(stdout, "%s", linea);
    i++;
  }
  return 0;
}

int tail (int N){
  int i = 0;
  char linea[1024];
  
  char **arr = (char**)malloc(N * sizeof(char *));
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
  for (int k = 0; k<N; k++){
    printf("%s", arr[k]);  
  }  
  for (int m=0;m<N; m++){
    free(arr[m]);
  } 
  free(arr);
  return 0;
}
int longlines (int N){
  
}
