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

/*Esta función copia una lista, el primer parametro es donde se copiará la lista
  el segundo parametro es la lista a copiar dentro.*/
list *copiar_lista(list *contenedor,list *contenido){

  tipoAuto * aux = firstList(contenido);
  cleanList(contenedor);
  contenedor = createList();
  
  do{
    
    pushFront(contenedor,aux);
    aux = nextList(contenido);
  }while(aux != NULL);

  cleanList(contenido);
  return contenedor;

}

/*Los modos son:
  1 = Comprobar si hay vehiculos en el mapa/lista con el rango de años ingresado 
  2 = Comprobar si hay vehiculos en el mapa/lista con el rango de precios ingresado
  3 = Comprobar si hay vehiculos en el mapa/lista con el rango de consumo ingresado
  4 = Comprobar si hay vehiculos en el mapa/lista con la cantidad de pasajeros ingresado
  5 = Comprobar si hay vehiculos en la mapa/lista con el rango de kilometraje ingresado
  Sub modos: 0 = mapa | 1 = lista*/
int busqueda_rango(int desde,int hasta,HashMap *mapa,list *filtrados,int modo,int submodo){

  tipoMarca *auxm = firstMap(mapa);
  tipoAuto *auxa;


  if(desde > hasta) return 1;
  

    switch (modo){
    case 1:

      if(submodo){

        auxa = firstList(filtrados);

        do{

          if(auxa->Ano >= desde && auxa->Ano <= hasta) return 0;
          auxa = nextList(filtrados);

        }while(auxa != NULL);
      }else{
        do{

        auxa = firstMap(auxm->Autos);

        do{

          if(auxa->Ano >= desde && auxa->Ano <= hasta) return 0;
          auxa = nextMap(auxm->Autos);

        }while(auxa != NULL);

        auxm = nextMap(mapa); 

        }while(auxm != NULL);
      }
    break;
    
    case 2:

      if(submodo){

        auxa = firstList(filtrados);

        do{

          if(auxa->Precio >= desde && auxa->Precio <= hasta) return 0;
          auxa = nextList(filtrados);

        }while(auxa != NULL);

      }else{

        do{

        auxa = firstMap(auxm->Autos);

          do{

            if(auxa->Precio >= desde && auxa->Precio <= hasta) return 0; 
            auxa = nextMap(auxm->Autos);

          }while(auxa != NULL);

          auxm = nextMap(mapa); 

        }while (auxm != NULL);
      }
    break;

    case 3:

      if(submodo){

        auxa = firstList(filtrados);

        do{

          if(auxa->Motor >= desde && auxa->Motor <= hasta) return 0;
          auxa = nextList(filtrados);

        }while(auxa != NULL);

      }else{

        do{

         auxa = firstMap(auxm->Autos);

        do{

          if(auxa->Motor >= desde && auxa->Motor <= hasta) return 0;
          
          auxa = nextMap(auxm->Autos);

        }while(auxa != NULL);

        auxm = nextMap(mapa); 

        }while(auxm != NULL);
      }
      
    break;

    case 4:


      if(submodo){

        auxa = firstList(filtrados);
        
        do{

          if(auxa->NumeroDePasajeros == desde ) return 0;
          auxa = nextList(filtrados);

        }while(auxa != NULL);

      }else{

        do{

         auxa = firstMap(auxm->Autos);

          do{

            if(auxa->NumeroDePasajeros == desde) return 0;
          
            auxa = nextMap(auxm->Autos);

          }while(auxa != NULL);

          auxm = nextMap(mapa); 

        }while(auxm != NULL);

      }
    break;
    case 5:

      if(submodo){

        auxa = firstList(filtrados);
        
        do{

          if(auxa->kilometraje >= desde && auxa->kilometraje <= hasta) return 0;
          auxa = nextList(filtrados);

        }while(auxa != NULL);

      }else{
        do{

         auxa = firstMap(auxm->Autos);

          do{

            if(auxa->kilometraje >= desde && auxa->kilometraje <= hasta) return 0;
          
            auxa = nextMap(auxm->Autos);

          }while(auxa != NULL);

          auxm = nextMap(mapa); 

        }while(auxm != NULL);
      }
    break;
   }
  return 1;
}

