#include <stdio.h>
#include <stdlib.h>
#include "Librerias/Utilidades/TDAs/hashmap.h"
#include "Librerias/Utilidades/Interfaz.h"
#include "Librerias/Aplicacion.h"
#include "Librerias/Utilidades/TDAs/list.h"
#include "Librerias/filtros.h"

int main(){
    HashMap* mapa=createMap(200);
    list* lista=createList();

    short opcion;

    do{

        desplegarMenu();

        //Elección de la opción del menu
        printf("\nElija una opcion: ");
        scanf("%hi", &opcion);
        if(opcion == 0) break;
        
        switch(opcion){
            case 1: printf(magenta"\nImportacion de archivo \n"reset);
                importarArchivo(mapa);
                break;
            case 2:
            //Buscar Vehiculos
                if(mapsize(mapa) != 0){
                    printf(magenta"\nBuscar Vehiculos por filtro\n"reset);
                    filtrar_autos(mapa);

                }
                else printf(red"\nLa base de datos se encuentra vacia\n"reset);
                break;
            case 3:
            //Buscar Vehiculos por nombre
            printf(magenta"\n Buscar Vehiculo por Nombre \n"reset);
             busca_auto_nombre(mapa);
                break;
            case 4:
            //Agregar Vehiculo
            printf(magenta"\n Agregar Vehiculo\n"reset);
             agregar_auto(mapa);
                break;
            case 5:
            //Ingresar Auto a lista de Autos Deseados
            printf(magenta"\n Ingresar Auto a Lista de Autos Deseados\n"reset);
            ingresar_auto_lista(lista,mapa);
                break;
            case 6:
            //Desplegar lista de Autos Deseados
            printf(magenta"\n Lista de Autos Deseados \n"reset);
            lista_autos(lista);
                break; 
            case 7: 
            //Desplegar Todos los autos
                if(mapsize(mapa) != 0){

                    printf(magenta"\nTodos los autos \n"reset);
                    desplegarautos(mapa);
                    
                }
                else printf(red"\nLa base de datos se encuentra vacia\n"reset);
                break;
            case 8:
            //Concretar Compra
            printf(magenta"\nCompra \n"reset);
            concretar_compra(mapa);
                break;
            case 9:
            //Eliminar Auto de la lista de Autos Deseados
            printf(magenta"\n Elimininación de Autos Deseados\n"reset);
             eliminar_auto_lista(lista);
                break;
            case 10:
            // Eliminar Auto de la base de Datos
            printf(magenta"\n Eliminacion de Autos Base de Datos \n"reset);
             eliminar_auto_base(mapa);
                break;
            case 11:
            //Exportar csv
            printf(magenta"\n Exportar CSV \n"reset);
            void exportar_csv();
                break; 
            case 0:

            printf(green"\nCerrando aplicacion\n"reset);
                break;

            default: 

            printf(red"\nIngrese una opcion valida\n"reset); 
                break;                                      
        }


    }while(opcion != 0);
}