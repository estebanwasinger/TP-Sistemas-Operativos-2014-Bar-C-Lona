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

t_list *listaNEW;
t_list *listaREADY;
t_list *listaEXEC;
t_list *listaEXIT;
t_list *listaBLOCK;
t_list *listaProcesosActivos;

#define DIRECCION "127.0.0.1"
#define PUERTO 5000
#define MAX_CONNECTION_SERVER 60

int ID=0;




int main() {
	//********************************//
	//	  Presentacion          	  //
	//********************************//
	printf("            //********************************//\n");
	printf("            //         PROCESO  KERNEL        //\n");
	printf("            //********************************//\n");

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

	int fallo = socket_conectarCliente(socketUMV, "127.0.0.1", 4000);
	if (fallo == -1) {
		printf("\n Error al conectarse a la UMV \n");
	}

	// Se crea el socket/estructuraAuxNuevosProcesos/se crea el server
	int socketPLP;
	t_struct_descriptor_procesos*nuevoProceso=malloc(sizeof(t_struct_descriptor_procesos));
	socketPLP = socket_crearServidor("127.0.0.1", 5000);

	//Se crea puntero donde se va a guardar el codigoAnsisop/variable de la estructura recibida
	void * codigoAnsisop;
	t_tipoEstructura tipoEstructura;

	while(1){
		printf("Esperando conexión entrante de ProcesoPrograma");
		//Se crea el socketPLPdeescucha/ se bloquea hasta encontrar una conexión entrante
		int * socketPLPEscucha = malloc(sizeof(int));
		*socketPLPEscucha = socket_aceptarCliente(socketPLP);
		nuevoProceso->socket=socketPLPEscucha;

		//Se recibe el cóodigo ansisop
		socket_recibir(*socketPLPEscucha, &tipoEstructura, &codigoAnsisop);
		char* codigoAnsisopLiteral = (((t_struct_string*) codigoAnsisop)->string);

		//Creacion del PCB
		t_medatada_program * metadata = metadatada_desde_literal(codigoAnsisopLiteral);
		t_struct_pcb * nuevoPCB = malloc(sizeof(t_struct_pcb));
		nuevoPCB->iD = obtenerID();
		nuevoProceso->ID = nuevoPCB->iD;
		nuevoPCB->programa_counter = metadata->instruccion_inicio;
		nuevoProceso->PCB = nuevoPCB;

		t_struct_crear_segmento * solicitud = malloc(sizeof(t_struct_crear_segmento));
		solicitud->ID = nuevoPCB->iD;
		solicitud->tamanio = (strlen(codigoAnsisopLiteral));

		//Se crea Segmento Codigo Literal
		nuevoPCB->seg_codigo = solicitarCreacionSegmento(socketUMV,strlen(codigoAnsisopLiteral),nuevoPCB->iD);
		//Se crea Segmento Indice de Código
		nuevoPCB->indice_codigo = solicitarCreacionSegmento(socketUMV,metadata->cantidad_de_funciones*8,nuevoPCB->iD);
		//Se crea Segmento Indice de etiquetas
		nuevoPCB->indice_etiquetas = solicitarCreacionSegmento(socketUMV,metadata->etiquetas_size,nuevoPCB->iD);
		//Se crea Segmento Stack (FALTARIA VER EL ARCHIVO DE CONFIGURACION)
		nuevoPCB->seg_stack = solicitarCreacionSegmento(socketUMV,500,nuevoPCB->iD);

		//Estructura aux para enviar bytes
		t_struct_env_bytes * estructuraParaGuardar = malloc(sizeof(t_struct_env_bytes));

		//Se envia el código literal
		estructuraParaGuardar->base = nuevoPCB->seg_codigo;
		estructuraParaGuardar->offset = 0;
		estructuraParaGuardar->tamanio = strlen(codigoAnsisopLiteral);
		estructuraParaGuardar->buffer = codigoAnsisopLiteral;
		socket_enviar(socketUMV, D_STRUCT_ENVIAR_BYTES, estructuraParaGuardar);

		//Se envia el indice de cóidgo
		estructuraParaGuardar->base = nuevoPCB->indice_codigo;
		estructuraParaGuardar->offset = 0;
		estructuraParaGuardar->tamanio = metadata->cantidad_de_funciones*8;
		estructuraParaGuardar->buffer = metadata->instrucciones_serializado;
		socket_enviar(socketUMV, D_STRUCT_ENVIAR_BYTES, estructuraParaGuardar);

		//Se envia el indice de etiquetas
		estructuraParaGuardar->base = nuevoPCB->indice_etiquetas;
		estructuraParaGuardar->offset = 0;
		estructuraParaGuardar->tamanio = metadata->etiquetas_size;
		estructuraParaGuardar->buffer = metadata->etiquetas;
		socket_enviar(socketUMV, D_STRUCT_ENVIAR_BYTES, estructuraParaGuardar);

		int pesoJob = calcularPesoJob(metadata);

		t_struct_peso_pcb *pesoPCB = malloc(sizeof(t_struct_peso_pcb));
		pesoPCB->pcb = nuevoPCB;
		pesoPCB->peso = pesoJob;

		insertarPCBOrdenadoSJN(listaNEW, pesoPCB);

		free(solicitud);
		free(estructuraParaGuardar);
	}

	return 0;
}
void* mainPCP() {
	printf("Hola soy el PCP \n\n");
	pasarPCBsimple(listaNEW, listaREADY);
	return 0;
}

int obtenerID(){
	ID++;
	return ID;
}

int calcularPesoJob(t_medatada_program* metadata) {
	int pesoJob;
	pesoJob= 5 * metadata->cantidad_de_etiquetas+ 3 * metadata->cantidad_de_funciones + metadata->instrucciones_size;
	return pesoJob;
}

void insertarPCBOrdenadoSJN(t_list *lista, t_struct_peso_pcb *registroPCB) {
	int pos = 0;
	if (list_is_empty(lista) == 0) {
		list_add(lista, registroPCB);
	} else {
		while (registroPCB->peso
				> ((t_struct_peso_pcb*) list_get(lista, pos))->peso) {
			pos++;

		}

		list_add_in_index(lista, (pos + 1), registroPCB);
	}
}

void pasarPCB(t_list *lista1, t_list *lista2) {
	list_add(lista2,list_remove(lista1, 0));
}

void pasarPCBsimple(t_list *listaNew, t_list *listaReady) {
	t_struct_pcb *nuevoPCB = ((t_struct_peso_pcb*)(list_remove(listaNew, 0)))->pcb;
	list_add(listaReady, nuevoPCB);
}

int solicitarCreacionSegmento(int socketUMV,int tamanio,int ID){
		void * direccionRecibida;
		t_tipoEstructura numeroEstruct;
		t_struct_crear_segmento * pedido = malloc(sizeof(t_struct_crear_segmento));
		pedido->tamanio=tamanio;
		pedido->ID=ID;
		socket_enviar(socketUMV,D_STRUCT_CREAR_SEGMENTO,pedido);
		socket_recibir(socketUMV,&numeroEstruct,&direccionRecibida);
		return((t_struct_numero*)direccionRecibida)->numero;
	}
