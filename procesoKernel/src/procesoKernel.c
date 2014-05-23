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
#include "socket.h"
#include "estructurasPackage.h"
#include "package.h"

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
	//char buffer[1024];
	int socketPLP;
	int socketPLPEscucha;
	//int nbytesRecibidos;
//	t_struct_handshakeUMV soyKernel;

	t_tipoEstructura * tipoHandshake = malloc(1);
	*tipoHandshake = 3;
	void *puntero = &soyKernel;
	socketPLP = socket_crearServidor("127.0.0.1",5000);
	socketPLPEscucha = socket_aceptarCliente(socketPLP);
	int ret = socket_recibir(socketPLPEscucha,tipoHandshake,puntero);
	printf("RETT %d",ret);

printf("\n Recibido: %d\n",soyKernel.tipo);
	close(socketPLP);
	close(socketPLPEscucha);

	return 0;
}
void* mainPCP() {
	printf("Hola soy el PCP \n\n");

	return 0;
}

int pcb_calcularPeso(t_medatada_program* metadata){
	int pesoJob;
	pesoJob =+ metadata->cantidad_de_etiquetas;
	pesoJob =+ metadata->cantidad_de_etiquetas;

	return pesoJob;
}

int grabarSegmentoCodigoLiteral(int32_t ID,char* codigo){
//	Con el ID y el codigo literal mandar un mensaje serializado para que la UMV guarde el segmento y devuelva la direccion me memoria
	int dir_memoria = 0;
	return dir_memoria;
}

