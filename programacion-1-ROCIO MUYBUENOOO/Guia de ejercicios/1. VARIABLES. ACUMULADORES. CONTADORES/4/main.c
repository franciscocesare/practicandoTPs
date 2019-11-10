#include <stdio.h>
#include <stdlib.h>

/* Escribir un programa que realice las siguientes acciones:
 Limpie la pantalla
 Declare 2 variables y les asigne los valores
 Realice la resta de dichas variables y muestre por pantalla la leyenda "Resultado positivo" en caso de
ser mayor que cero o "Resultado negativo" si es menor que cero */

int main()
{
    int num1;
    int num2;
    int resta;

    printf("ingrese numero: ");
    scanf("%d",&num1);

    printf("ingrese numero: ");
    scanf("%d",&num2);

    resta=num1-num2;

    system("cls");

    if(resta > 0)
    {
        printf("la resta es %d y es positivo\n\n", resta);
    }

    if(resta < 0)
    {
        printf("la resta es %d y es negativa\n\n", resta);
    }

    return 0;
}
