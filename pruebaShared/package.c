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
			case D_STRUCT_NUMERO:
				paquete = paquetizarStruct_numero((t_struct_numero *) estructuraOrigen);
				break;
			case D_STRUCT_CHAR:
				paquete = paquetizarStruct_char((t_struct_char *) estructuraOrigen);
				break;
			case D_STRUCT_STRING:
				paquete = paquetizarStruct_string((t_struct_string *) estructuraOrigen);
				break;
			case D_STRUCT_SIGNAL:
				paquete = paquetizarStruct_signal((t_struct_signal *) estructuraOrigen);
				break;
			case D_STRUCT_HANDSHAKE_UMV:
				paquete = paquetizarStruct_handshake_umv((t_struct_handshake_umv *) estructuraOrigen);
				break;
			case D_STRUCT_PCB:
				paquete = paquetizarStruct_pcb((t_struct_pcb *) estructuraOrigen);
				break;
			case D_STRUCT_ENVIAR_BYTES:
				paquete = paquetizarStruct_env_bytes((t_struct_env_bytes *) estructuraOrigen);
				break;
			case D_STRUCT_SOLICITAR_BYTES:
				paquete = paquetizarStruct_sol_bytes((t_struct_sol_bytes *) estructuraOrigen);
				break;
			case D_STRUCT_CREAR_SEGMENTO:
				paquete = paquetizarStruct_crear_segmento((t_struct_crear_segmento *) estructuraOrigen);
				break;
			case D_STRUCT_BORRAR_SEGMENTOS:
				paquete = paquetizarStruct_borrar_segmentos((t_struct_borrar_segmentos *) estructuraOrigen);
				break;
			case D_STRUCT_RESPUESTA_UMV:
				paquete = paquetizarStruct_respuesta_umv((t_struct_respuesta_umv *) estructuraOrigen);
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
 * Nombre: paquetizarStruct_numero/1
 * EJEMPLO PAQUETIZAR ESTRUCTURA ESTATICA
 * Argumentos:
 * 		- estructuraOrigen
 *
 * Devuelve:
 * 		paquete (buffer con la estructura paquetizada).
 *
 * Funcion: crearDataConHeader(1, length) -> reserva la memoria para el data del paquete, y le agrega el header.
 */
t_stream * paquetizarStruct_numero(t_struct_numero * estructuraOrigen){

	t_stream * paquete = malloc(sizeof(t_stream));		//creo el paquete

	paquete->length = sizeof(t_header) + sizeof(unsigned int);

	char * data = crearDataConHeader(D_STRUCT_NUMERO, paquete->length); //creo el data

	memcpy(data + sizeof(t_header), estructuraOrigen, sizeof(t_struct_numero));		//copio a data el numero.

	paquete->data = data;

	return paquete;
}


/*
 * Nombre: paquetizarStruct_char/1
 * Argumentos:
 * 		- estructuraOrigen
 *
 * Devuelve:
 * 		paquete (buffer con la estructura paquetizada).
 *
 * Funcion: crearDataConHeader(2, length) -> reserva la memoria para el data del paquete, y le agrega el header.
 */
t_stream * paquetizarStruct_char(t_struct_char * estructuraOrigen){

	t_stream * paquete = malloc(sizeof(t_stream));		//creo el paquete

	paquete->length = sizeof(t_header) + sizeof(unsigned int);

	char * data = crearDataConHeader(D_STRUCT_CHAR, paquete->length); //creo el data

	memcpy(data + sizeof(t_header), &estructuraOrigen->letra, sizeof(char));		//copio a data el char.

	paquete->data = data;

	return paquete;
}

/*
 * Nombre: paquetizarStruct_string/1
 * Argumentos:
 * 		- estructuraOrigen
 *
 * Devuelve:
 * 		paquete (buffer con la estructura paquetizada).
 *
 * Funcion: crearDataConHeader(3, length) -> reserva la memoria para el data del paquete, y le agrega el header.
 */
t_stream * paquetizarStruct_string(t_struct_string * estructuraOrigen){

	t_stream * paquete = malloc(sizeof(t_stream));		//creo el paquete

	paquete->length = sizeof(t_header) + strlen(estructuraOrigen->string) + 1;

	char * data = crearDataConHeader(D_STRUCT_STRING, paquete->length); //creo el data

	int tamanoTotal = sizeof(t_header);

	memcpy(data + tamanoTotal, estructuraOrigen->string, strlen(estructuraOrigen->string)+1);		//copio a data el string.

	paquete->data = data;

	return paquete;
}

/*
 * Nombre: paquetizarStruct_handshake_umv/1
 * Argumentos:
 * 		- estructuraOrigen
 *
 * Devuelve:
 * 		paquete (buffer con la estructura paquetizada).
 *
 * Funcion: crearDataConHeader(1, length) -> reserva la memoria para el data del paquete, y le agrega el header.
 */
