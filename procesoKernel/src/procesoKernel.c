/*
 ============================================================================
 Name        : procesoKernel.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <parser/metadata_program.h>
#include <parser/parser.h>

#include <commons/log.h>
#include <commons/config.h>
#include <commons/string.h>

t_log * logger;
int puerto_programa;
int puerto_cpu;
int Quantum;
int Retardo;
int nivel_multiprogramacion;


//El CPU entre otras cosas va a tener que parsear el codigo Ansisop
void imprimirMetadata();
int	string_count(char * text, char c);
int conf_es_valida(t_config * configuracion);
int main(int argc, char** argv) {
	t_config * configuracion;
	char * tempID_HIO;
	char * temp_retardoDisp;
	char * tempSemaforos;
	char * temp_valorIni;
	int cantidad_dispositivos;
	int cantidad_semaforos;
	char ** ID_HIO;
	char ** retardo_dispositivo;
	char ** semaforos;
	char ** valor_semaforo;

	//-------------leer archivo de configuracion>------------//

	if(argc != 2) //controlar que haya exactamente dos parámetro
				{
					puts("Uso: Kernel<arch.conf>\n");
					return -1;  // esto me saca inmediatamente del main ?
				}
	configuracion = config_create(argv[1]);

	if (!conf_es_valida(configuracion)) //ver que el archivo de config tenga todito
				{
					puts("Archivo de configuracion incompleto o invalido.\n");
					return -2;
				}

	puerto_cpu=config_get_int_value(configuracion,"PUERTO_CPU");
	puerto_programa=config_get_int_value(configuracion,"PUERTO_PROG");
	Quantum=config_get_int_value(configuracion,"QUANTUM");
	Retardo=config_get_int_value(configuracion,"RETARDO");
	nivel_multiprogramacion=config_get_int_value(configuracion,"MULTIPROGRAMACION");

	printf("puerto_cpu:%d\n",puerto_cpu);
	printf("puerto_programa:%d\n",puerto_programa);
	printf("Quantum:%d\n",Quantum);
	printf("Retardo:%d\n",Retardo);
	printf("nivel_multiprogramacion:%d\n",nivel_multiprogramacion);

	tempID_HIO=strdup(config_get_string_value(configuracion,"ID_HIO"));
	 cantidad_dispositivos=string_count(tempID_HIO, ',') + 1;
	ID_HIO= string_get_string_as_array(tempID_HIO);
    free(tempID_HIO);

    temp_retardoDisp=strdup(config_get_string_value(configuracion,"HIO"));
    retardo_dispositivo= string_get_string_as_array(temp_retardoDisp);
    free(temp_retardoDisp);

    int i=0;
    int retardo_entero;

while(i<cantidad_dispositivos){

	retardo_entero=atoi(retardo_dispositivo[i]);
	printf("el Dispositivo es:%s y tiene un retardo de:%d\n",ID_HIO[i],retardo_entero);
    i++;
}
  tempSemaforos=strdup(config_get_string_value(configuracion,"SEMAFOROS"));
  cantidad_semaforos=string_count(tempSemaforos,',')+1;
  semaforos=string_get_string_as_array(tempSemaforos);
  free(tempSemaforos);

  temp_valorIni=strdup(config_get_string_value(configuracion,"VALOR_SEMAFORO"));
  valor_semaforo=string_get_string_as_array(temp_valorIni);
  free(temp_valorIni);

  int j=0;
  int valor_entero;

  while(j<cantidad_semaforos){

  	valor_entero=atoi(valor_semaforo[j]);
  	printf("el Semaforo es:%s y tiene un Valor de:%d\n",semaforos[j],valor_entero);
      j++;
  }

 printf("#######################################\n");

	char* programa = malloc(511);
	strcpy(programa,"begin variables a,b,c\nend\n\n");
	t_medatada_program* metadata;
	metadata = metadatada_desde_literal(programa);
	printf("cantidad de instrucciones: %d\n", metadata->instrucciones_size);
	printf("Cantidad de etiquetas %i\n",metadata->cantidad_de_etiquetas);
	printf("----------- Funcion impresion -------- \n");

	imprimirMetadata(metadata);

	return 0;
}


void imprimirMetadata(t_medatada_program* metadata){
printf("Cantidad de etiquetas %i\n",metadata->cantidad_de_etiquetas);
printf("Cantidad de funciones %i\n",metadata->cantidad_de_funciones);
printf("Etiquetas %s\n",metadata->etiquetas);
printf("Tamaño del mapa serializado de etiquetas %i\n",metadata->etiquetas_size);
printf("Tamaño del mapa serializado de instrucciones %i\n",metadata->instrucciones_size);
printf("El numero de la primera instruccion es %i\n",metadata->instruccion_inicio);

}

int conf_es_valida(t_config * configuracion)
{
	return( config_has_property(configuracion, "ID_HIO") &&
			config_has_property(configuracion, "HIO") &&
			config_has_property(configuracion, "SEMAFOROS") &&
			config_has_property(configuracion, "VALOR_SEMAFORO") &&
			config_has_property(configuracion, "MULTIPROGRAMACION")&&
			config_has_property(configuracion, "PUERTO_PROG")&&
			config_has_property(configuracion, "PUERTO_CPU")&&
			config_has_property(configuracion, "QUANTUM")&&
			config_has_property(configuracion, "RETARDO"));
}

int	string_count(char * text, char c)
{
	int i=0;
	int pos=0;

	while(text[pos]!='\0')
	{
		if (text[pos] == c) i++;
		pos++;
	}
	return i;
}
