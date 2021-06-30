#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filtros.h"
#include "Utilidades/TDAs/list.h"
#include "Utilidades/Interfaz.h"
#include "Utilidades/TDAs/hashmap.h"
#include "Aplicacion.h"

void filtrarlista(int opcion,list * filtrados){

  switch (opcion)
  {
  case 1:

    
    
    break;
  
  default:
    break;
  }
  

}

void filtrarmapa(int opcion,list *filtrados,HashMap *mapa){

  tipoMarca *auxmarca = firstMap(mapa);
  tipoAuto *auxtos;
  int aux;
  int i=0;


  switch (opcion){
  case 1:

    printf(magenta"\nEscoja el tipo:\n"reset);
    printf(magenta"0."reset);
    printf(cyan" Auto\n"reset);
    printf(magenta"1."reset);
    printf(cyan" Camioneta\n"reset);

    do{
      if(i != 0) printf(red"\nIngrese una opcion valida\n"reset);
      scanf("%d",&aux);
      i++;
    } while (aux >= 1 && aux <= 0);


    for(int i = 0;i < mapsize(mapa);i++){

      auxtos = firstMap(auxmarca->Autos);

      for(int j = 0;j < mapsize(auxmarca->Autos)-1;j++){

        if(auxtos->Tipo == aux){
          pushFront(filtrados,auxtos);
          imprimirdatos(auxtos);
        } 
        auxtos = nextMap(auxmarca->Autos);

      }

      auxmarca = nextMap(mapa); 

    } 
    break;
  
  default:
    break;
  }
  

}





void filtrar_autos(HashMap *mapa){
  list * filtrados=createList(); 
  int *usadas=(int*)calloc(11,sizeof(int));
  short opcion;
  
  do{

      tipoAuto *aux = firstList(filtrados);

      menu_filtros(usadas);

      printf("\nEscoja un filtro: ");
      scanf("%hi",&opcion);

      switch (opcion){
      case 1:
        if(usadas[opcion-1] == 1) printf(red"\nLa opción ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;
        
          if(aux != NULL) filtrarlista(opcion,filtrados);
          else filtrarmapa(opcion,filtrados,mapa);

        }
        break;

      case 2:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{
          
          usadas[opcion-1] = 1;

          if(aux != NULL) filtrarlista(opcion,filtrados);
          else filtrarmapa(opcion,filtrados,mapa);

        } 
        break;

      case 3:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrarlista(opcion,filtrados);
          else filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 4:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrarlista(opcion,filtrados);
          else filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 5:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrarlista(opcion,filtrados);
          else filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 6:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrarlista(opcion,filtrados);
          else filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 7:
       if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrarlista(opcion,filtrados);
          else filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 8:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrarlista(opcion,filtrados);
          else filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 9:
       if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrarlista(opcion,filtrados);
          else filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 10:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrarlista(opcion,filtrados);
          else filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 11:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrarlista(opcion,filtrados);
          else filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 0:
        printf(green"\nVolviendo al menu principal...\n"reset); 
        break;

      default: 
        printf(red"\nIngrese una opcion valida\n"reset); 
        break;  
     }

  }while(opcion != 0);
  

}
