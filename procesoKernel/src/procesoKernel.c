/*
 ============================================================================
 Name        : procesoKernel.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "procesoKernel.h"

pthread_t hiloPLP;
pthread_t hiloPCP;
pthread_t pasarNewAReady;

pthread_mutex_t S_Lista_New = PTHREAD_MUTEX_INITIALIZER;

t_list *listaNEW;
t_list *listaREADY;
t_list *listaEXEC;
t_list *listaEXIT;
t_list *listaBLOCK;
t_list *listaProcesosActivos;

#define DIRECCION "127.0.0.1"
#define PUERTO 5000
#define MAX_CONNECTION_SERVER 60

int ID = 0;
unsigned int nivelDeMultiProgramacionActual = 0;

t_log * logger;
int puerto_programa;
int puerto_cpu;
int Quantum;
int Retardo;
int nivel_multiprogramacion;

t_config * configuracion;
char * tempID_HIO;
char * temp_retardoDisp;
char * tempSemaforos;
char * temp_valorIni;
int cantidad_dispositivos;
int cantidad_semaforos;
char ** ID_HIO;
char ** retardo_dispositivo;
char ** semaforos;
char ** valor_semaforo;

int main() {

	//********************************//
	//	  Presentacion          	  //
	//********************************//
	printf("            //********************************//\n");
	printf("            //         PROCESO  KERNEL        //\n");
	printf("            //********************************//\n");

	cargarArchivoConfiguracion();

	//********************************//
	//	  Creacion de las listas	  //
	//********************************//

	listaNEW = list_create();
	listaREADY = list_create();
	listaEXEC = list_create();
	listaEXIT = list_create();
	listaBLOCK = list_create();
	listaProcesosActivos = list_create();

	//-------------------------------//

	//********************************//
	//	  Creacion de los hilos  	  //
	//********************************//

	pthread_create(&hiloPLP, NULL, mainPLP, NULL );
	pthread_create(&hiloPCP, NULL, mainPCP, NULL );

	//-----------------------------//

	pthread_join(hiloPLP, NULL );
	pthread_join(hiloPCP, NULL );

	return 0;
}

