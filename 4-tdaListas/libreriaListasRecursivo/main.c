#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void menu(nodo *lista);
void recorrerYmostrar(nodo *lista);
int sumarListaRecursivo(nodo *lista);
nodo *insertarEnOrdenR(nodo *lista, nodo *nuevo);
nodo *invertirListaRecursivo(nodo *lista);
nodo *desvincularNodoInicial(nodo **p_lista);
nodo *subProgramaCargaRecursiva(nodo *lista);
nodo *eliminarPrimerNodo(nodo *lista);
nodo *borrarNodoRecursiva(nodo *lista, int num);

int main()
{
    nodo *lista = NULL;
    printf("Hello Listas Recursivas!\n");
    menu(lista);
    return 0;
}

void menu(nodo *lista)
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
               "[5] Invertir lista\n"
               "[6] Pasar lista a archivo\n"
               "[7] Pasar archivo a lista\n"
               "[8] Cargar lista recursivo\n"
               "[0] Salir\n\n"
               "Ingrese una opcion -> ");
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
            printf("\n\n");
            system("pause");
            break;
        case 3:
            // recorro y muestro la lista recursivamente
            system("cls");
            recorrerYmostrar(lista);
            printf("\n\n");
            system("pause");
            break;
        case 4:
            // recorro y sumo la lista recursivamente
            system("cls");
            printf("Suma = %d\n\n", sumarListaRecursivo(lista));
            system("pause");
            break;
        case 5:
            system("cls");
            lista = invertirListaRecursivo(lista);
            system("pause");
            break;
        case 6:
            system("cls");
            subProgramaListaToArchivo(lista, "lista.dat");
            system("pause");
            break;
        case 7:
            system("cls");
            lista = subProgramaArchivoToLista(lista, "lista.dat");
            system("pause");
            break;
        case 8:
            system("cls");
            lista = subProgramaCargaRecursiva(lista);
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

void recorrerYmostrar(nodo *lista)
{
    if (lista)
    {
        mostrarNodo(lista);
        recorrerYmostrar(lista->siguiente);
    }
}

int sumarListaRecursivo(nodo *lista)
{
    int suma;
    if (lista)
    {
        suma = lista->dato + sumarListaRecursivo(lista->siguiente);
        sumarListaRecursivo(lista->siguiente);
    }
    else
    {
        suma = 0;
    }
    return suma;
}

// nodo *invertirLista(nodo *lista)
// {
//     nodo *aux;
//     nodo *listaInvertida = inicLista();
//
//     while (lista)
//     {
//         aux = desvincularNodoInicial(&lista);
//         listaInvertida = agregarAlPrincipio(listaInvertida, aux);
//     }
//
//     return listaInvertida;
// }

nodo *desvincularNodoInicial(nodo **p_lista)
{
    nodo * aux;

    if (*p_lista)
    {
        aux = *p_lista;
        *p_lista = (*p_lista)->siguiente;
        aux->siguiente = NULL;
    }

    return aux;
}

nodo *intercalarListas(nodo *lista_A, nodo *lista_B, nodo *lista_C)
{
    nodo * aux;

    while ((lista_A) && (lista_B))
    {
        if(lista_A->dato < lista_B->dato)
        {
            aux = desvincularNodoInicial(&lista_A);
        }
        else
        {
            aux = desvincularNodoInicial(&lista_B);
        }
        lista_C = agregarAlFinal(lista_C, aux);
    }

    if (lista_A)
    {
        lista_C = agregarAlFinal(lista_C, lista_A);
    }
    else if (lista_B)
    {
        lista_C = agregarAlFinal(lista_C, lista_B);
    }

    return lista_C;
}

nodo *insertarEnOrdenR(nodo *lista, nodo *nuevo)
{
    if (!lista)
    {
        lista = nuevo;
    }
    else
    {
        if (lista->dato > nuevo->dato)
        {
            lista = agregarAlPrincipio(lista, nuevo);
        }
        else
        {
            lista->siguiente = insertarEnOrdenR(lista->siguiente, nuevo);
        }
    }
    return lista;
}

nodo *subProgramaCargaRecursiva(nodo *lista)
{
    char control;
    int num;

    do
    {
        printf("Introduzca un numero -> ");
        scanf("%d", &num);
        lista = insertarEnOrdenR(lista, crearNodo(num));

        printf("Quiere agregar otro numero? s/n ");
        fflush(stdin);
        scanf("%c", &control);
    }
    while (control == 's');

    return lista;
}

nodo *invertirListaRecursivo(nodo *lista) {
    nodo * aux;
    if (lista) {
        aux = desvincularNodoInicial(&lista);
        lista = invertirListaRecursivo(lista);
        lista = agregarAlFinal(lista, aux);
    }
    return lista;
}

nodo *eliminarPrimerNodo(nodo *lista) {
    if (lista) {
        nodo *aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    return lista;
}

nodo * borrarNodoRecursiva(nodo * lista, int num) {
    if (lista) {
        if (lista->dato == num) {
            lista = eliminarPrimerNodo(lista);
        } else {
            lista->siguiente = borrarNodoRecursiva(lista->siguiente, num);
        }
    }
    return lista;
}
