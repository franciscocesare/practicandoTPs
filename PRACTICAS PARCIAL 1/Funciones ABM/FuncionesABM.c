#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    int edad;
    int isEmpty;
    char nombre[20];
    char sexo;
    eFecha fecha;

} STRUCT_NAME;

int menuABM()
{
    int opcion;

    system("cls");
    printf("****** ABM *******\n\n");
    printf("1-Alta\n");
    printf("2-Baja\n");
    printf("3-Modificar\n");
    printf("4-Listar\n");
    printf("5-Ordenar\n");
    printf("6-Informes\n");
    printf("7-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarEstructura(STRUCT_NAME vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int buscarLibre(STRUCT_NAME vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void IniciarIncremental (STRUCT_NAME vec[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].legajo= i+1;
    }
}

void mostrarDato(STRUCT_NAME dato)
{
    printf("  %d     %s     %d  %c  %02d/%02d/%d\n",
           dato.legajo,
           dato.nombre,
           dato.edad,
           dato.sexo,
           dato.fecha.dia,
           dato.fecha.mes,
           dato.fecha.anio);
}

void mostrarDatos(STRUCT_NAME vec[], int tam)
{
    int flag = 0;
    system("cls");

    printf(" Legajo Nombre Edad Sexo FIngreso\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarDato(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay alumnos que mostrar\n");
    }

    printf("\n\n");
}

int buscarPersona(int VALOR_A_BUSCAR, STRUCT_NAME vec[], int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if( vec[i].DONDE_BUSCAR == VALOR_A_BUSCAR && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int alta(STRUCT_NAME vec[], int tam)
{
    int todoOk = 0;
    int indice;
    int esta;
    int id;

    system("cls");

    printf("*****  Alta  *****\n\n");

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {

        printf("Ingrese id: ");
        scanf("%d", &id);

        esta = buscarPersona(id, vec, tam);

        if( esta != -1)
        {
            printf("\nEse id ya se encuentra registrado\n\n");
            mostrarDato(vec[esta]);

        }
        else
        {
            /* printf("Ingrese nombre: ");
             fflush(stdin);
             gets(nombre);

             printf("Ingrese edad: ");
             scanf("%d", &edad);

             printf("Ingrese sexo: ");
             fflush(stdin);
             scanf("%c", &sexo);

             printf("Ingrese nota 1: ");
             scanf("%d", &n1);

             printf("Ingrese nota 2: ");
             scanf("%d", &n2);

             printf("Ingrese fecha ingreso: ");
             scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

             vec[indice] = newAlumno(legajo, nombre, edad, sexo, n1, n2, fecha); */

            todoOk = 1;
            printf("Alta exitosa!!\n\n");

        }

    }

    return todoOk;
}

int baja(STRUCT_NAME vec[], int tam)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja *****\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &id);

    indice = buscarPersona(id, vec, tam);

    if( indice == -1)
    {
        printf("No existe un alumno con ese legajo\n\n");
    }
    else
    {
        mostrarDato(vec[indice]);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}

int menuModificacion()
{
    int opcion;

    system("cls");
    printf("****** Menu Modificacion *******\n\n");

    printf("1- NOMBRE\n");
    printf("2- NOMBRE\n");
    printf("3- NOMBRE\n");
    printf("4- NOMBRE\n");
    printf("5- NOMBRE\n");
    printf("6- Salir\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int Modificar(STRUCT_NAME vec[], int tam)
{

    int todoOk = 0;
    int id;
    int indice;

    system("cls");
    printf("***** Modificar *****\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarPersona(id, vec, tam);

    if( indice == -1)
    {
        printf("No existe ese id\n\n");

    }
    else
    {
        mostrarDato(vec[indice]);

        switch(menuModificacion())
        {
        case 1:
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        default:
            printf("Opcion invalida!!\n\n");
        }

    }

    return todoOk;
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



