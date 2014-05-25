/*
 * estructurasPackage.h
 *
 *  Created on: 11/05/2013
 *      Author: utnso
 */

#ifndef ESTRUCTURASPACKAGE_H_
#define ESTRUCTURASPACKAGE_H_

#include  <commons/collections/list.h>

/*Defino las constantes que vamos a necesitar para manejar algunos casos*/
#define CONST_NUM_KERNEL 1
#define CONST_NUM_CPU 2
#define CONST_NUM_UMV 3
#define CONST_NUM_PROGRAMA 4

/* Defino los tipos de señales que se pueden mandar
 *
 * Sintaxis correcta para escribir una nueva señal:
 *
 * 	#define S_[Origen]_[Destino]_[Mensaje] numeroIncremental
 *
 * 	Donde:
 * 		[Origen] es quien manda el mensaje
 * 		[Destino] es quien recibe el mensaje
 * 		[Mensaje] lo que se le quiere mandar
 * 		numeroIncrementar un numero mas que la señal anterior
 */
#define S_ERROR 0	// Utilizada en socket_recibirSeñal, para decir que lo que se recibio no era una señal


/*Defino las estructuras de los paquetes
 *
 * Sintaxis correcta para escribir un nuev mensaje:
 *
 * 	#define D_STRUCT_[Nombre Estructura]
 *
 * 	Donde:
 * 		[Nombre Estructura] es el nombre de la estructura en MAYUSCULA
 *
 * 	Nota:
 * 		No olvidarse de crear la estructura y su paquetizador y despaquetizador asociado!
 */

#define D_STRUCT_NOMBREMENSAJE 0
#define D_STRUCT_NUMERO 1
#define D_STRUCT_CHAR 2
#define D_STRUCT_STRING 3
#define D_STRUCT_HANDSHAKE_UMV 4
#define D_STRUCT_SIGNAL 5
#define D_STRUCT_PCB 6


//Estructura auxiliar de stream
typedef struct {
	int length;
	char *data;
} t_stream;

// Header de stream
typedef struct {
	uint8_t tipoEstructura;
	uint16_t length;
} __attribute__ ((__packed__)) t_header;


/*
 *	TYPEDEF DE LAS ESTRUCTURAS A ENVIAR
 */

//Estructura tipo STRUCT_NOMBREMENSAJE(0)
typedef struct struct_nombreMensaje {
	char * nombre;
	char * mensaje;
} __attribute__ ((__packed__)) t_struct_nombreMensaje;

//Estructura tipo STRUCT_NUMERO(1)
typedef struct struct_numero {
	unsigned int numero;
} __attribute__ ((__packed__)) t_struct_numero;

//Estructura tipo STRUCT_CHAR(2)
typedef struct struct_char {
	char letra;
} __attribute__ ((__packed__)) t_struct_char;

//Estructura tipo STRUCT_STRING(3)
typedef struct struct_string {
	char * string;
} __attribute__ ((__packed__)) t_struct_string;

/*Estructura tipo STRUCT_HANDSHAKE(4)
 * Va a enviar la posicion en x y en y (dos unsigned int) en la que se encuentra el personaje o el recurso.
 */
typedef struct struct_handshake_umv {
	unsigned int tipoProceso;
} __attribute__ ((__packed__)) t_struct_handshake_umv;


/*Estructura tipo STRUCT_SIGNAL(5)
 * se va a usar cuando quiera enviar una señal.
 * cada señal va a estar numerada. Entonces aca envio el nro de señal.
 */
typedef unsigned int t_signal;

typedef struct struct_signal {
	t_signal signal;
} __attribute__ ((__packed__)) t_struct_signal;

/*Estructura tipo STRUCT_PCB(6)
 *va a enviar la estructura de un pcb
 */
typedef struct struct_pcb {
	uint32_t iD;
	uint32_t seg_codigo;
	uint32_t seg_stack;
	uint32_t indice_codigo;
	uint32_t indice_etiquetas;
	uint32_t programa_counter;

} __attribute__ ((__packed__)) t_struct_pcb;



#endif /* ESTRUCTURASPACKAGE_H_ */
