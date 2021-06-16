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
    printf(cyan" Importar csv\n"reset);
    printf(magenta"2."reset); 
    printf(cyan" Buscar Vehiculos\n"reset);
    printf(magenta"3."reset);
    printf(cyan" Buscar Vehiculo por nombre\n"reset);
    printf(magenta"4."reset);
    printf(cyan" Agregar Vehiculo\n"reset);
    printf(magenta"5."reset);
    printf(cyan" Ingresar Auto a lista de Autos Deseados\n"reset);
    printf(magenta"6."reset);
    printf(cyan" Desplegar lista de Autos Deseados\n"reset);
    printf(magenta"7."reset);
    printf(cyan" Desplegar todos los autos\n"reset);
    printf(magenta"8."reset);
    printf(cyan" Concretar Compra\n"reset);
    printf(magenta"9."reset);
    printf(cyan" Eliminar Auto de la lista de Autos Deseados\n"reset);
    printf(magenta"10."reset);
    printf(cyan" Eliminar Auto de la base de Datos\n"reset);
    printf(magenta"11."reset);
    printf(cyan" Exportar csv\n"reset);
    printf(magenta"0."reset);
    printf(cyan" Salir del Programa\n"reset);
}