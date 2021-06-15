#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aplicacion.h"

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

void importarArchivo(map* mapa){
  FILE *fp = fopen ("Vehiculos.csv", "r");
  char linea[1024];
  while(fgets (linea, 1023, fp) != NULL){
  
  char* aux;
  tipoAuto* a=(tipoAuto*)malloc(sizeof(tipoAuto));

  aux = get_csv_field(linea,0);
  strcpy(a->marca, aux);

  aux = get_csv_field(linea,1);
  strcpy(a->modelo, aux);

  a->motor = atof(get_csv_field(linea,2));
  
  aux = get_csv_field(linea,3);
  strcpy(a->condicion, aux);

  aux = get_csv_field(linea,4);
  strcpy(a->traccion, aux);

  aux = get_csv_field(linea,5);
  strcpy(a->caja, aux);

  a->año = atoi(get_csv_field(linea,6));
  
  a->precio = atol(get_csv_field(linea,7));

  a->kilometraje = atoi(get_csv_field(linea,8));

  a->combustible = atoi(get_csv_field(linea,9));

  a->puertas = atoi(get_csv_field(linea,10));

  a->pasajeros = atoi(get_csv_field(linea,11));

  aux = get_csv_field(linea,12);
  strcpy(a->comentario, aux);

  aux = get_csv_field(linea,12);
  strcpy(a->vendedor, aux);

  a->telefono = atol(get_csv_field(linea,13));

  }

}
