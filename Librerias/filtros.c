#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "filtros.h"
#include "Utilidades/TDAs/list.h"
#include "Utilidades/Interfaz.h"
#include "Utilidades/TDAs/hashmap.h"
#include "Aplicacion.h"
//Include “../aplicacion.h”


int ingreso_bool(int aux,int i){
  do{
      if(i != 0) printf(red"\nIngrese una opcion valida\n"reset);
      scanf("%d",&aux);
      i++;
    } while (aux >= 1 && aux <= 0);

  return aux;  
}

/*Los modos son:
  1 = Comprobar si hay vehiculos en el mapa con el rango de años ingresado 
  2 = Comprobar si hay vehiculos en la lista con el rango de años ingresado
  3 = Comprobar si hay vehiculos en el mapa con el rango de precios ingresado
  4 = Comprobar si hay vehiculos en la lista con el rango de precios ingresado
  5 = Comprobar si hay vehiculos en el mapa con el rango de consumo ingresado
  6 = Comprobar si hay vehiculos en la lista con el rango de consumo ingresado
  7 = Comprobar si hay vehiculos en el mapa con la cantidad de pasajeros ingresado
  8 = Comprobar si hay vehiculos en la lista con la cantidad de pasajeros ingresado
  9 = Comprobar si hay vehiculos en la mapa con el rango de kilometraje ingresado
  10 = Comprobar si hay vehiculos en la lista con el rango de kilometraje ingresado*/
