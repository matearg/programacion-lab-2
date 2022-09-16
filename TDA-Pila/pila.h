#include <stdio.h>
#include <stdlib.h>

#define Pila nodo *

typedef struct _nodo{
    int dato;
    struct _nodo * siguiente;
} nodo;

// Funciones independientes del tipo de dato
void inicpila(Pila * p);
void apilar(Pila * p, int dato);
void desapilar(Pila * p);
int tope(Pila * p);
int pilavacia(Pila * p);
void leer(Pila * p);
void mostrar(Pila * p);