void* mainPLP() {

	printf("Hola soy el PLP\n\n");

	//Nos conectamos a la UMV
	printf("Conectandose a la UMV... \n");
	int socketUMV;

	socketUMV = socket_crearCliente();
	if (socketUMV == -1) {
		printf("\nError al crear el cliente UMV\n");
	}
	printf("UMV CONECTADA! \n");
	int fallo = socket_conectarCliente(socketUMV, "127.0.0.1", 5000);
	if (fallo == -1) {
		printf("\n Error al conectarse a la UMV \n");
	}

	t_struct_handshake_umv * handshake = malloc(sizeof(t_struct_handshake_umv));
	handshake->tipoProceso = 1;

	socket_enviar(socketUMV, D_STRUCT_HANDSHAKE_UMV, handshake);

	// Se crea el socket/estructuraAuxNuevosProcesos/se crea el server
	int socketPLP;
	t_struct_descriptor_procesos*nuevoProceso = malloc(
			sizeof(t_struct_descriptor_procesos));
	socketPLP = socket_crearServidor("127.0.0.1", 6000);

	//Se crea puntero donde se va a guardar el codigoAnsisop/variable de la estructura recibida

	while (1) {

		printf("Esperando conexión entrante de ProcesoPrograma\n");
		void * codigoAnsisop;
		t_tipoEstructura tipoEstructura;

		//Se crea el socketPLPdeescucha/ se bloquea hasta encontrar una conexión entrante
		int * socketPLPEscucha = malloc(sizeof(int));
		*socketPLPEscucha = socket_aceptarCliente(socketPLP);
		printf("PROCESO CONECTADO! \n");
		nuevoProceso->socket = socketPLPEscucha;

		//Se recibe el cóodigo ansisop
		socket_recibir(*socketPLPEscucha, &tipoEstructura, &codigoAnsisop);
		char* codigoAnsisopLiteral =
				(((t_struct_string*) codigoAnsisop)->string);

		//Creacion del PCB
		t_metadata_program * metadata = metadata_desde_literal(
				codigoAnsisopLiteral);
		t_struct_pcb * nuevoPCB = malloc(sizeof(t_struct_pcb));
		nuevoPCB->iD = obtenerID();
		nuevoProceso->ID = nuevoPCB->iD;
		nuevoPCB->programa_counter = metadata->instruccion_inicio;
		nuevoProceso->PCB = nuevoPCB;

		t_struct_crear_segmento * solicitud = malloc(
				sizeof(t_struct_crear_segmento));
		solicitud->ID = nuevoPCB->iD;
		solicitud->tamanio = (strlen(codigoAnsisopLiteral));

		//Se crea Segmento Codigo Literal
		printf("Creacion segmento Cod literal! \n");
		nuevoPCB->seg_codigo = solicitarCreacionSegmento(socketUMV,
				strlen(codigoAnsisopLiteral), nuevoPCB->iD);
		//Se crea Segmento Indice de Código
		printf("Creacion segmento Ind Codigo! \n");
		nuevoPCB->indice_codigo = solicitarCreacionSegmento(socketUMV,
				metadata->cantidad_de_funciones * 8, nuevoPCB->iD);
		//Se crea Segmento Indice de etiquetas
		printf("Creacion segmento Ind de etiquetas! \n");
		nuevoPCB->indice_etiquetas = solicitarCreacionSegmento(socketUMV,
				metadata->etiquetas_size, nuevoPCB->iD);
		//Se crea Segmento Stack (FALTARIA VER EL ARCHIVO DE CONFIGURACION)
		printf("Creacion segmento Stack! \n");
		nuevoPCB->seg_stack = solicitarCreacionSegmento(socketUMV, 500,
				nuevoPCB->iD);

		//Estructura aux para enviar bytes
		t_struct_env_bytes * estructuraParaGuardar = malloc(
				sizeof(t_struct_env_bytes));
		t_tipoEstructura tipoRecibiido;
		void * cosaRecibida;
		printf("Se envia codigo literal! \n");
		//Se envia el código literal
		estructuraParaGuardar->base = nuevoPCB->seg_codigo;
		estructuraParaGuardar->offset = 0;
		estructuraParaGuardar->tamanio = strlen(codigoAnsisopLiteral);
		estructuraParaGuardar->buffer = codigoAnsisopLiteral;
		socket_enviar(socketUMV, D_STRUCT_ENVIAR_BYTES, estructuraParaGuardar);
		socket_recibir(socketUMV, &tipoRecibiido, &cosaRecibida);

//		t_struct_sol_bytes* estructuraRecibida = malloc(sizeof(t_struct_sol_bytes));
//		estructuraRecibida->base=nuevoPCB->seg_codigo;
//		estructuraRecibida->offset=0;
//		estructuraRecibida->tamanio = strlen(codigoAnsisopLiteral);
//		socket_enviar(socketUMV,D_STRUCT_SOLICITAR_BYTES,estructuraRecibida);
//
//		socket_recibir(socketUMV,&tipoRecibiido,&cosaRecibida);
//		printf("%d",((t_struct_respuesta_umv*)cosaRecibida)->tamano_buffer);
//		printf("%s",(char*)(((t_struct_respuesta_umv*)cosaRecibida)->buffer));

		//Se envia el indice de cóidgo
		printf("Se envia ind codigo! \n");
		estructuraParaGuardar->base = nuevoPCB->indice_codigo;
		estructuraParaGuardar->offset = 0;
		estructuraParaGuardar->tamanio = metadata->cantidad_de_funciones * 8;
		estructuraParaGuardar->buffer = metadata->instrucciones_serializado;
		socket_enviar(socketUMV, D_STRUCT_ENVIAR_BYTES, estructuraParaGuardar);
		socket_recibir(socketUMV, &tipoRecibiido, &cosaRecibida);

		//Se envia el indice de etiquetas
		printf("Se envia ind etiquetas! \n");
		estructuraParaGuardar->base = nuevoPCB->indice_etiquetas;
		estructuraParaGuardar->offset = 0;
		estructuraParaGuardar->tamanio = metadata->etiquetas_size;
		estructuraParaGuardar->buffer = metadata->etiquetas;
		socket_enviar(socketUMV, D_STRUCT_ENVIAR_BYTES, estructuraParaGuardar);
		socket_recibir(socketUMV, &tipoRecibiido, &cosaRecibida);

		int pesoJob = calcularPesoJob(metadata);

		t_struct_peso_pcb *pesoPCB = malloc(sizeof(t_struct_peso_pcb));
		pesoPCB->pcb = nuevoPCB;
		pesoPCB->peso = pesoJob;

		//Insertar en las correspondientes listas
		list_add(listaProcesosActivos, nuevoProceso);
		insertarPCBOrdenadoSJN(listaNEW, pesoPCB);

		free(solicitud);
		free(estructuraParaGuardar);
	}

	return 0;
}
void* mainPCP() {
	printf("Hola soy el PCP \n\n");
	pthread_create(&pasarNewAReady, NULL, newAReady, NULL );

	return 0;
}

int obtenerID() {
	ID++;
	return ID;
}

int calcularPesoJob(t_medatada_program* metadata) {
	int pesoJob;
	pesoJob = 5 * metadata->cantidad_de_etiquetas
			+ 3 * metadata->cantidad_de_funciones
			+ metadata->instrucciones_size;
	return pesoJob;
}

void insertarPCBOrdenadoSJN(t_list *lista, t_struct_peso_pcb *registroPCB) {
	int pos = 0;
	if (list_is_empty(lista) == 1) {
		list_add(lista, registroPCB);
	} else {
		while (registroPCB->peso
				> ((t_struct_peso_pcb*) list_get(lista, pos))->peso) {
			pos++;

		}
		pthread_mutex_lock(&S_Lista_New);
		list_add_in_index(lista, (pos + 1), registroPCB);
		pthread_mutex_unlock(&S_Lista_New);
	}
}

