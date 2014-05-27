/*
 * package.h
 *
 *  Created on: 24/04/2013
 *      Author: utnso
 */

#ifndef PACKAGE_H_
#define PACKAGE_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "string.h"
#include "estructurasPackage.h"

// ---------------------------------------------------------------------------

//FUNCION PRINCIPAL PAQUETIZAR
t_stream * paquetizar(int tipoEstructura, void * estructuraOrigen);

// ---------------------------------------------------------------------------

//FUNCION PAQUETIZAR SEGUN TIPO DE ESTRUCTURA
t_stream * paquetizarStruct_nombreMensaje(t_struct_nombreMensaje * estructuraOrigen); //ESTRUCTURA DINAMICA
t_stream * paquetizarStruct_numero(t_struct_numero * estructuraOrigen);//ESTRUCTURA ESTATICA
t_stream * paquetizarStruct_char(t_struct_char * estructuraOrigen); //E
t_stream * paquetizarStruct_string(t_struct_string * estructuraOrigen); //D
t_stream * paquetizarStruct_handshake_umv(t_struct_handshake_umv * estructuraOrigen);
t_stream * paquetizarStruct_signal(t_struct_signal * estructuraOrigen); //E
t_stream * paquetizarStruct_pcb(t_struct_pcb * estructuraOrigen);
t_stream * paquetizarStruct_env_bytes(t_struct_env_bytes * estructuraOrigen);
t_stream * paquetizarStruct_sol_bytes(t_struct_sol_bytes * estructuraOrigen);
t_stream * paquetizarStruct_crear_segmento(t_struct_crear_segmento * estructuraOrigen);
t_stream * paquetizarStruct_borrar_segmentos(t_struct_borrar_segmentos * estructuraOrigen);
// ---------------------------------------------------------------------------

//FUNCIONES DE HEADER QUE SIRVEN PARA PAQUETIZAR
char * crearDataConHeader(uint8_t tipoEstructura, int length);
t_header crearHeader(uint8_t tipoEstructura, uint16_t lengthDatos);

// ---------------------------------------------------------------------------

//FUNCION PRINCIPAL DESPAQUETIZAR
void * despaquetizar(uint8_t tipoEstructura, char * dataPaquete, uint16_t length);
//FUNCION DESPAQUETIZAR SEGUN TIPO DE ESTRUCTURA
t_struct_nombreMensaje * despaquetizarStruct_nombreMensaje(char * dataPaquete, uint16_t length); //ESTRUCTURA DINAMICA
t_struct_numero * despaquetizarStruct_numero(char * dataPaquete, uint16_t length);//ESTRUCTURA ESTATICA
t_struct_char * despaquetizarStruct_char(char * dataPaquete, uint16_t length);
t_struct_string * despaquetizarStruct_string(char * dataPaquete, uint16_t length);
t_struct_handshake_umv * despaquetizarStruct_handshake_umv(char * dataPaquete, uint16_t length);
t_struct_signal * despaquetizarStruct_signal(char * dataPaquete, uint16_t length);
t_struct_pcb * despaquetizarStruct_pcb(char * dataPaquete, uint16_t length);
t_struct_env_bytes * despaquetizarStruct_env_bytes(char * dataPaquete,uint16_t length);
t_struct_sol_bytes * despaquetizarStruct_sol_bytes(char * dataPaquete,uint16_t length);
t_struct_borrar_segmentos * despaquetizarStruct_crear_segmento(char * dataPaquete,uint16_t length);
t_struct_borrar_segmentos * despaquetizarStruct_borrar_segmentos(char * dataPaquete,uint16_t length);

// ---------------------------------------------------------------------------

//FUNCIONES DE HEADER QUE SIRVEN PARA DESPAQUETIZAR
t_header despaquetizarHeader(char * header);

#endif /* PACKAGE_H_ */
