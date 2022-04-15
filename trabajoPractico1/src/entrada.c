#include <stdio.h>
#include <stdlib.h>

int obtenerKm(){

	int km = 0;
	int validacion;

	do{
		printf("Ingrese la Cantidad de Kilometros:");

		scanf("%d",&km);

		//validar que km no sea una string.

		if(!km || km <= 0 ){

			printf("Error, Por favor ingrese un numero valido. \n");
			validacion = 0;
			fflush(stdin);

		}
		else{
			validacion = 1;
		}

	}while(validacion == 0);

		return km;
}

float obtenerAerolineas(){

	float precioAerolineas = 0;
	int validacion;

		do{
			printf("Ingrese el precio de Aerolineas:");

			scanf("%f",&precioAerolineas);

			//validar que km no sea una string.

			if(!precioAerolineas || precioAerolineas <= 0 ){

				printf("Error, Por favor ingrese un numero valido. \n");
				validacion = 0;
				fflush(stdin);

			}
			else{
				validacion = 1;
			}

		}while(validacion == 0);

			return precioAerolineas;
}

float obtenerLatam(){


	float precioLatam = 0;
	int validacion;

			do{
				printf("Ingrese el precio de Latam:");

				scanf("%f",&precioLatam);

				//validar que km no sea una string.

				if(!precioLatam || precioLatam <= 0 ){

					printf("Error, Por favor ingrese un numero valido. \n");
					validacion = 0;
					fflush(stdin);

				}
				else{
					validacion = 1;
				}

			}while(validacion == 0);

			return precioLatam;
}


