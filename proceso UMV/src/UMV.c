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
	//Inicializamos las cosas
	segmentosUMV = list_create();

	// Obtenemos la cantidad de memoria y la alocamos
	int memTotal = ObtenerCantidadMemoriaTotal();
	if (memTotal <= 0) {
		printf("Error De Archivo De Config");
		return -1;
	}
	memFisica = malloc(memTotal);

	LanzarConsola();

	return EXIT_SUCCESS;
}

/////////////   FIN MAIN  ///////////////////

//------------------ FUNCIONES ------------------------

//lee un archivo de configuracion y trae el tamaño de memoria a alocar
int ObtenerCantidadMemoriaTotal() {

	// El archivo de configuracion va en la carpeta raiz del proyecto "proceso UMV"
	t_config * arch_config = config_create("archconfig");

	//Validamos que este la propiedad
	if (!config_has_property(arch_config, "CANTIDAD_MEM_ALOCAR")) {
		puts("Archivo de configuracion incompleto o invalido.\n");
		return -2;
	}

	int cantidadMemoria = config_get_int_value(arch_config,
			"CANTIDAD_MEM_ALOCAR");

	return cantidadMemoria;
}

// crea un hilo que maneja la consola
void LanzarConsola() {
	pthread_t hilo_consola;
	pthread_create(&hilo_consola, NULL, (void*) Consola, NULL );
	pthread_join(hilo_consola, NULL );
}

// maneja consola y controla los comandos ingresados por teclado
void Consola() {
	//variables locales
	char* comando = string_new();
	t_list *listaComandos = list_create();

	// nos preparamos para leer
	printf("UMV Console\n");
	while (1) {
		char c = getchar();
		//si el primer caracter es un espacio hacemos B
		if (c == ' ') {
			return;
		}

		while (c != '\n') {
			//si hay un espacio agregamos el comando a la lista e intanceamos nueva string
			if (c == ' ') {
				list_add(listaComandos, comando);
				comando = string_new();
			} else {
				comando[strlen(comando)] = c;
				comando[strlen(comando) + 1] = '\0';
			}
			c = getchar();
		}

		list_add(listaComandos, comando);

		// ejecutamos el comando ingresado
		EjecutarComandos(listaComandos);
	}
}

// crea un segmento nuevo
Segmento *create_segmento(char* programa, void* base, int baseVirtual,
		int tamano) {
	Segmento *segmento_nuevo = malloc(sizeof(Segmento));
	segmento_nuevo->base = base;
	segmento_nuevo->baseVirtual = baseVirtual;
	segmento_nuevo->programa = programa;
	segmento_nuevo->tamano = tamano;

	return segmento_nuevo;
}

// crea un rango de memoria
RangoMemoria *create_rango_mem(int base, int tamano) {
	RangoMemoria *aRango = malloc(sizeof(RangoMemoria));
	aRango->base = base;
	aRango->tamano = tamano;

	return aRango;
}

// Ejecuta los comandos que entran por la consola
int EjecutarComandos(t_list *listaComandos) {
	char *nombreFuncion = string_new();
	int cantidadParams = list_size(listaComandos) - 1;
	nombreFuncion = (char*) list_get(listaComandos, 0);
	if(string_equals_ignore_case(nombreFuncion, "compactar") && cantidadParams == 0){
		CompactaMemoria(); return 1;
	}


	printf("No se encuentra el comando o alguno de los parametros es invalido");
	return 0;
}

// guarda el un nuevo segmento ordenado por su base en lista de segmentos
int GrabarNuevoSegmento(char* programa, int baseVirtual, int tamano) {
	Segmento * nuevo_segmento = create_segmento(programa,
			(memFisica + baseVirtual), baseVirtual, tamano);

	if (list_is_empty(segmentosUMV)) { // si la lista esta vacia lo agregamos en la primer posicion
		list_add(segmentosUMV, nuevo_segmento);
		return 1;
	} else {   // si no esta vacia agregamos ordenado por la baseVirtual
		int pos = 0;
		while (list_size(segmentosUMV) - 1 != pos
				&& ((Segmento*) list_get(segmentosUMV, pos))->baseVirtual
						> baseVirtual) {
			pos++;
		}
		list_add_in_index(segmentosUMV, pos, nuevo_segmento);
		return 1;
	}
}

// Permite el cambio de FirstFit a WorstFit
void CambiarAlgoritmo(char* nombreAlgoritmo) {
	if (string_equals_ignore_case("firstfit", nombreAlgoritmo)) {
		AlgoritmoActual = ALGOTIRMO_FIRSTFIT;
		printf(" Se a cambiado el algoritmo a FirstFit ");
		return;
	}
	if (string_equals_ignore_case("worstfit", nombreAlgoritmo)) {
		AlgoritmoActual = ALGOTIRMO_WORSTFIT;
		printf(" Se a cambiado el algoritmo a WorstFit ");
		return;
	}

	printf("No existe un algoritmo con ese nombre");
}

// Nos dice si hay memoria disponible junta para grabar un sengmento de tamaño fijo
bool SePuedeGrabarSegmento(int tamano) {

	t_list *listaRangosLibres = RangosLibresDeMemoria();

	// esta funcion auxiliar para fijarse si algun rango satisface la condicion
	int Hay_algun_rango_de_tamano_suficiente(RangoMemoria *rango) {
		return rango->tamano >= tamano;
	}
	return list_any_satisfy(listaRangosLibres,(void*) Hay_algun_rango_de_tamano_suficiente);

}

// Nos dice la cantidad total de memoria libre,
int CantidadMemoriaLibre(int tamano) {

	int tamanoTotal;

	void ContarTamano(RangoMemoria* rango)
	{
		tamanoTotal = tamanoTotal + rango->tamano;
	}

	t_list* rangosLibres = RangosLibresDeMemoria();

	list_iterate(rangosLibres, (void*)ContarTamano);

	return tamanoTotal;
}

// Nos devuelve un array de RangosDeMemoria con todos los rangos de memoria libres;
t_list *RangosLibresDeMemoria() {
	int pos = 0;
	int salida, llegada;
	RangoMemoria *rangoMem;
	t_list * rangos_de_memoria = list_create();

	while (list_size(segmentosUMV) - 1 <= pos) {
		Segmento segmentoAnterior = *((Segmento*) list_get(segmentosUMV, pos));
		Segmento segmentoPosterior = *((Segmento*) list_get(segmentosUMV,
				pos + 1));

		salida = segmentoAnterior.baseVirtual + segmentoAnterior.tamano;
		llegada = segmentoPosterior.baseVirtual;

		//con esto nos fijamos si hay espacio entre medio de los dos nodos
		if (salida < llegada) {
			rangoMem = create_rango_mem(salida, llegada - salida);
			list_add(rangos_de_memoria, rangoMem);
		}
	}

	return rangos_de_memoria;
}

// compacta la memoria dejando tod el espacio libre junto.
void CompactaMemoria() {
	int pos = 0;

	while(list_size(segmentosUMV) >= pos){

		Segmento segmentoPrimero = *((Segmento*)list_get(segmentoPrimero,pos));
		Segmento segmentoPrimero = *((Segmento*)list_get(segmentoPrimero,pos + 1));


		pos++;
	}
}


