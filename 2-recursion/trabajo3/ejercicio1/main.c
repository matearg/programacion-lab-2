#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int factorial(int num);

int main()
{
    srand(time(NULL));
    printf("%d", factorial(rand()%6));
    return 0;
}

int factorial(int num)
{
    int respuesta;

    if (num == 0 || num == 1) {
        respuesta = 1;
    } else {
        respuesta = num * factorial(num - 1);
    }

    return respuesta;
}
