/*
 * ArrayPassenger.c
 *
 *  Created on: 13 may. 2022
 *      Author: Lucas Torres Ezequiel
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger;
int statusFlight;
int isEmpty;
}typedef Passenger;


void initPassengers(Passenger* list, int len){

	for(int i=0 ;i < len;i++){

		list[i].isEmpty = 1;

	}

	fflush(stdin);
	return;
}

void addPassenger(Passenger* list, int len,char name[],char lastName[],
				 float price,int typePassenger, char flycode[]){

	for(int i =0 ; i < len; i++){

		//buscar el primero en la lista con isEmply en 1;
		if(list[i].isEmpty == 1){

			//ingresar los datos.
			list[i].id = i + 1;
			strcpy(list[i].name,name);
			strcpy(list[i].lastName, lastName);
			list[i].price = price;
			strcpy(list[i].flycode,flycode);
			list[i].typePassenger = typePassenger;
			list[i].statusFlight = rand() % 2;
			list[i].isEmpty = 0;

			printf("Pasajero agregado con exito.\n");
			break;

		}
	}
}

void modificarpasajero(int pos,Passenger* list, int len,char name[],char lastName[],
		 float price,int typePassenger, char flycode[]){

			for(int i =0 ; i < len; i++){

				if(i == pos){

					//ingresar los datos.
					strcpy(list[i].name,name);
					strcpy(list[i].lastName, lastName);
					list[i].price = price;
					strcpy(list[i].flycode,flycode);
					list[i].typePassenger = typePassenger;
					list[i].statusFlight = rand() % 2;

					printf("Pasajero modificado con exito.\n");
					break;

			}
		}


}
int findPassengerById(Passenger* list, int len,int id){

	for(int i = 0; i < len ; i++){

		if(list[i].id == id){

			return i;
		}
	}
	return -1;

}

void removePassenger(Passenger* list, int len, int id){

	for(int i = 0; i < len ; i++){

			if(list[i].id == id){

				list[i].isEmpty = 1;

				printf("pasajero eliminado con exito.\n");
			}
		}

}

void sortPassengers(Passenger* list, int len, int order){

	int j , i,auxValue = 0;

	Passenger aux;

	for(i = 0;i< len; i++){
		for ( j =i +  1; j < len; j++){
			
			if(list[j].isEmpty == 0){

				if(order == 1){
					if(list[i].typePassenger > list[j].typePassenger){
						auxValue = 1;
					}else{
						if(list[i].typePassenger == list[j].typePassenger){
							auxValue = strcmp(list[i].lastName,list[j].lastName);
						}
					}
				}
				else{
					if(list[i].typePassenger < list[j].typePassenger){
						auxValue = 1;
					}else{
						if(list[i].typePassenger == list[j].typePassenger){
							auxValue = strcmp(list[i].lastName,list[j].lastName);
						}
					}
				}

				if(auxValue == 1){

					auxValue = 0;

				    aux = list[i];
                	list[i] = list[j];
                	list[j] = aux;
				}
				else if (auxValue < 0){

					auxValue = 0;

					aux = list[i];
                	list[i] = list[j];
                	list[j] = aux;
				}
			}


		}
		

	}

}

void printPassenger(Passenger* list, int length){

	for(int i = 0; i < length ; i++){

		if(list[i].isEmpty == 0){

			printf("%d",list[i].id);
			printf(" ");
			printf("%s",list[i].name);
			printf(" ");
			printf("%s",list[i].lastName);
			printf(" ");
			printf("%f",list[i].price);
			printf(" ");
			printf("%s",list[i].flycode);
			printf(" ");
			printf("%d",list[i].typePassenger);
			printf(" ");

			if(list[i].statusFlight == 1){
				printf("ACTIVO");
			}
			else{
				printf("INACTIVO");
			}

			printf("\n");

		}
	}
}

void sortPassengersByCode(Passenger* list, int len, int order){

	int j,i;
	Passenger aux;

	for (i = 0; i < len; i++){
		for ( j = i + 1; j< len; j++){

			if(list[i].isEmpty == 0){

				if(order == 1){

					if(strcmp(list[i].flycode,list[j].flycode) > 0){
						aux = list[j];
						list[j] = list[i];
						list[i] = aux;

					}

					if(strcmp(list[i].flycode,list[j].flycode) == 0){
						if(list[i].statusFlight > list[j].statusFlight){
							aux = list[j];
							list[j] = list[i];
							list[i] = aux;
						}
					}
				}else{

					if(strcmp(list[i].flycode,list[j].flycode) < 0){
							aux = list[j];
							list[j] = list[i];
							list[i] = aux;
					}

					if(strcmp(list[i].flycode,list[j].flycode) == 0){
						if(list[i].statusFlight > list[j].statusFlight){
								aux = list[j];
								list[j] = list[i];
								list[i] = aux;
					}

				}

			}
		}
		
	}
	
}
}


float obtenerTotalPrice(Passenger* list, int length){

	int i;
	float totalPrice = 0;

	for(i = 0;i<length;i++){

		if(list[i].isEmpty == 0){

			totalPrice += list[i].price;
		}
	}

	return totalPrice;
}

int totalPasajeros(Passenger* list, int length){

	int i;
	int totalPasajeros = 0;

		for(i = 0;i<length;i++){

			if(list[i].isEmpty == 0){

				totalPasajeros += 1;
			}
		}

		return totalPasajeros;
}

int TotalPasajerosMaxN(Passenger* list , int length , float n){

		int i;
		int totalPasajeros = 0;

			for(i = 0;i<length;i++){

				if(list[i].isEmpty == 0){

					if(list[i].price > n){
						totalPasajeros += 1;
					}
				}
			}

			return totalPasajeros;

}