t_stream * paquetizarStruct_handshake_umv(t_struct_handshake_umv * estructuraOrigen){

	t_stream * paquete = malloc(sizeof(t_stream));		//creo el paquete

	paquete->length = sizeof(t_header) + sizeof(unsigned int);

	char * data = crearDataConHeader(D_STRUCT_HANDSHAKE_UMV, paquete->length); //creo el data

	memcpy(data + sizeof(t_header), estructuraOrigen, sizeof(t_struct_handshake_umv)); //copio a data el numero.

	paquete->data = data;

	return paquete;
}


/*
 * Nombre: paquetizarStruct_signal/1
 * Argumentos:
 * 		- estructuraOrigen
 *
 * Devuelve:
 * 		paquete (buffer con la estructura paquetizada).
 *
 * Funcion: crearDataConHeader(5, length) -> reserva la memoria para el data del paquete, y le agrega el header.
 */
t_stream * paquetizarStruct_signal(t_struct_signal * estructuraOrigen){

	t_stream * paquete = malloc(sizeof(t_stream));		//creo el paquete

	paquete->length = sizeof(t_header) + sizeof(t_struct_signal);

	char * data = crearDataConHeader(D_STRUCT_SIGNAL, paquete->length); //creo el data

	memcpy(data + sizeof(t_header), estructuraOrigen, sizeof(t_struct_signal));	//copio a data la estructura.

	paquete->data = data;

	return paquete;
}

/*
 * Nombre: paquetizarStruct_pcb/1
 * EJEMPLO PAQUETIZAR ESTRUCTURA ESTATICA
 * Argumentos:
 * 		- estructuraOrigen
 *
 * Devuelve:
 * 		paquete (buffer con la estructura paquetizada).
 *
 * Funcion: crearDataConHeader(6, length) -> reserva la memoria para el data del paquete, y le agrega el header.
 */
t_stream * paquetizarStruct_pcb(t_struct_pcb * estructuraOrigen){

	t_stream * paquete = malloc(sizeof(t_stream));		//creo el paquete

	paquete->length = sizeof(t_header) + sizeof(t_struct_pcb);

	char * dataNueva; //creo el data
	dataNueva = crearDataConHeader(D_STRUCT_PCB, paquete->length);

	memcpy(dataNueva + sizeof(t_header), estructuraOrigen, sizeof(t_struct_pcb));		//copio a data el numero.

	paquete->data = dataNueva;

	return paquete;
}

t_stream * paquetizarStruct_env_bytes(t_struct_env_bytes * estructuraOrigen){

	t_stream * paquete = malloc(sizeof(t_stream));		//creo el paquete

	paquete->length = sizeof(t_header) + (estructuraOrigen->tamanio) + sizeof(t_struct_env_bytes);

	void * data = crearDataConHeader(D_STRUCT_ENVIAR_BYTES, paquete->length); //creo el data

	int tamanoTotal = sizeof(t_header);

	memcpy(data + tamanoTotal, estructuraOrigen,sizeof(t_struct_env_bytes));

	tamanoTotal += sizeof(t_struct_env_bytes);

	memcpy(data + tamanoTotal, estructuraOrigen->buffer, estructuraOrigen->tamanio);		//copio a data el nombre.

	tamanoTotal += estructuraOrigen->tamanio;


	paquete->data = data;

	return paquete;

}

t_stream * paquetizarStruct_sol_bytes(t_struct_sol_bytes * estructuraOrigen){

	  t_stream * paquete = malloc(sizeof(t_stream));		//creo el paquete

		paquete->length = sizeof(t_header) + sizeof(t_struct_sol_bytes);

		char * dataNueva; //creo el data
		dataNueva = crearDataConHeader(D_STRUCT_SOLICITAR_BYTES, paquete->length);

		memcpy(dataNueva + sizeof(t_header), estructuraOrigen, sizeof(t_struct_sol_bytes));		//copio a data el numero.

		paquete->data = dataNueva;

		return paquete;

}

t_stream * paquetizarStruct_crear_segmento(t_struct_crear_segmento * estructuraOrigen){

	t_stream * paquete = malloc(sizeof(t_stream));		//creo el paquete

	paquete->length = sizeof(t_header) + sizeof(t_struct_crear_segmento);

		char * dataNueva; //creo el data
		dataNueva = crearDataConHeader(D_STRUCT_CREAR_SEGMENTO, paquete->length);

		memcpy(dataNueva + sizeof(t_header), estructuraOrigen, sizeof(t_struct_crear_segmento));		//copio a data el numero.

		paquete->data = dataNueva;

		return paquete;
}

