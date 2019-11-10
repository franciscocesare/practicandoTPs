#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Diseñar un programa que lea 4 números e imprima el mayor de los cuatro

int main()
{
    int numeros[] = {5,12,3,9};
    int max;
    int flag=0;

    for(int i=0; i<4; i++)
    {
        if(numeros[i] > max || flag == 0)
        {
            max=numeros[i];
            flag=1;
        }
    }

    printf("%d\n\n",max);



    return 0;
}
