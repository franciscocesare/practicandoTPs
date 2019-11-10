#include <stdio.h>
#include <stdlib.h>

//Hacer el programa que imprima los números pares entre el 1 y el 100

int main()
{
    int cont=0;

    while(cont <= 100)
    {
        cont++;

        if(cont %2 == 0)
        {
            printf("%d\n",cont);
        }
    }
    return 0;
}
