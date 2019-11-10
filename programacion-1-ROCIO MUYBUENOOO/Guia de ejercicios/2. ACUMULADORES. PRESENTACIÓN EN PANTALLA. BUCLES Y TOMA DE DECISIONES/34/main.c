#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

/* Introducir una letra por teclado. Imprimirla cinco veces en filas consecutivas,
pero en cada impresión ir desplazándola 4 columnas a la derecha */

int main()
{
    char letra;

    printf("ingrese letra: ");
    fflush(stdin);
    letra=getche();

    while(isalpha(letra) == 0)
    {
        printf("\nerror. ingrese letra: ");
        fflush(stdin);
        letra=getche();

    }

    system("cls");
    printf("%c\n",letra);
    printf("%4c\n",letra);
    printf("%8c\n",letra);
    printf("%12c\n",letra);
    printf("%16c\n",letra);


    return 0;

}

