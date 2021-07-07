#ifndef Aplicacion_h
#define Aplicacion_h
#include "Utilidades/TDAs/hashmap.h"
#include "Utilidades/TDAs/list.h"

typedef struct{
   char Vendedor[50];
   int numero;

}tipoContacto;

typedef struct{
  
  int Tipo;	//(si es 0 es auto, si es 1 es camioneta)
  int condicion;	//(0 nuevo, 1 usado)
  int Ano;
  int Precio;
  int Caja;	//(0 manual, 1 automático)
  int NumeroDePuertas;
  int NumeroDePasajeros;
  char Marca[20];
  int Traccion; //(0 si es 4x2, 1 si es 4x4)
  float Motor;
  char combustible[10];
  int kilometraje; 
  char Comentario[301];
  tipoContacto contacto;
  int key;
  char modelo[50];   


}tipoAuto;

typedef struct{
  int key;
  HashMap *Autos;
  char Marca[20];

}tipoMarca;


void importarArchivo(HashMap* mapa);
void busca_auto_nombre();
void agregar_auto();
void ingresar_auto_lista(list * lista);
void lista_autos(list * lista);
void desplegarautos(HashMap* mapa);
void concretar_compra();
void eliminar_auto_lista();
void eliminar_auto_base();
void exportar_csv();
void imprimirdatos(tipoAuto *vehiculo);



#endif