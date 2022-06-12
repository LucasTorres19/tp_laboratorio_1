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

/** \brief Passenger_new
 * crea un nuevo pasajero.
 * return Passenger*
 */

Passenger* Passenger_new();
/** \brief Passenger_newparametros
 * esta funcion crea un nuevo pasajero con todos los datos.
 * \param char* idStr
 * \param char* nombreStr
 * \param char* apellidoStr
 * \param char* FloatStr
 * \param char* codigoVueloStr
 * \param char* TipoPasjeroStr
 * \param char* *statusflightStr
 * \return Passenger* this
 *
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr ,char* floatStr ,char* codigoVueloStr,char* tipoPasajeroStr,char*statusflightStr);

/** \brief Passenger_delete
 * esta funcion elimina un pasajero.
 * \param Passenger* this
 * \return void
 *
 */
void Passenger_delete(Passenger* this);

//getters y setters.
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

/** \brief Passenger_print
 * esta funcion imprime todo los datos de un pasajero.
 * \param Passenger* this
 * \return void
 *
 */
void Passenger_print(Passenger* this);

/** \brief ColocarId
 * verifica cuantas id da y le da una id al pasajero.
 * \param LinkedList* pArrayListPassenger
 * \param Passenger* this
 * \return void
 *
 */

void colocarId(LinkedList* pArrayListPassenger , Passenger* this);

/** \brief Passenger_edit
 * Esta funcion edita un pasajero.
 * \param Passenger* this
 * \return void
 *
 */
void Passenger_edit(Passenger* this);

/** \brief Passenger_sortApellido
 * esta funcion toma 2 pasajeros para comprar sus apellidos y devolver si es mayor menor igual.
 * \param void* passenger1
 * \param void* passenger1
 * \return int
 *
 */
int Passenger_SortApellido(void* passenger1 , void* passenger2);

#endif /* PASSENGER_H_ */
