/*
 * procesoKernel.h
 *
 *  Created on: 19/05/2014
 *      Author: utnso
 */

#ifndef PROCESOKERNEL_H_
#define PROCESOKERNEL_H_

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
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <socket.h>
#include <package.h>
#include <estructurasPackage.h>


typedef struct registroPCB {
	int peso;
	t_struct_pcb *pcb;
} t_struct_peso_pcb;

char* leer_codAnsisop(FILE *file);
void imprimirMetadata();
void* mainPLP();
void* mainPCP();
int obtenerID();
void insertarPCBOrdenadoSJN(t_list *lista, t_struct_peso_pcb *registroPCB);
int calcularPesoJob(t_medatada_program* metadata);
void pasarPCBsimple(t_list *listaNew, t_list *listaReady);
int solicitarCreacionSegmento(int socketUMV,int tamanio,int ID);


typedef struct aux_programas {
	int ID;
	t_struct_pcb*PCB;
	int *socket;
}t_struct_descriptor_procesos;

#endif /* PROCESOKERNEL_H_ */
