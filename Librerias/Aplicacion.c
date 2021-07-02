#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aplicacion.h"
#include "Utilidades/TDAs/hashmap.h"
#include "Utilidades/TDAs/list.h"
#include "Utilidades/Interfaz.h"

char *get_csv_field (char * tmp, int k) {
	int open_mark = 0;
	char* ret=(char*) malloc (100*sizeof(char));
	int ini_i=0, i=0;
	int j=0;
	while(tmp[i+1]!='\0'){

		if(tmp[i]== '\"'){
			open_mark = 1-open_mark;
			if(open_mark) ini_i = i+1;
			i++;
			continue;
		}

		if(open_mark || tmp[i]!= ','){
			if(k==j) ret[i-ini_i] = tmp[i];
			i++;
			continue;
		}

		if(tmp[i]== ','){
			if(k==j) {
				ret[i-ini_i] = 0;
				return ret;
			}
			j++; ini_i = i+1;
		}

		i++;
	}

	if(k==j) {
		ret[i-ini_i] = 0;
		return ret;
	}

	return NULL;
}

/*Función encargada de convertir los ints booleanos de los datos de un auto en los strings correspondientes
  Se debe acompañar el int que se envía a la función con el numero de la conversión según sea el caso, estas
  son las siguientes:
  
  Tipo = 1
  Condición = 2
  Caja = 3
  Tracción = 4 */
char *conversion(int variable,int opcion){
  switch (opcion){

  case 1:
  
      if(variable)return "Camioneta";
      else return "Auto";

    break;

  case 2:

      if(variable) return "Usado";
      else return "Nuevo";

    break;

  case 3:

      if(variable) return "Automatico";
      else return "Manual";

    break;

  case 4:

      if(variable) return "4x4";
      else return "4x2";

    break;        
  }
}

void imprimirdatos(tipoAuto *vehiculo){

  printf(yellow"\n%s %s %s\n",conversion(vehiculo->Tipo,1),vehiculo->Marca,vehiculo->modelo,reset);
  printf("\n");
  printf(magenta"Precio: "reset);
  printf(cyan"%d$CLP",vehiculo->Precio,reset);
  printf(magenta"\tKilometraje: "reset);
  printf(cyan"%dKM",vehiculo->kilometraje,reset);
  printf(magenta"\tAno: "reset);
  printf(cyan"%d\n",vehiculo->Ano,reset);

  printf(magenta"\nCombustible: "reset);
  printf(cyan"%s",vehiculo->combustible,reset);
  printf(magenta"\tCondicion: "reset);
  printf(cyan"%s",conversion(vehiculo->condicion,2),reset);
  printf(magenta"\tCaja: "reset);
  printf(cyan"%s\n",conversion(vehiculo->Caja,3),reset);

  printf(magenta"\nNumero de puerta: "reset);
  printf(cyan"%d",vehiculo->NumeroDePuertas,reset);
  printf(magenta"\tNumero de pasajeros: "reset);
  printf(cyan"%d\n",vehiculo->NumeroDePasajeros,reset);
  
  printf(magenta"\nMotor: "reset);
  printf(cyan"%0.1f TDI",vehiculo->Motor,reset);
  printf(magenta"\tTraccion: "reset);
  printf(cyan"%s\n",conversion(vehiculo->Traccion,4),reset);
  printf("\n");

  //printf(magenta"\nComentario del vendedor:"reset);
  //printf(cyan"%s\n",vehiculo->Comentario,reset);

}



/*Función para detectar si una marca ya se encuentra en el mapa
  0 = No está dentro
  1 = Si está dentro*/
int dentro(HashMap * mapa,char *marca){

  if(mapsize(mapa)==0) return 0;

	tipoMarca *aux = searchMap(mapa,marca);

	if(aux==NULL) return 0;

	else return 1;

}

