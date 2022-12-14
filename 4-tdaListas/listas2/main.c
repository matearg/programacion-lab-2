#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void menu(nodo * lista);
void recorrerYmostrar(nodo * lista);
int sumarListaRecursivo(nodo * lista);

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
               "[3] Mostar lista recursivo\n"
               "[4] Sumar lista recursivo\n"
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
        case 3:
            // recorro y muestro la lista recursivamente
            system("cls");
            recorrerYmostrar(lista);
            system("pause");
            break;
        case 4:
            // recorro y sumo la lista recursivamente
            system("cls");
            printf("Suma = %d\n\n", sumarListaRecursivo(lista));
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

void recorrerYmostrar(nodo * lista)
{
    if (lista)
    {
        mostrarNodo(lista);
        recorrerYmostrar(lista->siguiente);
    }
}

int sumarListaRecursivo(nodo * lista)
{
    int suma;
    if (lista)
    {
        suma = lista->dato.dni + sumarListaRecursivo(lista->siguiente);
        sumarListaRecursivo(lista->siguiente);
    }
    else
    {
        suma = 0;
    }
    return suma;
}
