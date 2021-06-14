#ifndef Aplicacion_h
#define Aplicacion_h

typedef struct{
  
  char marca[20];
  char modelo[20];
  float motor;
  char condicion[20];
  char traccion[20];
  char caja[20];
  int año;
  long int precio;
  int kilometraje;
  int combustible;
  int puertas;
  int pasajeros;
  char comentario[301];
  char vendedor[30];
  long int telefono;

}tipoAuto

void importarArchivo(map* mapa);




#endif