void importarArchivo(HashMap* mapa){

  char archivo[50];
  printf(cyan"\nIngrese el nombre del archivo a importar: "reset);

  getchar();
  scanf("%49[^\n]s",archivo);
  FILE *fp = fopen (archivo, "r");

    if(fp == NULL){

	  printf(red"Archivo no encontrado"reset);
      
    }else{

	    char linea[1024];
        while(fgets (linea, 1023, fp) != NULL){
  
          char* aux;
          tipoAuto* a=(tipoAuto*)malloc(sizeof(tipoAuto));
          tipoMarca* b=(tipoMarca*)malloc(sizeof(tipoMarca));
          tipoContacto* c=(tipoContacto*)malloc(sizeof(tipoContacto));

          aux = get_csv_field(linea,0);
          strcpy(a->Marca,aux);

          aux = get_csv_field(linea,1);
          strcpy(a->modelo, aux);

          a->Tipo = atoi(get_csv_field(linea,2));

          a->Motor = atof(get_csv_field(linea,3));

          a->condicion = atoi(get_csv_field(linea,4));

          a->Traccion = atoi(get_csv_field(linea,5));

          a->Caja = atoi(get_csv_field(linea,6));

          a->Ano = atoi(get_csv_field(linea,7));
  
          a->Precio = atol(get_csv_field(linea,8));

          a->kilometraje = atoi(get_csv_field(linea,9));

          aux = (get_csv_field(linea,10));
          strcpy(a->combustible,aux);

          a->NumeroDePuertas = atoi(get_csv_field(linea,11));

          a->NumeroDePasajeros = atoi(get_csv_field(linea,12));

        // Multimapa los mapas de aqui abajo

          if(dentro(mapa,a->Marca)){

            tipoMarca *puntero = searchMap(mapa,a->Marca);
            insertMap(puntero->Autos,a->modelo,a);
            //printf("Marca vieja - ");

          }else{

            tipoMarca *puntero = (tipoMarca*)calloc(1,sizeof(tipoMarca));
            puntero->Autos = createMap(10);
            strcpy(puntero->Marca,a->Marca);
            insertMap(mapa,a->Marca,puntero);
            insertMap(puntero->Autos,a->modelo,a);

          }
        }

    printf(green"\nArchivo importado correctamente\n"reset);

    }
}

//Funcion para ingreso de nuevo auto a Mapa
tipoAuto* crearAuto(char* Marca, char* modelo, int Tipo, float Motor, int condicion, int traccion, int Caja, int anno, long int Precio, int kilometraje, char* combustible, int puertas, int pasajeros ){

  tipoAuto* auxauto=(tipoAuto*)malloc(sizeof(tipoAuto));

  strcpy(auxauto->Marca,Marca);
  strcpy(auxauto->modelo,modelo);
  auxauto->Tipo=Tipo;
  auxauto->Motor=Motor;
  auxauto->condicion=condicion;
  auxauto->Traccion=traccion;
  auxauto->Caja=Caja;
  auxauto->Ano=anno;
  auxauto->Precio=Precio;
  auxauto->kilometraje=kilometraje;
  strcpy(auxauto->combustible,combustible);
  auxauto->NumeroDePuertas=puertas;
  auxauto->NumeroDePasajeros=pasajeros;

  return auxauto;

}



/*void * buscar_auto(HashMap* mapa);

void busca_auto_nombre(HashMap* mapa){
  char* modelo;
  printf(cyan"\nIngrese el modelo del vehiculo que quiere buscar: "reset);
  scanf("%s",modelo);
  tipoMarca* auxmarca=(tipoMarca*)malloc(sizeof(tipoMarca));
  tipoAuto* automovil = searchMap(auxmarca->Autos,modelo);
  printf("\n%s\n",automovil->modelo);
  auxmarca = searchMap(mapa,automovil->Marca);

  while(automovil!=NULL){

    if(strcmp(automovil->modelo,modelo)==0){
      imprimirdatos(automovil);
    }
    automovil = nextMap(auxmarca->Autos);
  }
}*/

