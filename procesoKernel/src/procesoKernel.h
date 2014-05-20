/*
 * procesoKernel.h
 *
 *  Created on: 19/05/2014
 *      Author: utnso
 */

#ifndef PROCESOKERNEL_H_
#define PROCESOKERNEL_H_

char* leer_codAnsisop(FILE *file);
void imprimirMetadata();
void* mainPLP();
void* mainPCP();

typedef struct PCB {
    int ID;
    int SEG_CODIGO;
    int SEG_STACK;
    int CURSOR_STACK;
    int INDICE_CODIGO;
    int INDICE_ETIQUETAS;
    int PROGRAM_COUNTER;
    int SIZE_CONTEXTO_ACTUAL;
    int SIZE_INDICE_ETIQUETAS;
} PCB;

#endif /* PROCESOKERNEL_H_ */
