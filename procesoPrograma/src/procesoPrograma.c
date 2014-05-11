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

int Puerto;
char * IP;
t_log * logger;

int main(int argc, char** argv) {
	FILE *file;
	t_config * configuracion;
	char * temp_IP;
    char * log_name;

    log_name = malloc(strlen("Programa")+1);
    strcpy(log_name, "Programa");
    string_append(&log_name,".log"); // queda : nombre.log

    logger = log_create(log_name, "Programa", 1, LOG_LEVEL_TRACE);
    free(log_name);

	//-------------leer archivo de configuracion>------------//

	if (argc != 3) //controlar que haya exactamente dos parámetro
			{
		puts("Uso: programa <arch.conf>\n");
		return -1;  // esto me saca inmediatamente del main ?
	}

	configuracion = config_create(argv[1]);

	if (!conf_es_valida(configuracion)) //ver que el archivo de config tenga todito
			{
		puts("Archivo de configuracion incompleto o invalido.\n");
		return -2;
	}

	Puerto = config_get_int_value(configuracion, "Puerto");
	temp_IP = config_get_string_value(configuracion, "IP");
	IP = malloc(strlen(temp_IP) + 1);
	strcpy(IP, temp_IP);

	log_info(logger,"EL ARCHIVO DE CONFIGURACION SE LEVANTO CORRECTAMENTE");

	printf("Puerto=%d\n", Puerto); //imprime por pantalla el puerto
	printf("IP=%s\n", IP);     //imprime por pantalla la IP
	printf("\n");

	file = abrir_archivoRO(argv);
	int size = size_archivo(file);
	leer_codAnsisop(file);
	printf("%d", size);

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

void leer_codAnsisop(FILE *file) {
	char c;
	//while ((c = getc(file)) != '\n')
	//	(c = getc(file));

	while ((c = getc(file)) != EOF) //Lee cada caracter hasta encuentre el EndOfFile
		if (c == '\n')
			printf("\n");//Si encuentra el \n baja de linea
		else
			printf("%c", c); // y cualquier caracter que encuentra lo imprime por pantalla

	fclose(file);
}

/*
 * Nombre: abrir_archivoRO/1
 *
 *
 */
FILE *abrir_archivoRO(char** argv){
	return (fopen(argv[2], "r"));
}

