#include <stdio.h>
#include <stdlib.h>

/* Ingresar un número entero por consola y efectuar la suma de todos los números
que le anteceden, comenzando desde 0 y mostrar el resultado por pantalla */

int main()
{
    int num;
    int cont=0;
    int suma=0;

    printf("ingrese numero: ");
    scanf("%d",&num);

    while(cont < num-1)
    {
        cont++;
        //printf("\n%d\n",cont);
        suma+=cont;
    }

    printf("\nla suma de los numeros anteriores a %d es de %d\n",num,suma);

    return 0;
}
