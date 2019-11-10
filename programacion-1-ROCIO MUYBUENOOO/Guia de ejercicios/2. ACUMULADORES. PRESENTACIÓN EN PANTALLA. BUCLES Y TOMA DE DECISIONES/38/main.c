#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define TAM 10

/* Se registran de los empleados de una empresa Número de legajo, sueldo y sexo (1 femenino y 2
masculino). Diseñar en un programa que permita informar cuantas mujeres ganan más de á 500 y cuantos
hombres ganan menos de $ 400 */

int main()
{
    int legajoInt;
    int sueldoInt;
    int contM=0;
    int contF=0;
    char seguir;
    char sexo;
    char legajo[2];
    char sueldo[2];



    do
    {

        system("cls");

        printf("ingrese numero de legajo: ");
        gets(legajo);
        legajoInt=atoi(legajo);

        while(isdigit(legajo[0])==0 || legajo<0)
        {
            printf("error. ingrese numero de legajo: ");
            gets(legajo);
            legajoInt=atoi(legajo);
        }

        printf("\ningrese sueldo: ");
        gets(sueldo);
        sueldoInt=atoi(sueldo);

        while(isdigit(sueldo[0])==0 || sueldo<0)
        {
            printf("error. ingrese sueldo: ");
            gets(sueldo);
            sueldoInt=atoi(sueldo);
        }

        printf("\ningrese sexo f/m: ");
        fflush(stdin);
        scanf("%c",&sexo);

        while(sexo!='f' && sexo!='m')
        {
            printf("error. ingrese sexo f/m: ");
            fflush(stdin);
            scanf("%c",&sexo);
        }

        if(sueldoInt>500 && sexo=='f')
        {
            contF++;
        }
        else if(sueldoInt<400 && sexo=='m')
        {
            contM++;
        }

        printf("desea seguir: ");
        fflush(stdin);
        seguir=getche();

        while(seguir != 's' || seguir!= 'n')
        {
            printf("error. desea seguir: ");
            fflush(stdin);
            seguir=getche();
        }

    }while(seguir == 's');

    printf("mujeres que ganan mas de $500 %d",contF);
    printf("hombres que ganan menos de $400 %d",contM);


    return 0;
}
