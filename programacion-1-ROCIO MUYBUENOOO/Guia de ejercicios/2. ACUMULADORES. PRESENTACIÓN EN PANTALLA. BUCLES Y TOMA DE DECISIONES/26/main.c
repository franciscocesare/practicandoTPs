#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Hacer el programa ante la pregunta desea continuar sólo nos
 permita introducir como respuesta 'S' o'N' */

int main()
{
    char continuar;

    printf("desea continuar s/n: ");
    fflush(stdin);
    scanf("%c",&continuar);
    continuar=toupper(continuar);


    while(continuar != 'S' && continuar != 'N')
    {
        printf("error. desea continuar s/n: ");
        fflush(stdin);
        scanf("%c",&continuar);
        continuar=toupper(continuar);

        if(continuar == 'S')
        {
            break;
        }
        if(continuar == 'N')
        {
            break;
        }
    }

    return 0;
}
