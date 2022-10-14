#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cargarArr(int * arr, int dim);
int cargarArrRand(int * arr, int dim);
void mostrarArr(int * arr, int val);
float promArr(int * arr, int val);
void menu();

int main() {
    menu();
}

int cargarArr(int * arr, int dim) {
    char opcion = 's';
    int i = 0;
    
    while (opcion != 'n' && i < dim) {
        system("cls");

        printf("Ingresar nota: ");
        scanf("%d", &arr[i]);

        i++;

        printf("Desea agregar otra nota? s/n ");
        fflush(stdin);
        opcion = getchar();
    }

    return i;
}

int cargarArrRand(int * arr, int dim) {
    srand(time(NULL));
    int i;
    
    for (i = 0; i < dim; i++) {
        arr[i] = rand()%10 + 1;
    }

    return i;
}

void mostrarArr(int * arr, int val) {
    printf("Listado de notas:\n");
    for(int i = 0; i < val; i++) {
        printf("%d\n", arr[i]);
    }
}

float promArr(int * arr, int val) {
    int acu = 0;
    int i = 0;

    for(i = 0;i < val; i++) {
        acu += arr[i];
    }

    return (float)acu / i;
}

void menu() {
    int validos = 0;
    int dim = 10;
    int * arreglo = (int *)malloc(sizeof(int) * dim);
    char opcion = '1';

    while (opcion != '0') {
        system("cls");
        printf("[1] Cargar Notas\n"
               "[2] Generar Notas Aleatorias\n"
               "[3] Mostrar Notas\n"
               "[4] Promediar Notas\n"
               "[0] Salir\n\n");
        printf("Ingrese una opcion -> ");
        fflush(stdin);
        opcion = getchar();

        switch (opcion) {
            case '1':
                system("cls");
                validos = cargarArr(arreglo, dim);
                break;
            case '2':
                system("cls");
                validos = cargarArrRand(arreglo, dim);
                break;
            case '3':
                system("cls");
                mostrarArr(arreglo, validos);
                puts("\n");
                system("pause");
                break;
            case '4':
                system("cls");
                printf("El promedio de las notas es %f", promArr(arreglo, validos));
                puts("\n");
                system("pause");
                break;
            case '0':
                system("cls");
                puts("Adios!\n");
                system("pause");
                exit(0);
                break;
            default:
                system("cls");
                printf("Caso invalido");
                puts("\n");
                break;
        }
    }
}

