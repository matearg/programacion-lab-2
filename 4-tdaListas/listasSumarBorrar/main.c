#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

nodo * cargarLista(nodo * lista);
nodo * borrarTodaLaLista(nodo * lista);
int sumarLista(nodo * lista);
void menu(nodo * lista);

int main()
{
    nodo * lista = inicLista();

    menu(lista);

    return 0;
}

nodo * cargarLista(nodo * lista)
{
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        lista = agregarNodo(lista, crearNodo(rand()%100 + 1));
    }
    return lista;
}

int sumarLista(nodo * lista)
{
    int sum = 0;
    nodo * seg = lista;

    if (seg != NULL)
    {
        while (seg != NULL)
        {
            sum += seg->dato;
            seg = seg->siguiente;
        }
    }
    return sum;
}

nodo * borrarTodaLaLista(nodo * lista)
{
    nodo * seg;
    while (lista != NULL)
    {
        seg = lista;
        lista = lista->siguiente;
        free(seg);
    }
    return lista;
}

void menu(nodo * lista)
{
    char opcion;
    int rta;

    do
    {
        system("cls");
        printf("Hello Listas!\n"
               "1- Cargar lista\n"
               "2- Mostrar lista\n"
               "3- Sumatoria lista\n"
               "4- Limpiar lista\n"
               "(s)alir\n\n"
               "Ingrese una opcion -> ");
        fflush(stdin);
        opcion = getchar();
        switch (opcion)
        {
        case '1':
            system("cls");
            lista = cargarLista(lista);
            puts("Lista cargada\n");
            system("pause");
            break;
        case '2':
            system("cls");
            mostrarLista(lista);
            puts("\n\n");
            system("pause");
            break;
        case '3':
            system("cls");
            rta = sumarLista(lista);
            printf("La suma de los elementos de la lista es %d", rta);
            puts("\n\n");
            system("pause");
            break;
        case '4':
            system("cls");
            lista = borrarTodaLaLista(lista);
            puts("Lista limpia\n");
            system("pause");
        case 's':
            system("cls");
            printf("Adios!");
            break;
        default:
            puts("Opcion incorrecta\n");
            system("pause");
            break;
        }
    }
    while (opcion != 's');
}
