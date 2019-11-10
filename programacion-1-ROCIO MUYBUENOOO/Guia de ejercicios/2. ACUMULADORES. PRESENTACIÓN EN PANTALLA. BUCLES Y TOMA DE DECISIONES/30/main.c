#include <stdio.h>
#include <stdlib.h>

/* Dados 3 números donde el primero y el último son límites de un intervalo,
indicar si el tercero pertenece a dicho intervalo */


int main()
{
    int num1;
    int num2;
    int num3;

    printf("ingrese primer numero de intervalor: ");
    scanf("%d",&num1);

    printf("ingrese segundo numero de intervalor: ");
    scanf("%d",&num2);

    printf("ingrese numero a verificar: ");
    scanf("%d",&num3);

    if(num3>=num1 && num3<=num2)
    {
        printf("\n%d pertenece al intervalo\n",num3);
    }
    else if(num3<=num1 && num3>=num2)
    {
        printf("\n%d pertenece al intervalo\n",num3);
    }
    else
    {
        printf("\n%d no pertenece al intervalo\n",num3);
    }
    return 0;
}
