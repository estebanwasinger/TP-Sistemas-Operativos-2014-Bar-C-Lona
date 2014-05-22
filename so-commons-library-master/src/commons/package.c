/*
 * package.c
 *
 *  Created on: 24/04/2013
 *      Author: utnso
 */

#include "package.h"

/******************** PAQUETIZAR *************************/

/*
 * Nombre: paquetizar/2
 * Argumentos:
 * 		- tipoEstructura (un int, bajo criterio nuestro que representará la estructura que estoy enviando)
 * 		- estructuraOrigen
 *
 * Devuelve:
 * 		paquete (buffer con la estructura paquetizada).
 * 		--> Recordar hacer free del paquete luego de utilizar esta función.
 *
 * Funcion: Según el tipo de estructura, va a distintas funciones que las paquetizan.
 */
t_stream * paquetizar(int tipoEstructura, void * estructuraOrigen){
	t_stream * paquete;

	switch (tipoEstructura){
			case D_STRUCT_NOMBREMENSAJE:
				paquete = paquetizarStruct_nombreMensaje((t_struct_nombreMensaje *) estructuraOrigen);
				break;
			case D_STRUCT_HANDSHAKEUMV:
				paquete = paquetizarStruct_handshakeUMV((t_struct_handshakeUMV *) estructuraOrigen);
				break;
		}


	return paquete;
}

/*
 * Nombre: paquetizarStruct_nombreMensaje/1
 * EJEMPLO PAQUETIZAR ESTRUCTURA DINAMICA
 * Argumentos:
 * 		- estructuraOrigen
 *
 * Devuelve:
 * 		paquete (buffer con la estructura paquetizada).
 *
 * Funcion: crearDataConHeader(0, length) -> reserva la memoria para el data del paquete, y le agrega el header.
 */
t_stream * paquetizarStruct_nombreMensaje(t_struct_nombreMensaje * estructuraOrigen){

	t_stream * paquete = malloc(sizeof(t_stream));		//creo el paquete

	paquete->length = sizeof(t_header) + strlen(estructuraOrigen->nombre) + strlen(estructuraOrigen->mensaje) + 2;

	char * data = crearDataConHeader(D_STRUCT_NOMBREMENSAJE, paquete->length); //creo el data

	int tamanoTotal = sizeof(t_header), tamanoDato = 0;

	memcpy(data + tamanoTotal, estructuraOrigen->nombre, tamanoDato = strlen(estructuraOrigen->nombre)+1);		//copio a data el nombre.

	tamanoTotal += tamanoDato;

	memcpy(data + tamanoTotal, estructuraOrigen->mensaje, tamanoDato = strlen(estructuraOrigen->mensaje)+1);		//copio a data el mensaje.

	tamanoTotal += tamanoDato;

	paquete->data = data;

	return paquete;
}

/*
 * Nombre: paquetizarStruct_handshakeUMV/1
 * EJEMPLO PAQUETIZAR ESTRUCTURA HANDSHAKE
 * Argumentos:
 * 		- estructuraOrigen
 *
 * Devuelve:
 * 		paquete (buffer con la estructura paquetizada).
 *
 * Funcion: crearDataConHeader(0, length) -> reserva la memoria para el data del paquete, y le agrega el header.
 */

t_stream * paquetizarStruct_handshakeUMV(t_struct_handshakeUMV * estructuraOrigen){

	t_stream * paquete = malloc(sizeof(t_stream));		//creo el paquete

	paquete->length = sizeof(t_header) + sizeof(estructuraOrigen->tipo);

	char * data = crearDataConHeader(D_STRUCT_HANDSHAKEUMV, paquete->length); //creo el data

	memcpy(data + sizeof(t_header), estructuraOrigen, sizeof(estructuraOrigen));		//copio a data el int

	paquete->data = data;

	return paquete;
}


/*
 * Nombre: crearDataConHeader/2
 * Argumentos:
 * 		- tipoEstructura
 * 		- length
 *
 * Devuelve:
 * 		char * data (con los primeros bytes ocupados con el tipoEstructura, y el length de la misma.
 *
 * Funcion: crearHeader -> genera y devuelve la estructura del header, con los datos cargados.
 */
char * crearDataConHeader(uint8_t tipoEstructura, int length){
	char * data = malloc(length);

	uint16_t lengthDatos = length - sizeof(t_header);

	t_header header = crearHeader(tipoEstructura, lengthDatos); //creo el header

	int tamanoTotal = 0, tamanoDato = 0;

	memcpy(data, &header.tipoEstructura, tamanoDato = sizeof(uint8_t)); //copio el tipoEstructura del header a data
	tamanoTotal = tamanoDato;
	memcpy(data + tamanoTotal, &header.length, tamanoDato = sizeof(uint16_t)); //copio el length del header a data

	return data;
}


