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
	char buffer[1024];

	int socketPLP;
	int socketPLPEscucha;
	int nbytesRecibidos;
	socketPLP = socket_crearServidor("127.0.0.1",5000);
	socketPLPEscucha = socket_aceptarCliente(socketPLP);

	while (1) {

		// Recibir hasta BUFF_SIZE datos y almacenarlos en 'buffer'.
		if ((nbytesRecibidos = recv(socketPLPEscucha, buffer, 1024, 0)) > 0) {

			//	printf("Mensaje recibido: ");
			fwrite(buffer, 1, nbytesRecibidos, stdout);
			t_medatada_program* metadata;
			metadata = metadata_desde_literal(buffer);
			imprimirMetadata(metadata);
			printf("\n");
			//  printf("Tamanio del buffer %d bytes!\n", nbytesRecibidos);
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
	printf("Hola soy el PCP \n\n");

	return 0;
}

int socket_crearCliente(void) {

	int sockfd;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Error al crear socket"); //Crear log para este error.
		return -1;
	}

	return sockfd;

}
int socket_conectarCliente(int sockfd, char *serverIp, int serverPort) {

	struct sockaddr_in socketInfo;

	//INICIALIZACION DE SOCKETINFO
	socketInfo.sin_family = AF_INET;
	socketInfo.sin_port = htons(serverPort); //host to network short
	socketInfo.sin_addr.s_addr = inet_addr(serverIp);
	memset(&(socketInfo.sin_zero), '\0', 8); // PONGO A 0 EL RESTO DE LA ESTRUCTURA
	// ME CONECTO CON LA DIRECCIÓN DE SOCKETINFO
	//SIEMPRE VERIFICANDO QUE NO DEN -1 LAS FUNCIONES O 0 EN CASO DE RECV() -- SOLO PARA SERVER IGUAL :)

	if (connect(sockfd, (struct sockaddr *) &socketInfo, sizeof(socketInfo))
			== -1) {
		perror("Falló la conexión"); // Cambiar esto por un log.
		return -1;
	}

	return sockfd;
}
int socket_crearYConectarCliente(char *serverIp, int serverPort) {
	int sockfd;
	sockfd = socket_crearCliente();
	if (sockfd < 0)
		return -1;

	sockfd = socket_conectarCliente(sockfd, (char*) serverIp, serverPort);

	return sockfd;
}
int socket_crearServidor(char *ip, int port) {
	int socketEscucha;
	struct sockaddr_in miSocket; //ESTE ES EL SOCKET CON LA DRECCION IP

	if ((socketEscucha = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Error al crear socket");
		return -1;
	}

	miSocket.sin_family = AF_INET;
	miSocket.sin_port = htons(port);
	miSocket.sin_addr.s_addr = inet_addr(ip);
	memset(&(miSocket.sin_zero), '\0', 8); //NI LE PRESTEN ATENCION A ESTO

	int yes = 1;
	if (setsockopt(socketEscucha, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int))
			== -1) {
		perror("setsockopt");
		exit(1);
	}

	if (bind(socketEscucha, (struct sockaddr*) &miSocket, sizeof(miSocket))
			== -1) {
		perror("Error al bindear el socket escucha");
		return -1;
	}

	if (listen(socketEscucha, MAX_CONNECTION_SERVER) == -1) {
		perror("Error en la puesta de escucha");
		return -1;
	}

	return socketEscucha;

}
int socket_crearServidorPuertoRandom(char *ip, int * port) {
	int socketEscucha;
	struct sockaddr_in miSocket; //ESTE ES EL SOCKET CON LA DRECCION IP

	if ((socketEscucha = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Error al crear socket");
		return -1;
	}

	miSocket.sin_family = AF_INET;
	miSocket.sin_port = htons(0);
	miSocket.sin_addr.s_addr = inet_addr(ip);
	memset(&(miSocket.sin_zero), '\0', 8); //NI LE PRESTEN ATENCION A ESTO

	int yes = 1;
	if (setsockopt(socketEscucha, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int))
			== -1) {
		perror("setsockopt");
		exit(1);
	}

	if (bind(socketEscucha, (struct sockaddr*) &miSocket, sizeof(miSocket))
			== -1) {
		perror("Error al bindear el socket escucha");
		return -1;
	}

	if (listen(socketEscucha, MAX_CONNECTION_SERVER) == -1) {
		perror("Error en la puesta de escucha");
		return -1;
	}

	struct sockaddr_in sin;
	socklen_t len = sizeof(sin);
	if (getsockname(socketEscucha, (struct sockaddr *) &sin, &len) == -1) {
		perror("getsockname");
		return -1;
	}

	*port = ntohs(sin.sin_port);

	return socketEscucha;
}
int socket_aceptarCliente(int socketEscucha) {
	int socketNuevaConexion;
	unsigned int size_sockAddrIn;

	struct sockaddr_in suSocket;

	size_sockAddrIn = sizeof(struct sockaddr_in);
	socketNuevaConexion = accept(socketEscucha, (struct sockaddr *) &suSocket,
			&size_sockAddrIn);

	if (socketNuevaConexion < 0) {

		perror("Error al aceptar conexion entrante");
		return -1;

	}

	return socketNuevaConexion;

}
