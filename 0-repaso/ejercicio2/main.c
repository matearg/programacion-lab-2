#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int cargarArreglo(char *A, int dim);
void invertirArreglo(char *A, int validos);
void mostrarArreglo(char *A, int validos);
void menu(char *A, int dim);

int main()
{
    char *arreglo = (char *)malloc(sizeof(char) * 50);

    menu(arreglo, 50);

    return 0;
}

int cargarArreglo(char *A, int dim)
{
    char opcion;
    int i = 0;

    do
    {
        printf("\nIngrese un caracter -> ");
        fflush(stdin);
        A[i] = getchar();
        i++;

        printf("Desea ingresar otro caracter? s/n ");
        fflush(stdin);
        opcion = getche();

    }
    while (opcion == 's' && i < dim);

    return i;
}

void invertirArreglo(char *A, int validos)
{
    char aux[validos];
    int j = 0;

    for(int i = (validos - 1); i >= 0; i--)
    {
        aux[i] = A[j];
        j++;
    }

    A = aux;

    printf("\nArreglo invertido\n");
}

void mostrarArreglo(char *A, int validos)
{
    printf("\n---------------------------\n");
    for (int i = 0; i < validos; i++)
    {
        printf("%c ", A[i]);
    }
    printf("\n---------------------------\n");
}

void menu(char *A, int dim)
{
    char opcion;
    int validos = 0;

    do
    {
        system("cls");
        printf("[1] Cargar Arreglo\n"
               "[2] Invertir Arreglo\n"
               "[3] Mostrar Arreglo\n"
               "[0] Salir\n"
               "\nIngrese una opcion -> "
              );
        fflush(stdin);
        opcion = getche();

        switch (opcion)
        {
        case '1':
            validos = cargarArreglo(A, dim);
            break;
        case '2':
            invertirArreglo(A, validos);
            system("pause");
            break;
        case '3':
            mostrarArreglo(A, validos);
            system("pause");
            break;
        case '0':
            exit(0);
            printf("Adios\n");
            break;
        default:
            printf("Opcion incorrecta");
            system("pause");
            break;
        }

    }
    while (opcion != '0');
}
