#include "listaDoble.h"

nodoDoble * inicLstaD()
{
    return NULL;
}

nodoDoble * crearNodoD(int dato)
{
    nodoDoble * nuevo = (nodoDoble *)malloc(sizeof(int));
    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodoDoble * agregarAlPrincipioD(nodoDoble * lista, nodoDoble * nuevo)
{
    nuevo->siguiente = lista;
    if (lista)
    {
        lista->anterior = nuevo;
    }
    return nuevo;
}

nodoDoble * buscarUltimoDR(nodoDoble * lista)
{
    nodoDoble *rta;

    if (!lista)
    {
        rta = NULL;
    }
    else
    {
        if (!lista->siguiente)
        {
            rta = lista;
        }
        else
        {
            rta = buscarUltimoDR(lista->siguiente);
        }
    }

    return rta;
}

nodoDoble * agregarAlFinalD(nodoDoble * lista, nodoDoble * nuevo)
{
    if (!lista)
    {
        lista = nuevo;
    }
    else
    {
        nodoDoble * ultimo = buscarUltimoDR(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }
    return lista;
}

nodoDoble * agregarEnOrdenD(nodoDoble * lista, nodoDoble * nuevo)
{
    if (!lista)
    {
        lista = nuevo;
    }
    else
    {
        if (nuevo->dato < lista->dato)
        {
            lista = agregarAlPrincipioD(lista, nuevo);
        }
        else
        {
            nodoDoble * ante = lista;
            nodoDoble * seg = lista->siguiente;
            while ((seg) && (nuevo->dato > seg->dato))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            if (seg)
            {
                seg->anterior = nuevo;
            }
        }
    }
    return lista;
}
