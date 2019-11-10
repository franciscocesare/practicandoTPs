/**< Laboratorio I - TP Nº1 Calculadora - Alumno: Arias Mariano Luis - Abril 2019*/
#include <stdio.h>
#include <stdlib.h>
#include "funcionesCalculadora.h"

int main()
{
    int numeroA;
    int numeroB;
    int resultAdd;
    int resultSubs;
    int resultMult;
    float resultDiv;
    int calculoFactorialA;
    int calculoFactorialB;
    char opciones;
    int flagA=0; // Flag control para la carga del operando NumeroA
    int flagB=0; // Flag control para la carga del operando numeroB
    int flagC=0; // Flag control para no mostrar resultados si no se realizadon las operaciones previamente

    printf("Bienvenido a la Calculadora.\n");

    do {
        if (flagA==1){
            printf("\nEl numero A ingresado es :%d",numeroA);
        }
        if (flagB==1){
            printf("\nEl numero B ingresado es :%d\n",numeroB);
        }
        printf("\n");
        printf("\n Elija su opcion: \n\n 1. Ingresar primer operando Numero A\n 2. Ingresar segundo operando Numero B\n 3. Calcular operaciones\n 4. Mostrar resultados\n 5. Finalizar\n");
        printf("\n");
        printf("\n Su opcion: ");
        scanf("%c",&opciones);
        switch (opciones){
            case '1':
                system("cls");
                printf("Ingrese el numero A: ");
                scanf("%d",&numeroA);
                flagA=1;
                system("cls");
                break;

            case '2':
                system("cls");
                printf("Ingrese el numero B: ");
                scanf("%d",&numeroB);
                flagB=1;
                system("cls");
                break;

            case '3':
                system("cls");
                if (flagA==0 || flagB==0){
                    printf("\nError. Aun no se ingresaron los operandos.\n");
                }else{
                    flagC=1;
                    resultAdd=add(numeroA, numeroB);
                    resultSubs=substract(numeroA, numeroB);
                    if (numeroB!=0){
                    resultDiv=divide(numeroA,numeroB);
                    }
                    resultMult=multiply(numeroA, numeroB);
                    if (numeroA>=0){
                    calculoFactorialA=factorize(numeroA);
                    }
                    if (numeroB>=0){
                    calculoFactorialB=factorize(numeroB);
                    }
                printf("\nLas operaciones han sido realizadas.\n");
                }
                break;
            case '4':
                if (flagC==0){
                    system("cls");
                    printf("\nError. Aun no se realizaron las operaciones.\n");
                }else{
                    system("cls");
                    printf("\nLos resultados de las operaciones son los siguientes:\n");
                    printf("\nEl resultado de A+B es: %d",resultAdd);
                    printf("\nEl resultado de A-B es: %d",resultSubs);
                    if (numeroB==0){
                    printf("\nEl resultado de A/B es: Error. No es posible dividir por 0 (cero)");
                    } else {
                    printf("\nEl resultado de A/B es: %.1f", resultDiv);
                    }
                    printf ("\nEl resultado de A*B es: %d",resultMult);
                    if (numeroA>=0){
                    printf("\nEl factorial de A es: %d",calculoFactorialA);
                    } else {
                    printf("\nEl factorial de A es: Error. No hay factorial de numero negativo");
                    }
                    if (numeroB>=0){
                    printf("\nEl factorial de B es: %d\n",calculoFactorialB);
                    }else{
                    printf("\nEl factorial de B es: Error. No hay factorial de numero negativo");
                    }
                }
                break;
            case '5':
               break;
            default:
                system("cls");
                printf("\nError , la opcion ingresada no es valida.\n");
        }
        fflush(stdin);
    }while (opciones!='5');
}
