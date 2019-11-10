#include <stdio.h>
#include <stdlib.h>

/* Ingresar por teclado 3 números correspondientes a los lados de un triángulo. Teniendo en cuenta que la
suma de los dos lados menores tiene que ser superior al lado mayor para que formen un triángulo, indicar si
los números indicados forman un triángulo y si lo forman que tipo de triángulo es */


int main()
{
    int lado1;
    int lado2;
    int lado3;

    printf("ingrese primer lado del triangulo: ");
    scanf("%d",&lado1);

    printf("ingrese segundo lado del triangulo: ");
    scanf("%d",&lado2);

    printf("ingrese tercer lado del triangulo: ");
    scanf("%d",&lado3);

    if(lado1==lado2 && lado2==lado3 && lado1==lado3)
    {
        printf("\nEs un triangulo equilatero\n\n");
    }
    else if (lado1==lado2 && lado2!=lado3 && lado1!=lado3)
    {
        printf("\nEs un triangulo isosceles\n\n");
    }
    else
    {
        printf("\nEs un triangulo escaleno\n\n");
    }

    return 0;
}
