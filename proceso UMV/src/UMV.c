#include"UMV.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/string.h>
#include <commons/config.h>
#include <pthread.h>

//Variables Globales de la UMV
int *memFisica;
int a = 0;

int main(void) {
	// Obtenemos la cantidad de memoria y la alocamos
	int memTotal = ObtenerCantidadMemoriaTotal();
	if(memTotal <= 0){ printf("Error De Archivo De Config"); return -1;}
	memFisica = malloc(memTotal);

	LanzarConsola();

	return EXIT_SUCCESS;
}

int ObtenerCantidadMemoriaTotal(){

		// El archivo de configuracion va en la carpeta raiz del proyecto "proceso UMV"
		t_config * arch_config = config_create("archconfig");

		//Validamos que este la propiedad
		if (!config_has_property(arch_config, "CANTIDAD_MEM_ALOCAR" ))
		{
			puts("Archivo de configuracion incompleto o invalido.\n");
			return -2;
		}

		int cantidadMemoria = config_get_int_value(arch_config,"CANTIDAD_MEM_ALOCAR");

	   return cantidadMemoria;
}

void LanzarConsola(){
    pthread_t hilo_consola;
    pthread_create(&hilo_consola,NULL, Consola, NULL);
    pthread_join(&hilo_consola,NULL);
    printf("%d",a);
}

void Consola(){
	while(a<10){
		a++;
	}
 }
