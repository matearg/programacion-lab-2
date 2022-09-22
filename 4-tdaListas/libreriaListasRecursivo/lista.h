#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo
{
    int dato;
    struct _nodo * siguiente;
} nodo;

// Funciones independientes del tipo de dato
nodo * inicLista();
nodo * crearNodo(int dato);
nodo * agregarAlFinal(nodo * lista, nodo * nuevo);
nodo * agregarAlPrincipio(nodo * lista, nodo * nuevo);
nodo * buscarUltimo(nodo * lista);
nodo * agregarEnOrden(nodo * lista, nodo * nuevo);
nodo * buscarNodo(nodo * lista, int valor);
nodo * borrarNodo(nodo * lista, int valor);
void mostrarLista(nodo * lista);
void mostrarNodo(nodo * lista);


// Funciones dependientes del tipo de dato
nodo * subProgramaAgregarAlFinal(nodo * lista, int dato);
nodo * subProgramaArchivoToLista(nodo * lista, char archivo[]);
nodo * subProgramaVaciarLista(nodo * lista);
nodo * subProgramaCargarLista(nodo * lista);
nodo * subProgramaCargarOrdenada(nodo * lista);
nodo * subProgramaInvertirLista(nodo * lista);
