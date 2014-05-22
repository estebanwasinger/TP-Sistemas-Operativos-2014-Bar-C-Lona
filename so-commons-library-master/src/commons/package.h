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


//FUNCION PRINCIPAL PAQUETIZAR
t_stream * paquetizar(int tipoEstructura, void * estructuraOrigen);
//FUNCION PAQUETIZAR SEGUN TIPO DE ESTRUCTURA
t_stream * paquetizarStruct_nombreMensaje(t_struct_nombreMensaje * estructuraOrigen); //ESTRUCTURA DINAMICA
t_stream * paquetizarStruct_handshakeUMV(t_struct_handshakeUMV * estructuraOrigen);//ESTRUCTURA ESTATICA


//FUNCIONES DE HEADER QUE SIRVEN PARA PAQUETIZAR
char * crearDataConHeader(uint8_t tipoEstructura, int length);
t_header crearHeader(uint8_t tipoEstructura, uint16_t lengthDatos);

//FUNCION PRINCIPAL DESPAQUETIZAR
void * despaquetizar(uint8_t tipoEstructura, char * dataPaquete, uint16_t length);
//FUNCION DESPAQUETIZAR SEGUN TIPO DE ESTRUCTURA
t_struct_nombreMensaje * despaquetizarStruct_nombreMensaje(char * dataPaquete, uint16_t length); //ESTRUCTURA DINAMICA
t_struct_handshakeUMV * despaquetizarStruct_handshakeUMV(char * dataPaquete, uint16_t length);


//FUNCIONES DE HEADER QUE SIRVEN PARA DESPAQUETIZAR
t_header despaquetizarHeader(char * header);

#endif /* PACKAGE_H_ */
