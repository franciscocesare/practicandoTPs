#include <stdio.h>
#include <stdlib.h>

/*Diseñar un programa que calcule la superficie de un triángulo a partir del ingreso de su base y altura y
muestre el resultado. */


int main()
{
    int base;
    int altura;
    int resultado;

    printf("ingrese base de triangulo: ");
    scanf("%d",&base);
    printf("ingrese altura de triangulo: ");
    scanf("%d",&altura);

    resultado=base*altura;

    printf("\n\nsuperficie: %d metros cuadrados\n",resultado);
    return 0;
}
