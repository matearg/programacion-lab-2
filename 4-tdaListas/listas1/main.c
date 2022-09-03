#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

nodo * cargarLista(nodo * lista);
void menu(nodo * lista);

int main() {
    // creo e inicializo la lista
    nodo * lista;
    lista = inicLista();

    menu(lista);

    return 0;
}

void menu(nodo * lista) {
    int opcion = 0;

    do {
        system("cls");
        printf("------ Listas ------\n"
               "[1] Cargar lista\n"
               "[2] Mostar lista\n"
               "[0] Salir\n\n"
               "Ingrese una opcion -> "
               );
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                // cargo la lista
                lista = cargarLista(lista);
                break;
            case 2:
                // recorro y muestro la lista
                system("cls");
                mostrarLista(lista);
                system("pause");
                break;
            case 0:
                system("cls");
                printf("Adios!");
                break;
            default:
                printf("Opcion incorrecta");
                system("pause");
        }
    } while (opcion != 0);
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