list * filtrarlista(int opcion,list * filtrados){
   list *listaux = createList();
   int aux,aux2,i = 0,a = 0,ingreso = 0;
   tipoAuto * auxtos = firstList(filtrados);
   char marca[25];

  switch (opcion){
  case 1:

    printf(magenta"\nEscoja el tipo:\n"reset);
    printf(magenta"\n0."reset);
    printf(cyan" Auto\n"reset);
    printf(magenta"1."reset);
    printf(cyan" Camioneta\n"reset);

    aux = ingreso_bool(aux,i);
    
    auxtos = firstList(filtrados);

    do{

      if(auxtos->Tipo == aux){
        pushBack(listaux,auxtos);
        imprimirdatos(auxtos);
        ingreso = 1;
      } 
      auxtos = nextList(filtrados);

    }while(auxtos != NULL);

    filtrados = copiar_lista(filtrados,listaux);
    cleanList(listaux);
    break;
    
  case 2:

    printf(magenta"\nSeleccione condicion:\n"reset);
    printf(magenta"\n0."reset);
    printf(cyan" Nuevo\n"reset);
    printf(magenta"1."reset);
    printf(cyan" Usado\n"reset);

    aux = ingreso_bool(aux,i);
    
    auxtos = firstList(filtrados);

    do{

      if(auxtos->condicion == aux){
        pushBack(listaux,auxtos);
        imprimirdatos(auxtos);
        ingreso = 1;
      } 
      auxtos = nextList(filtrados);

    }while(auxtos != NULL);

    filtrados = copiar_lista(filtrados,listaux);
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
    
    }while(busqueda_rango(aux,aux2,createMap(0),filtrados,1,1) || aux>=aux2);

    auxtos = firstList(filtrados);

    do{

      if(auxtos->Ano >= aux && auxtos->Ano <= aux2){
        pushBack(listaux,auxtos);
        imprimirdatos(auxtos);
        ingreso = 1;
      } 
      auxtos = nextList(filtrados);

    }while(auxtos != NULL);

    filtrados = copiar_lista(filtrados,listaux);
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
    
    }while(busqueda_rango(aux,aux2,createMap(0),filtrados,2,1) || aux>=aux2);


    auxtos = firstList(filtrados);

    do{


      if(auxtos->Precio >= aux && auxtos->Precio <= aux2){
        pushBack(listaux,auxtos);
        imprimirdatos(auxtos);
        ingreso = 1;
      } 
      auxtos = nextList(filtrados);

    }while(auxtos != NULL);

    filtrados = copiar_lista(filtrados,listaux);
    break;

  case 5:

    printf(magenta"\nSeleccione Caja de cambios:\n"reset);
    printf(cyan"\n0."reset);
    printf(magenta" Manual\n"reset);
    printf(cyan"1."reset);
    printf(magenta" Automatico\n"reset);

    aux = ingreso_bool(aux,i);

    auxtos = firstList(filtrados);

    do{

      if(auxtos->Caja == aux){
        pushBack(listaux,auxtos);
        imprimirdatos(auxtos);
        ingreso = 1;
      } 
      auxtos = nextList(filtrados);

    }while(auxtos != NULL);
    
    filtrados = copiar_lista(filtrados,listaux);
    break;

  case 6:

    printf(magenta"Ingrese la cantidad de pasajeros deseada: \n"reset);
    do{

      if(i != 0) printf(red"\nNo hay vehiculos con la cantidad de pasajeros deseada\n"reset);

      scanf("%d",&aux);
      aux2 = 9999;
      i++;
    
    }while(busqueda_rango(aux,aux2,createMap(0),filtrados,4,1));

      auxtos = firstList(filtrados);

      do{

        if(auxtos->NumeroDePasajeros == aux){
          pushBack(listaux,auxtos);
          imprimirdatos(auxtos);  
          ingreso = 1; 
        }

        auxtos = nextList(filtrados);

      }while(auxtos != NULL);

      filtrados = copiar_lista(filtrados,listaux);
 
    break;

    case 7:

    printf(magenta"\nIngrese marca de vehiculos:\n"reset);
    auxtos = firstList(filtrados);
    
    do{

      if(i != 0) printf(red"\nNo hay existencias de la marca en la base de datos\n"reset);
      scanf("%s",&marca);
      marca[0] = toupper(marca[0]); 
      if(strcmp(marca,auxtos->Marca) == 0) a = 1;
      
      auxtos = nextList(filtrados);
      i++;

    }while(auxtos != NULL && a == 0);

    auxtos = firstList(filtrados);

    do{

      if(strcmp(marca,auxtos->Marca) == 0){
        imprimirdatos(auxtos);
        pushBack(listaux,auxtos);
        ingreso = 1;
      }
      auxtos = nextList(filtrados);

    }while(auxtos != NULL);

    filtrados = copiar_lista(filtrados,listaux);
    break;

  case 8:

    printf(magenta"\nSeleccione traccion:\n"reset);
    printf(cyan"\n0."reset);
    printf(magenta" 4x2\n"reset);
    printf(cyan"1."reset);
    printf(magenta" 4x4\n"reset);

    aux = ingreso_bool(aux,i);

    auxtos = firstList(filtrados);

    do{

        if(auxtos->Traccion == aux){
          pushBack(listaux,auxtos);
          imprimirdatos(auxtos);
          ingreso = 1;
        } 
        auxtos = nextList(filtrados);

    }while(auxtos != NULL);

    filtrados = copiar_lista(filtrados,listaux);
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
    
    }while(busqueda_rango(aux,aux2,createMap(0),filtrados,3,1) || aux>=aux2);

    auxtos = firstList(filtrados);

    do{

      if(auxtos->Motor >= aux && auxtos->Motor <= aux2){
        pushBack(listaux,auxtos);
        imprimirdatos(auxtos);
        ingreso = 1;
      } 
      auxtos = nextList(filtrados);

    }while(auxtos != NULL);

    filtrados = copiar_lista(filtrados,listaux);

    break;

  case 10:

    printf(magenta"\nSeleccione el tipo de combustible:\n"reset);
    printf(cyan"\n0."reset);
    printf(magenta" Bencina\n"reset);
    printf(cyan"1."reset);
    printf(magenta" Electricidad\n"reset);
    printf(cyan"2."reset);
    printf(magenta" Diesel\n"reset);

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
        strcpy(marca,"Diesel");
      break;  
    }

    auxtos = firstList(filtrados);

    do{

      if(strcmp(marca,auxtos->combustible) == 0){
        pushBack(listaux,auxtos);
        imprimirdatos(auxtos);
        ingreso = 1;
      } 
      auxtos = nextList(filtrados);

    }while(auxtos != NULL);

    filtrados = copiar_lista(filtrados,listaux);

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
    
    }while(busqueda_rango(aux,aux2,createMap(0),filtrados,5,1) || aux>=aux2);

    auxtos = firstList(filtrados);

    do{

      if(auxtos->kilometraje >= aux && auxtos->kilometraje <= aux2){
        pushBack(listaux,auxtos);
        imprimirdatos(auxtos);
        ingreso = 1;
      } 
      auxtos = nextList(filtrados);

    }while(auxtos != NULL);

    filtrados = copiar_lista(filtrados,listaux);

    break;
  }
  if(ingreso){

    return filtrados;

  }
  return NULL;
  

}

