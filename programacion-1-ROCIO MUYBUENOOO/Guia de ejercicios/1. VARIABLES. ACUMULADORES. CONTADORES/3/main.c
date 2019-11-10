#include <stdio.h>
#include <stdlib.h>

/* Escribir un programa que realice las siguientes acciones:
- Limpie la pantalla
- Asigne a 2 variables numero1 y numero2 valores distintos de cero
- Efectúe el producto de dichas variables
- Muestre el resultado pos pantalla
- Obtenga el cuadrado de numero1 y lo muestre par pantalla */


int main()
{
    int num1;
    int num2;
    int producto;
    int cuadrado;

    printf("ingrese numero: ");
    scanf("%d",&num1);

    while(num1 == 0)
    {
        printf("error ingrese numero distinto de 0: ");
        scanf("%d",&num1);
    }

    printf("ingrese numero: ");
    scanf("%d",&num2);

    while(num2 == 0)
    {
        printf("error ingrese numero distinto de 0: ");
        scanf("%d",&num2);
    }

    producto=num1*num2;
    cuadrado=num1*num1;

    printf("\n\nel producto es %d\n",producto);
    printf("el cuadrado del primer numero es %d\n\n",cuadrado);

    return 0;
}
