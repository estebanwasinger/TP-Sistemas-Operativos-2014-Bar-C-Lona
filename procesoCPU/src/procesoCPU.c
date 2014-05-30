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
#include <package.h>
#include <estructurasPackage.h>
#include <socket.h>
#include <stdint.h>



int Puerto_Kernel;
int Puerto_UMV;
char * IP_Kernel;
char * IP_UMV;
t_log * logger;
t_dictionary * dicc_variables;
uint32_t var_seg_stack;

int conf_es_valida(t_config * configuracion);
//t_puntero definirVariable(t_nombre_variable * identificador_variable);

int main(int argc, char **argv) {

t_config * configuracion;
char * temp_IP_Kernel;
char * temp_IP_UMV;
char * log_name;
//t_struct_pcb * otroPCB;


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

	int socket_UMV;
	int socket_recibir;
	uint32_t temp_ind_codigo;
	uint32_t temp_counter;

//	unPcb.iD=1987;
//	unPcb.indice_codigo=0x1;
//	unPcb.indice_etiquetas=0x34;
//	unPcb.programa_counter=1;
//	unPcb.seg_codigo=0x2;
//	unPcb.seg_stack=0x3;

	void * estructuraRecibida;
	t_struct_pcb tipoRecibido;

	// aca recibimos el pcb del PCP
	socket_recibir(socket_recibir,&tipoRecibido,&estructuraRecibida);
	temp_ind_codigo =((t_struct_pcb*) estructuraRecibida)->indice_codigo;
	temp_counter=((t_struct_pcb*)estructuraRecibida)->programa_counter;
	temp_counter++; //incrementamos el counter;

	var_seg_stack=((t_struct_pcb*) estructuraRecibida)->seg_stack; //asignamos el valor recibido del PCB a una var aux.
	t_struct_sol_bytes * solicitar_indice = malloc(sizeof(t_struct_sol_bytes));
	solicitar_indice->base=temp_ind_codigo;
	solicitar_indice->offset=temp_ind_codigo;
	solicitar_indice->tamanio=2*sizeof(uint32_t);

socket_UMV=socket_crearYConectarCliente(IP_UMV,Puerto_UMV); //nos conectamos a la UMV
socket_enviar(socket_UMV,D_STRUCT_SOLICITAR_BYTES,solicitar_indice); // le envio a la umv el base_indice y offset para que
																	 //me devuelva los 8 bytes que hay despues de esa base

//aca vamos a recibir el char* conteniendo el numero de Indice de Codigo y su desplazamiento, para asi poder enviarle
//la base del segemento codigo con el offset y el tamnio.
//socket_recibir(socket_recibir,tipo_recibir_bytes,t_struct_recibir_bytes);


 dicc_variables =dictionary_create(); // este el diccinario de las variables del programa.


//estas son pruebas.

//    t_stream * unStream = malloc(sizeof(t_stream));
//    t_struct_env_bytes * env1=malloc(sizeof(t_struct_env_bytes));
//
//    env1->base=23;
//    env1->offset=12;
//    env1->tamanio=12;
//    env1->buffer=strdup("holacomoteva");
//
//   unStream = paquetizarStruct_env_bytes(env1);

//   printf("hola\n");
//   printf("%d\n",unStream->length);
//   printf("%s\n",unStream->data);
//   printf("hola\n");

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


//
//t_puntero definirVariable(t_nombre_variable  identificador_variable){
//
//
//	memcpy(&var_seg_stack ,&identificador_variable ,sizeof(t_nombre_variable)); //aca ver seria mejor solo usar el sizeof(t_nombre_variable)
//	//asegurarme que identificador_variable sea dianmico.
//
//
//	dictionary_put(dicc_variables,&identificador_variable,&var_seg_stack+sizeof(t_nombre_variable));
//    return var_seg_stack+sizeof(t_nombre_variable); // posicion del valor de la variable en el stack
//
//}
////
//
//t_puntero obtenerPosicionVariable(t_nombre_variable identificador_variable){
//
//	return dictionary_get(dicc_variables,&identificador_variable);
//
//}
//
//t_valor_variable dereferenciar(t_puntero direccion_variable){ // retorna el valor de una variable
//
//    //leo la direccion del valor de la variable en el dicccionario
//	//le envia esa direccion a la umv para que me devuelva lo que hay 4 bytes despues de esa direccion.
//	//recibo el valor y lo devuelvo
//
//
//}
