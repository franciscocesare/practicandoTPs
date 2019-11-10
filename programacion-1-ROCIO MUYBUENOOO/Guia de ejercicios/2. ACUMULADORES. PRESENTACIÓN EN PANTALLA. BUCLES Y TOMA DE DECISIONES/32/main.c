#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM 15

/* En una empresa se carga por teclado los siguientes datos: nombre del empleado, nacionalidad (A argentino,
E -extranjero), estudios cursados (1- primaria, 2 - secundario, 3 - universitario) y antigüedad. Se pide emitir
un listado con aquellos empleados que sean extranjeros, tengan estudios universitarios y tengan una
antigüedad igual o mayor a 20 años y por último indicar cuantos son y qué porcentaje son respecto del total
de empleados de la empresa */

int main()
{
    int estudios[TAM];
    int antiguedad[TAM];
    int i=0;
    float porcentaje=0;
    int cont=0;
    char nombre[TAM][20];
    char nacionalidad[TAM];
    char seguir;

    do
    {
        system("cls");
        printf("\ningresar nombre de empleado: ");
        fflush(stdin);
        gets(nombre[i]);

        printf("\n(A)argentino / (E)extranjero\n");
        printf("ingrese nacionalidad A/E: ");
        fflush(stdin);
        nacionalidad[i]=getche();

        while(nacionalidad[i] != 'a' && nacionalidad[i] != 'e')
        {
            printf("\n(A)argentino / (E)extranjero\n");
            printf("ingrese nacionalidad A/E: ");
            fflush(stdin);
            nacionalidad[i]=getche();
        }

        printf("\n\n1_ primario / 2_secundario / 3_universitario");
        printf("\ningrese nivel de estudio: ");
        scanf("%d",&estudios[i]);

        while(estudios[i] != 1 && estudios[i] != 2 && estudios[i] != 3)
        {
            printf("\n\n1_ primario / 2_secundario / 3_universitario");
            printf("\ningrese nivel de estudio: ");
            scanf("%d",&estudios[i]);
        }

        printf("\ningrese antiguedad: ");
        scanf("%d",&antiguedad[i]);

        i++;

        printf("\ndesea seguir s/n: ");
        fflush(stdin);
        seguir=getche();


    }
    while(seguir != 'n');

    system("cls");
    printf(" nombre   nacionalidad   estudios   antiguedad\n\n");

    for(int i=0; i<TAM; i++)
    {
        if(nacionalidad[i] == 'e')
        {
            if(estudios[i] == 3)
            {
                if(antiguedad[i] > 20)
                {
                    printf("%2s %10c %10d %12d\n",nombre[i],nacionalidad[i],estudios[i],antiguedad[i]);
                    cont++;
                }
            }
        }
    }

    porcentaje+=(float)i;
    porcentaje=(float)porcentaje/cont;

    printf("\n\ncantidad de empleados extrajeros, con antiguedad mayor a 20 anos y estudios universitrios son %d\n",cont);
    printf("porcentaje del total de empleados %.2f\n\n",porcentaje);






    return 0;
}
