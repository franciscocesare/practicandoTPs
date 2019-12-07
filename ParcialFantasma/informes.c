#include "inputDiaz.h"
#include "entidad_1.h"
#include "entidad_2.h"
#include "entidad_3.h"
#include "informes.h"

int menuInformes()
{
    int opcion;

    system("cls");
    printf("  ***  MENU DE INFORMES ***   \n\n");
    printf("1. Todos los Vuelos de un Piloto Seleccionado\n");
    printf("2. Todos los pilotos que volaron a un destino especifico\n");
    printf("3. Recaudacion por cada Piloto\n");
    printf("4. Destino mas elegido\n");
    printf("5. Atras\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int menuOrdenar()
{
    int opcion;

    system("cls");
    printf("****** Menu ordenar *******\n\n");

    printf("1- Ordenar por nombre\n");
    printf("2- Ordenar por sexo\n");
    printf("3- Ordenar por id\n");
    printf("4- NOMBRE_VALOR_A_ORDENAR\n");
    printf("5- Salir\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

//////////////////////////////////////////////////////////////////////

int ordenarEstructura(STRUCT_NAME vec[], int tam)
{
    STRUCT_NAME aux;
    int retorno=-1;

    switch(menuOrdenar())
    {
    case 1:
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if( strcmp(vec[i].nombre, vec[j].nombre) > 0)
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                    retorno=1;
                }
            }
        }
        break;

    case 2:
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(vec[i].sexo > vec[j].sexo)
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                    retorno=1;
                }
            }
        }
        break;

    case 3:
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(vec[i].legajo > vec[j].legajo)
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                    retorno=1;
                }
            }
        }
        break;

    case 4:
        break;

    default:

        printf("Opcion invalida!!\n\n");
    }

    return retorno;
}

