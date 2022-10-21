#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodoArbol {
    int dato;
    struct _nodoArbol * izq;
    struct _nodoArbol * der;
} nodoArbol;

nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(int dato);
nodoArbol * buscarNodo(nodoArbol * arbol, int dato);
nodoArbol * insertarNodo(nodoArbol * arbol, int dato);
void preorder(nodoArbol * arbol);
void inorder(nodoArbol * arbol);
void postorder(nodoArbol * arbol);
nodoArbol * busquedaPreorder(nodoArbol * arbol, int dato);
int contarNodos(nodoArbol * arbol);
int alturaArbol(nodoArbol * arbol);

#endif // ARBOLES_H_INCLUDED