t_stream * paquetizarStruct_borrar_segmentos(t_struct_borrar_segmentos * estructuraOrigen){

	t_stream * paquete = malloc(sizeof(t_stream));		//creo el paquete

	paquete->length = sizeof(t_header) + sizeof(t_struct_borrar_segmentos);

	char * dataNueva; //creo el data
	dataNueva = crearDataConHeader(D_STRUCT_BORRAR_SEGMENTOS, paquete->length);

	memcpy(dataNueva + sizeof(t_header), estructuraOrigen, sizeof(t_struct_borrar_segmentos));		//copio a data el numero.

	paquete->data = dataNueva;

	return paquete;
}

t_stream * paquetizarStruct_respuesta_umv(t_struct_respuesta_umv * estructuraOrigen){
	t_stream * paquete = malloc(sizeof(t_stream));		//creo el paquete

	paquete->length = sizeof(t_header) + (estructuraOrigen->tamano_buffer) + sizeof(t_struct_respuesta_umv);

	void * data = crearDataConHeader(D_STRUCT_ENVIAR_BYTES, paquete->length); //creo el data

	int tamanoTotal = sizeof(t_header);

	memcpy(data + tamanoTotal, estructuraOrigen,sizeof(t_struct_env_bytes));

	tamanoTotal += sizeof(t_struct_env_bytes);

	memcpy(data + tamanoTotal, estructuraOrigen->buffer, estructuraOrigen->tamano_buffer);		//copio a data el nombre.

	tamanoTotal += estructuraOrigen->tamano_buffer;

	paquete->data = data;

	return paquete;
}

// --------------------------------------------------------------------------------------

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
			case D_STRUCT_NUMERO:
				estructuraDestino = despaquetizarStruct_numero(dataPaquete, length);
				break;
			case D_STRUCT_STRING:
				estructuraDestino = despaquetizarStruct_string(dataPaquete, length);
				break;
			case D_STRUCT_SIGNAL:
				estructuraDestino = despaquetizarStruct_signal(dataPaquete, length);
				break;
			case D_STRUCT_CHAR:
				estructuraDestino = despaquetizarStruct_char(dataPaquete, length);
				break;
			case D_STRUCT_HANDSHAKE_UMV:
				estructuraDestino = despaquetizarStruct_handshake_umv(dataPaquete, length);
				break;
			case D_STRUCT_PCB:
				estructuraDestino = despaquetizarStruct_pcb(dataPaquete, length);
				break;
			case D_STRUCT_ENVIAR_BYTES:
				estructuraDestino = despaquetizarStruct_env_bytes(dataPaquete, length);
				break;
			case D_STRUCT_SOLICITAR_BYTES:
				estructuraDestino = despaquetizarStruct_sol_bytes(dataPaquete, length);
				break;
			case D_STRUCT_CREAR_SEGMENTO:
				estructuraDestino = despaquetizarStruct_crear_segmento(dataPaquete, length);
				break;
			case D_STRUCT_BORRAR_SEGMENTOS:
				estructuraDestino = despaquetizarStruct_borrar_segmentos(dataPaquete, length);
				break;
			case D_STRUCT_RESPUESTA_UMV:
				estructuraDestino = despaquetizarStruct_respuesta_umv(dataPaquete, length);
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

/*
 * Nombre: despaquetizarStruct_pcb/2
 * Devuelve:
 * 		una estructura de tipo D_STRUCT_PCB.
 *
 */

t_struct_pcb * despaquetizarStruct_pcb(char * dataPaquete, uint16_t length){
	t_struct_pcb * estructuraDestino = malloc(sizeof(t_struct_pcb));

	memcpy(estructuraDestino, dataPaquete, sizeof(t_struct_pcb)); //copio el data del paquete a la estructura.

	return estructuraDestino;
}

t_struct_env_bytes * despaquetizarStruct_env_bytes(char * dataPaquete,uint16_t length){

	void * buffer = malloc(length - sizeof(t_struct_env_bytes));
	t_struct_env_bytes * estructuraDestino = malloc(sizeof(t_struct_env_bytes));

	memcpy(estructuraDestino, dataPaquete, sizeof(t_struct_env_bytes)); //copio el data del paquete a la estructura.
	memcpy(buffer, dataPaquete + sizeof(t_struct_env_bytes), length - sizeof(t_struct_env_bytes)); // copiamos los bytes que queriamos enviar

	estructuraDestino->buffer = buffer;

	return estructuraDestino;
}

t_struct_sol_bytes * despaquetizarStruct_sol_bytes(char * dataPaquete,uint16_t length){
	t_struct_sol_bytes * estructuraDestino = malloc(sizeof(t_struct_sol_bytes));

			memcpy(estructuraDestino, dataPaquete, sizeof(t_struct_sol_bytes)); //copio el data del paquete a la estructura.

			return estructuraDestino;
}

