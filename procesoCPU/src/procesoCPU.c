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
#include <commons/collections/dictionary.h>
#include <parser/metadata_program.h>
#include <parser/parser.h>
#include <stdint.h>


int Puerto_Kernel;
int Puerto_UMV;
char * IP_Kernel;
char * IP_UMV;
t_log * logger;
//t_PCB * unPcb;
t_dictionary * dicc_variables;

int conf_es_valida(t_config * configuracion);
//t_puntero definirVariable(t_nombre_variable * identificador_variable);

int main(int argc, char **argv) {

t_config * configuracion;
char * temp_IP_Kernel;
char * temp_IP_UMV;
char * log_name;
int nuevo_socket;

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
//----------------leo el archivo de configuracion-----------------//
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

	//----------------termino archivo de configuracion--------------------//


	socket_crearYConectarCliente(IP_Kernel,Puerto_Kernel); // se conecta al kernel

while(1){

//unPcb = recibir_PCB();
//unPcb->cursor_stack=unPcb->cursor_stack+1;


//	unPcb=malloc(sizeof(unPcb));
//
//	unPcb->Id=435;
//    unPcb->cursor_stack =0X45;
//    unPcb->indice_codigo=0X67;
//    unPcb->seg_stack="a";
//	unPcb->indice_etiquetas=0X23;
//	unPcb->program_counter=1;
//	unPcb->seg_codigo=0X234;
//	unPcb->size_contexto_actual=34;
//	unPcb->size_indice_etiquetas=0X56;


 dicc_variables =dictionary_create(); // este el diccinario de las variables del programa.



}

	return 0;


}


int conf_es_valida(t_config * configuracion) // verifica que el arch de conf tenga los datos correctos
{
	return (config_has_property(configuracion, "Puerto_kernel")
			&& config_has_property(configuracion, "Puerto_UMV")
			&& config_has_property(configuracion, "Ip_kernel")
			&& config_has_property(configuracion, "Ip_UMV"));

}



//t_puntero definirVariable(t_nombre_variable  identificador_variable){
//	memcpy(unPcb->seg_stack ,identificador_variable ,sizeof(t_nombre_variable)+sizeof(t_valor_variable)); //aca ver seria mejor solo usar el sizeof(t_nombre_variable)
//	//asegurarme que identificador_variable sea dianmico.
//    dictionary_put(dicc_variables,identificador_variable,unPcb->seg_stack);
//    return unPcb+sizeof(t_nombre_variable); // posicion del valor de la variable en el stack
//
//}
//
//
//t_puntero obtenerPosicionVariable(t_nombre_variable identificador_variable){
//
//
//}
