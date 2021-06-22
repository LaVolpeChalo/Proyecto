#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aplicacion.h"
#include "hashmap.h"

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

void importarArchivo(HashMap* mapa){
  FILE *fp = fopen ("Vehiculos.csv", "r");
  char linea[1024];
  while(fgets (linea, 1023, fp) != NULL){
  
  char* aux;
  tipoAuto* a=(tipoAuto*)malloc(sizeof(tipoAuto));
  tipoMarca* b=(tipoMarca*)malloc(sizeof(tipoMarca));
  tipoContacto* c=(tipoContacto*)malloc(sizeof(tipoContacto));

  aux = get_csv_field(linea,0);
  strcpy(a->Marca,aux);
  strcpy(b->Marca,aux);

  aux = get_csv_field(linea,1);
  strcpy(a->modelo, aux);

  a->Tipo = atoi(get_csv_field(linea,2));

  a->Motor = atof(get_csv_field(linea,3));

  a->condicion = atoi(get_csv_field(linea,4));

  a->Traccion = atoi(get_csv_field(linea,5));

  a->Caja = atoi(get_csv_field(linea,6));

  a->Año = atoi(get_csv_field(linea,7));
  
  a->Precio = atol(get_csv_field(linea,8));

  a->kilometraje = atoi(get_csv_field(linea,9));

  aux = (get_csv_field(linea,10));
  strcpy(a->combustible,aux);

  a->NumeroDePuertas = atoi(get_csv_field(linea,11));

  a->NumeroDePasajeros = atoi(get_csv_field(linea,12));
  insertMap(mapa,a->modelo,a);
  
  }

}

