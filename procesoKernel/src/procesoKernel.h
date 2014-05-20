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

//FUNCIONES PARA EL CLIENTE
int socket_crearCliente(void);
int socket_conectarCliente(int sockfd,char *serverIp, int serverPort);
int socket_crearYConectarCliente(char *serverIp, int serverPort);

//FUNCIONES PARA EL SERVIDOR
int socket_crearServidor(char *ip, int port);
int socket_crearServidorPuertoRandom(char *ip, int * port);
int socket_aceptarCliente(int socketEscucha);


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