/*
 * Nombre: crearHeader/2
 * Argumentos:
 * 		- tipoEstructura
 * 		- lengthDatos
 *
 * Devuelve:
 * 		genera y devuelve la estructura del t_header, con los datos cargados.
 *
 */
t_header crearHeader(uint8_t tipoEstructura, uint16_t lengthDatos){
	t_header header;
	header.tipoEstructura = tipoEstructura;
	header.length = lengthDatos;
	return header;
}

/******************** DESPAQUETIZAR *************************/

/*
 * Nombre: despaquetizar/3
 * Argumentos: (estos 3 datos serían el data del paquete:).
 * 		- tipoEstructura (un numero que, bajo criterio nuestro, representará la estructura que estoy recibiendo para despaquetizar)
 * 		- char * dataPaquete
 * 		- length
 *
 * Devuelve:
 * 		estructuraDestino (estructura donde se guardó el paquete).
 * 		--> Recordar hacer free de la estructuraDestino luego de utilizar esta función.
 *
 * Funcion: Según el tipo de estructura, va a distintas funciones que las despaquetizan.
 */
void * despaquetizar(uint8_t tipoEstructura, char * dataPaquete, uint16_t length){

	void * estructuraDestino;

	switch (tipoEstructura){
			case D_STRUCT_NOMBREMENSAJE:
				estructuraDestino = despaquetizarStruct_nombreMensaje(dataPaquete, length);
				break;
			case D_STRUCT_HANDSHAKEUMV:
				estructuraDestino = despaquetizarStruct_handshakeUMV(dataPaquete, length);
				break;
		
		}

	return estructuraDestino;
}

/*
 * Nombre: despaquetizarStruct_nombreMensaje/2
 * * EJEMPLO DESPAQUETIZAR ESTRUCTURA DINAMICA
 * Argumentos:
 * 		- char * dataPaquete
 * 		- length
 *
 * Devuelve:
 * 		una estructura de tipo D_STRUCT_NOMBREMENSAJE.
 *
 * Funcion: Según el tipo de estructura, va a distintas funciones que las despaquetizan.
 */
t_struct_nombreMensaje * despaquetizarStruct_nombreMensaje(char * dataPaquete, uint16_t length){
	t_struct_nombreMensaje * estructuraDestino = malloc(sizeof(t_struct_nombreMensaje));

	int tamanoTotal = 0, tamanoDato = 0;

	tamanoTotal = tamanoDato;

	for(tamanoDato = 1; (dataPaquete + tamanoTotal)[tamanoDato -1] != '\0';tamanoDato++); 	//incremento tamanoDato, hasta el tamaño del nombre.

	estructuraDestino->nombre = malloc(tamanoDato);
	memcpy(estructuraDestino->nombre, dataPaquete + tamanoTotal, tamanoDato); //copio el nombre a la estructura

	tamanoTotal += tamanoDato;

	for(tamanoDato = 1; (dataPaquete + tamanoTotal)[tamanoDato -1] != '\0';tamanoDato++); //incremento tamanoDato, hasta el tamaño del mensaje.

	estructuraDestino->mensaje = malloc(tamanoDato);
	memcpy(estructuraDestino->mensaje, dataPaquete + tamanoTotal, tamanoDato); //copio el mensaje a la estructura

	return estructuraDestino;
}

t_struct_handshakeUMV * despaquetizarStruct_handshakeUMV(char * dataPaquete, uint16_t length){
	t_struct_handshakeUMV * estructuraDestino = malloc(sizeof(t_struct_handshakeUMV));

	memcpy(estructuraDestino, dataPaquete, sizeof(t_struct_handshakeUMV)); //copio el data del paquete a la estructura

	return estructuraDestino;
}



/*
 * Nombre: despaquetizarHeader/1
 * Argumentos:
 * 		- char * header
 *
 * Devuelve:
 * 		una estructura de tipo t_header.
 *
 */
t_header despaquetizarHeader(char * header){
	t_header estructuraHeader;

	int tamanoTotal = 0, tamanoDato = 0;
	memcpy(&estructuraHeader.tipoEstructura, header + tamanoTotal, tamanoDato = sizeof(uint8_t));
	tamanoTotal = tamanoDato;
	memcpy(&estructuraHeader.length, header + tamanoTotal, tamanoDato = sizeof(uint16_t));

	return estructuraHeader;
}
