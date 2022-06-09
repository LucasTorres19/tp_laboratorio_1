#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int r;
	char id[50],price[50],nombre[50],apellido[50],flycode[50],typePassenger[50],StatusFlight[50];
	Passenger * passenger;

	if(pFile != NULL){

		if(pArrayListPassenger != NULL){

			//lectura fantasma.
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,price,flycode,typePassenger,StatusFlight);

			while(1){

			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,price,flycode,typePassenger,StatusFlight);

			//verificar que haya leido la cantidad correcta de campos.
			if(r == 7){

				passenger = Passenger_newParametros(id,nombre,apellido,price,flycode,typePassenger,StatusFlight);

				if(passenger != NULL){
					ll_add(pArrayListPassenger,passenger);
				}

			}

			//dejar de leer el archivo.
			if(feof(pFile) != 0){
				printf("Datos Cargados con exito.\n");
				return 1;
			}

			}
		}
	}

	return 0;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
