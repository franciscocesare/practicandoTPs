#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarVectorInt(int vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d ", vec[i]);
    }
}

int obtenerMayor(int vec[],int tam)
{
    int max;
    int flag=0;

    for(int i=0; i<tam; i++)
    {
        if(vec[i] > max || flag == 0)
        {
            max=vec[i];
            flag=1;
        }
    }

    return max;
}

void cargarVector (int vec[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("Ingrese numeros: ");
        scanf("%d",&vec[i]);
    }
}

int main()
{
    int max;
    int numeros[TAM];

    cargarVector (numeros,TAM);

    mostrarVectorInt(numeros,TAM);

    max = obtenerMayor(numeros,TAM);

    printf("\n\nnumero mayor: %d ",max);
    printf("\n\n");

    return 0;
}
