#include <stdio.h>

#define reset "\e[0m"  
#define black "\e[90m"
#define red "\e[91m"
#define green "\e[92m"
#define yellow "\e[93m"
#define blue "\e[94m"
#define magenta "\e[95m"
#define cyan "\e[96m"
#define white "\e[97m"

void desplegarMenu(){

    printf(magenta"\nMenu principal\n"reset);

    printf(magenta"\n1."reset);
    printf(" Importar csv\n");
    printf(magenta"2."reset); 
    printf(" Buscar Vehiculos\n");
    printf(magenta"3."reset);
    printf(" Buscar Vehiculo por nombre\n");
    printf(magenta"4."reset);
    printf(" Agregar Vehiculo\n");
    printf(magenta"5."reset);
    printf(" Ingresar Auto a lista de Autos Deseados\n");
    printf(magenta"6."reset);
    printf(" Desplegar lista de Autos Deseados\n");
    printf(magenta"7."reset);
    printf(" Desplegar todos los autos\n");
    printf(magenta"8."reset);
    printf(" Concretar Compra\n");
    printf(magenta"9."reset);
    printf(" Eliminar Auto de la lista de Autos Deseados\n");
    printf(magenta"10."reset);
    printf(" Eliminar Auto de la base de Datos\n");
    printf(magenta"11."reset);
    printf(" Exportar csv\n");
    printf(magenta"0."reset);
    printf(" Salir del Programa\n");
}