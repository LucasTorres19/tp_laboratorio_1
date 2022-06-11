/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	float precio;
	char nombre[50];
	char apellido[50];
	char codigoVuelo[8];
	char  tipoPasajero[50];
	char statusflight[50];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr ,char* floatStr ,char* codigoVueloStr,char* tipoPasajeroStr,char*statusflightStr);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setstatusflight(Passenger* this,char statusflight);
int Passenger_getstatusflight(Passenger* this,char* statusflight);

//funciones propias.
void Passenger_print(Passenger* this);
void colocarId(LinkedList* pArrayListPassenger , Passenger* this);
void Passenger_edit(Passenger* this);
int Passenger_SortApellido(void* passenger1 , void* passenger2);

#endif /* PASSENGER_H_ */
