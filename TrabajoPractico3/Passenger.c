/*
 * Passenger.c
 *
 *  Created on: 9 jun. 2022
 *      Author: liqui
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		strcpy(apellido,this->nombre);
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
