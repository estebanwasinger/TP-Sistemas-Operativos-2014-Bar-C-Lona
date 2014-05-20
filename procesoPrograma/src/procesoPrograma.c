/*
 ============================================================================
 Name        : procesoPrograma.c
 Author      : Bar C Lona
 Version     :
 Copyright   : (R) Copyright Bar C Lona - 2014
 Description : ProcesoPrograma
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/config.h>
#include <commons/log.h>
#include <commons/string.h>
#include "procesoPrograma.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <errno.h>
#include <sys/ioctl.h>

#define DIRECCION "127.0.0.1"
#define PUERTO 5000
#define MAX_CONNECTION_SERVER 60

int Puerto;
char * IP;
t_log * logger;

int main(int argc, char** argv) {
	FILE *file;
//	t_config * configuracion;
//	char * temp_IP;
//    char * log_name;
//
//    log_name = malloc(strlen("Programa")+1);
//    strcpy(log_name, "Programa");
//    string_append(&log_name,".log"); // queda : nombre.log
//
//    logger = log_create(log_name, "Programa", 1, LOG_LEVEL_TRACE);
//    free(log_name);
//
//	//-------------leer archivo de configuracion>------------//
//
//	if (argc != 3) //controlar que haya exactamente dos parámetro
//			{
//		puts("Uso: programa <arch.conf>\n");
//		return -1;  // esto me saca inmediatamente del main ?
//	}
//
//	configuracion = config_create(argv[1]);
//
//	if (!conf_es_valida(configuracion)) //ver que el archivo de config tenga todito
//			{
//		puts("Archivo de configuracion incompleto o invalido.\n");
//		return -2;
//	}
//
//	Puerto = config_get_int_value(configuracion, "Puerto");
//	temp_IP = config_get_string_value(configuracion, "IP");
//	IP = malloc(strlen(temp_IP) + 1);
//	strcpy(IP, temp_IP);
//
//	log_info(logger,"EL ARCHIVO DE CONFIGURACION SE LEVANTO CORRECTAMENTE");
//
//	printf("Puerto=%d\n", Puerto); //imprime por pantalla el puerto
//	printf("IP=%s\n", IP);     //imprime por pantalla la IP
//	printf("\n");

//	struct sockaddr_in socketInfo;

	//**********************************//
	//	   Conexión con el Kernel		//
	//**********************************//

	int socketKernel;
	socketKernel = socket_crearCliente();
	socket_conectarCliente(socketKernel, "127.0.0.1", 5000);

	//**********************************//
	//	   Leectura y envio de codigo	//
	//**********************************//

	file = abrir_archivoRO(argv);
	int size = size_archivo(file);
	char* codigo = leer_codAnsisop(file);

	send(socketKernel, codigo, size, 0);
	send(socketKernel,"fin",3,0);

	close(socketKernel);
	return EXIT_SUCCESS;
}

int conf_es_valida(t_config * configuracion) // verifica que el arch de conf tenga los datos correctos
{
	return (config_has_property(configuracion, "Puerto")
			&& config_has_property(configuracion, "IP"));

}

int size_archivo(FILE *file) {
	fseek(file, 0L, SEEK_END);
	int size = ftell(file);
	fseek(file, 0L, SEEK_SET);
	return size;
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
//	while ((c = getc(file)) != '\n')
//		(c = getc(file));
	while ((c = getc(file)) != EOF) { //Lee cada caracter hasta encuentre el EndOfFile
		text2[i] = c;
		i++;
	}
	strcpy(text, text2);

	fclose(file);
	return text;
}

/*
 * Nombre: abrir_archivoRO/1
 *
 *
 */
FILE *abrir_archivoRO(char** argv) {
	//printf("%s \n", argv[2]);
	return (fopen("completo.ansisop", "r"));
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

