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
#include "extraFunctions.h"

int main(void) {

	setbuf(stdout,NULL);

	//variables
	int opcionElejida; //opcion elejida.

	//variables auxiliares.
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
	int kmForzado = 7090;
	float aerolineasForzada = 162965;
	float latamForzada = 159339;

	printf("| Agencia De Vuelo |\n");

	do{

		printf("\n1.ingresar kilometros.\n"
				"2.Ingresar Precio de Vuelos.\n"
				"3.Calcular los costos.\n"
				"4.Informar Resultados\n"
				"5.Carga forzada de datos\n"
				"6.Salir\n"
				);

		getInt(&opcionElejida,"ingrese una opcion:","Error. ingrese nuevamente la opcion.\n",1,6);

		switch(opcionElejida){

		case 1:

			//ingreso de kilometros.
			getInt(&km,"ingrese la cantidad de kilometros:","Error. ingrese nuevamente los km.\n",1,999999999);
			printf("Kilometros cargados con exito.\n");
			break;

		case 2:

			//ingreso de los precios.
			getFloat(&precioAerolineas ,"ingrese el precio del vuelo(Aerolineas):\n","error:ingrese nuevamente el precio.\n",1,999999999);
			getFloat(&precioLatam ,"ingrese el precio del vuelo(LATAM):\n","error:ingrese nuevamente el precio.\n",1,999999999);
			printf("precios subidos con exito.\n");
			break;

		case 3:

			if(km != 0 && precioAerolineas != 0 && precioLatam != 0){

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

				printf("Costos calculados.\n");
			}
			else{

				printf("Por favor lleno los datos previos.\n");

			}
			break;

		case 4://mostrar datos.

			if(precioAerolineas != 0 && precioLatam != 0  && km != 0){
			mostrarDatos(km,precioAerolineas, tarjetaDebitoAerolineas, tarjetaCreditoAerolineas,bitcoinAerolineas,precioUnitarioAerolineas,
			precioLatam ,tarjetaDebitoLatam , tarjetaCreditoLatam,bitcoinLatam ,precioUnitarioLatam ,diferencia);
			}
			else{
				printf("Por favor llene los datos previos.\n");
			}
			break;

		case 5: //carga forzada

			//obtener precio con tarjetas de debito.
			tarjetaDebitoAerolineas = descuentoTarjeta(aerolineasForzada);
			tarjetaDebitoLatam = descuentoTarjeta(latamForzada);

			//obtener precio con tarjetas de credito.
			tarjetaCreditoAerolineas = interesCredito(aerolineasForzada);
			tarjetaCreditoLatam = interesCredito(latamForzada);

			//obtener bitcoins.
			bitcoinLatam = 	obtenerBitcoin(latamForzada);
			bitcoinAerolineas = obtenerBitcoin(aerolineasForzada);

			//obtener precio unitario.
			precioUnitarioAerolineas = obtenerUnidad(aerolineasForzada, kmForzado);
			precioUnitarioLatam = obtenerUnidad(latamForzada, kmForzado);

			//obtener diferencia de precio.
			diferencia = diferenciaPrecio(aerolineasForzada,latamForzada);

			mostrarDatos(kmForzado,aerolineasForzada, tarjetaDebitoAerolineas, tarjetaCreditoAerolineas,bitcoinAerolineas,precioUnitarioAerolineas,
					latamForzada,tarjetaDebitoLatam , tarjetaCreditoLatam,bitcoinLatam ,precioUnitarioLatam ,diferencia);

			break;
		}


	}while(opcionElejida != 6);


	return EXIT_SUCCESS;
}
