#include "arboles.h"

nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(int dato)
{
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
        if (dato == arbol->dato)
        {
            rta = arbol;
        }
        else
        {
            if (dato > arbol->dato)
            {
                rta = buscarNodo(arbol->der, dato);
            }
            else
            {
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

void preorder(nodoArbol * arbol)
{
    if (arbol)
    {
        printf("%d", arbol->dato);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void inorder(nodoArbol * arbol)
{
    if (arbol)
    {
        inorder(arbol->izq);
        printf("%d", arbol->dato);
        inorder(arbol->der);
    }
}

void postorder(nodoArbol * arbol)
{
    if (arbol)
    {
        inorder(arbol->izq);
        inorder(arbol->der);
        printf("%d", arbol->dato);
    }
}

nodoArbol * busquedaPreorder(nodoArbol * arbol, int dato)
{
    nodoArbol * rta = NULL;
    if (arbol)
    {
        if (arbol->dato == dato)
        {
            rta = arbol;
        }
        else
        {
            rta = busquedaPreorder(arbol->izq, dato);
            if (!rta)
            {
                rta = busquedaPreorder(arbol->der, dato);
            }
        }
    }
    return rta;
}

int contarNodo(nodoArbol * arbol)
{
    int rta = 0;

    if (arbol)
        rta = 1 + contarNodo(arbol->izq) + contarNodo(arbol->der);

    return rta;
}

int alturaArbol(nodoArbol * arbol)
{
    int rta = 0;

    if (arbol)
    {
        rta = 1;
    }

    return rta;
}

nodoArbol * nodoMasDerecha(nodoArbol * arbol)
{
    nodoArbol * rta = arbol;

    if (arbol)
        if (arbol->der)
            rta = nodoMasDerecha(arbol->der);

    return rta;
}

nodoArbol * nodoMasIzquierda(nodoArbol * arbol)
{
    nodoArbol * rta = arbol;

    if (arbol)
        if (arbol->izq)
            rta = nodoMasIzquierda(arbol->izq);

    return rta;
}

int esHoja(nodoArbol * nodo)
{
    int rta = 0;

    if (nodo)
        if ((nodo->der != NULL) & (nodo->izq != NULL))
            rta = 1;

    return rta;
}

nodoArbol * archivoToArbol(nodoArbol * arbol)
{
    FILE * archivo = fopen("datos.dat","rb");
    int aux;

    if (archivo)
    {
        while(fread(&aux, sizeof(int), 1, archivo) > 0)
        {
            arbol = insertarNodo(arbol, aux);
        }
        fclose(archivo);
    }
    return arbol;
}

void arbolToArchivo(nodoArbol * arbol)
{
    FILE * archivo = fopen("datos.dat", "ab");
    if (archivo)
    {
        escribirEnArchivo(arbol, archivo);
        fclose(archivo);
    }
}

void escribirEnArchivo(nodoArbol * arbol, FILE * archivo)
{
    if (arbol)
    {
        fwrite(&arbol->dato, sizeof(int), 1, archivo);
        escribirEnArchivo(arbol->der, archivo);
        escribirEnArchivo(arbol->izq, archivo);
    }
}
