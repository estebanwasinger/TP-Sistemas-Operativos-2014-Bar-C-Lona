#include"UMV.h"

// Variables Globales de la UMV
void *MemFisica;
int MemTotal;
t_list * Segmentos_UMV;
int AlgoritmoActual = 1;
int FinPrograma = 0;

/////////////   COMIENZO MAIN  ///////////////////

int main(void) {
	//Inicializamos las cosas
	Segmentos_UMV = list_create();
	srand(time(NULL ));

	// Obtenemos la cantidad de memoria y la alocamos
	MemTotal = ObtenerCantidadMemoriaTotal();
	if (MemTotal <= 0) {
		printf("Error De Archivo De Config");
		return -1;
	}
	MemFisica = malloc(MemTotal);

	// comienzan a correr los procesos
	// LanzarConsola();

	// comienza a escuchar
	// EscucharYLanzarHilos();

	printf("Cantidad Mem Libre %d \n\n", CantidadMemoriaLibre());

	GrabarSegmento("prog1 ", 1000);

	printf("Cantidad Mem Libre %d \n\n", CantidadMemoriaLibre());
	Segmento aSeg1 =  *((Segmento *)list_get(Segmentos_UMV, 0));
	printf("1 Base: %d, Tam: %d \n", aSeg1.baseVirtual,aSeg1.tamano);


	MostrarRangosMemoriaLibre();


	printf("\n\n");
	GrabarSegmento("prog1", 1800);
	printf("Cantidad Mem Libre %d \n\n", CantidadMemoriaLibre());
	 aSeg1 =  *((Segmento *)list_get(Segmentos_UMV, 0));
	printf("1 Base: %d, Tam: %d \n", aSeg1.baseVirtual,aSeg1.tamano);
    aSeg1 =  *((Segmento *)list_get(Segmentos_UMV, 1));
	printf("2 Base: %d, Tam: %d \n", aSeg1.baseVirtual,aSeg1.tamano);

	MostrarRangosMemoriaLibre();

	printf("\n\n");
	GrabarSegmento("prog1", 1300);
	printf("Cantidad Mem Libre %d \n\n", CantidadMemoriaLibre());
	 aSeg1 =  *((Segmento *)list_get(Segmentos_UMV, 0));
	printf("1 Base: %d, Tam: %d \n", aSeg1.baseVirtual,aSeg1.tamano);
    aSeg1 =  *((Segmento *)list_get(Segmentos_UMV, 1));
	printf("2 Base: %d, Tam: %d \n", aSeg1.baseVirtual,aSeg1.tamano);
    aSeg1 =  *((Segmento *)list_get(Segmentos_UMV, 2));
	printf("3 Base: %d, Tam: %d \n", aSeg1.baseVirtual,aSeg1.tamano);

	MostrarRangosMemoriaLibre();

	printf("\n\n");
	GrabarSegmento("prog1", 1200);
	printf("Cantidad Mem Libre %d \n\n", CantidadMemoriaLibre());

	 aSeg1 =  *((Segmento *)list_get(Segmentos_UMV, 0));
	printf("1 Base: %d, Tam: %d \n", aSeg1.baseVirtual,aSeg1.tamano);
    aSeg1 =  *((Segmento *)list_get(Segmentos_UMV, 1));
	printf("2 Base: %d, Tam: %d \n", aSeg1.baseVirtual,aSeg1.tamano);
    aSeg1 =  *((Segmento *)list_get(Segmentos_UMV, 2));
	printf("3 Base: %d, Tam: %d \n", aSeg1.baseVirtual,aSeg1.tamano);
    aSeg1 =  *((Segmento *)list_get(Segmentos_UMV, 3));
	printf("4 Base: %d, Tam: %d \n", aSeg1.baseVirtual,aSeg1.tamano);

	MostrarRangosMemoriaLibre();

	printf("\n\n");
	GrabarSegmento("prog1", 800);
	printf("Cantidad Mem Libre %d \n\n", CantidadMemoriaLibre());

	 aSeg1 =  *((Segmento *)list_get(Segmentos_UMV, 0));
	printf("1 Base: %d, Tam: %d \n", aSeg1.baseVirtual,aSeg1.tamano);
    aSeg1 =  *((Segmento *)list_get(Segmentos_UMV, 1));
	printf("2 Base: %d, Tam: %d \n", aSeg1.baseVirtual,aSeg1.tamano);
    aSeg1 =  *((Segmento *)list_get(Segmentos_UMV, 2));
	printf("3 Base: %d, Tam: %d \n", aSeg1.baseVirtual,aSeg1.tamano);
    aSeg1 =  *((Segmento *)list_get(Segmentos_UMV, 3));
	printf("4 Base: %d, Tam: %d \n", aSeg1.baseVirtual,aSeg1.tamano);
    aSeg1 =  *((Segmento *)list_get(Segmentos_UMV, 4));
	printf("5 Base: %d, Tam: %d \n", aSeg1.baseVirtual,aSeg1.tamano);

	MostrarRangosMemoriaLibre();

	printf("\n\n");
	printf("Cantidad Segmentos Hasta el momento %d \n\n", (int)list_size(Segmentos_UMV));


	printf("\n\n");




	return EXIT_SUCCESS;
}

