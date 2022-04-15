/*
 * salida.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Lucas Torres Ezequiel
 */

#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"
#include "funciones.h"
#include "salida.h"

void menu(){

	printf("| Agencia De Vuelo |\n");

	//declarando variables.
	int km = 0;
	float precioAerolineas = 0;
	float tarjetaDebitoAerolineas;
	float tarjetaCreditoAerolineas;
	float bitcoinAerolineas;
	float precioUnitarioAerolineas;
	float precioLatam = 0;
	float tarjetaDebitoLatam;
	float tarjetaCreditoLatam;
	float bitcoinLatam;
	float precioUnitarioLatam;
	float diferencia;

	//obtener los datos.
	km = obtenerKm();
	precioAerolineas = obtenerAerolineas();
	precioLatam = obtenerLatam();

	//obtener precio con tarjetas de debito.
	tarjetaDebitoAerolineas = descuentoTarjeta(precioAerolineas);
	tarjetaDebitoLatam = descuentoTarjeta(precioLatam);

	//obtener precio con tarjetas de credito.
	tarjetaCreditoAerolineas = interesCredito(precioAerolineas);
	tarjetaCreditoLatam = interesCredito(precioLatam);

	//obtener bitcoins.
	bitcoinLatam = 	obtenerBitcoin(precioLatam);
	bitcoinAerolineas = obtenerBitcoin(precioAerolineas);

	//obtener precio unitario.
	precioUnitarioAerolineas = obtenerUnidad(precioAerolineas,km);
	precioUnitarioLatam = obtenerUnidad(precioLatam,km);

	//obtener diferencia de precio.
	diferencia = diferenciaPrecio(precioAerolineas,precioLatam);

	//mostrar datos
	printf(" KMS INGRESADOS: %i\n", km );
	printf("\n");
	printf(" Precio Aerolineas: %f\n", precioAerolineas);
	printf("a)Precio con tarjeta de debito: %f\n", tarjetaDebitoAerolineas);
	printf("b)Precio con tarjeta de credito: %f\n", tarjetaCreditoAerolineas);
	printf("c)Precio pagando con bitcoin: %f\n", bitcoinAerolineas);
	printf("d)Mostrar precio unitario: %f\n",precioUnitarioAerolineas);
	printf("\n");
	printf(" Precio Latam: %f\n", precioLatam);
	printf("a)Precio con tarjeta de debito: %f\n", tarjetaDebitoLatam);
	printf("b)Precio con tarjeta de credito: %f\n", tarjetaCreditoLatam);
	printf("c)Precio pagando con bitcoin: %f\n", bitcoinLatam);
	printf("d)Mostrar precio unitario: %f\n",precioUnitarioLatam);
	printf("\n");
	printf(" La diferencia de precio es: %f\n", diferencia );

}
