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
#include <sys/socket.h>
pthread_t hiloPLP;
pthread_t hiloPCP;

t_list *listaNEW;
t_list *listaREADY;
t_list *listaEXEC;
t_list *listaEXIT;
t_list *listaBLOCK;

#define DIRECCION "127.0.0.1"
#define PUERTO 5000

int main() {

	//********************************//
	//	  Creacion de las listas	  //
	//********************************//

	listaNEW = list_create();
	listaREADY = list_create();
	listaEXEC = list_create();
	listaEXIT = list_create();
	listaBLOCK = list_create();

	//-------------------------------//

	FILE *file = NULL;
	file =
			fopen(
					"/home/utnso/workspace/tp-2014-1c-bar-c-lona/procesoKernel/Debug/completo.ansisop",
					"r");
	char* codigo = leer_codAnsisop(file);
	printf("%s", codigo);

	t_medatada_program* metadata;
	metadata = metadata_desde_literal(codigo);
	imprimirMetadata(metadata);

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

char* leer_codAnsisop(FILE *file) {
	char c;
	fseek(file, 0L, SEEK_END);
	int size = ftell(file);
	fseek(file, 0L, SEEK_SET);
	int size2 = size;
	char* text = malloc(size2);
	char text2[size2];
	int i = 0;
	while ((c = getc(file)) != '\n')
		(c = getc(file));
	while ((c = getc(file)) != EOF) { //Lee cada caracter hasta encuentre el EndOfFile
		text2[i] = c;
		i++;
	}
	strcpy(text, text2);

	fclose(file);
	return text;
}

void* mainPLP() {
	printf("Hola soy el PLP");
	struct sockaddr_in socketInfo;
	char buffer[1024];
	socketInfo.sin_family = AF_INET;
	socketInfo.sin_addr.s_addr = DIRECCION;
	socketInfo.sin_port = htons(PUERTO);

	int socketPLP;
	int socketPLPEscucha;
	int nbytesRecibidos;
	socketPLP = socket(AF_INET, SOCK_STREAM, 0);
	bind(socketPLP, (struct sockaddr*) &socketInfo, sizeof(socketInfo));
	listen(socketPLP, 10);
	socketPLPEscucha = accept(socketPLP,NULL,0);

	while (1) {

		// Recibir hasta BUFF_SIZE datos y almacenarlos en 'buffer'.
		if ((nbytesRecibidos = recv(socketPLPEscucha, buffer, 1024, 0))> 0) {

		//	printf("Mensaje recibido: ");
			fwrite(buffer, 1, nbytesRecibidos, stdout);
			printf("\n");
	//		printf("Tamanio del buffer %d bytes!\n", nbytesRecibidos);
			fflush(stdout);

			if (memcmp(buffer, "fin", nbytesRecibidos) == 0) {

				printf("Server cerrado correctamente.\n");
				break;

			}

		} else {
//			printf("Tamanio del buffer %d bytes!\n", nbytesRecibidos);
			perror("Error al recibir datos");
			break;
		}
	}

	close(socketPLP);
	close(socketPLPEscucha);

return 0;
}
void* mainPCP() {
printf("Hola soy el PCP");

return 0;
}

