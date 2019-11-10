#include <stdio.h>
#include <stdlib.h>

/* Escribir en y codificar en C un programa que muestre los
       números primos comprendidos entre 0 y 100 */


int main()
{
    int cont=0;

    for(int num=2; num<=100; num++)
    {
        for(int divisor=2; divisor<=num; divisor++)

            if(num%divisor==0)
                cont++;

            if(cont == 1)
                printf("%d\n",num);
                cont=0;
    }



    return 0;
}