int busqueda_rango(int desde,int hasta,HashMap *mapa,list *filtrados,int modo){

  tipoMarca *auxm = firstMap(mapa);
  tipoAuto *auxa;


  if(desde > hasta) return 1;
  

    switch (modo){
    case 1:
      do{

        auxa = firstMap(auxm->Autos);

        do{

          if(auxa->Ano >= desde && auxa->Ano <= hasta) return 0;
          auxa = nextMap(auxm->Autos);

        }while(auxa != NULL);

        auxm = nextMap(mapa); 

      }while(auxm != NULL);
      return 1;
    break;
    
    case 3:
      do{

        auxa = firstMap(auxm->Autos);

        do{

          if(auxa->Precio >= desde && auxa->Precio <= hasta) return 0; 
          auxa = nextMap(auxm->Autos);

        }while(auxa != NULL);

        auxm = nextMap(mapa); 

      }while (auxm != NULL);
      return 1;
    break;

    case 5:
      do{

         auxa = firstMap(auxm->Autos);

        do{

          if(auxa->Motor >= desde && auxa->Motor <= hasta) return 0;
          
          auxa = nextMap(auxm->Autos);

        }while(auxa != NULL);

        auxm = nextMap(mapa); 

      }while(auxm != NULL);
      return 1;
    break;

    case 7:
       do{

         auxa = firstMap(auxm->Autos);

        do{

          if(auxa->NumeroDePasajeros == desde) return 0;
          
          auxa = nextMap(auxm->Autos);

        }while(auxa != NULL);

        auxm = nextMap(mapa); 

      }while(auxm != NULL);
      return 1;
    break;
    case 9:
      do{

         auxa = firstMap(auxm->Autos);

        do{

          if(auxa->kilometraje >= desde && auxa->kilometraje <= hasta) return 0;
          
          auxa = nextMap(auxm->Autos);

        }while(auxa != NULL);

        auxm = nextMap(mapa); 

      }while(auxm != NULL);
      return 1;
    break;
   }
}

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
  int aux,aux2;
  int i=0;
  char marca[25];


  switch (opcion){
  case 1:

    printf(magenta"\nEscoja el tipo:\n"reset);
    printf(magenta"\n0."reset);
    printf(cyan" Auto\n"reset);
    printf(magenta"1."reset);
    printf(cyan" Camioneta\n"reset);

    aux = ingreso_bool(aux,i);

    auxmarca = firstMap(mapa);

    do{

      auxtos = firstMap(auxmarca->Autos);

      do{

        if(auxtos->Tipo == aux){
          pushFront(filtrados,auxtos);
          imprimirdatos(auxtos);
        } 
        auxtos = nextMap(auxmarca->Autos);

      }while(auxtos != NULL);

      auxmarca = nextMap(mapa); 

    }while(auxmarca != NULL); 
    break;

  case 2:

    printf(magenta"\nSeleccione condicion:\n"reset);
    printf(cyan"\n0."reset);
    printf(magenta" Nuevo\n"reset);
    printf(cyan"1."reset);
    printf(magenta" Usado\n"reset);

    aux = ingreso_bool(aux,i);

    auxmarca = firstMap(mapa);

    do{

      auxtos = firstMap(auxmarca->Autos);

      do{

        if(auxtos->condicion == aux){
          pushFront(filtrados,auxtos);
          imprimirdatos(auxtos);
        } 
        auxtos = nextMap(auxmarca->Autos);

      }while(auxtos != NULL);

      auxmarca = nextMap(mapa); 

    }while (auxmarca != NULL);
    break;
  
  case 3:

    printf(magenta"\nIngrese un rango de Anos:\n"reset);
    do{

      if(i != 0){
        if(aux <= aux2) printf(red"\nNo hay vehiculos dentro del rango escogido\n"reset);
        else printf(red"\nIngrese un rango valido\n"reset);
      }
      printf(cyan"\nDesde:\n"reset);
      scanf("%d",&aux);
      printf(cyan"\nHasta:\n"reset);
      scanf("%d",&aux2);
      i++;
    
    }while(busqueda_rango(aux,aux2,mapa,filtrados,1) || aux>=aux2);

    auxmarca = firstMap(mapa);

    do{

      auxtos = firstMap(auxmarca->Autos);

      do{

        if(auxtos->Ano >= aux && auxtos->Ano <= aux2){
          pushFront(filtrados,auxtos);
          imprimirdatos(auxtos);
        } 
        auxtos = nextMap(auxmarca->Autos);

      }while(auxtos != NULL);

      auxmarca = nextMap(mapa); 

    }while(auxmarca != NULL);
    break;
  
  case 4:
    
    printf(magenta"Ingrese un rango de Precios:"reset);
    do{

      if(i != 0){
        if(aux <= aux2) printf(red"\nNo hay vehiculos dentro del rango escogido\n"reset);
        else printf(red"\nIngrese un rango valido\n"reset);
      }
      printf(cyan"\nDesde:\n"reset);
      scanf("%d",&aux);
      printf(cyan"\nHasta:\n"reset);
      scanf("%d",&aux2);
      i++;
    
    }while(busqueda_rango(aux,aux2,mapa,filtrados,3) || aux>=aux2);

     auxmarca = firstMap(mapa);

    do{

      auxtos = firstMap(auxmarca->Autos);

      do{


        if(auxtos->Precio >= aux && auxtos->Precio <= aux2){
          pushFront(filtrados,auxtos);
          imprimirdatos(auxtos);
        } 
        auxtos = nextMap(auxmarca->Autos);

      }while(auxtos != NULL);

      auxmarca = nextMap(mapa); 

    }while(auxmarca != NULL);
    break;

  case 5:
   
    printf(magenta"\nSeleccione Caja de cambios:\n"reset);
    printf(cyan"\n0."reset);
    printf(magenta" Manual\n"reset);
    printf(cyan"1."reset);
    printf(magenta" Automatico\n"reset);

    aux = ingreso_bool(aux,i);

    auxmarca = firstMap(mapa);

    do{

      auxtos = firstMap(auxmarca->Autos);

      do{

        if(auxtos->Caja == aux){
          pushFront(filtrados,auxtos);
          imprimirdatos(auxtos);
        } 
        auxtos = nextMap(auxmarca->Autos);

      }while(auxtos != NULL);

      auxmarca = nextMap(mapa); 

    }while(auxmarca != NULL);
    break;

  case 6:
      
    printf(magenta"Ingrese la cantidad de pasajeros deseada: \n"reset);
    do{

      if(i != 0) printf(red"\nNo hay vehiculos con la cantidad de pasajeros deseada\n"reset);

      scanf("%d",&aux);
      aux2 = 9999;
      i++;
    
    }while(busqueda_rango(aux,aux2,mapa,filtrados,7));

    auxmarca = firstMap(mapa);

    do{

      auxtos = firstMap(auxmarca->Autos);

      do{

        if(auxtos->NumeroDePasajeros == aux){
          pushFront(filtrados,auxtos);
          imprimirdatos(auxtos);   
        }

        auxtos = nextMap(auxmarca->Autos);

      }while(auxtos != NULL);

      auxmarca = nextMap(mapa); 

    }while(auxmarca != NULL);
    break;

  case 7:

    printf(magenta"\nIngrese marca de vehiculos:\n"reset);
    
    do{

      if(i != 0) printf(red"\nNo hay existencias de la marca en la base de datos\n"reset);
      scanf("%s",&marca);
      marca[0] = toupper(marca[0]); 
      
      auxmarca = searchMap(mapa,marca); 
      i++;

    }while(auxmarca == NULL);

    auxtos = firstMap(auxmarca->Autos);

    do{

      imprimirdatos(auxtos);
      pushFront(filtrados,auxtos);
      auxtos = nextMap(auxmarca->Autos);

    }while(auxtos != NULL);

    break;
  case 8:

    printf(magenta"\nSeleccione traccion:\n"reset);
    printf(cyan"\n0."reset);
    printf(magenta" 4x2\n"reset);
    printf(cyan"1."reset);
    printf(magenta" 4x4\n"reset);

    aux = ingreso_bool(aux,i);

    auxmarca = firstMap(mapa);

    do{

      auxtos = firstMap(auxmarca->Autos);

      do{

        if(auxtos->Traccion == aux){
          pushFront(filtrados,auxtos);
          imprimirdatos(auxtos);
        } 
        auxtos = nextMap(auxmarca->Autos);

      }while(auxtos != NULL);

      auxmarca = nextMap(mapa); 

    }while (auxmarca != NULL);
    break;
  case 9:

    printf(magenta"\nIngrese un rango de consumo (omita decimales):\n"reset);
    do{

      if(i != 0){
        if(aux <= aux2) printf(red"\nNo hay vehiculos dentro del rango escogido\n"reset);
        else printf(red"\nIngrese un rango valido\n"reset);
      }
      printf(cyan"\nDesde:\n"reset);
      scanf("%d",&aux);
      printf(cyan"\nHasta:\n"reset);
      scanf("%d",&aux2);
      i++;
    
    }while(busqueda_rango(aux,aux2,mapa,filtrados,5) || aux>=aux2);

    auxmarca = firstMap(mapa);

    do{

      auxtos = firstMap(auxmarca->Autos);

      do{

        if(auxtos->Motor >= aux && auxtos->Motor <= aux2){
          pushFront(filtrados,auxtos);
          imprimirdatos(auxtos);
        } 
        auxtos = nextMap(auxmarca->Autos);

      }while(auxtos != NULL);

      auxmarca = nextMap(mapa); 

    }while(auxmarca != NULL);
    break;
  
  case 10:

    printf(magenta"\nSeleccione el tipo de combustible:\n"reset);
    printf(cyan"\n0."reset);
    printf(magenta" Bencina\n"reset);
    printf(cyan"1."reset);
    printf(magenta" Electricidad\n"reset);
    printf(cyan"2."reset);
    printf(magenta"Diesel\n"reset);

    do{
      if(i != 0) printf(red"\nIngrese una opcion valida\n"reset);
      scanf("%d",&aux);
      i++;

    }while(aux < 0 && aux > 2);

    switch (aux){
      case 0:
        strcpy(marca,"Bencina");
      break;
      case 1:
        strcpy(marca,"Electricidad");
      break;
      case 2:
        strcpy(marca," Diesel");
      break;  
    }

    auxmarca = firstMap(mapa);

    do{

      auxtos = firstMap(auxmarca->Autos);

      do{

        if(strcmp(marca,auxtos->combustible) == 0){
          pushFront(filtrados,auxtos);
          imprimirdatos(auxtos);
        } 
        auxtos = nextMap(auxmarca->Autos);

      }while(auxtos != NULL);

      auxmarca = nextMap(mapa); 

    }while(auxmarca != NULL);
    break;
  case 11:
    printf(magenta"\nIngrese un rango de kilometraje:\n"reset);
    do{

      if(i != 0){
        if(aux <= aux2) printf(red"\nNo hay vehiculos dentro del rango escogido\n"reset);
        else printf(red"\nIngrese un rango valido\n"reset);
      }
      printf(cyan"\nDesde:\n"reset);
      scanf("%d",&aux);
      printf(cyan"\nHasta:\n"reset);
      scanf("%d",&aux2);
      i++;
    
    }while(busqueda_rango(aux,aux2,mapa,filtrados,9) || aux>=aux2);

    auxmarca = firstMap(mapa);

    do{

      auxtos = firstMap(auxmarca->Autos);

      do{

        if(auxtos->kilometraje >= aux && auxtos->kilometraje <= aux2){
          pushFront(filtrados,auxtos);
          imprimirdatos(auxtos);
        } 
        auxtos = nextMap(auxmarca->Autos);

      }while(auxtos != NULL);

      auxmarca = nextMap(mapa); 

    }while(auxmarca != NULL);
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
        cleanList(filtrados);
        break;

      default: 
        printf(red"\nIngrese una opcion valida\n"reset); 
        break;  
     }

  }while(opcion != 0);
  

}
