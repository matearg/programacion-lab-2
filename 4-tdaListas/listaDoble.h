#include <stdio.h>

typedef struct _nodoDoble {
    int dato;
    struct _nodoDoble * anterior;
    struct _nodoDoble * siguiente;
} nodoDoble;

nodoDoble * inicLstaD();
nodoDoble * crearNodoD(int dato);
nodoDoble * agregarAlPrincipioD();
