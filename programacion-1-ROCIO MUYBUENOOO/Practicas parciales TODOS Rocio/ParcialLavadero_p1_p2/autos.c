#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "inputDiaz.h"
#include "autos.h"
#include "trabajos.h"

int menuABM()
{
    int opcion;

    system("cls");
    printf("##### Menu ABM #####\n\n");
    printf("   1. Alta Autos.\n");
    printf("   2. Modificar Auto.\n");
    printf("   3. Baja Auto.\n");
    printf("   4. Listar Autos.\n");
    printf("   5. Listar Marcas.\n");
    printf("   6. Listar Colores.\n");
    printf("   7. Listar Servicio.\n");
    printf("   8. Alta Trabajos.\n");
    printf("   9. Listar trabajos.\n");
    printf("   10. Informes.\n\n");
    printf("   11. Salir.\n\n");
    printf(">> Ingresar opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void inicializarAuto(eAuto vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int buscarLibre(eAuto vec[], int tam)
{
    int indice = -1;

    for(int i=0; i <tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarMarca(eMarca lista)
{
    printf("%d  %10s\n", lista.idMarca, lista.nombreMarca);
}

void mostrarMarcas(eMarca lista[], int tam)
{
    int cont=0;

    system("cls");
    printf(" ID      MARCAS\n");
    printf("--      -------");
    printf("\n\n");

    for(int i=0; i<tam; i++)
    {
        mostrarMarca(lista[i]);
        cont++;
    }
    printf("\n\n");
    if(cont==0)
    {
        printf("\nNo hay autos para mostrar!!!\n\n");
        system("pause");
    }
}

int obtenerMarcas(eMarca vecMarca[], int tamMarca, int idMarca, char dondeAsinar[])
{
    int todoOk=-1;

    for(int i= 0 ; i<tamMarca; i++)
    {
        if(idMarca == vecMarca[i].idMarca)
        {
            strcpy(dondeAsinar,vecMarca[i].nombreMarca);
            todoOk=1;
            break;
        }
    }
    return todoOk;
}

void mostrarColor(eColor lista)
{
    printf("%d %10s\n",lista.idColor, lista.nombreColor);
}

int obtenerColores(eColor vecColor[], int tamColor, int idColor, char dondeAsinar[])
{
    int todoOk=-1;

    for(int i= 0 ; i<tamColor; i++)
    {
        if(idColor == vecColor[i].idColor)
        {
            strcpy(dondeAsinar,vecColor[i].nombreColor);
            todoOk=1;
            break;
        }
    }
    return todoOk;
}

void mostrarColores(eColor lista[], int tam)
{
    int cont=0;

    system("cls");
    printf(" ID      COLOR\n");
    printf("--     -------");
    printf("\n\n");

    for(int i=0; i<tam; i++)
    {
        mostrarColor(lista[i]);
        cont++;
    }

    printf("\n\n");

    if(cont==0)
    {
        printf("\nNo hay autos para mostrar!!!\n\n");
        system("pause");
    }
}

void mostrarAuto(eAuto vecAuto, eColor vecColor[], int tamColor, eMarca vecMarca[], int tamMarca)
{
    char nombreColor[20];
    char nombreMarca[20];

    obtenerColores(vecColor, tamColor, vecAuto.idColor, nombreColor);
    obtenerMarcas(vecMarca, tamMarca, vecAuto.idMarca, nombreMarca);

    printf("%02d  %10s  %10s  %8s  %7d  %10s  %5c\n",vecAuto.idAuto,vecAuto.patente, nombreMarca, nombreColor, vecAuto.anioAuto, vecAuto.nombre, vecAuto.sexo);
}

void mostrarAutos(eAuto vecAuto[],int tamAuto, eColor vecColor[], int tamColor, eMarca vecMarca[], int tamMarca)
{
    int cont=0;

    system("cls");

    system("cls");
    printf("ID     Patente      Marca      Color     Modelo     Nombre     Sexo\n");
    printf("--     -------      -----      -----     ------     ------     ----");
    printf("\n\n");
    for(int i=0; i<tamAuto; i++)
    {
        if(vecAuto[i].ocupado==1)
        {
            mostrarAuto(vecAuto[i], vecColor, tamColor, vecMarca, tamMarca);
            cont++;
        }
    }
    printf("\n\n");

    if(cont==0)
    {
        printf("\nNo hay autos para mostrar!!!\n\n");
        system("pause");
    }
}

void altaAuto(eAuto vecAuto[],int tamAuto, eColor vecColor[], int tamColor, eMarca vecMarca[], int tamMarca)
{
    int indice;
    int indiceMarca;
    int indiceColor;
    int id;
    char auxChar[50];

    indice=buscarLibre(vecAuto,tamAuto);

    if(indice != -1)
    {
        vecAuto[indice].idAuto=generarIdAletatorio(100, 1);

        validarPatente(auxChar,"## Ingresar patente (3 letra)-(3 numeros): ");
        strcpy(vecAuto[indice].patente, auxChar);
        /////////////

        mostrarMarcas(vecMarca, tamMarca);
        printf("\nIngrese el Id de la marca: ");
        scanf("%d",&id);

        indiceMarca=buscarMarcaPorId(vecMarca, tamMarca, id);

        if(indiceMarca != -1)
        {
            vecAuto[indice].idMarca=id;
        }
        while(indiceMarca==-1)
        {
            printf("\nNo existe ese id!!!\n");
            printf("\nIngrese el Id de la marca: ");
            scanf("%d",&id);
            indiceMarca=buscarMarcaPorId(vecMarca, tamMarca, id);
        }

        ////////////////////////////
        mostrarColores(vecColor, tamColor);
        printf("\nIngrese el Id del color: ");
        scanf("%d",&id);

        indiceColor=buscarColorPorId(vecColor, tamColor, id);

        if(indiceColor != -1)
        {
            vecAuto[indice].idColor=id;
        }
        while(indiceColor==-1)
        {
            printf("\nNo existe ese id!!!\n");
            printf("\nIngrese el Id del color: ");
            scanf("%d",&id);
            indiceColor=buscarColorPorId(vecColor, tamColor, id);
        }

        /////////////
        system("cls");
        vecAuto[indice].anioAuto=obtenerNumeroEntre(2020, 1980, "## Ingrese anio del auto: ");

        obtenerCadenaChar(auxChar, 20, "## Ingrese nombre: ");
        strcpy(vecAuto[indice].nombre, auxChar);

        vecAuto[indice].sexo=obtenerSexo("## Ingrese sexo f/m: ");

        vecAuto[indice].ocupado=1;

        printf("\nTrabajo dado de alta con exito!!!.\n\n");
    }
    else
    {
        printf("No hay mas lugar en el sistema!!!\n\n");
        system("pause");
    }
}

int menuModificacionAuto()
{
    int opcion;

    system("cls");
    printf("#####  Menu de Modificion  ####\n\n");

    printf("    1_ Color.\n");
    printf("    2_ Modelo.\n");
    printf("    3_ Volver al menu principal.\n");
    printf("\n\n>>>> Opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int buscarAutoPorPatente(eAuto vec[],int tam, char patente[])
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if((vec[i].ocupado == 1)&& strcmp(vec[i].patente, patente)==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void modificarAuto(eAuto vecAuto[],int tamAuto, eColor vecColor[], int tamColor, eMarca vecMarca[], int tamMarca)
{
    int indice;
    int idColor;
    int opcion;
    char confirma;
    char auxChar[50];

    mostrarAutos(vecAuto, tamAuto, vecColor, tamColor, vecMarca, tamMarca);
    printf("\n>>> Ingrese patente: ");
    fflush(stdin);
    gets(auxChar);

    indice=buscarAutoPorPatente(vecAuto, tamAuto, auxChar);

    while(indice == -1)
    {
        printf("Patente no registrada!!!\n");
        printf("\n>>> Ingrese patente: ");
        fflush(stdin);
        gets(auxChar);
        indice=buscarAutoPorPatente(vecAuto, tamAuto, auxChar);
    }
    if(indice != -1)
    {
        printf ("\nDesea modificar auto? s/n: ");
        fflush (stdin);
        confirma = tolower(getche());

        if(confirma=='n')
        {
            menuABM();
        }
        else
        {
            switch(menuModificacionAuto())
            {
            case 1:
                mostrarColores(vecColor, tamColor);
                printf("\nIngrese el Id del color: ");
                scanf("%d",&idColor);
                vecAuto[indice].idColor=idColor;
                break;

            case 2:
                vecAuto[indice].anioAuto=obtenerNumeroEntre(2020, 1980, "## Ingrese anio del auto: ");
                break;

            case 3:
                menuABM();
                break;

            default:
                if(opcion > 3 || opcion < 0)
                {
                    printf("\nIngrese opcion valida: ");
                    scanf("%d",&opcion);
                }
            }

        }
    }
}

void bajaAuto(eAuto vecAuto[],int tamAuto, eColor vecColor[], int tamColor, eMarca vecMarca[], int tamMarca)
{
    int indicePatente;
    char confirma;
    char auxChar[10];

    mostrarAutos(vecAuto, tamAuto, vecColor, tamColor, vecMarca, tamMarca);
    validarPatente(auxChar, "Ingrese patente: ");

    while(buscarAutoPorPatente(vecAuto, tamAuto,auxChar)==-1)
    {
        printf("\nNo existe esa patente!!!\n");
        validarPatente(auxChar, "Ingrese patente: ");
    }

    indicePatente=buscarAutoPorPatente(vecAuto, tamAuto, auxChar);

    if(indicePatente != -1)
    {
        printf ("\nDesea dar de baja el auto? s/n: ");
        fflush (stdin);
        confirma = tolower(getche());

        if(confirma=='n')
        {
            menuABM();
        }
        else
        {
            vecAuto[indicePatente].ocupado=0;
            printf("\n\nAuto dado de baja con exito!!!\n\n");
            system("pause");
        }
    }
    else
    {
        printf("Auto no registrado!!!\n\n");
        system("pause");
    }
}

void ordenarAutos(eAuto vec[], int tam)
{
    eAuto aux;

    for(int i = 0 ; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(vec[i].idMarca>vec[j].idMarca)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
            else
            {
                if(vec[i].idMarca==vec[j].idMarca && stricmp(vec[i].patente, vec[j].patente)>0)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }
    }
}

int buscarMarcaPorId(eMarca vec[], int tam, int idMarca)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].idMarca==idMarca)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarColorPorId(eColor vec[], int tam, int idColor)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].idColor==idColor)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
