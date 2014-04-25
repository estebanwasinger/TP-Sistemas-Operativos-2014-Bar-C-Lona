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
#include <commons/config.h>
#include <commons/log.h>

int conf_es_valida(t_config * configuracion);
int Puerto;
char * IP;

int main(int argc, char** argv) {
	char c;
	FILE *file;
	t_config * configuracion;

	//-------------leer archivo de configuracion>------------//

	if(argc != 3) //controlar que haya exactamente dos parámetro
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

		Puerto = config_get_int_value(configuracion,"Puerto");
		IP = config_get_string_value(configuracion,"IP");

	printf("Puerto=%d\n",Puerto); //imprime por pantalla el puerto
	printf("IP=%s\n",IP);     //imprime por pantalla la IP
    printf("\n");

	file = fopen(argv[2], "r"); //Abre el archivo pasado por parametro
	while((c=getc(file))!='\n')(c=getc(file));

	while((c=getc(file))!=EOF) //Lee cada caracter hasta encuentre el EndOfFile
		if(c=='\n')
			printf("\n");//Si encuentra el \n baja de linea
		else
			printf("%c",c); // y cualquier caracter que encuentra lo imprime por pantalla

	fclose(file);

	return EXIT_SUCCESS;
}


int conf_es_valida(t_config * configuracion) // verifica que el arch de conf tenga los datos correctos
{
	return( config_has_property(configuracion, "Puerto") &&
			config_has_property(configuracion, "IP"));

}
