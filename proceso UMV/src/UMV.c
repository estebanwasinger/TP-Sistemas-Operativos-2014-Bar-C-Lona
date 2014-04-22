#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void compactar_memoria();
void switch_function(char* funcion);


int main(void) {

	char *nombre_funcion = NULL;

	// Aca hacemos el maloc para la string que va a ser el recibidor del comando
	nombre_funcion = malloc(sizeof(char) * 30);

	if(nombre_funcion == NULL){
		printf("Fallo al alocar memoria \n");
	}

	printf("UMV Bar - C - Lona Console. \n\n");

	while(1){
		scanf("%s",nombre_funcion);
		if(!strcmp(nombre_funcion, "exit")){
			printf("\n\n Adios \n");
			break;
		}
		switch_function(nombre_funcion);

	}


	return EXIT_SUCCESS;
}

	void switch_function(char *funcion){
		if(!strcmp(funcion, "compactar")){
			compactar_memoria();
			return;
		}

		printf("No se encontro el Comando <%s>", funcion);

	}

	void compactar_memoria(){
		printf("La Compactacion fue exitosa \n");
	}
