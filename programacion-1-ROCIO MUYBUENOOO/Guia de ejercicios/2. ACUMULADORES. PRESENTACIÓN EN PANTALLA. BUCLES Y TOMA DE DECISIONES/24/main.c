#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Diseñar en un programa que permita registrar de los empleados de una fábrica
(no se sabe cuántos) su peso y saber cuántos pesan hasta 80 kg. inclusive y
cuantos pesan más de 80 kg. */

int main()
{
    int pesos[50];
    int i=0;
    int contMin=0;
    int contMax=0;
    char seguir;

    do
    {
        printf("\ningrese peso: ");
        scanf("%d",&pesos[i]);


        printf("desea seguir s/n: ");
        fflush(stdin);
        seguir=getche();

        if(pesos[i]<80)
        {
            contMin++;
        }
        if(pesos[i]>80)
        {
            contMax++;
        }
        i++;

    }while(seguir == 's');

    printf("\n\npesos mayores a 80: %d\npesos menores a 80: %d\n\n",contMax,contMin);

    return 0;
}
