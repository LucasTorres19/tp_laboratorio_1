/*
 * Salida.c
 *
 *  Created on: 13 may. 2022
 *      Author: Lucas Torres Ezequiel
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "extraFunctions.h"


void menu(){

	int frag = 0;//bandera utilizada para impedir modificar o borrar un pasajero , si no existen.
	int opcionElejida;
	int validacion = 0; // utilizada para verificar que los datos sean correctos.
	int finMenu = 0; //se utiliza para finalizar el programa.

	//crear array de pasajeros.
	int largo = 2000;
	Passenger pasajeros[largo];

	//variables  pasajero.

	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;

	//variables de calculos.
	int idElejida;
	int idobtenida;
	int aux = 0;
	float precioTotal = 0;
	int  contadorPasajeros = 0;
	float promedio = 0;
	int contadorPasajerosSuperiorPromedio = 0;


	//inicio menu.
	printf("| Aerolinea control de pasajeros|\n");

	do{

		if(frag == 0){

			//iniciar a todos en 1 en isEmply.
			initPassengers(pasajeros,largo);

		do{
			printf("1.Ingresar Pasajero.\n"
				   "2.Salir\n"
					);

			//Obtener opcion elejida.
			scanf("%d",&opcionElejida);

			validacion = validarInt(opcionElejida,1,2);

		}while(validacion == 0);

		switch(opcionElejida){

		case 1:
			//pedir datos del pasajero.
			getString(name,"Ingrese el nombre del pasajero:\n","Error:ingrese nuevamente el nombre.\n");
			getString(lastName,"Ingrese el apellido del pasajero:\n","Error:ingrese nuevamente el apellido.\n");
			getFloat(&price ,"ingrese el precio del vuelo:\n","error:ingrese nuevamente el precio.\n",1,9999);
			getString(flycode,"ingrese el codigo de vuelo(Solo letras):\n","error:ingrese nuevamente el codigo de vuelo\n");

			do{
			getInt(&typePassenger,"ingrese el tipo de pasajero(1:empleado , 2:comercial 3: primera clase):\n","error:ingrese nuevamente el tipo de pasajero.\n",1,9999);

			aux = validarInt(typePassenger,0,3);

			}
			while(aux == 0);
			aux = 0;

			//agregar el pasajero.
			addPassenger(pasajeros, largo,name,lastName,price,typePassenger,flycode);

			break;

		default:
				finMenu = 1;
				break;
		}

		frag = 1;//una vez generado un pasajero , ya se puede usar las demas opciones.
		validacion = 0;
		fflush(stdin);

		}

		else{

			do{
				printf("\n1.Ingresar Pasajero.\n");
				printf("2.Modificar Pasajero.\n");
				printf("3.Borrar Pasajero.\n");
				printf("4.informar.\n");
				printf("5.Salir.\n");

				scanf("%d",&opcionElejida);

				validacion = validarInt(opcionElejida,1,5);

			}while(validacion == 0);

			switch(opcionElejida){

					case 1:
						//pedir datos del pasajero.
						getString(name,"Ingrese el nombre del pasajero:\n","Error:ingrese nuevamente el nombre.\n");
						getString(lastName,"Ingrese el apellido del pasajero:\n","Error:ingrese nuevamente el apellido.\n");
						getFloat(&price ,"ingrese el precio del vuelo:\n","error:ingrese nuevamente el precio.\n",1,9999);
						getString(flycode,"ingrese el codigo de vuelo(Solo letras):\n","error:ingrese nuevamente el codigo de vuelo\n");

						do{
						getInt(&typePassenger,"ingrese el tipo de pasajero(1:empleado , 2:comercial 3: primera clase):\n","error:ingrese nuevamente el tipo de pasajero.\n",1,9999);

						aux = validarInt(typePassenger,0,3);

						}
						while(aux == 0);
						aux = 0;

						//agregar el pasajero.
						addPassenger(pasajeros, largo,name,lastName,price,typePassenger,flycode);

						break;

					case 2:

						getInt(&idElejida,"ingrese la id del pasajero a modificar:\n","error:ingrese nuevamente la id del pasajero.\n",1,2000);

						idobtenida = findPassengerById(pasajeros, largo,idElejida);

						if(idobtenida == -1){

							printf("El pasajero que usted quiere modificar no existe.\n");

						}else{
							printf("modificando el pasajero con id:");
							printf("%d",idElejida);
							printf("\n");

							getString(name,"Ingrese el nombre del pasajero:\n","Error:ingrese nuevamente el nombre.\n");
							getString(lastName,"Ingrese el apellido del pasajero:\n","Error:ingrese nuevamente el apellido.\n");
							getFloat(&price ,"ingrese el precio del vuelo:\n","error:ingrese nuevamente el precio.\n",1,9999);
							getString(flycode,"ingrese el codigo de vuelo(Solo letras):\n","error:ingrese nuevamente el codigo de vuelo\n");

							do{
							getInt(&typePassenger,"ingrese el tipo de pasajero(1:empleado , 2:comercial 3: primera clase:\n","error:ingrese nuevamente el tipo de pasajero.\n",1,9999);

							aux = validarInt(typePassenger,0,2);

							}
							while(aux == 0);
							aux = 0;

							modificarpasajero(idobtenida,pasajeros, largo,name,lastName,price,typePassenger,flycode);
						}

						break;

					case 3:

						getInt(&idElejida,"ingrese la id del pasajero a borrar:\n","error:ingrese nuevamente la id del pasajero.\n",1,2000);

						idobtenida = findPassengerById(pasajeros, largo,idElejida);

						if(idobtenida == -1){
							printf("El pasajero que usted quiere borrar no existe.\n");
						}else{

							removePassenger(pasajeros,largo,idElejida);
						}

						break;

					case 4:

						printf("Lista de pasajeros ordenados por tipo de pasajero (1:empleado , 2:comercial 3: primera clase) y apellido.\n");
						sortPassengers(pasajeros,largo,1);
						printPassenger(pasajeros,largo);

						//obtener total de los pasajes.
						precioTotal = obtenerTotalPrice(pasajeros,largo);
						contadorPasajeros = totalPasajeros(pasajeros,largo);
						//obtener promedio.

						promedio = precioTotal / contadorPasajeros;
						//obtener pasajeros con precio mayor al promedio.

						contadorPasajerosSuperiorPromedio = TotalPasajerosMaxN(pasajeros,largo,promedio);

						//mostrar informacion.
						printf("\nTotal de precio de los pasajes:");
						printf("%f",precioTotal);
						printf("\n");
						printf("Promedio del precio de los pasajes:");
						printf("%f",promedio);
						printf("\n");
						printf("total de pasajeros que superan el promedio:");
						printf("%d",contadorPasajerosSuperiorPromedio);
						printf("\n");

						printf("\nLista de pasajeros ordenados por Codigo de vuelo y estado de vuelo. \n");
						sortPassengersByCode(pasajeros,largo,1);
						printPassenger(pasajeros,largo);


						break;

					default:
							finMenu = 1;
							break;
					}

		}


	}while(finMenu == 0);


}
