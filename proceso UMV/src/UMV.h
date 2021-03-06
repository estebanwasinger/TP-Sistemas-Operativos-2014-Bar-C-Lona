#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <commons/string.h>
#include <commons/config.h>
#include <commons/collections/list.h>
#include <pthread.h>
#include <socket.h>
#include <estructurasPackage.h>
#include <package.h>

//Definicion de Structss
typedef struct{
   int programa;
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
void Grabar(int posMem, void * element);
void * Consultar(int posMem);
void ManejoKernel(int coneccion);
void MostrarRangosMemoriaLibre();
void EliminarSegmento(int base);
void EliminarSegmentosDePrograma(int programa);
void Mostrar(Segmento* rango);
void MostrarSegmentos();
void Dump();
void DumpDeUnPrograma(int Programa);
void CambiarRetardo(int retardo);
void EscucharYLanzarHilos();
void ManejoKernel(int nueva_coneccion);
void ManejoCPU(int nueva_coneccion);

//Firmas funciones Int
int GrabarSegmento(int programa, int tamanoSegmento);
int ObtenerCantidadMemoriaTotal();
int EjecutarComandos(t_list *lista);
int GuardarNuevoSegmentoOrdenado();
int Hay_algun_rango_de_tamano_suficiente(RangoMemoria *rango);
int CantidadMemoriaLibre();
int GuardarNuevoSegmentoOrdenado(int programa, int baseVirtual, int tamano);
int PosicionDeSegmento(int base);

//Otra firmas de funciones
Segmento *create_segmento(int programa,void* base, int baseVirtual,int tamano);
t_list *RangosLibresDeMemoria();
RangoMemoria  RangoMasGrandeLibre();
bool SePuedeGrabarSegmento(int tamano);
Segmento BuscarSegmento(int base);


//Variables Estaticas
int ALGOTIRMO_FIRSTFIT = 1;
int ALGOTIRMO_WORSTFIT = 2;








