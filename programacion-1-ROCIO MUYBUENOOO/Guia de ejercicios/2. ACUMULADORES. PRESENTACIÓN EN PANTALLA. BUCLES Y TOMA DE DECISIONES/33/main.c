#include <stdio.h>
#include <stdlib.h>

#define TAM 15

/* En un restaurante hay 2 mozos; al final del día su dueño entrega un plus al mozo que más clientes haya
atendido, ese plus es de 1/3 de lo que facturó cada mozo. El proceso termina cuando se ingresa un número
de mozo 0 */


int main()
{
    int ventas1[TAM];
    float total1=0;
    float porcentaje1;
    int ventas2[TAM];
    float total2=0;
    float porcentaje2;

    for(int i=0; i<TAM; i++)
    {
        printf("ingresar montos de mozo 1: ");
        scanf("%d",&ventas1[i]);

        if(ventas1[i]==0)
        {
            break;
        }

        total1+=(float)ventas1[i];
    }

    system("cls");
    for(int i=0; i<TAM; i++)
    {
        printf("ingresar montos de mozo 2: ");
        scanf("%d",&ventas2[i]);

        if(ventas2[i]==0)
        {
            break;
        }

        total2+=(float)ventas2[i];
    }

    porcentaje1=(total1 /3)*1;
    porcentaje2=(total2 /3)*1;

    if(total1 > total2)
    {
        printf("\nplus para el mozo 1 %.2f\n",porcentaje1);
    }
    else
    {
        printf("\nplus para el mozo 2 %.2f\n",porcentaje2);
    }


    return 0;
}
