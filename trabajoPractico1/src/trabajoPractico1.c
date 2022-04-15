/*
 ============================================================================
 Name        : trabajoPractico1.c
 Author      : Lucas Torres Ezequiel
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "entrada.h"
#include "funciones.h"

int main(void) {

	setbuf(stdout,NULL);

	printf("| Agencia De Vuelo |\n");

	//declarando variables.
	int km = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;
	float tarjetaLatam;
	float bitcoin;

	km = obtenerKm();
	precioAerolineas = obtenerAerolineas();
	precioLatam = obtenerLatam();

	printf("%i\n", km);
	printf("%f\n", precioAerolineas);
	printf("%f\n", precioLatam);

	tarjetaLatam = descuentoTarjeta(precioLatam);
	bitcoin = obtenerBitcoin(precioLatam);

	printf("tarjeta: %f\n", tarjetaLatam);
	printf("bitcoin: %f\n", bitcoin);


	return EXIT_SUCCESS;
}
