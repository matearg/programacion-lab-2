#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void menu(nodo * lista);

int main()
{
    nodo * lista = inicLista();
    menu(lista);
    return 0;
}

void menu(nodo * lista)
{
    int opcion = 0;

    do
    {
        system("cls");
        printf("------ Listas ------\n"
               "[1] Cargar lista\n"
               "[2] Mostar lista\n"
               "[0] Salir\n\n"
               "Ingrese una opcion -> "
              );
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            // cargo la lista
            lista = subProgramaCargarOrdenada(lista);
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
    }
    while (opcion != 0);
}