/////////////   FIN MAIN  ///////////////////

//------------------ FUNCIONES ------------------------

//lee un archivo de configuracion y trae el tamaño de memoria a alocar --- OK
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

// crea un hilo que maneja la consola --- OK
void LanzarConsola() {
	pthread_t hilo_consola;
	pthread_create(&hilo_consola, NULL, (void*) Consola, NULL );
	pthread_join(hilo_consola, NULL );
}

// maneja consola y controla los comandos ingresados por teclado --- OK
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

// crea un segmento nuevo -- OK
Segmento *create_segmento(char* programa, void* base, int base_virtual,
		int tamano) {
	Segmento *segmento_nuevo = malloc(sizeof(Segmento));
	segmento_nuevo->base = base;
	segmento_nuevo->baseVirtual = base_virtual;
	segmento_nuevo->programa = programa;
	segmento_nuevo->tamano = tamano;

	return segmento_nuevo;
}

// crea un rango de memoria --OK
RangoMemoria *create_rango_mem(int base, int tamano) {
	RangoMemoria *aRango = malloc(sizeof(RangoMemoria));
	aRango->base = base;
	aRango->tamano = tamano;

	return aRango;
}

// Ejecuta los comandos que entran por la consola
int EjecutarComandos(t_list *lista_comandos) {
	char *nombreFuncion = string_new();
	int cantidadParams = list_size(lista_comandos) - 1;
	nombreFuncion = (char*) list_get(lista_comandos, 0);

	if (string_equals_ignore_case(nombreFuncion, "compactar")
			&& cantidadParams == 0) {
		CompactaMemoria();
		return 1;
	}

	printf("No se encuentra el comando o alguno de los parametros es invalido");
	return 0;
}

// Elije una base aleatoria y graba el segmento segun el algoritmo indicado
void GrabarSegmento(char* programa, int tamano_Segmento) {

	if (!SePuedeGrabarSegmento(tamano_Segmento)) {
		printf("MEMORY OVERLOAD, No hay memoria para grabar el segmento");
		return;
	}

	// segun el algoritmo se elige una base aleatoria.
	if (ALGOTIRMO_FIRSTFIT == AlgoritmoActual) {
		int pos = 0;
		int tamanoRangoLibre = 0;
		RangoMemoria rango;

		// calculamos el primer rango de memoria en el que entra el segmento
		while (tamanoRangoLibre < tamano_Segmento) {
			rango = *((RangoMemoria*)list_get(RangosLibresDeMemoria(), pos));
			tamanoRangoLibre = rango.tamano;
			pos++;
		}
		// calculamos la base aletoria dentro del rango
		int base = (rand() % (rango.base + rango.tamano - tamano_Segmento)) + (rango.base);
		GuardarNuevoSegmentoOrdenado(programa, base, tamano_Segmento);

	} else {
		RangoMemoria elRangoGrande = RangoMasGrandeLibre();
		// calculamos la base, es un numero random en el que puede entrar el segmento dentro del mayor rango de memoria libre
		int base = (rand() % (elRangoGrande.base + elRangoGrande.tamano)) + (elRangoGrande.base + elRangoGrande.tamano - tamano_Segmento);
		GuardarNuevoSegmentoOrdenado(programa, base, tamano_Segmento);
	}
}

