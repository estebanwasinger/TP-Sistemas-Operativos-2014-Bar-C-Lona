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

//El CPU entre otras cosas va a tener que parsear el codigo Ansisop
void imprimirMetadata();
int main(void) {


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
