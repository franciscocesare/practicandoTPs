#include <stdio.h>
#include <stdlib.h>

// De 3 números ingresados desde el teclado por el usuario, indicar cuál es el mayor

int main()
{
    int numeros[3];
    int flag=0;
    int max;

    for(int i=0; i<3; i++)
    {
        printf("ingrese numeros: ");
        scanf("%d",&numeros[i]);

        if(numeros[i] > max || flag == 0)
        {
            max=numeros[i];
            flag=1;
        }
    }

    printf("\nnumero max %d\n",max);

    return 0;
}