// guarda el un nuevo segmento ordenado por su base en lista de segmentos -- OK
int GuardarNuevoSegmentoOrdenado(char* programa, int base_virtual, int tamano) {
	Segmento * nuevo_segmento = create_segmento(programa,
			(MemFisica + base_virtual), base_virtual, tamano);

	if (list_is_empty(Segmentos_UMV)) { // si la lista esta vacia lo agregamos en la primer posicion
		list_add(Segmentos_UMV, nuevo_segmento);
		return 1;
	}
	else {   // si no esta vacia agregamos ordenado por la baseVirtual
		int pos = 0;
		Segmento aSeg = *((Segmento*) list_get(Segmentos_UMV, pos));
		while (list_size(Segmentos_UMV) > pos && aSeg.baseVirtual < base_virtual) // vamos a la posicion donde este ordenado
		{
			pos++;
			if(pos != list_size(Segmentos_UMV)){
				aSeg = *((Segmento*) list_get(Segmentos_UMV, pos));
			}
		}

		list_add_in_index(Segmentos_UMV, pos, nuevo_segmento);
		return 1;
	}
}

// Permite el cambio de FirstFit a WorstFit -- OK
void CambiarAlgoritmo(char* nombre_algoritmo) {
	if (string_equals_ignore_case("firstfit", nombre_algoritmo)) {
		AlgoritmoActual = ALGOTIRMO_FIRSTFIT;
		printf(" Se a cambiado el algoritmo a FirstFit ");
		return;
	}
	if (string_equals_ignore_case("worstfit", nombre_algoritmo)) {
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
	return (list_any_satisfy(listaRangosLibres, (void*) Hay_algun_rango_de_tamano_suficiente));

}

// Nos dice la cantidad total de memoria libre,
int CantidadMemoriaLibre() {

	int tamanoTotal = 0;

	void ContarTamano(RangoMemoria* rango) {
		tamanoTotal = tamanoTotal + rango->tamano;
	}

	t_list* rangosLibres = RangosLibresDeMemoria();

	list_iterate(rangosLibres, (void*)ContarTamano);

	return tamanoTotal;
}

void MostrarRangosMemoriaLibre() {

	void ContarTamano(RangoMemoria* rango) {
		 printf("Rango: Base %d , Tam: %d \n", rango->base, rango->tamano);
	}

	t_list* rangosLibres = RangosLibresDeMemoria();

	list_iterate(rangosLibres, (void*)ContarTamano);

}


// Nos devuelve un array de RangosDeMemoria con todos los rangos de memoria libres;
t_list *RangosLibresDeMemoria() {
	int pos = 0;
	int salida, llegada;
	RangoMemoria *rangoMem;
	t_list * rangos_de_memoria = list_create();

	if (list_is_empty(Segmentos_UMV)) {
		rangoMem = create_rango_mem(0, MemTotal);
		list_add(rangos_de_memoria, rangoMem);
		return rangos_de_memoria;
	}
	else{
		// primer segmento a analizar
		Segmento primerSegmento = *((Segmento*) list_get(Segmentos_UMV, 0));
		if(primerSegmento.baseVirtual != 0){
			salida = 0;
			llegada = primerSegmento.baseVirtual;
			rangoMem = create_rango_mem(salida, llegada);
			list_add(rangos_de_memoria, rangoMem);
		}
	}

	while (list_size(Segmentos_UMV) - 1 > pos) {

		Segmento segmentoAnterior = *((Segmento*) list_get(Segmentos_UMV, pos));
		Segmento segmentoPosterior = *((Segmento*) list_get(Segmentos_UMV,pos + 1));

		salida = segmentoAnterior.baseVirtual + segmentoAnterior.tamano;
		llegada = segmentoPosterior.baseVirtual;

		//con esto nos fijamos si hay espacio entre medio de los dos nodos
		if (salida < (llegada - 1)) {
			rangoMem = create_rango_mem(salida, llegada - salida);
			list_add(rangos_de_memoria, rangoMem);
		}

		pos++;
	}

	// Ultimo segmento a analizar
	Segmento ultimoSegmento = *((Segmento*) list_get(Segmentos_UMV, pos));
	salida = ultimoSegmento.baseVirtual + ultimoSegmento.tamano;

	if (MemTotal > salida) { // si no esta tocando el final de nuestra memoria
		rangoMem = create_rango_mem(salida, MemTotal - salida);
		list_add(rangos_de_memoria, rangoMem);
	}

	return rangos_de_memoria;
}

// compacta la memoria dejando tod el espacio libre junto.
void CompactaMemoria() {
	int pos = 0;
	int salida, llegada;

	if (list_is_empty(Segmentos_UMV)) {
		printf("No Hay nada que compactar");
		return;
	}

	Segmento segPrimero = *((Segmento*) list_get(Segmentos_UMV, pos));

	// Nos traemos el primer segmento a la poscicion 0 si no estaba ahi.
	if (segPrimero.baseVirtual != 0) {
		void* baseFisica = MemFisica;
		Segmento * segAcomodado = create_segmento(segPrimero.programa,
				baseFisica, 0, segPrimero.tamano);

		// copaimos toda la info del segmento y la ponemos donde va a estar el nuevo
		memcpy(baseFisica, segPrimero.base, segPrimero.tamano);

		//remplazamos el segmento viejo por el modificado
		list_replace(Segmentos_UMV, pos, segAcomodado);
	}

	while (list_size(Segmentos_UMV) - 1 > pos && list_size(Segmentos_UMV) > 1) {

		Segmento segPrimero = *((Segmento*) list_get(Segmentos_UMV, pos));
		Segmento segSegundo = *((Segmento*) list_get(Segmentos_UMV, pos + 1));
		salida = segPrimero.baseVirtual + segPrimero.tamano;
		llegada = segSegundo.baseVirtual;

		//con esto nos fijamos si hay espacio entre medio de los dos nodos
		if (salida < (llegada - 1)) {
			// si estaban separados compactamos
			void* baseFisica = MemFisica + salida + 1;
			Segmento * segAcomodado = create_segmento(segSegundo.programa,
					baseFisica, salida + 1, segSegundo.tamano);

			// copaimos toda la info del segmento y la ponemos donde va a estar el nuevo
			memcpy(baseFisica, segSegundo.base, segSegundo.tamano);

			//remplazamos el segmento viejo por el modificado
			list_replace(Segmentos_UMV, pos + 1, segAcomodado);
		}

		pos++;
	}
}

// solicita bytes para grabar en memoria
int SolicitarBytesParaGrabar(int base, int offset, int tamano, int buffer){
	return 1;
}

// Envia bytes
int EnviarBytes(int base, int offset, int tamano){
	return 1;
}

// Nos devuelve la pos del rango de mayor tamaño -- OK
RangoMemoria RangoMasGrandeLibre() {
	int pos = 0;
	int mayorTamano;
	RangoMemoria mayorRango;
	t_list * rangos = RangosLibresDeMemoria();

	while (list_size(rangos) > pos) {
		RangoMemoria rango = *((RangoMemoria*) list_get(rangos, pos));
		if (rango.tamano > mayorTamano) {
			mayorRango = rango;
			mayorTamano = rango.tamano;
		}
	}

	return mayorRango;
}

// Encargado de lanzar hilos de atencion y separarlos segun su funcionalidad
void EscucharYLanzarHilos() {

	int servidor = socket_crearServidor("127.0.0.1", 5000);
	if (servidor == -1) {
		printf("Error Al Crear Servidor UMV. Contactese con servicio tecnico.");
		return;
	}

	while (1) {
		int nueva_coneccion = socket_aceptarCliente(servidor);
		if (servidor == -1) {
			printf("Error Al Adquirir una nueva coneccion con el servidor UMV. Contactese con servicio tecnico.");
			return;
		}

		void * handshake;
		t_tipoEstructura tipo_estructura;
		if(socket_recibir(nueva_coneccion,&tipo_estructura, &handshake) == -1){ printf("Error al recibir el tipo de proceso que se conecta.");}

		if(((t_struct_handshake_umv*)handshake)->tipoProceso == CONST_NUM_KERNEL){
				printf("es un KERNEL");
				pthread_t hilo_kernel;
				pthread_create(&hilo_kernel, NULL, (void*) ManejoKernel, (void*)nueva_coneccion);
		}

		if(((t_struct_handshake_umv*)handshake)->tipoProceso == CONST_NUM_CPU){
				printf("es una CPU");

		}
	}

}

// se encarga de manejar la conneccion con el kernel
void ManejoKernel(int coneccion){
	t_tipoEstructura tipo_estructura;
	void * nuevoSegmento;
	socket_recibir(coneccion,&tipo_estructura, &nuevoSegmento);
}

