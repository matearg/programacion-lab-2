#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

nodo * cargarLista(nodo * lista);

int main() {
    // creo e inicializo la lista
    nodo * lista;
    lista = inicLista();

    // cargo la lista
    lista = cargarLista(lista);

    // recorro y muestro la lista
    mostrarLista(lista);

    return 0;
}

nodo * cargarLista(nodo * lista) {

    char cond = 's';
    do {
        system("cls");
        lista = agregarNodo(lista, crearNodo(cargarPersona()));

        printf("Desea agregar otra persona? s/n ");
        fflush(stdin);
        scanf("%c", &cond);

    } while (cond == 's');

    return lista;
}
