#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Escribir un programa que realice lea por teclado 20 caracteres. Luego de la lectura indicar cuantas "a" se
ingresaron, cuantas "e, i, o, u" */

int main()
{
    int contA=0;
    int contE=0;
    int contI=0;
    int contO=0;
    int contU=0;
    char letras[20];

    for(int i=0; i<20; i++)
    {
        printf("\ningrese letra %d: ",i);
        letras[i]=getche();

        if(letras[i]=='a')
        {
            contA++;
        }
        if(letras[i]=='e')
        {
            contE++;
        }
        if(letras[i]=='i')
        {
            contI++;
        }
        if (letras[i]=='o')
        {
            contO++;
        }
        if(letras[i]=='u')
        {
            contU++;
        }
    }


    printf("\n\ncantidad de a %d",contA);
    printf("\ncantidad de b %d",contE);
    printf("\ncantidad de c %d",contI);
    printf("\ncantidad de d %d",contO);
    printf("\ncantidad de e %d\n\n",contU);

    return 0;
}
