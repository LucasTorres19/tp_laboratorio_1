#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "extraFunctions.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

	//variables
    int option = 0;
    int banderaCarga = 0;
    //creando la linkedlist
    LinkedList* listaPasajeros = ll_newLinkedList();


    printf("|Aerolineas| \n");

    do{

    	if(banderaCarga == 1){

			printf("1.Cargar los datos de los pasajeros desde el archivo(txt)\n"
				   "2.Cargar los datos de los pasajeros desde el archivo(bin)\n"
					"3.Alta de pasajero.\n"
					"4.Modificar datos de pasajero\n"
					"5.Baja de pasajero.\n"
					"6.Listar pasajeros.\n"
					"7. Ordenar pasajeros\n"
					"8. Guardar los datos de los pasajeros en el archivo(txt)\n"
					"9. Guardar los datos de los pasajeros en el archivo(bin)\n"
					"10.Salir\n"
			);

			//pedir la opcion.
			getInt(&option,"ingrese una opcion:","Error. ingrese nuevamente la opcion.\n",1,10);


			switch(option)
			{
				case 1:
					controller_loadFromText("data.csv",listaPasajeros);
					break;
				case 2:
					controller_loadFromBinary("bin.dat",listaPasajeros);
					break;
				case 3:
					controller_addPassenger(listaPasajeros);
					break;
				case 4:
					 controller_editPassenger(listaPasajeros);
					break;
				case 5:
					controller_removePassenger(listaPasajeros);
					break;
				case 6:
					controller_ListPassenger(listaPasajeros);
					break;
				case 7:
					controller_sortPassenger(listaPasajeros);
					break;
				case 8:
					controller_saveAsText("data.csv",listaPasajeros);
					break;
				case 9:
					controller_saveAsBinary("bin.dat",listaPasajeros);
					break;
			}

    }else{


		printf("1.Cargar los datos de los pasajeros desde el archivo(txt)\n"
				"2.Cargar los datos de los pasajeros desde el archivo(bin)\n"
				"3.Alta de pasajero.\n"
				"10.Salir\n"
		);

		//pedir la opcion.
		getInt(&option,"ingrese una opcion:","Error. ingrese nuevamente la opcion.\n",1,10);


		switch(option)
		{
			case 1:
				controller_loadFromText("data.csv",listaPasajeros);
				banderaCarga = 1;
				break;
			case 2:
				controller_loadFromBinary("bin.dat",listaPasajeros);
				banderaCarga = 1;
				break;
			case 3:
				controller_addPassenger(listaPasajeros);
				banderaCarga = 1;
				break;
			default:
				printf("Elija una opcion valida.\n\n");
				break;
		}

    }

    }while(option != 10);


    return 0;
}

