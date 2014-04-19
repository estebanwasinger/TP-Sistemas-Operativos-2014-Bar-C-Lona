/*
 ============================================================================
 Name        : tp-2014-1c-bar-c-lona.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <commons/temporal.h>

int main(void) {

	char* tiempo = temporal_get_string_time();
	printf("El tiempo es %s:", tiempo);
	free(tiempo);

	return EXIT_SUCCESS;
}
