#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void inicArreglo(int *A, int dim);
int cargarArreglo(int *A, int dim);
void mostrarArreglo(int *A, int validos);
int sumarArreglo(int *A, int validos);
int contarArreglo(int *A);
float promedioArreglo(int *A);
void menu(int *A, int dim);

int main()
{
    int *arreglo = (int*)malloc(sizeof(int) * 50);

    menu(arreglo, 50);

    return 0;
}

void inicArreglo(int *A, int dim)
{
    for(int i = 0; i < dim; i++)
    {
        A[i] = -1;
    }
}

int cargarArreglo(int *A, int dim)
{
    int i = 0;
    char opcion;

    do
    {
        printf("\nIngrese un numero al arreglo -> ");
        scanf("%d", &A[i]);
        i++;
        printf("Quiere agregar otro numero? s/n ");
        opcion = getche();
    }
    while (opcion == 's' && i < dim);

    return i;
}

void mostrarArreglo(int *A, int validos)
{
    int i;

    printf("\n----------------------------------\n");
    for (i = 0; i < validos; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n----------------------------------\n");
}

int sumarArreglo(int *A, int validos)
{
    int sum = 0;

    for(int i = 0; i < validos; i++)
    {
        sum += A[i];
    }

    return sum;
}

int contarArreglo(int *A)
{
    int i = 0;
    while (A[i] != -1)
    {
        i++;
    }
    return i;
}

float promedioArreglo(int *A)
{
    float prom = 0;
    int validos = contarArreglo(A);
    int sumArreglo = sumarArreglo(A, validos);


    prom = (float)sumArreglo / validos;

    return prom;
}

void menu(int *A, int dim)
{
    char opcion;
    int validos = 0;
    float promArreglo = 0;

    do
    {
        system("cls");
        printf("[1] Inicializar arreglo\n"
               "[2] Cargar arreglo\n"
               "[3] Mostrar arreglo\n"
               "[4] Promedio arreglo\n"
               "[0] Salir\n"
               "\nIngrese una opcion -> ");

        opcion = getche();

        switch (opcion)
        {
        case '1':
            inicArreglo(A, dim);
            puts("\nArreglo inicializado\n");
            system("pause");
            break;
        case '2':
            validos = cargarArreglo(A, dim);
            break;
        case '3':
            mostrarArreglo(A, validos);
            system("pause");
            break;
        case '4':
            promArreglo = promedioArreglo(A);
            printf("\nEl promedio del arreglo es %.2f\n", promArreglo);
            system("pause");
            break;
        case '0':
            puts("\nAdios");
            exit(0);
            break;
        default:
            puts("\nOpcion incorrecta\n\n");
            system("pause");
            break;
        }

    }
    while (opcion != 0);
}