void pasarPCB(t_list *lista1, t_list *lista2) {
	list_add(lista2, list_remove(lista1, 0));
}

void pasarPCBsimple(t_list *listaNew, t_list *listaReady) {
	t_struct_pcb *nuevoPCB =
			((t_struct_peso_pcb*) (list_remove(listaNew, 0)))->pcb;
	pthread_mutex_lock(&S_Lista_New);
	list_add(listaReady, nuevoPCB);
	pthread_mutex_unlock(&S_Lista_New);
}

int solicitarCreacionSegmento(int socketUMV, int tamanio, int ID) {
	void * direccionRecibida;
	t_tipoEstructura numeroEstruct;
	t_struct_crear_segmento * pedido = malloc(sizeof(t_struct_crear_segmento));
	pedido->tamanio = tamanio;
	pedido->ID = ID;
	socket_enviar(socketUMV, D_STRUCT_CREAR_SEGMENTO, pedido);
	socket_recibir(socketUMV, &numeroEstruct, &direccionRecibida);
	return ((t_struct_numero*) direccionRecibida)->numero;
}

void* newAReady() {
	while (1) {
		if (nivelDeMultiProgramacionActual < 5) {
		}
	}

	return 0;
}

int conf_es_valida(t_config * configuracion) {
	return (config_has_property(configuracion, "ID_HIO")
			&& config_has_property(configuracion, "HIO")
			&& config_has_property(configuracion, "SEMAFOROS")
			&& config_has_property(configuracion, "VALOR_SEMAFORO")
			&& config_has_property(configuracion, "MULTIPROGRAMACION")
			&& config_has_property(configuracion, "PUERTO_PROG")
			&& config_has_property(configuracion, "PUERTO_CPU")
			&& config_has_property(configuracion, "QUANTUM")
			&& config_has_property(configuracion, "RETARDO"));
}

int string_count(char * text, char c) {
	int i = 0;
	int pos = 0;

	while (text[pos] != '\0') {
		if (text[pos] == c)
			i++;
		pos++;
	}
	return i;
}

int cargarArchivoConfiguracion() {
	int retorno = 0;
	//		******************************************************//
	//																//
	//		-------------Leer archivo de configuracion------------//
	//																//
	//		******************************************************//

	configuracion =
			config_create(
					"/home/utnso/workspace/tp-2014-1c-bar-c-lona/procesoKernel/Debug/kernel.conf");

	if (!conf_es_valida(configuracion)) //ver que el archivo de config tenga todito
			{
		puts("Archivo de configuracion incompleto o invalido.\n");
		retorno = -2;
	}

	puerto_cpu = config_get_int_value(configuracion, "PUERTO_CPU");
	puerto_programa = config_get_int_value(configuracion, "PUERTO_PROG");
	Quantum = config_get_int_value(configuracion, "QUANTUM");
	Retardo = config_get_int_value(configuracion, "RETARDO");
	nivel_multiprogramacion = config_get_int_value(configuracion,
			"MULTIPROGRAMACION");

	printf("puerto_cpu:%d\n", puerto_cpu);
	printf("puerto_programa:%d\n", puerto_programa);
	printf("Quantum:%d\n", Quantum);
	printf("Retardo:%d\n", Retardo);
	printf("nivel_multiprogramacion:%d\n", nivel_multiprogramacion);

	tempID_HIO = strdup(config_get_string_value(configuracion, "ID_HIO"));
	cantidad_dispositivos = string_count(tempID_HIO, ',') + 1;
	ID_HIO = string_get_string_as_array(tempID_HIO);
	free(tempID_HIO);

	temp_retardoDisp = strdup(config_get_string_value(configuracion, "HIO"));
	retardo_dispositivo = string_get_string_as_array(temp_retardoDisp);
	free(temp_retardoDisp);

	int i = 0;
	int retardo_entero;

	while (i < cantidad_dispositivos) {

		retardo_entero = atoi(retardo_dispositivo[i]);
		printf("el Dispositivo es:%s y tiene un retardo de:%d\n", ID_HIO[i],
				retardo_entero);
		i++;
	}
	tempSemaforos = strdup(config_get_string_value(configuracion, "SEMAFOROS"));
	cantidad_semaforos = string_count(tempSemaforos, ',') + 1;
	semaforos = string_get_string_as_array(tempSemaforos);
	free(tempSemaforos);

	temp_valorIni = strdup(
			config_get_string_value(configuracion, "VALOR_SEMAFORO"));
	valor_semaforo = string_get_string_as_array(temp_valorIni);
	free(temp_valorIni);

	int j = 0;
	int valor_entero;

	while (j < cantidad_semaforos) {

		valor_entero = atoi(valor_semaforo[j]);
		printf("el Semaforo es:%s y tiene un Valor de:%d\n", semaforos[j],
				valor_entero);
		j++;
	}

	//			******************************************************//
	//																	//
	//			-----------Fin de lectura Arch Configuracion----------//
	//																	//
	//			******************************************************//
return retorno;
}


