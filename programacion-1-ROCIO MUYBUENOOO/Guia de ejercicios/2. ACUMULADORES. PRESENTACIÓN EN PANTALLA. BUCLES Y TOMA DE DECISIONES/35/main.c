#include <stdio.h>
#include <stdlib.h>

/* Hacer un que imprima los números de 0 al 100, controlando las filas y
las columnas de forma tal que se visualicen en pantalla todos a la vez */

int main()
{
    for(int i=0; i<101; i++)
    {
        if(i%10 == 0)
        {
             printf("%d \n",i);
        }
        else
        {
             printf("%d",i);
        }

    }

    return 0;
}
