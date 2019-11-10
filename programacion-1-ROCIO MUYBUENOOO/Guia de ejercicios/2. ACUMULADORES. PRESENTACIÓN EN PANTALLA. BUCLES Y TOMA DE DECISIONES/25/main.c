#include <stdio.h>
#include <stdlib.h>

/* En una tienda de artículos para caballeros al final del día se carga en la computadora las boletas que
confeccionaron los distintos vendedores para saber cuánto fue la comisión del día de cada uno de ellos. Los
datos que se ingresan (por boleta) son: el número de vendedor y el importe. Cuando no hay más boletas
para cargar se ingresa 0. Teniendo en cuenta que el negocio tiene 3 vendedores y que el porcentaje sobre
las ventas es del 5%, indicar cuánto ganó cada vendedor en el día */

int main()
{
    int vendedor1;
    int total1=0;
    int importe1[15];
    int vendedor2;
    int total2=0;
    int importe2[15];
    int vendedor3;
    int total3=0;
    int importe3[15];

    printf("ingrese numero de vendedor 1: ");
    scanf("%d",&vendedor1);

    for(int i=0; i<15; i++)
    {
        printf("ingrese importe: ");
        scanf("%d",&importe1[i]);

        if(importe1[i] == 0)
        {
            break;
        }

        total1+=importe1[i];
    }

    total1=(total1*5)/100;

    system("cls");
    printf("ingrese numero de vendedor 2: ");
    scanf("%d",&vendedor2);

    for(int i=0; i<15; i++)
    {
        printf("ingrese importe: ");
        scanf("%d",&importe2[i]);

        if(importe2[i] == 0)
        {
            break;
        }

        total2+=importe2[i];
    }

    total2=(total2*5)/100;

    system("cls");
    printf("ingrese numero de vendedor 3: ");
    scanf("%d",&vendedor3);

    for(int i=0; i<15; i++)
    {
        printf("ingrese importe: ");
        scanf("%d",&importe3[i]);

        if(importe3[i] == 0)
        {
            break;
        }

        total3+=importe3[i];
    }

    total3=(total3*5)/100;

    system("cls");
    printf("comision vendedor numero %d es: %d",vendedor1,total1);
    printf("\ncomision vendedor numero %d es: %d",vendedor2,total2);
    printf("\ncomision vendedor numero %d es: %d\n\n",vendedor3,total3);


    return 0;
}
