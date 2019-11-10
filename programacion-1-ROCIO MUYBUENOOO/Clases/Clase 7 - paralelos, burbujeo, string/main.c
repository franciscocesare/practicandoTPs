#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

void mostrarAlumno(char nombre[],int legajo, int edad, int nota1, int nota2, char sexo, float promedio)
{
    printf("\n%8s  %d     %d       %d        %2d         %c     %.2f",nombre,legajo, edad, nota1, nota2, sexo, promedio);
}


void mostrarAlumnos(char nombre[][20],int legs[], int ages[], int n1[], int n2[], char sexs[], float averages[], int tam)
{
    printf("Nombre   Legajo  Edad  Parcial l  Parcial 2  Sexo  Promedio\n");

    for(int i=0; i<tam; i++)
    {
        mostrarAlumno(nombre[i],legs[i],ages[i],n1[i],n2[i],sexs[i],averages[i]);
    }
}


void ordenarSexoNombre (char nombre[][20], int legs[], int ages[], int n1[], int n2[], char sexs[], float averages[], int tam)
{
    int auxInt;
    int flag=0;
    float auxfloat;
    char auxChar;
    char auxString[20];

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(sexs[i]>sexs[j])
            {
                flag=1;
            }
            else if (sexs[i]==sexs[j] && stricmp(nombre[i],nombre[j]) > 0)
            {
                flag=1;
            }
            if(flag)
            {
                strcpy(auxString,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],auxString);

                auxInt=legs[i];
                legs[i]=legs[j];
                legs[j]=auxInt;

                auxInt=ages[i];
                ages[i]=ages[j];
                ages[j]=auxInt;

                auxInt=n1[i];
                n1[i]=n1[j];
                n1[j]=auxInt;

                auxInt=n2[i];
                n2[i]=n2[j];
                n2[j]=auxInt;

                auxChar=sexs[i];
                sexs[i]=sexs[j];
                sexs[j]=auxChar;

                auxfloat=averages[i];
                averages[i]=averages[j];
                averages[j]=auxfloat;
            }
        }
    }
}


int main()
{
    int legajo[TAM]={5325,7442,5135,6453,1424};
    int edad[TAM]={24,18,21,19,25};
    int notas1[TAM]={7,5,9,8,6};
    int notas2[TAM]={8,6,10,9,7};
    float promedio[TAM]={7.5,5.5,9.5,8.5,6.5};
    char sexo[TAM]={'m','f','f','m','m'};
    char nomApe[TAM][20]={"juan","josefina","ana","alberto","pepe"};

  ordenarSexoNombre(nomApe,legajo,edad,notas1,notas2,sexo,promedio,TAM);
   mostrarAlumnos(nomApe,legajo,edad,notas1,notas2,sexo,promedio,TAM);

    return 0;
}







