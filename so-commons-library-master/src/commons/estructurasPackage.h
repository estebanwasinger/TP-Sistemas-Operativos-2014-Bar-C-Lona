/*
 * estructurasPackage.h
 *
 *  Created on: 11/05/2013
 *      Author: utnso
 */

#ifndef ESTRUCTURASPACKAGE_H_
#define ESTRUCTURASPACKAGE_H_

#include "collections/list.h"

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

#define KERNEL 0
#define CPU 1

#define D_STRUCT_NOMBREMENSAJE 0
#define D_STRUCT_CREARSEGMENTO 1
#define D_STRUCT_BORRARSEGMENTOS 2
#define D_STRUCT_HANDSHAKEUMV 3

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

//Estructura tipo STRUCT_CREARSEGMENTO(1)
typedef struct struct_crearSegmento {
    char * ID;
    uint16_t longitud;
} __attribute__ ((__packed__)) t_struct_crearSegmento;


//Estructura tipo STRUCT_BORRARSEGMENTOS(2)
typedef struct struct_borrarSegmentos {
    char ID;
} __attribute__ ((__packed__)) t_struct_borrarSegmentos;

//Estructura tipo STRUCT_HANDSHAKEUMV(3)
typedef struct struct_handshakeUMV {
    uint8_t tipo;
} __attribute__ ((__packed__)) t_struct_handshakeUMV;


#endif /* ESTRUCTURASPACKAGE_H_ */
