/*
 * socket.h
 *
 *  Created on: 22/04/2014
 *      Author: utnso
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include <stdint.h>
#include <commons/log.h>

    #define TIPO_MENSAJE 1						// el tipo de mensaje que se quiere enviar.

	//typedefs de punteros a funciones
	typedef void *(*p_funcion_deserial)(char *buffer); //punteros a funciones para serializar y deserializar.
	typedef char *(*p_funcion_serial)(void *data, int *tamanio);


	//la cabecera que se lee en todos los mensajes, esto es lo que lee primero el que recibe el mensaje y segun eso elige
											// un serializador o deserializador.
	typedef struct {
		char tipo;
		uint16_t len;  // entero sin signo de dos bytes
	} __attribute__((packed)) t_cabecera;  // este atributo hace que en el struct no exista relleno en los dos campos

 //este es el strcut del mensaje le puse arbitrariamente dos variables pero PUEDE TENER OTRAS Y DE OTROS TIPOS va eso
 //va a depender como formulemos los mensajes que vamos a enviar.
	 typedef struct {
	    	char *mensaje_cadena;
	    	char caracter;
	    }__attribute__((packed)) t_mensaje;

	//funciones de envio/recepcion
	int getnextmsg(int socket);
	void *recibir(int socket, int tipo);
	int enviar(int socket, int tipo, void *struct_mensaje, t_log *logger);
	t_cabecera *deserializar_cabecera(char *buffer);

	//funciones de socket
	bool is_connected(int socket);
	char *get_ip_string(int socket);
	int init_socket_externo(int puerto, char *direccion, t_log *logger);
	int init_socket_escucha(int puerto, int optval, t_log *logger);

	char *srlz_mensaje(void *data, int *tamanio);
	void *deserializar_mensaje(char *buffer);

	 // funcion de inicializacion
	void iniciar_serializadora();



#endif /* SOCKET_H_ */
