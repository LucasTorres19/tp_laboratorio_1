/*
 * funciones.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Lucas Torres Ezequiel
 */
#include <stdio.h>
#include <stdlib.h>

float descuentoTarjeta(float precio){

	float descuento = 0;
	float resultado = 0;

	//aplicamos el 10% de descuento.
	descuento = (precio * 10) / 100;

	resultado = precio - descuento;

	return resultado;

}

float interesCredito(float precio){

	float interes = 0;
	float resultado = 0;


	//aplicamos el 25% de interes.
	interes = (precio * 25) / 100;

	resultado = precio + interes;

	return resultado;

}

float obtenerBitcoin(float precio){

	float precioBitcoin = 4606954.55;
	float resultado;

	resultado = precio / precioBitcoin;

	return resultado;

}

float obtenerUnidad(float precio , int km){

	float resultado;

	resultado = precio / km;

	return resultado;

}

float diferenciaPrecio(float precio1 , float precio2){

	float resultado;

	if(precio1 > precio2){
		resultado = precio1 - precio2;
	}
	else if(precio2 > precio1){
		resultado = precio2 - precio1;
	}
	else{
		resultado = 0;
	}

	return resultado;

}

void mostrarDatos(int km,float precioAerolineas,float tarjetaDebitoAerolineas,float tarjetaCreditoAerolineas,float bitcoinAerolineas,float precioUnitarioAerolineas,
float precioLatam , float tarjetaDebitoLatam , float tarjetaCreditoLatam,float bitcoinLatam , float precioUnitarioLatam ,float diferencia)
{

				printf("KMS INGRESADOS: %d", km);
				printf("km\n\n");
				printf("Precio Aerolineas: $%.2f\n", precioAerolineas);
				printf("a)Precio con tarjeta de debito: $%.2f\n", tarjetaDebitoAerolineas);
				printf("b)Precio con tarjeta de credito: $%.2f\n", tarjetaCreditoAerolineas);
				printf("c)Precio pagando con bitcoin: %.2f", bitcoinAerolineas);
				printf("BTC\n");
				printf("d)Mostrar precio unitario: $%.2f\n",precioUnitarioAerolineas);
				printf("\n");
				printf("Precio Latam: %.2f\n", precioLatam);
				printf("a)Precio con tarjeta de debito: $%.2f\n", tarjetaDebitoLatam);
				printf("b)Precio con tarjeta de credito: $%.2f\n", tarjetaCreditoLatam);
				printf("c)Precio pagando con bitcoin: %.2f", bitcoinLatam);
				printf("BTC\n");
				printf("d)Mostrar precio unitario: $%.2f\n",precioUnitarioLatam);
				printf("\n");
				printf("La diferencia de precio es: $%.2f\n", diferencia );
}
