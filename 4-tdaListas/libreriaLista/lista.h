#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

typedef struct _nodo{
    persona dato;
    struct _nodo * siguiente;
} nodo;

// Funciones independientes del tipo de dato
nodo * inicLista();
nodo * crearNodo(persona dato);
nodo * agregarAlFinal(nodo * lista, nodo * nuevo);
nodo * agregarAlPrincipio(nodo * lista, nodo * nuevo);
nodo * buscarUltimo(nodo * lista);
nodo * agregarEnOrden(nodo * lista, nodo * nuevo);
nodo * buscarNodo(nodo * lista, char nombre[20]);
nodo * borrarNodo(nodo * lista, char nombre[20]);
void mostrarLista(nodo * lista);
void mostrarNodo(nodo * lista);


// Funciones dependientes del tipo de dato
nodo * subProgramaAgregarAlFinal(nodo * lista, persona dato);
nodo * subProgramaArchivoToLista(nodo * lista, char archivo[]);
nodo * subProgramaVaciarLista(nodo * lista);
nodo * subProgramaCargarLista(nodo * lista);
nodo * subProgramaCargarOrdenada(nodo * lista);
nodo * subProgramaInvertirLista(nodo * lista);
