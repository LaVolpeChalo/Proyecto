#ifndef Aplicacion_h
#define Aplicacion_h
#include "TDAs/hashmap.h"
#include "TDAs/list.h"

typedef struct{
   char Vendedor[50];
   int numero;

}tipoContacto;

typedef struct{
  
  int Tipo;	//(si es 0 es auto, si es 1 es camioneta)
  int condicion;	//(1 usado, 0 nuevo)
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
void desplegarautos(HashMap* mapa);





#endif