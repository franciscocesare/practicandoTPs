#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "inputDiaz.h"
#include "autos.h"
#include "trabajos.h"
#include "informes.h"

int menuInformes()
{
    int opcion;

    system("cls");
    printf("    #####  Menu de Informes  ####\n\n\n");

    printf("    1_ Listar autos por color.\n");
    printf("    2_ Mostrar autos de marca seleccionada.\n");
    printf("    3_ Mostrar todos los trabajos aplicado a un auto.\n");
    printf("    4_ (corregitr)Listar autos que no tuvieron trabajos.\n");
    printf("    5_ Importe total de trabajos realizados a un auto.\n");
    printf("    6_ (corregir)Mostrar servicio mas pedido.\n");
    printf("    7_ Mostrar recaudacion en fecha especifica.\n");
    printf("    8_ Mostrar autos que realizaron encerado y fecha.\n");
    printf("    9_ Trabajos realizados a autos blancos.\n");
    printf("    10_ Facturacion total por pulidos.\n");
    printf("    12_ Listar autos que recibieron trabajos en una fecha especifica.\n");
    printf("    13_ Volver al menu principal.\n");
    printf("\n\n>>>> Opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void mostrarAutosPorColor(eAuto lista[], int tam, eColor color[], int tamColor, eMarca marca[], int tamMarca)
{
    int idColor;
    int indiceColor;

    mostrarColores(color, tamColor);
    printf("\nIngrese el Id del color: ");
    scanf("%d",&idColor);


    while(buscarColorPorId(color, tamColor, idColor)==-1)
    {
        printf("\nNo existe ese id!!!\n");
        printf("\nIngrese el Id del color: ");
        scanf("%d",&idColor);
    }

    indiceColor=buscarColorPorId(color, tamColor, idColor);

    if(indiceColor != -1)
    {
        system("cls");
        printf("   ID       Patente      Marca    Color     Modelo    Nombre   Sexo");
        printf("\n\n");
        for(int i=0; i<tam; i++)
        {
            if(lista[i].ocupado == 1 && lista[i].idColor == idColor)
            {
                mostrarAuto(lista[i],color, tamColor, marca, tamMarca);
            }
        }

        printf("\n\n");
    }
}

void mostrarAutosPorMarca(eAuto lista[], int tam, eColor color[], int tamColor, eMarca marca[], int tamMarca)
{
    int idMarca;
    int indiceMarca;

    mostrarMarcas(marca, tamMarca);
    printf("\nIngrese el Id de la marca: ");
    scanf("%d",&idMarca);

    while(buscarMarcaPorId(marca, tamMarca, idMarca)==-1)
    {
        printf("\nNo existe ese id!!!\n");
        printf("\nIngrese el Id de la marca: ");
        scanf("%d",&idMarca);
    }

    indiceMarca=buscarMarcaPorId(marca, tamMarca, idMarca);

    if(indiceMarca != -1)
    {
        system("cls");
        printf("   ID       Patente      Marca    Color     Modelo    Nombre   Sexo");
        printf("\n\n");
        for(int i=0; i<tam; i++)
        {
            if(lista[i].ocupado==1 && lista[i].idMarca==idMarca)
            {
                mostrarAuto(lista[i],color, tamColor, marca, tamMarca);
            }
        }
        printf("\n\n");
    }
}

void trabajosUnAuto(eAuto listA[], int tamA, eServicio listaS[], int tamS, eTrabajo listT[], int tamT, eColor listC[], int tamC, eMarca listM[], int tamM)
{
    int indicePatente;
    char patente[10];

    mostrarAutos(listA, tamA, listC, tamC, listM, tamM);
    validarPatente(patente, "Ingrese patente: ");

    while(buscarAutoPorPatente(listA, tamA, patente)==-1)
    {
        printf("\nNo existe esa patente!!!\n");
        validarPatente(patente, "Ingrese patente: ");
    }

    indicePatente=buscarAutoPorPatente(listA, tamA, patente );

    if(indicePatente != 1)
    {
        system("cls");
        printf(" ID    PATENTE    TRABAJO   FECHA");
        printf("\n\n");

        for(int i=0; i<tamT; i++)
        {
            if(stricmp(listT[i].patente, patente)==0 && listT[i].ocupado==1)
            {
                mostrarTrabajo(listT[i], listaS, tamS);
            }
        }
        printf("\n\n");
    }
}

int listarAutosSinTrabajos(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eTrabajo trabajos[], int tamTrabajos)
{
    int todoOk = 0;
    int flag;
    int contador = 0;
    char aux[21];
    int auxComp;
    char nombreColor[20];
    char nombreMarca[20];

    system("cls");

    printf(" ID        PATENTE           MARCA          COLOR      MODELO\n");
    printf(" --        -------           -----          -----      ------\n");

    for(int i=0; i < tam; i++)
    {
        if(autos[i].idAuto != 0)
        {
            strcpy(aux,autos[i].patente);
        }

        flag = 0;

        for(int j=0; j<tamTrabajos; j++)
        {
            if(trabajos[j].idTrabajo != 0)
            {
                auxComp = strcmp(trabajos[j].patente, aux);

                if(auxComp == 0)
                {
                    flag = 1;

                }
            }
        }

        if(flag == 0)
        {

            obtenerColores(colores, tamColores, autos.idColor, nombreColor);
            obtenerMarcas(marcas, tamMarcas, autos.idMarca, nombreMarca);

            printf("%02d  %10s  %10s  %8s  %7d  %10s  %5c\n",autos.idAuto,autos.patente, nombreMarca, nombreColor, autos.anioAuto, autos.nombre, autos.sexo);
            printf("")
            contador++;
        }
    }

    printf("\n\n");C:\Users\alumno\Desktop\programacion-1\Diaz.Rocio.1G\informes.c

    if( contador == 0)
    {
        printf("\nNo hay autos que mostrar\n");
    }

    todoOk = 1;

    return todoOk;
}
void importePorAuto(eAuto listA[], int tamA, eServicio listaS[], int tamS, eTrabajo listT[], int tamT, eColor listC[], int tamC, eMarca listM[], int tamM)
{
    int indicePatente;
    int acumulador=0;
    char patente[10];

    mostrarAutos(listA, tamA, listC, tamC, listM, tamM);
    validarPatente(patente, "Ingrese patente: ");

    while(buscarAutoPorPatente(listA, tamA, patente)==-1)
    {
        printf("\nNo existe esa patente!!!\n");
        validarPatente(patente, "Ingrese patente: ");
    }

    indicePatente=buscarAutoPorPatente(listA, tamA, patente );

    if(indicePatente != 1)
    {
        system("cls");
        printf(" ID    PATENTE    TRABAJO   FECHA");
        printf("\n\n");

        for(int i=0; i<tamT; i++)
        {
            for(int j=0; j<tamS; j++)
            {
                if(stricmp(listT[i].patente, patente)==0 && listT[i].idServicio==listaS[j].idServicio)
                {
                    mostrarTrabajo(listT[i], listaS, tamS);
                    acumulador+=listaS[j].precio;
                }
            }
        }
        printf("\nImporte total: %d.\n\n", acumulador);
        system("pause");
    }
}

void servicioMasPedido(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eAuto listaA[], int tamA)
{
    int cont[tamS];
    int max;
    int posMax=0;



    for(int i=0; i<tamS; i++)
    {
        cont[i]=0;

        for(int j=0; j<tamT; j++)
        {
            for(int k=0; k<tamA; k++)
            {
                if(listaT[j].idServicio==listaS[i].idServicio && stricmp(listaT[j].patente,listaA[k].patente)==0 && listaT[j].ocupado==1)
                {
                    cont[i]++;
                }
            }
        }
    }

    for(int i=0; i<tamS; i++)
    {
        if(cont[i]>=max)
        {
            max=cont[i];
            posMax=i;
        }

    }

    printf("\n\n");
    printf("El servicio mas solicitado es %s con %d trabajos\n", listaS[posMax].nombreServicio,max);
    printf("\n\n");

}

void totalPorFecha(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{
    int dia;
    int mes;
    int anio;
    int cont=0;
    int acumulador=0;

    dia=obtenerNumeroEntre(31, 1, "## Ingrese dia: ");
    mes=obtenerNumeroEntre(12, 1, "## Ingrese mes: ");
    anio=obtenerNumeroIgualA(2019, "## Ingresar anio: ");
    printf("\n\n");

    printf(" ID    PATENTE    TRABAJO   FECHA");
    printf("\n\n");

    for (int i=0; i<tamS; i++)
    {
        for(int j=0; j<tamT; j++)
        {
            if(listaS[i].idServicio == listaT[j].idServicio && listaT[j].fechaTrabajo.dia==dia && listaT[j].fechaTrabajo.mes==mes && listaT[j].fechaTrabajo.anio==anio && listaT[j].ocupado==1)
            {
                mostrarTrabajo(listaT[j], listaS, tamS);
                acumulador+=listaS[i].precio;
                cont++;
            }
        }
    }

    if(cont==0)
    {
        printf("No hay servicios solicitados en la fecha %02d/%02d/%d\n\n",dia,mes,anio);
    }

    printf("\nEl total acumulado en la fecha de %02d/%02d/%d es de $%d\n\n",dia,mes,anio,acumulador);
}

void mostrarAutosPorTrabajo(eAuto listaA[], int tamA, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{
    int idServicio;
    int indice;

    mostrarServicios(listaS, tamS);
    printf("\nIngrese el Id del servicio: ");
    scanf("%d",&idServicio);


    while(buscarServicioPorId(listaS, tamS, idServicio)==-1)
    {
        printf("\nNo existe ese id!!!\n");
        printf("\nIngrese el Id del servicio: ");
        scanf("%d",&idServicio);
    }

    indice=buscarServicioPorId(listaS, tamS, idServicio);

    if(indice != -1)
    {
        system("cls");
        printf("ID     PATENTE    SERVICIO    FECHA");
        printf("\n\n");
        for(int i=0; i<tamT; i++)
        {
            if(listaT[i].ocupado == 1 && listaT[i].idServicio == idServicio)
            {
                mostrarTrabajo(listaT[i], listaS, tamS);
            }
        }
        printf("\n\n");
    }
}

int validarColor(eColor vec[],int tam)
{
    int indice=-1;
    int id;

    mostrarColores(vec, tam);
    printf("\nIngrese el Id del color: ");
    scanf("%d",&id);

    while(buscarColorPorId(vec, tam, id)==-1)
    {
        printf("\nNo existe ese id!!!\n");
        printf("\nIngrese el Id del color: ");
        scanf("%d",&id);
    }

    if(buscarColorPorId(vec, tam, id)==1)
    {
        indice=1;
    }

    return indice;
}
void trabajosPorColor(eServicio listaS[], int tamS, eTrabajo listT[], int tamT, eColor listC[], int tamC, eAuto listaA[], int tamA)
{
    int indice;
    int id;
    int cont=0;

    /*mostrarColores(listC, tamC);
    printf("\nIngrese el Id del color: ");
    scanf("%d",&id);

    while(buscarColorPorId(listC, tamC, id)==-1)
    {
        printf("\nNo existe ese id!!!\n");
        printf("\nIngrese el Id del color: ");
        scanf("%d",&id);
    }

    indice=buscarColorPorId(listC, tamC, id);*/

    indice=validarColor(listC,tamC);

    if(indice != 1)
    {
        system("cls");
        printf("ID     PATENTE     TRABAJO     FECHA");
        printf("\n\n");

        for(int i=0; i<tamT; i++)
        {
            for(int j=0; j<tamA; j++)
            {
                if(stricmp(listaA[j].patente, listT[i].patente)==0 && listaA[j].idColor==id && listT[i].ocupado==1)
                {
                    mostrarTrabajo(listT[i], listaS, tamS);
                    cont++;
                }
            }
        }
        printf("\n\n");

        if(cont==0)
        {
            printf("No hay trabajos para mostrar!!!\n\n");
        }

        printf("\n\n");
    }
}

void totalPorServicio(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{
    int indiceServicio;
    int idServicio;
    int cont=0;
    int acumulador=0;

    mostrarServicios(listaS, tamS);
    printf("\nIngrese Id servicio: ");
    scanf("%d",&idServicio);

    while(buscarServicioPorId(listaS, tamS, idServicio)==-1)
    {
        printf("\nServicio no registrado!!!\n");
        printf("\nIngrese Id servicio: ");
        scanf("%d",&idServicio);
    }

    indiceServicio=buscarServicioPorId(listaS, tamS, idServicio);

    if(indiceServicio != -1)
    {
        system("cls");
        printf(" ID    PATENTE    TRABAJO   FECHA");
        printf("\n\n");

        for (int i=0; i<tamS; i++)
        {
            for(int j=0; j<tamT; j++)
            {
                if(listaT[j].idServicio==listaS[i].idServicio && listaT[j].idServicio==idServicio && listaT[j].ocupado==1)
                {
                    mostrarTrabajo(listaT[j], listaS, tamS);
                    acumulador+=listaS[i].precio;
                    cont++;
                }
            }
        }
    }

    if(cont==0)
    {
        printf("No hay trabajos solicitados para ese servicio!!!\n");
    }

    printf("\nEl total acumulado es de $%d\n\n",acumulador);
}

void autosConTrabajoXFecha(eAuto listaA[], int tamA, eTrabajo listaT[], int tamT, eColor listaC[], int tamC, eMarca listaM[], int tamM)
{
    int dia;
    int mes;
    int anio;
    int cont=0;

    dia=obtenerNumeroEntre(31, 1, "## Ingrese dia: ");
    mes=obtenerNumeroEntre(12, 1, "## Ingrese mes: ");
    anio=obtenerNumeroIgualA(2019, "## Ingresar anio: ");
    printf("\n\n");

    system("cls");
    printf("ID     Patente      Marca       Color     Modelo     Nombre     Sexo\n");
    printf("--     -------      -----       -----     ------     ------     ----");
    printf("\n\n");

    for (int i=0; i<tamA; i++)
    {
        for(int j=0; j<tamT; j++)
        {
            if(stricmp(listaA[i].patente,listaT[j].patente)==0 && listaT[j].fechaTrabajo.dia==dia && listaT[j].fechaTrabajo.mes==mes && listaT[j].fechaTrabajo.anio==anio && listaT[j].ocupado==1)
            {
                mostrarAuto(listaA[i], listaC, tamC,listaM, tamM);
                cont++;
            }
        }
    }
    printf("\nAutos con trabajos realizados en la fecha %02d/%02d/%d\n\n",dia,mes,anio);
    printf("\n\n");

    if(cont==0)
    {
        printf("No hay autos con trabajos realizados en la fecha %02d/%02d/%d\n\n",dia,mes,anio);
    }
}

