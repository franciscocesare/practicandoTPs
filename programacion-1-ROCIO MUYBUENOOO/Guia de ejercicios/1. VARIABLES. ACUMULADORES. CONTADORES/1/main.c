#include <stdio.h>
#include <stdlib.h>


// Ingresar 5 números y calcular su media


int main()
{
    int numeros[5];
    int cont=0;
    int total=0;
    int promedio;

    for(int i=0; i<5; i++)
    {
        printf("Ingrese numero: ");
        scanf("%d",&numeros[i]);
        cont++;

        total+=numeros[i];
    }

    promedio=total/cont;


    printf("\n\nel promedio de los numeros ingresado es de %d\n\n",promedio);

    return 0;
}
