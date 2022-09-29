#include <stdio.h>
#include <stdlib.h>

typedef struct _nodoDoble
{
    int dato;
    struct _nodoDoble * anterior;
    struct _nodoDoble * siguiente;
} nodoDoble;

nodoDoble * inicLstaD();
nodoDoble * crearNodoD(int dato);
nodoDoble * agregarAlPrincipioD(nodoDoble * lista, nodoDoble * nuevo);
nodoDoble * buscarUltimoDR(nodoDoble * lista);
nodoDoble * agregarAlFinalD(nodoDoble * lista, nodoDoble * nuevo);
nodoDoble * agregarEnOrdenD(nodoDoble * lista, nodoDoble * nuevo);
