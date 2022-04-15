/*
 * funciones.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Lucas Torres Ezequiel
 */


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
	else{
		resultado = precio2 - precio1;
	}

	return resultado;

}

