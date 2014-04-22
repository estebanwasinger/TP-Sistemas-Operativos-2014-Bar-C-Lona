/*
 ============================================================================
 Name        : procesoPrograma.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	char c;
	FILE *file;
	file = fopen(argv[1], "r"); //Abre el archivo pasado por parametro
	while((c=getc(file))!='\n')(c=getc(file));

	while((c=getc(file))!=EOF) //Lee cada caracter hasta encuentre el EndOfFile
		if(c=='\n')
			printf("\n");//Si encuentra el \n baja de linea
		else
			printf("%c",c); // y cualquier caracter que encuentra lo imprime por pantalla

	fclose(file);

	return EXIT_SUCCESS;
}
