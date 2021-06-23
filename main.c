#include <stdio.h>
#include <stdlib.h>
#include "Librerias/TDAs/hashmap.h"
#include "Librerias/Interfaz/Interfaz.h"
#include "Librerias/Aplicacion.h"
#include "Librerias/TDAs/list.h"

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
            Printf(green"\n Importacion de archivo \n"reset);
                break;
            case 2:
            Printf(green"\n Buscar Vehiculo \n"reset);
            //Buscar Vehiculos
                break;
            case 3:
            Printf(green"\n Buscar Vehiculo por Nombre \n"reset);
            //Buscar Vehiculos por nombre
                break;
            case 4:
            Printf(green"\n Agregar Vehiculo\n"reset);
            //Agregar Vehiculo
                break;
            case 5:
            Printf(green"\n Ingresar Auto a Lista de Autos Deseados\n"reset);
            //Ingresar Auto a lista de Autos Deseados
                break;
            case 6:
            Printf(green"\n Lista de Autos Deseados \n"reset);
            //Desplegar lista de Autos Deseados
                break; 
            case 7: 
            Printf(green"\n Todos los autos \n"reset);
                if(mapsize(mapa) != 0) desplegarautos(mapa);
                else printf(red"\nLa base de datos se encuentra vacia\n"reset);
                break;
            case 8:
            Printf(green"\n Compra \n"reset);
            //Concretar Compra
                break;
            case 9:
            Printf(green"\n Elimininación de Autos Deseados\n"reset);
            //Eliminar Auto de la lista de Autos Deseados
                break;
            case 10:
            Printf(green"\n Eliminacion de Autos Base de Datos \n"reset);
            // Eliminar Auto de la base de Datos
                break;
            case 11:
            Printf(green"\n Exportar CSV \n"reset);
            //Exportar csv
                break;                                    
        }


    }while(opcion != 0);
}