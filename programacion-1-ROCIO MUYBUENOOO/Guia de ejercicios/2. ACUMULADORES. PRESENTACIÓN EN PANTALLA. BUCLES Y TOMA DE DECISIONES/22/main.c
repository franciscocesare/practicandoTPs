#include <stdio.h>
#include <stdlib.h>

/* Diseñar el programa necesario para que habiéndose leído el valor de 2
variables NUM1 y NUM2 se intercambien los valores de las variables, es decir
que el valor que tenía NUM1 ahora lo contenga NUM2 y viceversa */

int main()
{
    int num1;
    int num2;
    int aux;

    printf("ingrese numero 1: ");
    scanf("%d",&num1);

    printf("ingrese numero 2: ");
    scanf("%d",&num2);

    aux=num1;
    num1=num2;
    num2=aux;

    printf("\nnumero 1 %d\nnumero 2 %d\n",num1,num2);

    return 0;
}
