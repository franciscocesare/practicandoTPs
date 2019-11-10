#include <stdio.h>
#include <stdlib.h>

// Calcular y generar los primeros 100 números múltiplos de 5, de 7 y de ambos

int main()
{
    printf("multiplos de 5: ");

    for(int i=1; i<=100; i++)
    {
        if(i%5==0)
        {
            printf("%d ",i);
        }
    }

    printf("\n\nmultiplos de 7: ");

     for(int i=1; i<=100; i++)
    {
        if(i%7==0)
        {
            printf("%d ",i);
        }
    }

    printf("\n\nmultiplos de 5 y 7: ");

     for(int i=1; i<=100; i++)
    {
        if(i%5==0 && i%7==0)
        {
            printf("%d ",i);
        }
    }
    return 0;
}
