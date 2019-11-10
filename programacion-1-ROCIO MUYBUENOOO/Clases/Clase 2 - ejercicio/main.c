#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

//pedir nombre-nota-sexo hasta que usuario quiera
// mostrar promedio de notas totales
// promedio de notas solo mujeres
// nombre sexo y nota maximo
// nombre sexo y nota minimo


int main()
{
    int nota;
    int notaMax;
    int notaMin;
    int flag = 0;
    int cont = 0;
    int contF = 0;
    int acumulador = 0;
    int acumuladorF = 0;

    float promedioTotal;
    float promedioFem;

    char nombre[20];
    char nombreMax[20];
    char nombreMin[20];
    char sexo;
    char sexoMax;
    char sexoMin;
    char seguir;


    do
    {

        printf("ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("ingrese nota: ");
        scanf("%d",&nota);

        while(nota > 10 || nota < 0)
        {
            printf("\ningrese nota valida 0-10: ");
            scanf("%d",&nota);
        }

        printf("ingrese sexo : ");
        fflush(stdin);
        sexo = getchar();

        if(sexo != 'f' || sexo != 'm')
        {
            printf("error, ingrese sexo : ");
            fflush(stdin);
            sexo = getchar();
        }

        cont++;
        acumulador+=nota;

        if(sexo == 'f')
        {
            contF++;
            acumuladorF+=nota;
        }

        if(notaMax < nota || flag == 0)
        {
            notaMax = nota;
            strcpy(nombreMax, nombre);
            sexoMax = sexo;
        }

        if(notaMin > nota || flag == 0)
        {
            notaMin = nota;
            strcpy(nombreMin, nombre);
            sexoMin =sexo;
            flag=1;
        }

        printf("\ndesea seguir s/n?: ");
        fflush(stdin);
        scanf("%c",&seguir);

        printf("\n\n");


    }
    while(seguir == 's');

    system("cls");

    promedioTotal = (float) acumulador / cont;

    if(contF != 0)
    {
        promedioFem = (float) acumuladorF / contF;
    }

    printf("\nEl promedio total es de %.2f",promedioTotal);
    printf("\nEl promedio total de f es de %.2f",promedioFem);
    printf("\nmaximo  %s  %d  %c",nombreMax,notaMax,sexoMax);
    printf("\nminimo  %s  %d  %c",nombreMin, notaMin, sexoMin);

    return 0;
}

// menu opciones //

void menuOpciones()
{
    char salir;
    char opcion;

    do
    {
        system("cls");

        printf("----- Menu de opciones -----\n\n");
        printf("a. sumar\n");
        printf("b. restar\n");
        printf("c. multiplicar\n");
        printf("d. dividir\n");
        printf("\ne. salir\n\n");
        printf("ingresar opcion: ");
        fflush(stdin);
        opcion=getchar();

        switch(opcion)
        {
        case 'a':
            printf("suma\n");
            system("pause");
            break;

        case 'b':
            printf("resta\n");
            break;

        case 'c':
            printf("multiplicar\n");
            system("pause");
            break;

        case 'd':
            printf("dividir\n");
            system("pause");
            break;

        case 'e':

            printf("\ndesea salir s/n?: ");
            fflush(stdin);
            salir = getchar();
            break;

        default:
            printf("opcion invalida!!");
            system("pause");
            break;
        }

    }
    while(salir == 'n');
}
