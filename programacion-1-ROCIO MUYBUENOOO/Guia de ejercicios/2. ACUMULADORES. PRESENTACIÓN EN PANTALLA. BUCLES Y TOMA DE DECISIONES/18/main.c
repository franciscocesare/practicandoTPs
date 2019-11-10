#include <stdio.h>
#include <stdlib.h>

/* Diseñar en un programa que permita ingresar 10 números, ninguno de ellos igual a cero. Se pide sumar los
positivos, obtener el producto de los negativos y luego mostrar ambos resultados */

int main()
{
    int numeros[11];
    int sumaPos=0;
    int productoNeg=0;

    for(int i=0; i<10; i++)
    {
        printf("ingrese numero: ");
        scanf("%d",&numeros[i]);

        while(numeros[i]==0)
        {
           printf("error. ingrese numero: ");
            scanf("%d",&numeros[i]);
        }

        if(numeros[i]>0)
        {
            sumaPos+=numeros[i];
        }
        if(numeros[i]<0)
        {
            productoNeg*=numeros[i];
        }
    }

    printf("\nsuma de positivos %d\n",sumaPos);
    printf("\nproducto de negativos %d\n",productoNeg);

    return 0;
}
