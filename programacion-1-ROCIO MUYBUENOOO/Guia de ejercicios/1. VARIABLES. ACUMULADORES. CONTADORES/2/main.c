#include <stdio.h>
#include <stdlib.h>

// Escribir el programa necesario para calcular la suma de dos números. Mostrar el resultado

int main()
{
    int numeros[2];
    int suma=0;

    for(int i=0; i<2; i++)
    {
        printf("ingrese numero: ");
        scanf("%d",&numeros[i]);

        suma+=numeros[i];
    }

    printf("\n\nla suma es igual a %d\n\n",suma);
    return 0;
}
