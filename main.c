#include <stdio.h>
#include <stdlib.h>
#include "Librerias/TDAs/hashmap.h"
#include "Librerias/Interfaz/Interfaz.h"
#include "Librerias/Aplicacion.h"
#include "Librerias/TDAs/list.h"

int main(){
    HashMap* mapa=createMap(85);
    HashMap* mapa2=createMap(85);
    tipoMarca* mapaMarca;
    mapaMarca->Autos=createMap(85);

    short opcion;

    do{

        desplegarMenu();

        //Elección de la opción del menu
        printf("\nElija una opcion: ");
        scanf("%hi", &opcion);
        if(opcion == 0) break;
        
        switch(opcion){
            case 1: importarArchivo(mapa,mapa2,mapaMarca);
            printf(green"\n Importacion de archivo \n"reset);
                break;
            case 2:
            printf(green"\n Buscar Vehiculo \n"reset);
            //Buscar Vehiculos
                break;
            case 3:
            printf(green"\n Buscar Vehiculo por Nombre \n"reset);
            //Buscar Vehiculos por nombre
                break;
            case 4:
            printf(green"\n Agregar Vehiculo\n"reset);
            //Agregar Vehiculo
                break;
            case 5:
            printf(green"\n Ingresar Auto a Lista de Autos Deseados\n"reset);
            //Ingresar Auto a lista de Autos Deseados
                break;
            case 6:
            printf(green"\n Lista de Autos Deseados \n"reset);
            //Desplegar lista de Autos Deseados
                break; 
            case 7: 
            printf(green"\n Todos los autos \n"reset);
                if(mapsize(mapa) != 0) desplegarautos(mapa);
                else printf(red"\nLa base de datos se encuentra vacia\n"reset);
                break;
            case 8:
            printf(green"\n Compra \n"reset);
            //Concretar Compra
                break;
            case 9:
            printf(green"\n Elimininación de Autos Deseados\n"reset);
            //Eliminar Auto de la lista de Autos Deseados
                break;
            case 10:
            printf(green"\n Eliminacion de Autos Base de Datos \n"reset);
            // Eliminar Auto de la base de Datos
                break;
            case 11:
            printf(green"\n Exportar CSV \n"reset);
            //Exportar csv
                break;                                    
        }


    }while(opcion != 0);
}