/*
 ============================================================================
 Name        : procesoCPU.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/config.h>
#include <commons/log.h>
#include <commons/string.h>


int Puerto_Kernel;
int Puerto_UMV;
char * IP_Kernel;
char * IP_UMV;
t_log * logger;

int conf_es_valida(t_config * configuracion);

int main(int argc, char **argv) {

t_config * configuracion;
char * temp_IP_Kernel;
char * temp_IP_UMV;
char * log_name;

   log_name = malloc(strlen("CPU")+1);
   strcpy(log_name, "CPU");
   string_append(&log_name,".log"); // queda : nombre.log

   logger = log_create(log_name, "CPU", 1, LOG_LEVEL_TRACE);
   free(log_name);

if (argc != 2) //controlar que haya exactamente un parámetro
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

    Puerto_UMV = config_get_int_value(configuracion, "Puerto_UMV");
    Puerto_Kernel = config_get_int_value(configuracion, "Puerto_kernel");
    temp_IP_UMV=config_get_string_value(configuracion, "Ip_kernel");;
	temp_IP_Kernel = config_get_string_value(configuracion, "Ip_UMV");
	IP_Kernel = malloc(strlen(temp_IP_Kernel)+ 1);
	IP_UMV = malloc(strlen(temp_IP_UMV)+ 1);
	strcpy(IP_Kernel,temp_IP_Kernel);
	strcpy(IP_UMV,temp_IP_UMV);

	log_info(logger,"EL ARCHIVO DE CONFIGURACION SE LEVANTO CORRECTAMENTE");

	printf("Puerto_k=%d\n", Puerto_Kernel); //imprime por pantalla el puerto
	printf("Puerto_U=%d\n", Puerto_UMV); //imprime por pantalla el puerto

	printf("IP_K=%s\n", IP_Kernel);     //imprime por pantalla la IP
	printf("IP_K=%s\n", IP_UMV);     //imprime por pantalla la IP

	printf("\n");


	return 0;

}

int conf_es_valida(t_config * configuracion) // verifica que el arch de conf tenga los datos correctos
{
	return (config_has_property(configuracion, "Puerto_kernel")
			&& config_has_property(configuracion, "Puerto_UMV")
			&& config_has_property(configuracion, "Ip_kernel")
			&& config_has_property(configuracion, "Ip_UMV"));

}
