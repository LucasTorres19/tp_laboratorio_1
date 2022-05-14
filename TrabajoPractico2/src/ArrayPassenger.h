/*
 * ArrayPassenger.h
 *
 *  Created on: 13 may. 2022
 *      Author: Lucas Torres Ezequiel
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

//estructura de los passengers.

struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger;
char statusFlight[9];
int isEmpty;
}typedef Passenger;

//funciones.

int initPassengers(Passenger* list, int len);
int addPassenger(Passenger* list, int len,char name[],char lastName[],float price,int typePassenger, char flycode[]);
int findPassengerById(Passenger* list, int len,int id);
int removePassenger(Passenger* list, int len, int id);
int sortPassengers(Passenger* list, int len, int order);
int sortPassengersByCode(Passenger* list, int len, int order);
void modificarpasajero(int pos,Passenger* list, int len,char name[],char lastName[],float price,int typePassenger, char flycode[]);
void printPassenger(Passenger* list, int length);
float obtenerTotalPrice(Passenger* list, int length);
int totalPasajeros(Passenger* list, int length);
int TotalPasajerosMaxN(Passenger* list , int length , float n);

#endif /* ARRAYPASSENGER_H_ */
