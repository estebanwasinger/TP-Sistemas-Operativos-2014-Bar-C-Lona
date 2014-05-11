/*
 * socket.c
 *
 *  Created on: 22/04/2014
 *      Author: utnso
 */
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <commons/string.h>
#include <commons/log.h>
#include <commons/collections/list.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>
#include <fcntl.h>
#include "socket.h"

#define N_MENSAJES 23 // este 23 es por que para el tp pasado habian 23 tipos de mensajes.


static p_funcion_deserial vec_deserializador[N_MENSAJES];  //vectores de tipo punteros a funcion
static p_funcion_serial vec_serializador[N_MENSAJES];

static void init_vec_deserial();
static void init_vec_serial();

void iniciar_serializadora(){
	init_vec_serial();
	init_vec_deserial();
}
//setea el vector de serializadores
static void init_vec_serial(){
	vec_serializador[TIPO_MENSAJE] = srlz_mensaje;  //inicializa todos los elementos del vector q serializa
}

//deserializa un char * y lo devuelve como un struct (dependiendo el mensaje)
void *deserializar_mensaje(char *buffer){
	t_mensaje *mensaje = malloc(sizeof(t_mensaje));
	mensaje->mensaje_cadena = strdup(buffer);
	memcpy(&mensaje->caracter, buffer+strlen(buffer)+1, sizeof(char));
    return mensaje;
}

//setea el vector de de-serializadores
static void init_vec_deserial(){
	vec_deserializador[TIPO_MENSAJE] = deserializar_mensaje; //inicializa todos los elementos del vector q deserializa
}

//serializa un struct y lo devuelve como char* listo para ser enviado
char *srlz_mensaje(void *data, int *tamanio){
	int offset;
	t_mensaje *sol = data;
	char *buffer = malloc(*tamanio = strlen(sol->mensaje_cadena)+1 + sizeof(char));

    memcpy(buffer, sol->mensaje_cadena, offset = strlen(sol->mensaje_cadena)+1 );
    memcpy(buffer+offset, &sol->caracter, sizeof(char));

    free(sol->mensaje_cadena);
	free(data);
	return buffer;
}

//mira el tipo de dato entrante en el flujo de entrada sin vaciar el socket
int getnextmsg(int socket){
	char tipo;
	char buffer[sizeof(char)];

	if(recv(socket, buffer, sizeof(t_cabecera), MSG_PEEK) < 0){
		exit(1);
	}

	memcpy(&tipo, buffer, sizeof(char));

	return tipo;
}


//lee de un socket y devuelve un struct validando por "tipo"
void *recibir(int socket, int tipo)
{
	char *buffer;
	t_cabecera cabecera;

	// Primero: Recibir el header para saber cuando ocupa el payload.
	if (recv(socket, &cabecera, sizeof(t_cabecera), MSG_WAITALL) <= 0) {
		exit(1);
	}

	// Segundo: Alocar memoria suficiente para el payload.
	buffer= malloc(cabecera.len); //le sumo un 1

	// Tercero: Recibir el payload.
	if(recv(socket, buffer, cabecera.len, 0) < 0){ //le sumo un 1
		exit(1);
	}

	//de-serializado y validacion de tipo
	void *deserializado = (*vec_deserializador[tipo])(buffer);
	bool tipo_valido = cabecera.tipo==tipo;
	free(buffer);
	return tipo_valido? deserializado : NULL ; // return el deserializado correspondiente al tipo validado
}


//funcion que recibe un socket, un tipo de mensaje, un struct y un logger
//envia un mensaje de un tipo serializando un struct al socket, retorna el resultado de send(),osea la cantidad de datos enviados.
int enviar(int socket, int tipo, void *struct_mensaje, t_log *logger)
{
	t_cabecera cabecera;
	int resultado, *tamanio = malloc(sizeof(int));
	char *serializado = (*vec_serializador[tipo])(struct_mensaje, tamanio);//contiene el serializado correspondiente dado por el "vec"
	                  	  	  	  	  	  	  	  	  	  	  	  	  	   //ademas devuelve *tamanio
	char *buffer = malloc(sizeof(t_cabecera) + *tamanio);//buffer de envio del tamaño de la cabecera + el serializado

	cabecera.tipo = tipo;
	cabecera.len = *tamanio;

	//armado del buffer con cabecera y lo serializado por vec_serializador
	memmove(buffer, &cabecera, sizeof(t_cabecera));

	memcpy(buffer + sizeof(t_cabecera), serializado, *tamanio);

	//envio de mensaje, aca capaz implementar un sendall()
	resultado = send(socket, buffer, sizeof(t_cabecera) + *tamanio, MSG_NOSIGNAL);

	//liberacion de mallocs y retorno
	free(serializado);
	free(tamanio);
	free(buffer);
	return resultado;
}



