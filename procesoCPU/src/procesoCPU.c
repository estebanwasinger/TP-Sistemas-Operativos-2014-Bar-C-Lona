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
#include <parser/metadata_program.h>
#include <parser/parser.h>
#include <commons/string.h>
#include <commons/txt.h>

//El CPU entre otras cosas va a tener que parsear el codigo Ansisop
int main(void) {
	char* programa = malloc(100);
	strcpy(programa,"begin variables a,b,c\nend\n\n");

	t_medatada_program *datos;
	datos = metadatada_desde_literal(programa);
	printf("cantidad: %d", datos->instrucciones_size);
	return 0;
}
