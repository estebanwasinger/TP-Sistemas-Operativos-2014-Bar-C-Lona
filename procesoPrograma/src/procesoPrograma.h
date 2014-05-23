/*
 * procesoPrograma.h
 *
 *  Created on: 10/05/2014
 *      Author: utnso
 */

#ifndef PROCESOPROGRAMA_H_
#define PROCESOPROGRAMA_H_

int conf_es_valida(t_config * configuracion);
int size_archivo(FILE *file);
FILE *abrir_archivoRO(char** argv);
char *leer_codAnsisop(FILE *file);



#endif /* PROCESOPROGRAMA_H_ */
