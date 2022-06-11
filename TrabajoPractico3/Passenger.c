/*
 * Passenger.c
 *
 *  Created on: 9 jun. 2022
 *      Author: liqui
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "extraFunctions.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	char  tipoPasajero[50];
	char statusflight[50];

}Passenger;

Passenger* Passenger_new(){

	Passenger* newPassenger = NULL;
	newPassenger = (Passenger*) malloc(sizeof(Passenger));

	if(newPassenger != NULL){

		newPassenger->id = 0;
		strcpy(newPassenger->nombre, " ");
		strcpy(newPassenger->apellido, " ");
		newPassenger->precio = 0;
		strcpy(newPassenger->codigoVuelo, " ");
		strcpy(newPassenger->tipoPasajero, " ");
		strcpy(newPassenger->statusflight," ");

	}

	return newPassenger;
}

void Passenger_delete(Passenger* this){

	if(this != NULL)
		{
			free(this);
		}
}

int Passenger_setId(Passenger* this,int id){

	int retorno = 0;

	if(this != NULL && id > 0){
		this->id = id;
		retorno = 1;
	}

	return retorno;
}
int Passenger_getId(Passenger* this,int* id){

	int retorno = 0;

	if(this != NULL && id != NULL){
		*id = this->id;
		retorno = 0;

	}

	return retorno;

}

int Passenger_setNombre(Passenger* this,char* nombre){

	int retorno = 0;

		if(this != NULL && nombre != NULL){
			strcpy(this->nombre,nombre);
			retorno = 1;
		}

		return retorno;

}
int Passenger_getNombre(Passenger* this,char* nombre){

		int retorno = 0;

		if(this != NULL && nombre != NULL){
			strcpy(nombre,this->nombre);
			retorno = 0;

		}

		return retorno;

}


int Passenger_setApellido(Passenger* this,char* apellido){

	int retorno = 0;

	if(this != NULL && apellido != NULL){
		strcpy(this->apellido,apellido);
		retorno = 1;
	}

	return retorno;

}
int Passenger_getApellido(Passenger* this,char* apellido){
	int retorno = 0;

	if(this != NULL && apellido != NULL){
		strcpy(apellido,this->apellido);
		retorno = 0;
	}

	return retorno;

}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){

	int retorno = 0;

	if(this != NULL && codigoVuelo != NULL){
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno = 1;
	}

	return retorno;

}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){

	int retorno = 0;

		if(this != NULL && codigoVuelo != NULL){
			strcpy(codigoVuelo,this->codigoVuelo);
			retorno = 0;
		}

		return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero){

	int retorno = 0;

	if(this != NULL &&  tipoPasajero != NULL ){

		strcpy(this->tipoPasajero,tipoPasajero);
		retorno = 1;
	}

	return retorno;

}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero){
	int retorno = 0;

			if(this != NULL && tipoPasajero != NULL){
				strcpy(tipoPasajero,this->tipoPasajero);
				retorno = 0;
			}

	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio){

	int retorno = 0;

		if(this != NULL && precio > 0){
			this->precio = precio;
			retorno = 1;
		}

	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio){

	int retorno = 0;

		if(this != NULL && precio != NULL){
			*precio = this->precio;
			retorno = 0;

		}

		return retorno;


}

int Passenger_setstatusflight(Passenger* this,char* statusflight){

	int retorno = 0;

		if(this != NULL &&  statusflight != NULL ){

			strcpy(this->statusflight,statusflight);
			retorno = 1;
		}

	return retorno;
}
int Passenger_getstatusflight(Passenger* this,char* statusflight){

	int retorno = 0;

	if(this != NULL && statusflight != NULL){
		strcpy(statusflight,this->statusflight);
		retorno = 0;
	}

		return retorno;
}


Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr ,char* precioStr ,char* codigoVueloStr,char* tipoPasajeroStr,char* statusflightStr ){

	Passenger* newPassenger = Passenger_new();

	if(newPassenger != NULL){

		if(
			Passenger_setId(newPassenger,atoi(idStr)) != 0 &&
			Passenger_setNombre(newPassenger,nombreStr) != 0 &&
			Passenger_setApellido(newPassenger,apellidoStr) != 0 &&
			Passenger_setPrecio(newPassenger,atof(precioStr)) != 0 &&
			Passenger_setCodigoVuelo(newPassenger,codigoVueloStr) != 0 &&
			Passenger_setTipoPasajero(newPassenger,tipoPasajeroStr) != 0 &&
			Passenger_setstatusflight(newPassenger,statusflightStr)

		){
			return newPassenger;
		}else{
			newPassenger = NULL;
		}
	}

	return newPassenger;
}

void Passenger_print(Passenger* this){

	int id;
	float precio;
	char nombre[50];
	char apellido[50];
	char tipoPasajero[50];
	char codigoVuelo[50];
	char statusFlight[50];


	Passenger_getId(this,&id);
	Passenger_getNombre(this,nombre);
	Passenger_getApellido(this,apellido);
	Passenger_getPrecio(this,&precio);
	Passenger_getTipoPasajero(this,tipoPasajero);
	Passenger_getCodigoVuelo(this,codigoVuelo);
	Passenger_getstatusflight(this,statusFlight);


	printf("%d %s %s %.2f %s %s %s",id,nombre,apellido,precio,tipoPasajero,codigoVuelo,statusFlight);
	printf("\n");



}

void colocarId(LinkedList* pArrayListPassenger , Passenger* this){

	int largo;
	int id = 1;

	largo = ll_len(pArrayListPassenger);

	id += largo;

	Passenger_setId(this,id);

}

void Passenger_edit(Passenger* this){

	char nombre[50];
	char apellido[50];
	char codigoVuelo[50];
	char tipoPasajero[50];
	char statusFlight[50];
	float precio;
	int auxstatusflight;
	int auxtipo;

	getString(nombre,"Ingrese el nombre del pasajero:\n","Error:ingrese nuevamente el nombre.\n");
	getString(apellido,"Ingrese el apellido del pasajero:\n","Error:ingrese nuevamente el apellido.\n");
	getFloat(&precio,"ingrese el precio del vuelo:\n","error:ingrese nuevamente el precio.\n",1,9999);
	getString(codigoVuelo,"ingrese el codigo de vuelo:\n","error:ingrese nuevamente el codigo de vuelo\n");
	getInt(&auxtipo,"ingrese el tipo de pasajero(1:EconomyClass, 2:ExecutiveClass 3:FirstClass):\n","error:ingrese nuevamente el tipo de pasajero.\n",1,3);
	getInt(&auxstatusflight,"ingrese el estado del vuelo(1:En Vuelo , 2:En Horario ,3: Aterrizado,, 4:Demorado):\n","error:ingrese nuevamente el estado.\n",1,4);

	//obtener datos.
		switch(auxtipo){
		case 1:
			strcpy(tipoPasajero,"EconomyClass");
			break;
		case 2:
			strcpy(tipoPasajero,"ExecutiveClass");
			break;
		case 3:
			strcpy(tipoPasajero,"FirstClass");
			break;
		}

		switch(auxstatusflight){
			case 1:
				strcpy(statusFlight,"En Vuelo");
				break;
			case 2:
				strcpy(statusFlight,"En Horario");
				break;
			case 3:
				strcpy(statusFlight,"Aterrizado");
				break;
			case 4:
				strcpy(statusFlight,"Demorado");
				break;
			}

		//cambiar los datos.
		Passenger_setNombre(this,nombre);
		Passenger_setApellido(this,apellido);
		Passenger_setCodigoVuelo(this,codigoVuelo);
		Passenger_setTipoPasajero(this,tipoPasajero);
		Passenger_setPrecio(this,precio);
		Passenger_setstatusflight(this,statusFlight);
}

int Passenger_SortApellido(void* passenger1 , void* passenger2){

	int retorno = 0;
	char apellido1[50], apellido2[50];

	if(passenger1 !=NULL && passenger2 != NULL){

		if(Passenger_getApellido(passenger1,apellido1) == 0 &&
		   Passenger_getApellido(passenger2,apellido2) == 0){

			retorno = strcmp(apellido1,apellido2);

		}
	}

	return retorno;
}
