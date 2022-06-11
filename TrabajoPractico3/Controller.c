#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "extraFunctions.h"
/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	FILE* pfile;

	//abrir el archivo.
	pfile = fopen(path,"r");

	if(pfile == NULL){

		printf("Ocurrio un error al abrir el archivo\n");
		exit(EXIT_FAILURE);
	}

	//llamamos a la funcion que intruduce los pasajeros.
	if(parser_PassengerFromText(pfile,pArrayListPassenger) == 1){
		retorno = 1;
	}

	fclose(pfile);

	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* bin;
	int retorno = 0;

	if((bin=fopen(path,"rb")) ==NULL){
		printf("Error al intentar abrir el archivo.");
		exit(EXIT_FAILURE);

	}

	if(parser_PassengerFromBinary(bin,pArrayListPassenger) == 1){

		retorno = 1;
		printf("\nPasajeros cargados con exito.\n\n");
	}

	fclose(bin);

    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{

	//variables.
	int id;
	char idStr[50];
	char nombre[50];
	char apellido[50];
	float price;
	char priceStr[10];
	char codigoVuelo[8];
	char tipoPasajero[50];
	int auxtipo;
	char statusFlight[50];
	int auxstatusflight;
	int largo = ll_len(pArrayListPassenger);

	Passenger* passenger;

	//pedir datos.
	getString(nombre,"Ingrese el nombre del pasajero:\n","Error:ingrese nuevamente el nombre.\n");
	getString(apellido,"Ingrese el apellido del pasajero:\n","Error:ingrese nuevamente el apellido.\n");
	getFloat(&price,"ingrese el precio del vuelo:\n","error:ingrese nuevamente el precio.\n",1,9999);
	getString(codigoVuelo,"ingrese el codigo de vuelo:\n","error:ingrese nuevamente el codigo de vuelo\n");
	getInt(&auxtipo,"ingrese el tipo de pasajero(1:EconomyClass, 2:ExecutiveClass 3:FirstClass):\n","error:ingrese nuevamente el tipo de pasajero.\n",1,3);
	getInt(&auxstatusflight,"ingrese el estado del vuelo(1:En Vuelo , 2:En Horario 3: Aterrizado 4:Demorado):\n","error:ingrese nuevamente el estado.\n",1,4);

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

		if(largo == 0){
			id = 1;
		}
		else{
			id = largo + 1;
		}

		itoa(id,idStr,10);
		itoa(price,priceStr,10);

		//crear el pasajero.

		passenger = Passenger_newParametros(idStr,nombre,apellido,priceStr,codigoVuelo,tipoPasajero,statusFlight);

		//agregar a la lista.
		ll_add(pArrayListPassenger,passenger);

		printf("Pasajero agregado con exito.\n\n");
    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int id;
		int auxId = 0;
		int largo = ll_len(pArrayListPassenger);
		int retorno = 0;
		Passenger* passenger;

		//pedir la id.
		getInt(&id,"ingrese la id del Pasajero a eliminar:\n","error:ingrese una id valida.\n",1,largo);

		//recorrer los pasajeros hasta encontrar el que coincida la id.
		for(int i = 0;i < largo;i++){

			passenger = (Passenger*) ll_get(pArrayListPassenger,i);
			Passenger_getId(passenger,&auxId);

			//editar el pasajero cuando se encuentra.
			if(auxId == id){

				Passenger_edit(passenger);
				retorno = 1;
				printf("Pasajero con la id:");
				printf("%d",id);
				printf(" editado con exito.\n\n");
				break;
			}

		}

    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int id;
	int auxId = 0;
	int largo = ll_len(pArrayListPassenger);
	int retorno = 0;
	Passenger* passenger;

	//pedir la id.
	getInt(&id,"ingrese la id del Pasajero a eliminar:\n","error:ingrese una id valida.\n",1,largo);

	//recorrer los pasajeros hasta encontrar el que coincida la id.
	for(int i = 0;i < largo;i++){

		passenger = (Passenger*) ll_get(pArrayListPassenger,i);
		Passenger_getId(passenger,&auxId);

		//eliminar el pasajero cuando se encuentra.
		if(auxId == id){
			ll_remove(pArrayListPassenger,i);
			retorno = 1;
			printf("Pasajero con la id:");
			printf("%d",id);
			printf(" elimiado con exito.\n\n");
			break;
		}

	}

    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno  = 0;
	Passenger* passenger;

	if(pArrayListPassenger != NULL){

		for(int i = 0; i < ll_len(pArrayListPassenger);i++){

			passenger = (Passenger*) ll_get(pArrayListPassenger,i);
			Passenger_print(passenger);

		}

		printf("\n");
	}

    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{

	ll_sort(pArrayListPassenger,Passenger_SortApellido,1);

	printf("lista ordenada por apellido.\n\n");

    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pfile;
	int tamanoLista = ll_len(pArrayListPassenger);
	int retorno = 0;
	int id;
	char idStr[10];
	float price;
	char priceStr[10];
	char nombre[50];
	char apellido[50];
	char codigoVuelo[8];
	char  tipoPasajero[50];
	char statusflight[50];


	Passenger* passenger;

	//abrir el archivo.
	pfile = fopen(path,"w");

	if(pfile == NULL){
		printf("Ocurrio un error al abrir el archivo\n");
		exit(EXIT_FAILURE);
	}
	else{
		for(int i = 0;i < tamanoLista;i++){

			passenger =ll_get(pArrayListPassenger,i);

			Passenger_getId(passenger,&id);
			Passenger_getNombre(passenger,nombre);
			Passenger_getApellido(passenger,apellido);
			Passenger_getPrecio(passenger,&price);
			Passenger_getTipoPasajero(passenger,tipoPasajero);
			Passenger_getCodigoVuelo(passenger,codigoVuelo);
			Passenger_getstatusflight(passenger,statusflight);

			itoa(id,idStr,10);
			itoa(price,priceStr,10);

			fwrite(idStr,sizeof(char),strlen(idStr),pfile);
			fwrite(",",sizeof(char),1,pfile);
			fwrite(nombre,sizeof(char),strlen(nombre),pfile);
			fwrite(",",sizeof(char),1,pfile);
			fwrite(apellido,sizeof(char),strlen(apellido),pfile);
			fwrite(",",sizeof(char),1,pfile);
			fwrite(priceStr,sizeof(char),strlen(priceStr),pfile);
			fwrite(",",sizeof(char),1,pfile);
			fwrite(tipoPasajero,sizeof(char),strlen(tipoPasajero),pfile);
			fwrite(",",sizeof(char),1,pfile);
			fwrite(codigoVuelo,sizeof(char),strlen(codigoVuelo),pfile);
			fwrite(",",sizeof(char),1,pfile);
			fwrite(statusflight,sizeof(char),strlen(statusflight),pfile);
			fwrite("\n",sizeof(char),1,pfile);
		}
		retorno = 1;

		printf("\n Pasajeros guardados con exito en un archivo(txt)\n");
	}
	fclose(pfile);

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pfile;
	int tamanoLista = ll_len(pArrayListPassenger);
	int retorno = 0;

	Passenger* passenger;

	//abrir el archivo.
	pfile = fopen(path,"wb");

	if(pfile == NULL){
		printf("Ocurrio un error al abrir el archivo\n");
		exit(EXIT_FAILURE);
	}
	else{
		//recorre la lista.
		for(int i = 0;i < tamanoLista;i++){

			//consegui cada pasajero y lo escribe en el archivo.
			passenger =(Passenger*) ll_get(pArrayListPassenger,i);

			fwrite(passenger,sizeof(Passenger),1,pfile);

		}
		retorno = 1;
		printf("\n Pasajeros guardados con exito en un archivo(bin)\n");
	}
	fclose(pfile);

    return retorno;
}

