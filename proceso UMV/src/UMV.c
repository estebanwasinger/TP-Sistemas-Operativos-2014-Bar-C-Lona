#include"UMV.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/string.h>
#include <commons/config.h>
#include <commons/collections/list.h>
#include <pthread.h>

//Variables Globales de la UMV
void *memFisica;
t_list * segmentosUMV;
int AlgoritmoActual = 1;


/////////////   COMIENZO MAIN  ///////////////////

int main(void) {

	// Obtenemos la cantidad de memoria y la alocamos
	int memTotal = ObtenerCantidadMemoriaTotal();
	if(memTotal <= 0){ printf("Error De Archivo De Config"); return -1;}
	memFisica = malloc(memTotal);

	LanzarConsola();

	return EXIT_SUCCESS;
}

/////////////   FIN MAIN  ///////////////////

//------------------ FUNCIONES ------------------------

//lee un archivo de configuracion y trae el tamaño de memoria a alocar
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

// crea un hilo que maneja la consola
void LanzarConsola(){
    pthread_t hilo_consola;
    pthread_create(&hilo_consola,NULL, (void*)Consola, NULL);
    pthread_join(hilo_consola,NULL);
}

// maneja consola y controla los comandos ingresados por teclado
void Consola(){
	//variables locales
	char* comando = string_new();
	t_list *listaComandos = list_create();

	// nos preparamos para leer
	printf("UMV Console\n");
	while(1){
		char c = getchar();
		//si el primer caracter es un espacio hacemos B
		if(c==' '){return;}

		while(c != '\n'){
			//si hay un espacio agregamos el comando a la lista e intanceamos nueva string
			if(c==' '){
				list_add(listaComandos,comando);
				comando = string_new();
			}
			else{
				comando[strlen(comando)] = c;
				comando[strlen(comando)+1] ='\0';
			}
			c = getchar();
		}

		// ejecutamos el comando ingresado
		EjecutarComandos(listaComandos);
	}
 }

// crea un segmento nuevo
Segmento *create_segmento(char* programa,void* base, int baseVirtual,int tamano ){
	Segmento *segmento_nuevo = malloc(sizeof(Segmento));
	segmento_nuevo->base = base;
	segmento_nuevo->baseVirtual = baseVirtual;
	segmento_nuevo->programa = programa;
	segmento_nuevo->tamano = tamano;

	return segmento_nuevo;
}

// Ejecuta los comandos que entran por la consola
int EjecutarComandos(t_list *lista){
	printf("Comando!");
	return 0;
}

// Alocar el un nuevo segmento
int AlocarNuevoSegmento(char* programa,int base,int tamano){
	Segmento nuevo_segmento = create_segmento(programa,(memFisica + base),base,tamano);

	return 1;
}

// Permite el cambio de FirstFit a WorstFit
void CambiarAlgoritmo(char* nombreAlgoritmo){
	if(strcmp(nombreAlgoritmo, "firstfit") || strcmp(nombreAlgoritmo, "FirstFit") ||strcmp(nombreAlgoritmo, "FirstFit")){
		AlgoritmoActual = ALGOTIRMO_FIRSTFIT; printf(" Se a cambiado el algoritmo a FirstFit "); return;
	}
	if(strcmp(nombreAlgoritmo, "worstfit") || strcmp(nombreAlgoritmo, "WORSTFIT") ||strcmp(nombreAlgoritmo, "WorstFit")){
		AlgoritmoActual = ALGOTIRMO_WORSTFIT; printf(" Se a cambiado el algoritmo a WorstFit "); return;
	}

	printf("No existe un algoritmo con ese nombre");
}






