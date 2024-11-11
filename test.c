//implementar librerias
#include "libreria.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//funcion principal
int main(int argc, char *argv[]){
  int numLineas = 10;         //numero de lineas por defecto              
  char *nombreFuncion = argv[1];    //variable que guarda la funcion 
  
  //comprobar que el numero de argumentos es valido
  if(argc < 1 || argc > 3){
    printf("Numero de argumentos invalido.");
    return 1;
  }
  
  //comprobar si se ha pasado un numero de lineas valido 
  if(argv[2]>0){
    numLineas = atoi(argv[2]);
  }
  //llamadas a las funciones correspondientes
  if (strcmp(nombreFuncion, "-head") == 0){
    head(numLineas);
    return 0;
  } else if (strcmp(nombreFuncion, "-tail") == 0){
    tail(numLineas);
    return 0;
  } else if (strcmp(nombreFuncion, "-longLines") == 0){
    longlines(numLineas);
    return 0;
  } else{
    printf("La función introducida no es correcta");
    return 1;
  }

}
