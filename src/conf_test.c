/*
 * conf_test.c
 *
 *  Created on: 20/04/2014
 *      Author: utnso
 */


/*
 * probar_conf.c
 *
 *  Created on: 19/04/2014
 *      Author: utnso
 */

#include <stdio.h>
#include <commons/config.h>
#include <commons/log.h>


#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define DIRECCION "127.0.0.1"

//#define BUFF_SIZE 1024

int Puerto;
char * IP;
//t_log* logger;

int conf_es_valida(t_config * configuracion);

int main2(int argc, char **argv) {

	t_config * configuracion;
//	char * log_name;
	int unSocket;
	struct sockaddr_in socketInfo;
//	char buffer[BUFF_SIZE];

	printf("Conectando...\n");


	//-------------leer archivo de configuracion>------------//

if(argc != 2) //controlar que haya exactamente un parámetro
		{
			puts("Uso: personaje <arch.conf>\n");
			return -1;  // esto me saca inmediatamente del main ?
		}

	configuracion = config_create(argv[1]);

	if (!conf_es_valida(configuracion)) //ver que el archivo de config tenga todito
		{
			puts("Archivo de configuracion incompleto o invalido.\n");
			return -2;
		}

	Puerto = config_get_int_value(configuracion,"Puerto");
    IP = config_get_string_value(configuracion,"IP");

    //-------------fin archivo de configuracion>------------//

    // Crear un socket:
    // AF_INET: Socket de internet IPv4
    // SOCK_STREAM: Orientado a la conexion, TCP
    // 0: Usar protocolo por defecto para AF_INET-SOCK_STREAM: Protocolo TCP/IPv4
    if ((unSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    		perror("Error al crear socket");
    		return EXIT_FAILURE;
    	}

        socketInfo.sin_family = AF_INET;
    	socketInfo.sin_addr.s_addr = inet_addr(DIRECCION);
    	socketInfo.sin_port = htons(Puerto);

   // Conectar el socket con la direccion 'socketInfo'.
    	if (connect(unSocket, (struct sockaddr*) &socketInfo, sizeof(socketInfo))
    				!= 0) {
    		perror("Error al conectar socket");
    		return EXIT_FAILURE;
    	}

    	printf("Conectado!\n");

    // Enviar los datos leidos por teclado a traves del socket.
     if (send(unSocket,IP, strlen(IP), 0) >= 0) {
    				printf("Datos enviados!\n");
    			} else {
    				perror("Error al enviar datos. Server no encontrado.\n");

    			}

    	close(unSocket);

	/*printf("el puerto es:%d\n",Puerto);
	printf("el nombre es:%s\n",IP);*/

	return 0;
}


int conf_es_valida(t_config * configuracion)
{
	return( config_has_property(configuracion, "Puerto") &&
			config_has_property(configuracion, "IP"));

}
