/*
 * procesoPrograma.h
 *
 *  Created on: 10/05/2014
 *      Author: utnso
 */

#ifndef PROCESOPROGRAMA_H_
#define PROCESOPROGRAMA_H_

int conf_es_valida(t_config * configuracion);
int size_archivo(FILE *file);
FILE *abrir_archivoRO(char** argv);
char *leer_codAnsisop(FILE *file);
//FUNCIONES PARA EL CLIENTE
int socket_crearCliente(void);
int socket_conectarCliente(int sockfd,char *serverIp, int serverPort);
int socket_crearYConectarCliente(char *serverIp, int serverPort);

//FUNCIONES PARA EL SERVIDOR
int socket_crearServidor(char *ip, int port);
int socket_crearServidorPuertoRandom(char *ip, int * port);
int socket_aceptarCliente(int socketEscucha);


#endif /* PROCESOPROGRAMA_H_ */
