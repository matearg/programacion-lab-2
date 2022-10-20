#include "arboles.h"

nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(int dato){
    nodoArbol * aux = (nodoArbol *)malloc(sizeof(nodoArbol));

    aux->dato = dato;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

nodoArbol * buscarNodo(nodoArbol * arbol, int dato)
{
    nodoArbol * rta = NULL;

    if(arbol)
    {
        if (dato == arbol->dato) {
            rta = arbol;
        } else {
            if (dato > arbol->dato) {
                rta = buscarNodo(arbol->der, dato);
            } else {
                rta = buscarNodo(arbol->izq, dato);
            }
        }
    }

    return rta;
}

nodoArbol * insertarNodo(nodoArbol * arbol, int dato)
{
    if(!arbol)
    {
        arbol = crearNodoArbol(dato);
    }
    else
    {
        if(dato > arbol->dato)
        {
            arbol->der = insertarNodo(arbol->der, dato);
        }
        else
        {
            arbol->izq = insertarNodo(arbol->izq, dato);
        }
    }
    return arbol;
}

void preorder(nodoArbol * arbol) {
    if (arbol) {
        printf("%d", arbol->dato);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void inorder(nodoArbol * arbol) {
    if (arbol) {
        inorder(arbol->izq);
        printf("%d", arbol->dato);
        inorder(arbol->der);
    }
}

void postorder(nodoArbol * arbol) {
    if (arbol) {
        inorder(arbol->izq);
        inorder(arbol->der);
        printf("%d", arbol->dato);
    }
}
