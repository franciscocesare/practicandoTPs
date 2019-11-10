#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[5];
    int suma=0;


    for(int i=0; i<5; i++)
    {
        printf("Ingrese numeros: ");
        scanf("%d",&numeros[i]);
    }

    printf("\n\n");

    for(int i=0; i<5; i++)
    {
        printf("%d ", numeros[i]);
    }

    for(int i=0; i<5; i++)
    {
        suma+=numeros[i];
    }

    printf("\n\nSuma total: %d\n\n",suma);

    return 0;
}
