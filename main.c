#include <stdio.h>
#include <stdlib.h>
#include "Librerias/hashmap.h"
#include "Librerias/Interfaz/Interfaz.h"
#include "Librerias/Aplicacion.h"
#include "Librerias/list.h"

int main(){
    HashMap* mapa=createMap(85);

    short opcion;

    do{

        desplegarMenu();

        //Elección de la opción del menu
        printf("\nElija una opcion: ");
        scanf("%hi", &opcion);
        if(opcion == 0) break;
        
        switch(opcion){
            case 1: importarArchivo(mapa);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break; 
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;                                    
        }


    }while(opcion != 0);
}