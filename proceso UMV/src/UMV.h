#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

typedef struct{
   int base;
   int tamano;
}RangoMemoria;



// Firmas funciones Void
void LanzarConsola();
void Consola();
void CambiarAlgoritmo(char* nombreAlgoritmo);
void CompactaMemoria();
void ContarTamano(RangoMemoria* rango);

//Firmas funciones Int
int ObtenerCantidadMemoriaTotal();
int EjecutarComandos(t_list *lista);
int GrabarNuevoSegmento();
int Hay_algun_rango_de_tamano_suficiente(RangoMemoria *rango);
int CantidadMemoriaLibre();

//Otra firmas de funciones
Segmento *create_segmento(char* programa,void* base, int baseVirtual,int tamano);
t_list *RangosLibresDeMemoria();


//Variables Estaticas
int ALGOTIRMO_FIRSTFIT = 1;
int ALGOTIRMO_WORSTFIT = 2;