//recibe un socket y devuelve su IP como un string
char *get_ip_string(int socket){
	struct sockaddr_storage addr;
	socklen_t len = sizeof addr;
	char *IP = malloc(INET_ADDRSTRLEN);

	getpeername(socket, (struct sockaddr*)&addr, &len);

	struct sockaddr_in *s = (struct sockaddr_in *)&addr;
	inet_ntop(AF_INET, &s->sin_addr, IP, INET_ADDRSTRLEN);

	return IP;
}


//devuelve un socket para comunicacion listo para usar, escribiendo en el logger pasado y terminando el programa ante errores
int init_socket_externo(int puerto, char *direccion, t_log *logger)
{
	int unSocket;
	struct linger lo = { 1, 0 };
	struct sockaddr_in socketInfo;

	// Crear un socket:
	// AF_INET: Socket de internet IPv4
	// SOCK_STREAM: Orientado a la conexion, TCP
	// 0: Usar protocolo por defecto para AF_INET-SOCK_STREAM: Protocolo TCP/IPv4
	if ((unSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		if(logger!=NULL) log_error(logger, "Error creando socket", "ERROR");
		exit(1);
	}
	fcntl(unSocket, F_SETFL, FD_CLOEXEC);

	setsockopt(unSocket, SOL_SOCKET, SO_LINGER, &lo, sizeof(lo));

	socketInfo.sin_family = AF_INET;
	socketInfo.sin_addr.s_addr = inet_addr(direccion);
	socketInfo.sin_port = htons(puerto);

	connect(unSocket, (struct sockaddr*) &socketInfo, sizeof(socketInfo));
	if(logger!=NULL) log_info(logger, string_from_format("Conectando con la direccion %s", direccion), "INFO");
	return unSocket;
}


//devuelve un socket escucha listo para usar, escribiendo en el logger pasado y terminando el programa ante errores
int init_socket_escucha(int puerto, int optval, t_log *logger){
	int socketEscucha;
	struct sockaddr_in socketInfo;

	// Crear un socket:
	// AF_INET: Socket de internet IPv4
	// SOCK_STREAM: Orientado a la conexion, TCP
	// 0: Usar protocolo por defecto para AF_INET-SOCK_STREAM: Protocolo TCP/IPv4
	if ((socketEscucha = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
	//	if(logger!=NULL) log_error(logger, "Error creando socket", "ERROR");
		exit(1);
	}

	fcntl(socketEscucha, F_SETFL, FD_CLOEXEC); // esto no esta en el original

	// Hacer que el SO libere el puerto inmediatamente luego de cerrar el socket.
	setsockopt(socketEscucha, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

	socketInfo.sin_family = AF_INET;
	socketInfo.sin_addr.s_addr = INADDR_ANY; //Notar que aca no se usa inet_addr()
	socketInfo.sin_port = htons(puerto);

	// Vincular el socket con una direccion de red almacenada en 'socketInfo'.
	if (bind(socketEscucha, (struct sockaddr*) &socketInfo, sizeof(socketInfo))	!= 0) {
	//	if(logger!=NULL) log_error(logger, "Error bindeando socket", "ERROR");
		exit(1);
	}
	listen(socketEscucha, 10);
//	if(logger!=NULL)log_info(logger, string_from_format("Se comienza a escuchar por el puerto %d", ntohs(socketInfo.sin_port)),"INFO");
	return socketEscucha;
}

//cuidado con esta funcion: solo usenla cuando saben que tienen que recibir algo (por ejemplo en select)
bool is_connected(int socket){
	char buffer[1];
	return recv(socket, buffer, sizeof buffer, MSG_PEEK)>0;
}

