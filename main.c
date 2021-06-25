#include <stdio.h>
#include <stdlib.h>
#include "Librerias/TDAs/hashmap.h"
#include "Librerias/Interfaz/Interfaz.h"
#include "Librerias/Aplicacion.h"
#include "Librerias/TDAs/list.h"

int main(){
    HashMap* mapa=createMap(85);
    HashMap* mapa2=createMap(85);
    list* lista=createList();
    tipoMarca* mapaMarca=(tipoMarca*)malloc(sizeof(tipoMarca));
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
            //Buscar Vehiculos
            printf(green"\n Buscar Vehiculo \n"reset);
            void busca_auto_nombre();
                break;
            case 3:
            //Buscar Vehiculos por nombre
            printf(green"\n Buscar Vehiculo por Nombre \n"reset);
            void * buscar_auto(HashMap* mapa);
                break;
            case 4:
            //Agregar Vehiculo
            printf(green"\n Agregar Vehiculo\n"reset);
            void agregar_auto();
                break;
            case 5:
            //Ingresar Auto a lista de Autos Deseados
            printf(green"\n Ingresar Auto a Lista de Autos Deseados\n"reset);
            void ingresar_auto_lista();
                break;
            case 6:
            //Desplegar lista de Autos Deseados
            printf(green"\n Lista de Autos Deseados \n"reset);
            void lista_autos();
                break; 
            case 7: 
            //Desplegar Todos los autos
            printf(green"\n Todos los autos \n"reset);
                if(mapsize(mapa2) != 0) desplegarautos(mapa);
                else printf(red"\nLa base de datos se encuentra vacia\n"reset);
                break;
            case 8:
            //Concretar Compra
            printf(green"\n Compra \n"reset);
            void concretar_compra();
                break;
            case 9:
            //Eliminar Auto de la lista de Autos Deseados
            printf(green"\n Elimininación de Autos Deseados\n"reset);
            void eliminar_auto_lista();
                break;
            case 10:
            // Eliminar Auto de la base de Datos
            printf(green"\n Eliminacion de Autos Base de Datos \n"reset);
            void eliminar_auto_base();
                break;
            case 11:
            //Exportar csv
            printf(green"\n Exportar CSV \n"reset);
            void exportar_csv();
                break;                                   
        }


    }while(opcion != 0);
}