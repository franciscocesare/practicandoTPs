#include <stdio.h>
#include <stdlib.h>


int getIntRange(int* numero, int min, int max, int intentos, char* mensaje)
{
    int aux;
    int todoOk = 1;

    printf("%s",mensaje);
    scanf("%d",&aux);

    while(aux < min || aux > max)
    {
        intentos--;
        if(intentos == 0)
        {
            todoOk=0;
            break;
        }
        printf("Error. %s",mensaje);
        scanf("%d",&aux);
    }

    if(intentos != 0)
    {
        *numero = aux;
    }

    return todoOk;
}

int main()
{
    int num;
    int todoOk;

   todoOk= getIntRange(&num, 0, 10,3 ,"Ingrese numero entre 1-10: ");

   if(todoOk == 0)
   {
       printf("\nNo se pudo obtener la nota\n");
   }
   else
   {
       printf("\nLa nota es %d",num);
   }

    return 0;
}