list * filtrarmapa(int opcion,list *filtrados,HashMap *mapa){

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
          pushBack(filtrados,auxtos);
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
          pushBack(filtrados,auxtos);
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
    
    }while(busqueda_rango(aux,aux2,mapa,filtrados,1,0) || aux>=aux2);

    auxmarca = firstMap(mapa);

    do{

      auxtos = firstMap(auxmarca->Autos);

      do{

        if(auxtos->Ano >= aux && auxtos->Ano <= aux2){
          pushBack(filtrados,auxtos);
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
    
    }while(busqueda_rango(aux,aux2,mapa,filtrados,2,0) || aux>=aux2);

     auxmarca = firstMap(mapa);

    do{

      auxtos = firstMap(auxmarca->Autos);

      do{


        if(auxtos->Precio >= aux && auxtos->Precio <= aux2){
          pushBack(filtrados,auxtos);
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
          pushBack(filtrados,auxtos);
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
    
    }while(busqueda_rango(aux,aux2,mapa,filtrados,4,0));

    auxmarca = firstMap(mapa);

    do{

      auxtos = firstMap(auxmarca->Autos);

      do{

        if(auxtos->NumeroDePasajeros == aux){
          pushBack(filtrados,auxtos);
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
      pushBack(filtrados,auxtos);
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
          pushBack(filtrados,auxtos);
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
    
    }while(busqueda_rango(aux,aux2,mapa,filtrados,3,0) || aux>=aux2);

    auxmarca = firstMap(mapa);

    do{

      auxtos = firstMap(auxmarca->Autos);

      do{

        if(auxtos->Motor >= aux && auxtos->Motor <= aux2){
          pushBack(filtrados,auxtos);
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
    printf(magenta" Diesel\n"reset);

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
          pushBack(filtrados,auxtos);
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
    
    }while(busqueda_rango(aux,aux2,mapa,filtrados,5,0) || aux>=aux2);
    auxmarca = firstMap(mapa);

    do{

      auxtos = firstMap(auxmarca->Autos);

      do{

        if(auxtos->kilometraje >= aux && auxtos->kilometraje <= aux2){
          pushBack(filtrados,auxtos);
          imprimirdatos(auxtos);
        } 
        auxtos = nextMap(auxmarca->Autos);

      }while(auxtos != NULL);

      auxmarca = nextMap(mapa); 

    }while(auxmarca != NULL);
    break;
  }
  return filtrados;

}





void filtrar_autos(HashMap *mapa){
  list * filtrados = createList(); 
  int *usadas=(int*)calloc(11,sizeof(int));
  short opcion=-1;
  tipoAuto *aux;
  
  do{

      aux = firstList(filtrados);

      if(aux == NULL && opcion != -1){

        printf(red"\nNo hay vehiculos que cumplan el conjunto de parametros solicitado\n"reset);
        return;

      }

      menu_filtros(usadas);

      printf("\nEscoja un filtro: ");
      scanf("%hi",&opcion);

      switch (opcion){
      case 1:
        if(usadas[opcion-1] == 1) printf(red"\nLa opción ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;
        
          if(aux != NULL) filtrados = filtrarlista(opcion,filtrados);
          else filtrados = filtrarmapa(opcion,filtrados,mapa);

        }
        break;

      case 2:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{
          
          usadas[opcion-1] = 1;

          if(aux != NULL) filtrados = filtrarlista(opcion,filtrados);
          else filtrados = filtrarmapa(opcion,filtrados,mapa);

        } 
        break;

      case 3:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrados = filtrarlista(opcion,filtrados);
          else filtrados = filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 4:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrados = filtrarlista(opcion,filtrados);
          else filtrados = filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 5:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrados = filtrarlista(opcion,filtrados);
          else filtrados = filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 6:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrados = filtrarlista(opcion,filtrados);
          else filtrados = filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 7:
       if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrados = filtrarlista(opcion,filtrados);
          else filtrados = filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 8:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrados = filtrarlista(opcion,filtrados);
          else filtrados = filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 9:
       if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrados = filtrarlista(opcion,filtrados);
          else filtrados = filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 10:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrados = filtrarlista(opcion,filtrados);
          else filtrados = filtrarmapa(opcion,filtrados,mapa);
        
        }
        break;

      case 11:
        if(usadas[opcion-1] == 1) printf(red"\nLa opcion ingresada ya fue utilizada\n"reset);
        else{

          usadas[opcion-1] = 1;

          if(aux != NULL) filtrados = filtrarlista(opcion,filtrados);
          else filtrados = filtrarmapa(opcion,filtrados,mapa);
        
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
