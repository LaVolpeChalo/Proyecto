#include <stdio.h>

#include "Librerias\Interfaz\Interfaz.h"
#include "Librerias\Aplicacion.h"

int main(){

    short opcion;

    do{

        desplegarMenu();

        //Elección de la opción del menu
        printf("\nElija una opcion: ");
        scanf("%i", &opcion);
        if(opcion == 0) break;
        
        switch(opcion){
            case 1:
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