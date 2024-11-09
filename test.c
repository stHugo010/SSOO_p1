//implementar librerias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libreria.h"

//funcion principal
int main(int argc, char *argv[]){
  int numLineas = 10;         //numero de lineas por defecto              
  char *funcion = argv[1];    //variable que guarda la funcion 
  //comprobar si se ha pasado un numero de lineas
  if(argc = 2 && argv[2]>0){
    numLineas = atoi(argv[2]);
  }
  //llamadas a las funciones correspondientes
  if (strcmp(funcion, "-head") == 0){
    head(numLineas);
  } else if (strcmp(funcion, "-tail") == 0){
    tail(numLineas);
  } else if (strcmp(funcion, "-longLines") == 0){
    longlines(numLineas);
  } else{
    printf("La función introducida no es correcta");
    return 1;
  }

}
