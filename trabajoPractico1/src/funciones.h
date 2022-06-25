/*
 * funciones.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Lucas Torres  Ezequiel
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

float descuentoTarjeta(float precio);
float interesCredito(float precio);
float obtenerBitcoin(float precio);
float obtenerUnidad(float precio , int km);
float diferenciaPrecio(float precio1 , float precio2);
void mostrarDatos(int km,float precioAerolineas,float tarjetaDebitoAerolineas,float tarjetaCreditoAerolineas,float bitcoinAerolineas,float precioUnitarioAerolineas,
float precioLatam , float tarjetaDebitoLatam , float tarjetaCreditoLatam,float bitcoinLatam , float precioUnitarioLatam ,float diferencia);


#endif /* FUNCIONES_H_ */
