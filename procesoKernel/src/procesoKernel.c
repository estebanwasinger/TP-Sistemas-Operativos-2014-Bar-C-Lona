/*
 ============================================================================
 Name        : procesoKernel.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <parser/metadata_program.h>
#include <parser/parser.h>
#include <string.h>
#include <commons/log.h>
#include <commons/config.h>
#include <commons/string.h>
#include <pthread.h>
#include <commons/collections/list.h>
#include "procesoKernel.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <socket.h>
#include <package.h>
#include <estructurasPackage.h>

pthread_t hiloPLP;
pthread_t hiloPCP;

t_list *listaNEW;
t_list *listaREADY;
t_list *listaEXEC;
t_list *listaEXIT;
t_list *listaBLOCK;

#define DIRECCION "127.0.0.1"
#define PUERTO 5000
#define MAX_CONNECTION_SERVER 60

int ID=0;

typedef struct registroPCB {
	int peso;
	t_struct_pcb pcb;
} t_struct_peso_pcb;

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

void imprimirMetadata(t_medatada_program* metadata) {
	printf("cantidad de instrucciones: %d\n", metadata->instrucciones_size);
	printf("Cantidad de etiquetas %i\n", metadata->cantidad_de_etiquetas);
	printf("Cantidad de funciones %i\n", metadata->cantidad_de_funciones);
	printf("Etiquetas %s\n", metadata->etiquetas);
	printf("Tamaño del mapa serializado de etiquetas %i\n",
			metadata->etiquetas_size);
	printf("Tamaño del mapa serializado de instrucciones %i\n",
			metadata->instrucciones_size);
	printf("El numero de la primera instruccion es %i\n",
			metadata->instruccion_inicio);
}

void* mainPLP() {

	printf("Hola soy el PLP\n\n");

	// Escuchar conexiones entrantes de los procesosPrograma

	int socketPLP;
	int socketPLPEscucha;

	socketPLP = socket_crearServidor("127.0.0.1", 5000);
	socketPLPEscucha = socket_aceptarCliente(socketPLP);

	//Recibir Código Ansisop
	void * codigoAnsisop;
	t_tipoEstructura tipoEstructura;
	socket_recibir(socketPLPEscucha, &tipoEstructura, &codigoAnsisop);
	char* codigoAnsisopLiteral = (((t_struct_string*) codigoAnsisop)->string);

	//Nos conectamos a la UMV
	int socketUMV;
	socket_conectarCliente(socketUMV,"127.0.0.1",4000);

	//Creacion del PCB
	t_medatada_program * metadata = metadatada_desde_literal(codigoAnsisopLiteral);
	t_struct_pcb * nuevoPCB = malloc(sizeof(t_struct_pcb));
	nuevoPCB->iD=obtenerID();
	nuevoPCB->programa_counter=0;

	t_struct_crear_segmento * solicitud = malloc(sizeof(t_struct_crear_segmento));
	solicitud->ID=nuevoPCB->iD;
	solicitud->tamanio=(strlen(codigoAnsisopLiteral));


	void * direccionRecibida;

	//Se crea Segmento Codigo Literal
	socket_enviar(socketUMV,D_STRUCT_CREAR_SEGMENTO,solicitud);
	socket_recibir(socketUMV,&tipoEstructura,&direccionRecibida);
	nuevoPCB->seg_codigo=((t_struct_numero*)direccionRecibida)->numero;

	//Se crea Segmento Indice de Código
	solicitud->tamanio=(metadata->cantidad_de_funciones*8);
	socket_enviar(socketUMV,D_STRUCT_CREAR_SEGMENTO,solicitud);
	socket_recibir(socketUMV,&tipoEstructura,&direccionRecibida);
	nuevoPCB->indice_codigo=((t_struct_numero*)direccionRecibida)->numero;

	//Se crea Segmento Indice de etiquetas
	solicitud->tamanio=metadata->etiquetas_size;
	socket_enviar(socketUMV,D_STRUCT_CREAR_SEGMENTO,solicitud);
	socket_recibir(socketUMV,&tipoEstructura,&direccionRecibida);
	nuevoPCB->indice_etiquetas=((t_struct_numero*)direccionRecibida)->numero;

	//Se crea Segmento Stack (FALTARIA VER EL ARCHIVO DE CONFIGURACION)
	solicitud->tamanio=500;
	socket_enviar(socketUMV,D_STRUCT_CREAR_SEGMENTO,solicitud);
	socket_recibir(socketUMV,&tipoEstructura,&direccionRecibida);
	nuevoPCB->seg_stack=((t_struct_numero*)direccionRecibida)->numero;

	//Se envia el código literal
	t_struct_env_bytes * estructuraParaGuardar = malloc(sizeof(t_struct_env_bytes));
	estructuraParaGuardar->base=nuevoPCB->seg_codigo;
	estructuraParaGuardar->offset=0;
	estructuraParaGuardar->tamanio=strlen(codigoAnsisopLiteral);
	estructuraParaGuardar->buffer=codigoAnsisopLiteral;
	socket_enviar(socketUMV,D_STRUCT_ENVIAR_BYTES,estructuraParaGuardar);

	//Se envía el Indice de código
	t_struct_env_bytes * estructuraParaGuardar = malloc(sizeof(t_struct_env_bytes));
	estructuraParaGuardar->base = nuevoPCB->seg_codigo;
	estructuraParaGuardar->offset = 0;
	estructuraParaGuardar->tamanio = strlen(codigoAnsisopLiteral);
	estructuraParaGuardar->buffer = codigoAnsisopLiteral;
	socket_enviar(socketUMV, D_STRUCT_ENVIAR_BYTES, estructuraParaGuardar);


	return 0;
}
void* mainPCP() {
	printf("Hola soy el PCP \n\n");

	return 0;
}

int obtenerID(){
	ID++;
	return ID;
}

int pcb_calcularPeso(t_medatada_program* metadata) {
	int pesoJob;
	pesoJob = +metadata->cantidad_de_etiquetas;
	pesoJob = +metadata->cantidad_de_etiquetas;

	return pesoJob;
}

int grabarSegmentoCodigoLiteral(int32_t ID, char* codigo) {

//	Con el ID y el codigo literal mandar un mensaje serializado para que la UMV guarde el segmento y devuelva la direccion me memoria
	int dir_memoria = 0;
	return dir_memoria;
}

void insertarPCBOrdenado(t_list *lista, t_struct_peso_pcb *registroPCB) {
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
	t_struct_pcb *nuevoPCB = malloc(sizeof(t_struct_pcb));
	*nuevoPCB = ((t_struct_peso_pcb*)(list_remove(listaNew, 0)))->pcb;
	list_add(listaReady, nuevoPCB);
}
