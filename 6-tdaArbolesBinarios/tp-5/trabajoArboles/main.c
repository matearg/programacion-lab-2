#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arboles.h"

int main()
{
    srand(time(NULL));

    printf("Hello Arboles!\n");

    nodoArbol * arbol = inicArbol();
    int nuevo = 0;

    while (nuevo <= 50)
    {
        printf("Se ingreso el %d al arbol\n\n", nuevo);
        arbol = insertarNodo(arbol, nuevo);
        nuevo = nuevo + 1;
    }

    inorder(arbol);

    return 0;
}
