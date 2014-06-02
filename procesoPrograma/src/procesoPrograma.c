/*
 ============================================================================
 Name        : procesoPrograma.c
 Author      : Bar C Lona
 Version     :
 Copyright   : (R) Copyright Bar C Lona - 2014
 Description : ProcesoPrograma
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/config.h>
#include <commons/log.h>
#include <commons/string.h>
#include "procesoPrograma.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <socket.h>
#include <estructurasPackage.h>
#include <package.h>


#define DIRECCION "127.0.0.1"
#define PUERTO 5000
#define MAX_CONNECTION_SERVER 60

int Puerto;
char * IP;
t_log * logger;

int main(int argc, char** argv) {
	FILE *file;
//	t_config * configuracion;
//	char * temp_IP;
//    char * log_name;
//
//    log_name = malloc(strlen("Programa")+1);
//    strcpy(log_name, "Programa");
//    string_append(&log_name,".log"); // queda : nombre.log
//
//    logger = log_create(log_name, "Programa", 1, LOG_LEVEL_TRACE);
//    free(log_name);
//
//	//-------------leer archivo de configuracion>------------//
//
//	if (argc != 3) //controlar que haya exactamente dos parámetro
//			{
//		puts("Uso: programa <arch.conf>\n");
//		return -1;  // esto me saca inmediatamente del main ?
//	}
//
//	configuracion = config_create(argv[1]);
//
//	if (!conf_es_valida(configuracion)) //ver que el archivo de config tenga todito
//			{
//		puts("Archivo de configuracion incompleto o invalido.\n");
//		return -2;
//	}
//
//	Puerto = config_get_int_value(configuracion, "Puerto");
//	temp_IP = config_get_string_value(configuracion, "IP");
//	IP = malloc(strlen(temp_IP) + 1);
//	strcpy(IP, temp_IP);
//
//	log_info(logger,"EL ARCHIVO DE CONFIGURACION SE LEVANTO CORRECTAMENTE");
//
//	printf("Puerto=%d\n", Puerto); //imprime por pantalla el puerto
//	printf("IP=%s\n", IP);     //imprime por pantalla la IP
//	printf("\n");

//	struct sockaddr_in socketInfo;

	//**********************************//
	//	   Conexión con el Kernel		//
	//**********************************//

	int socketKernel;
	socketKernel = socket_crearCliente();
	socket_conectarCliente(socketKernel, "127.0.0.1", 6000);

	//**********************************//
	//	   Leectura y envio de codigo	//
	//**********************************//

	file = abrir_archivoRO(argv);
	int size = size_archivo(file);
	char* codigo = leer_codAnsisop(file);

	t_struct_string * codigoAEnviar = malloc(sizeof(t_struct_string));
	codigoAEnviar->string = codigo;

	socket_enviar(socketKernel,D_STRUCT_STRING,codigoAEnviar);

	while(1){

	}
	close(socketKernel);
	return EXIT_SUCCESS;
}

int conf_es_valida(t_config * configuracion) // verifica que el arch de conf tenga los datos correctos
{
	return (config_has_property(configuracion, "Puerto")
			&& config_has_property(configuracion, "IP"));

}

int size_archivo(FILE *file) {
	fseek(file, 0L, SEEK_END);
	int size = ftell(file);
	fseek(file, 0L, SEEK_SET);
	return size;
}

char* leer_codAnsisop(FILE *file) {
	char c;
	fseek(file, 0L, SEEK_END);
	int size = ftell(file);
	fseek(file, 0L, SEEK_SET);
	int size2 = size;
	char* text = malloc(size2);
	char text2[size2];
	int i = 0;
	while ((c = getc(file)) != EOF) { //Lee cada caracter hasta encuentre el EndOfFile
		text2[i] = c;
		i++;
	}
	strcpy(text, text2);

	fclose(file);
	return text;
}

FILE *abrir_archivoRO(char** argv) {
	//printf("%s \n", argv[2]);
	return (fopen("/home/utnso/workspace/tp-2014-1c-bar-c-lona/procesoPrograma/Debug/facil.ansisop", "r"));
}

