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
int socket_kernel; // sockets globales para ser usados en las primitivas
int socket_UMV;    // sockets globales para ser usados en las primitivas
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


	socket_kernel=socket_crearYConectarCliente(IP_Kernel,Puerto_Kernel); // se conecta al kernel

	uint32_t temp_ind_codigo;
	uint32_t temp_counter;

	void * estructuraRecibida;
	t_tipoEstructura tipoRecibido;

//while(1){


//	int socket_UMV;			//declaro los sockets globales para usarlos en las funciones
//	int socket_kernel;

	// aca recibimos el pcb del PCP
	socket_recibir(socket_kernel,&tipoRecibido,&estructuraRecibida);

	if(tipoRecibido != D_STRUCT_PCB){ //verificamos que el PCB sea el correcto.
	 printf("Struct equivocado\n");
		return 0;
	}

	temp_ind_codigo =((t_struct_pcb*) estructuraRecibida)->indice_codigo;
	temp_counter=((t_struct_pcb*)estructuraRecibida)->programa_counter;
	temp_counter++;

	var_seg_stack=((t_struct_pcb*) estructuraRecibida)->seg_stack; //asignamos el valor recibido del PCB a una var aux.

	t_struct_sol_bytes * solicitar_indice = malloc(sizeof(t_struct_sol_bytes));

	solicitar_indice->base=temp_ind_codigo;
	solicitar_indice->offset=temp_ind_codigo;
	solicitar_indice->tamanio=2*sizeof(uint32_t);

	printf("%d\n",solicitar_indice->tamanio);




//socket_UMV=socket_crearYConectarCliente(IP_UMV,Puerto_UMV); //nos conectamos a la UMV
//socket_enviar(socket_UMV,D_STRUCT_SOLICITAR_BYTES,solicitar_indice); // le envio a la umv el base_indice y offset para que
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

//}

	return 0;


}


int conf_es_valida(t_config * configuracion) // verifica que el arch de conf tenga los datos correctos
{
	return (config_has_property(configuracion, "Puerto_kernel")
			&& config_has_property(configuracion, "Puerto_UMV")
			&& config_has_property(configuracion, "Ip_kernel")
			&& config_has_property(configuracion, "Ip_UMV"));

}


//PRIMITIVAS ANSISOP
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
// void asignar(t_puntero direccion_variable, t_valor_variable valor){ //asigna el valor que recibimos de la funcion "dereferenciar" a la variable en cuestion
//
//				memcpy(direccion_variable,&valor,sizeof(t_valor_variable);
//}
//
// t_valor_variable obtenerValorCompartida(t_nombre_compartida variable){//solicita al kernel valor de una variable compartida
//
// }
//
//t_valor_variable asignarValorCompartida(t_nombre_compartida variable, t_valor_variable valor){// solicita al kernel asignar un valor a la variable compartida
//
// }
//
//t_puntero_instruccion irAlLabel(t_nombre_etiqueta etiqueta){// devuelve el numero de primera instruccion ejecutable de etiqueta, -1 si error
//
//}
//
//t_puntero_instruccion llamarSinRetorno(t_nombre_etiqueta etiqueta, t_puntero_instruccion linea_en_ejecucion){ //guarda el contexto de ejecucion para poder retornar luego, muestra un nuevo contexto vacio y retorna el numero de instruccion a ejecutar
//
//}
//
//t_puntero_instruccion llamarConRetorno(t_nombre_etiqueta etiqueta, t_puntero donde_retornar, t_puntero_instruccion linea_en_ejecucion){ //guarda contexto de ejecucion actual, para retomar luego, y guarda la posicion de la variable entregada por donde_retornar
//
//}
//
//t_puntero_instruccion finalizar(void){ //cambia el contexto de ejecucion del actual al anterior, se recupera el cursor de contexto actual y program cuonter apilados en el stack. Si el contexto principal(ubicado al principio del stack) finalizo, devuelve -1
//
//}
//
//t_puntero_intruccion retornar(t_valor_variable retorno){ // cambia contexto de ejecucion actual por el anterior recuperando cursor de contexto acutal, program counter y direccion a donde retornar,
//
//}
//
//int imprimir(t_valor_variable valor_mostrar){ // envia al kernel valor_mostrar para que este le envia al programa en ejecucion y que imprima en consola
//
//}
//
//int imprimirTexto(char* texto){ // envia al kernel una cadena de texto para q este la envie al programa en ejecucion y que muestre por pantalla
//
//}
//
//int entradaSalida(t_nombre_dispositivo, int tiempo){ // informa al kernel que el programa actual pretende usar el dispositivo, durante tiempo
//
//}
//
//int wait(t_nombre_semaforo identificador_semaforo){ // informa al kernel que ejecute la funcion wait para el semaforo identificador_semaforo, el kernel decide si bloquear o no
//
//}
//
//int signal(t_nombre_semaforo idetificador_semaforo){ // informa al kernel que ejecute signal correspondiente para el semaforo identificador_semaforo
//
//}