void agregar_auto(HashMap* mapa){

  int Tipo;	//(si es 0 es auto, si es 1 es camioneta)
  int condicion;	//(0 nuevo, 1 usado)
  int Ano;
  long int Precio;
  int Caja;	//(0 manual, 1 automático)
  int NumeroDePuertas;
  int NumeroDePasajeros;
  char Marca[20];
  int Traccion; //(0 si es 4x2, 1 si es 4x4)
  float Motor;
  char combustible[10];
  int kilometraje; 
  char Comentario[301];
  char modelo[50];

  printf(cyan"\nIngrese la marca de su nuevo vehiculo: "reset);
  scanf("%s",Marca);
  printf(cyan"Ingrese el modelo de su nuevo vehiculo: "reset);
  scanf("%s",modelo);
  printf(cyan"Ingrese el tipo de su auto ( 0 si es auto, 1 si es camioneta ): "reset);
  scanf("%d",&Tipo);
  printf(cyan"Ingrese el motor de su nuevo vehiculo: "reset);
  scanf("%f",&Motor);
  printf(cyan"Ingrese la condicion en la que se encuentra su vehiculo( 0 si es nuevo, 1 si es usado ): "reset);
  scanf("%d",&condicion);
  printf(cyan"Ingrese la traccion de su vehiculo(0 si es 4x2, 1 si es 4x4): "reset);
  scanf("%d",&Traccion);
  printf(cyan"Ingrese la caja de cambios de su vehiculo(0 si es manual, 1 si es automático): "reset);
  scanf("%d",&Caja);
  printf(cyan"Ingrese el anno de salida de su nuevo vehiculo: "reset);
  scanf("%d",&Ano);
  printf(cyan"Ingrese el valor de su nuevo vehiculo: "reset);
  scanf("%ld",&Precio);
  printf(cyan"Ingrese el kilometraje de su nuevo vehiculo: "reset);
  scanf("%d",&kilometraje);
  printf(cyan"Ingrese el tipo de combustible acorde a su nuevo vehiculo: "reset);
  scanf("%s",combustible);
  printf(cyan"Ingrese el numero de puertas: "reset);
  scanf("%d",&NumeroDePuertas);
  printf(cyan"Ingrese la cantidad de pasajeros: "reset);
  scanf("%d",&NumeroDePasajeros);

  tipoAuto* nuevoAuto=crearAuto(Marca,modelo,Tipo,Motor,condicion,Traccion,Caja,Ano,Precio,kilometraje,combustible,NumeroDePuertas,NumeroDePasajeros);

          if(dentro(mapa,nuevoAuto->Marca)){

            tipoMarca *puntero = searchMap(mapa,nuevoAuto->Marca);
            insertMap(puntero->Autos,nuevoAuto->modelo,nuevoAuto);
            

          }else{

            tipoMarca *puntero = (tipoMarca*)calloc(1,sizeof(tipoMarca));
            puntero->Autos = createMap(10);
            strcpy(puntero->Marca,nuevoAuto->Marca);
            insertMap(mapa,nuevoAuto->Marca,puntero);
            insertMap(puntero->Autos,nuevoAuto->modelo,nuevoAuto);

          }
        

}

/*void ingresar_auto_lista();

void lista_autos();*/

void desplegarautos(HashMap * mapa){
	///Primero haré que recorra los mapas así nomas y luego me encargare de la impresión por alfabeto
  tipoMarca *auxmarca = firstMap(mapa);
  tipoAuto *auxtos;


  for(int i = 0;i < mapsize(mapa);i++){

    printf(green"\n%s\n",auxmarca->Marca,reset);

    auxtos = firstMap(auxmarca->Autos);

    for(int j = 0;j < mapsize(auxmarca->Autos)-1;j++){

      imprimirdatos(auxtos);
      auxtos = nextMap(auxmarca->Autos);

    }

    auxmarca = nextMap(mapa); 

  }

}
//void concretar_compra();

void eliminar_auto_lista(list * lista){
printf(green "Seleccione el modelo del auto que necesita eliminar"reset);
char modelo[50];
tipoAuto* aux=firstList(lista);
scanf("%s", modelo);
getchar();

	while (aux != NULL) {  
		if (strcmp (aux->modelo,modelo) == 0) {
			tipoAuto *b = popCurrent(lista);
			free(aux);
			break;
		}

    aux=nextList(lista);

  }
}

/*void eliminar_auto_base(HashMap * mapa){
  printf(green "Seleccione un auto por modelo que desea eliminar"reset);
  char * modelo[50];
  scanf("%s", modelo);
  buscado =  * busca_auto_nombre(modelo);
  while(buscado =! mapa){
    nextmap(mapa)
  }

}

*/