t_struct_crear_segmento * despaquetizarStruct_crear_segmento(char * dataPaquete,uint16_t length){
	t_struct_crear_segmento * estructuraDestino = malloc(sizeof(t_struct_crear_segmento));

			memcpy(estructuraDestino, dataPaquete, sizeof(t_struct_crear_segmento)); //copio el data del paquete a la estructura.

			return estructuraDestino;
}

t_struct_borrar_segmentos * despaquetizarStruct_borrar_segmentos(char * dataPaquete,uint16_t length){
	t_struct_borrar_segmentos * estructuraDestino = malloc(sizeof(t_struct_borrar_segmentos));

			memcpy(estructuraDestino, dataPaquete, sizeof(t_struct_borrar_segmentos)); //copio el data del paquete a la estructura.

			return estructuraDestino;
}

/*
 * Nombre: despaquetizarStruct_numero/2
 * EJEMPLO DESPAQUETIZAR ESTRUCTURA ESTATICA
 * Argumentos:
 * 		- char * dataPaquete
 * 		- length
 *
 * Devuelve:
 * 		una estructura de tipo D_STRUCT_NUMERO.
 *
 * Funcion: Según el tipo de estructura, va a distintas funciones que las despaquetizan.
 */
t_struct_numero * despaquetizarStruct_numero(char * dataPaquete, uint16_t length){
	t_struct_numero * estructuraDestino = malloc(sizeof(t_struct_numero));

	memcpy(estructuraDestino, dataPaquete, sizeof(unsigned int)); //copio el data del paquete a la estructura.

	return estructuraDestino;
}

/*
 * Nombre: despaquetizarStruct_handshake_umv/2
 * Argumentos:
 * 		- char * dataPaquete
 * 		- length
 *
 * Devuelve:
 * 		una estructura de tipo D_STRUCT_HANDSHAKE_UMV.
 *
 * Funcion: Según el tipo de estructura, va a distintas funciones que las despaquetizan.
 */
t_struct_handshake_umv * despaquetizarStruct_handshake_umv(char * dataPaquete, uint16_t length){
	t_struct_handshake_umv * estructuraDestino = malloc(sizeof(t_struct_handshake_umv));

	memcpy(estructuraDestino, dataPaquete, sizeof(unsigned int)); //copio el data del paquete a la estructura.

	return estructuraDestino;
}

/*
 * Nombre: despaquetizarStruct_char/2
 * Argumentos:
 * 		- char * dataPaquete
 * 		- length
 *
 * Devuelve:
 * 		una estructura de tipo D_STRUCT_CHAR.
 *
 */
t_struct_char * despaquetizarStruct_char(char * dataPaquete, uint16_t length){
	t_struct_char * estructuraDestino = malloc(sizeof(t_struct_char));

	memcpy(&estructuraDestino->letra, dataPaquete, sizeof(char)); //copio la letra a la estructura

	return estructuraDestino;
}

/*
 * Nombre: despaquetizarStruct_string/2
 * Argumentos:
 * 		- char * dataPaquete
 * 		- length
 *
 * Devuelve:
 * 		una estructura de tipo D_STRUCT_STRING.
 *
 */
t_struct_string * despaquetizarStruct_string(char * dataPaquete, uint16_t length){
	t_struct_string * estructuraDestino = malloc(sizeof(t_struct_string));

	int tamanoTotal = 0, tamanoDato = 0;

	tamanoTotal = tamanoDato;

	for(tamanoDato = 1; (dataPaquete + tamanoTotal)[tamanoDato -1] != '\0';tamanoDato++); 	//incremento tamanoDato, hasta el tamaño del nombre.

	estructuraDestino->string = malloc(tamanoDato);
	memcpy(estructuraDestino->string, dataPaquete + tamanoTotal, tamanoDato); //copio el string a la estructura

	return estructuraDestino;
}

t_struct_signal * despaquetizarStruct_signal(char * dataPaquete, uint16_t length){
	t_struct_signal * estructuraDestino = malloc(sizeof(t_struct_signal));

	memcpy(estructuraDestino, dataPaquete, sizeof(t_struct_signal)); //copio el data del paquete a la estructura

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

t_struct_respuesta_umv * despaquetizarStruct_respuesta_umv(char * dataPaquete,uint16_t length){

	void * buffer = malloc(length - sizeof(t_struct_respuesta_umv));
	t_struct_respuesta_umv * estructuraDestino = malloc(sizeof(t_struct_respuesta_umv));

	memcpy(estructuraDestino, dataPaquete, sizeof(t_struct_respuesta_umv)); //copio el data del paquete a la estructura.
	memcpy(buffer, dataPaquete + sizeof(t_struct_respuesta_umv), length - sizeof(t_struct_respuesta_umv)); // copiamos los bytes que queriamos enviar

	estructuraDestino->buffer = buffer;

	return estructuraDestino;
}
