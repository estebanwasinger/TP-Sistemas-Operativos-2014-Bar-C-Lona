#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/string.h>
#include <commons/config.h>
#include <commons/collections/list.h>
#include <pthread.h>

//Definicion de Structss
typedef struct{
   char* programa;
   void* base;
   int baseVirtual;
   int tamano;
}Segmento;



// Firmas funciones Void
void compactar_memoria();
void switch_function(char* funcion);
void LanzarConsola();
void Consola();
void CambiarAlgoritmo(char* nombreAlgoritmo);

//Firmas funciones Int
int ObtenerCantidadMemoriaTotal();
int EjecutarComandos(t_list *lista);
int AlocarNuevoSegmento();

//Otra firmas de funciones
Segmento *create_segmento(char* programa,void* base, int baseVirtual,int tamano);


//Variables Estaticas
int ALGOTIRMO_FIRSTFIT = 1;
int ALGOTIRMO_WORSTFIT = 2;


