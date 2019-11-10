#include <stdio.h>
#include <stdlib.h>

int buscarNumero(int vec[],int tam, int numero)
{
    int todoOk=0;;

    for(int i=0; i<tam;i++)
    {
        if(vec[i] == numero)
        {
            todoOk=1;
            break;
        }
    }

    return todoOk;
}

int main()
{
    int numero[] = {4,76,63,23,54,24,56,12,98,10};
    int esta;

    esta=buscarNumero(numero,10,77);

    if(esta == 1)
    {
        printf("Esta\n");
    }
    else
    {
        printf("No esta\n");
    }
    return 0;
}
