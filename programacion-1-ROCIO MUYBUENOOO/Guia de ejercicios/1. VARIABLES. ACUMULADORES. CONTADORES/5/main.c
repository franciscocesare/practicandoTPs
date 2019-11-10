#include <stdio.h>
#include <stdlib.h>

/* Escribir el programa necesario para calcular y mostrar el cuadrado de un número. El número debe ser
mayor que cero, en caso de error que aparezca el mensaje "ERROR, el número debe ser mayor que cero" */


int main()
{
    int num1;
    int cuadrado;

    printf("ingrese numero: ");
    scanf("%d",&num1);

    while(num1 < 0)
    {
        printf("ERROR, el numero debe ser mayor que cero: ");
        scanf("%d",&num1);
    }

    cuadrado= num1*num1;

    printf("\n\nel cuadrado del numero %d es %d\n\n", num1, cuadrado);

    return 0;
}
