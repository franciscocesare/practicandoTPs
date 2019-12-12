#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "inputElian.h"

//#define __unix__
#ifdef __unix__
#include <unistd.h>
#else
#include <windows.h>
#endif


/*Funciones para obtener valores*/
void f_i_PedirInt (int * var_dondeAsignar, char mensaje[])
{
    printf("\n%s\n",mensaje);
    fflush(stdin);
    scanf("%d",var_dondeAsignar);
    return;
}


void f_i_PedirFloat (float * var_dondeAsignar, char mensaje[])
{
    printf("\n%s\n",mensaje);
    fflush(stdin);
    scanf("%f",var_dondeAsignar);
    return;
}


void f_i_PedirChar (char * var_dondeAsignar, char mensaje[])
{
    printf("\n%s\n",mensaje);
    fflush(stdin);
    scanf(" %c",var_dondeAsignar);
    return;
}


void f_i_PedirString(char var_dondeAsignar[], int longitudMaxString, char mensaje[])
{
    char aux[longitudMaxString];
    fflush(stdin);
    printf("\n%s\n",mensaje);
    fgets(aux,longitudMaxString,stdin);

    //Elimino salto de linea//
    int len = strlen(aux);
    if(aux[len-1] =='\n')
    {
        aux[len-1]='\0';
    };

    strcpy(var_dondeAsignar,aux);
    return;
}


void f_i_PedirIntEntre(int * var_dondeAsignar, int min, int max, char mensaje[])
{
    int aux;
    do
    {
        fflush(stdin);
        printf("\n%s\n", mensaje);
        fflush(stdin);
        scanf("%d", &aux);

        if (aux > max || aux < min)
        {
            printf("\n**Error,opcion invalida**");

        };
    }
    while (aux > max || aux < min);
    *var_dondeAsignar = aux;
    return;
}

/*Funciones para obtener datos especificos*/


void f_i_PedirNombre(char var_dondeAsignar[],int longitudMaxString, char mensaje[])
{
    int i;
    int no_es_un_nombre;
    char auxiliar[longitudMaxString];
    do
    {
        fflush(stdin);
        printf("%s\n",mensaje);

        fgets(auxiliar,longitudMaxString,stdin);

        for (i=0; i<strlen(auxiliar)-1; i++)
        {
            auxiliar[i] = tolower(auxiliar[i]);
            if ((auxiliar[i]<'a' || auxiliar[i]>'z') && auxiliar[i] != ' ')
            {
                no_es_un_nombre = -1;
                printf("\n**Error, ingrese solo letras y espacios**\n");
                break;
            }
            else
            {
                if (i == 0 || auxiliar[i-1] == ' ')
                {
                    auxiliar[i] = toupper(auxiliar[i]);
                }
                no_es_un_nombre = 0;
            }
        }
    }
    while (no_es_un_nombre);

    int len = strlen(auxiliar);

    if(auxiliar[len-1]=='\n')
    {

        auxiliar[len-1]='\0';

    };

    strcpy(var_dondeAsignar, auxiliar);
    return;
}


void f_i_PedirStringSoloNumeros(char var_dondeAsignar[],int longitudMaxString,char mensaje[])
{
    //acordate atoi() para pasar a int//
    int i;
    int invalido;
    char auxiliar[longitudMaxString];
    fflush(stdin);
    printf("%s\n",mensaje);

    do
    {
        fflush(stdin);
        fgets(auxiliar,longitudMaxString,stdin);

        for (i=0; i<strlen(auxiliar)-1; i++)
        {
            if (auxiliar[i]<'0' || auxiliar[i]>'9')
            {
                invalido = 1;
                printf("\nError, ingrese solo numeros \n");
                break;
            }
            else
            {
                invalido = 0;
            }
        }
    }
    while (invalido);
    //elimino saltos de linea//
    int len = strlen(auxiliar);

    if(auxiliar[len-1]=='\n')
    {

        auxiliar[len-1]='\0';

    };
    strcpy(var_dondeAsignar,auxiliar);
    return;
}


void f_i_PedirStringSoloLetras(char var_dondeAsignar[],int longitudMaxString,char mensaje[])
{

    char aux[longitudMaxString];
    int esSoloLetras=1;
    int i=0;
    printf("\n%s\n",mensaje);

    do
    {
        fflush(stdin);
        fgets(aux,longitudMaxString,stdin);
        for (i=0; i<strlen(aux)-1; i++)
        {
            if((aux[i] != ' ') && (aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z'))
            {
                esSoloLetras = 0;
                printf("\nError, ingrese solo Letras y Espacios\n");
                printf("\n%s\n",mensaje);
                break;
            }
            else
            {
                esSoloLetras=1;
            };
        };
    }
    while (esSoloLetras == 0 );


    //Elimino salto de linea//
    int len = strlen(aux);
    if(aux[len-1] =='\n')
    {
        aux[len-1]='\0';
    };

    strcpy(var_dondeAsignar,aux);
    return;
}


void f_i_PedirStringSoloFloat(char var_dondeAsignar[],int longitudMaxString,char mensaje[])
{
    //acordate de atof()

    char aux[longitudMaxString];
    int i=0;
    int cantidadPuntos;
    int invalido;

    do
    {
        fflush(stdin);
        invalido = 0;
        cantidadPuntos=0;
        printf("\n%s\n",mensaje);
        fgets(aux,longitudMaxString,stdin);

        for (i=0; i<strlen(aux)-1; i++)
        {
            if (aux[i] == '.')
            {
                cantidadPuntos++;
            };

            if( (aux[i] < '0' && aux[i] != '.' ) || (aux[i] > '9'&& aux[i] != '.') || (aux[0] == '.') || (cantidadPuntos > 1) )
            {
                printf("**\nError, ingrese un numero (con un punto separando el decimal si no es un entero)**\n");
                invalido = 1;
                break;
            };
        }
    }
    while (invalido==1);

    strcpy(var_dondeAsignar,aux);

    return;
}


void f_i_PedirStringAlfaNumerico(char var_dondeAsignar[],int longitudMaxString,char mensaje[])
{
    char aux[longitudMaxString];
    int esAlfaNumerico = 1;
    int i = 0;
    printf("\n%s\n",mensaje);

    do
    {
        fflush(stdin);
        fgets(aux,longitudMaxString,stdin);
        for (i=0; i<strlen(aux)-1; i++)
        {
            if((aux[i] != ' ') && (aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z') && (aux[i] < '0' || aux[i] > '9'))
            {
                esAlfaNumerico = 0;
                printf("\nError, ingrese solo Letras , Numeros y Espacios\n");
                printf("\n%s\n",mensaje);
                break;
            }
            else
            {
                esAlfaNumerico = 1;
            };
        };
    }
    while (esAlfaNumerico == 0 );

    //Elimino salto de linea//
    int len = strlen(aux);
    if(aux[len-1] =='\n')
    {
        aux[len-1]='\0';
    };

    strcpy(var_dondeAsignar,aux);
    return;
}


void f_i_PedirPatenteVieja(char var_DondeAsignar[], char mensaje[])
{
    char aux_Patente[10];
    int i, len;
    int taMal = 0;

    do
    {

        if (taMal == 1 )
        {
            printf("\nIngrese una patente de este formato > \"AAA 123\"");
        }

        taMal=0;

        printf("\n%s", mensaje);

        fflush(stdin);

        f_i_PedirStringAlfaNumerico( aux_Patente, 10,"");

        strupr(aux_Patente);

        len = (strlen(aux_Patente));

        for (i=0 ; i<3 ; i++)
        {
            if( (aux_Patente[i] < 'A' || aux_Patente[i] > 'Z') )
            {
                taMal = 1;
                break;
            };
        };

        if (aux_Patente [3]!= ' ')
        {
            taMal = 1;
        }

        for (i=4 ; i<7 ; i++)
        {
            if( (aux_Patente[i] < '0' || aux_Patente[i] > '9') )
            {

                taMal = 1;

                break;
            };
        };

        if (len>7)
        {
            taMal = 1;
        };

    }
    while (taMal == 1);



    if(aux_Patente[len]=='\n');
    {

        aux_Patente[len]='\0';

    };


    strcpy(var_DondeAsignar, aux_Patente);
    return ;

}

void f_i_PedirEmail (char var_dondeAsignar [], int longitudMaxString, char mensaje [] )
{

    int cantidadArrobas, cantidadPuntos, pusoArroba;
    int i;
    int invalido;
    char auxiliar[longitudMaxString];
    do
    {

        cantidadArrobas = 0, cantidadPuntos = 0, invalido = 0, pusoArroba = 0;
        fflush(stdin);
        printf("%s\n",mensaje);
        fgets(auxiliar,longitudMaxString,stdin);
        strlwr(auxiliar);

        for (i=0 ; i<strlen(auxiliar)-1 ; i++)
        {

            if (auxiliar[i] == ' ')
            {
                invalido = 1;
                break;
            };

            if (i==0 && (auxiliar[i] == '@' || auxiliar[i] == '.'))
            {
                invalido = 1;
                break;
            };

            if ( ((auxiliar[i] < 'a' || auxiliar[i] > 'z') && (auxiliar[i]<'0' || auxiliar[i]>'9')) && (auxiliar[i] != '@') && (auxiliar[i] != '.') && (auxiliar[i] != '_') && (auxiliar[i] =! '-')  )
            {
                invalido=1;
                break;
            };

            if (auxiliar[i] == '@')
            {
                if (cantidadArrobas >= 1)
                {
                    invalido=1;
                    break;
                };
                pusoArroba = 1;
                cantidadArrobas ++;
            };

            if (auxiliar[i] == '.')
            {

                if (cantidadPuntos >= 1 || pusoArroba == 0)
                {
                    invalido = 1;
                    break;
                };
                cantidadPuntos ++;
            };

        } // for

        if(cantidadPuntos == 0 || pusoArroba == 0)
        {
            invalido = 1;
        };

        if ( invalido == 1 )
        {
            printf("\n*Mail invalido*\n");
        };

    }
    while (invalido == 1);

    //elimino saltos de linea//
    int len = strlen(auxiliar);

    if(auxiliar[len-1]=='\n')
    {

        auxiliar[len-1]='\0';
    };

    strcpy(var_dondeAsignar, auxiliar);

    return;
}


void f_i_PedirTelefono (char var_dondeAsignar[], int longitudMaxString, char mensaje[])
{

    int i;
    int invalido;
    char auxiliar[longitudMaxString];
    int len;

    do
    {

        invalido = 0;
        fflush(stdin);
        printf("%s\n",mensaje);
        fgets(auxiliar,longitudMaxString,stdin);
        len = (strlen(auxiliar)-1);

        if ( ( len < 8 ) || (len > longitudMaxString) )
        {
            invalido = 1;
        }
        else
        {

            for (i=0; i<strlen(auxiliar)-1; i++)
            {
                if (auxiliar[i]<'0' || auxiliar[i]>'9')
                {
                    invalido = 1;
                    break;
                };

            };
        };

        if (invalido == 1)
        {
            printf("\n*Telefono Invalido*\n");

        }

    }
    while (invalido == 1);

    //elimino saltos de linea//

    len = (strlen(auxiliar));

    if(auxiliar[len-1]=='\n')
    {

        auxiliar[len-1]='\0';

    };

    strcpy(var_dondeAsignar,auxiliar);

    return;
}


void f_i_PedirSexo(char * var_dondeAsignar, char mensaje[])
{
    char r;
    printf("%s",mensaje);
    printf( "\n --F-- o --M-- \n");
    fflush(stdin);
    r = toupper(getche());
    while ( !((r=='F')||(r=='M')) )
    {

        printf ("\nError, ingrese (F/M)... \n");
        fflush(stdin);
        r = toupper(getche());
    };
    *var_dondeAsignar=r;
    return;
}


void f_i_PedirEdad (int * var_dondeAsignar,char mensaje[])
{
    int edad;
    fflush(stdin);
    printf("\n%s:\n",mensaje);
    scanf("%d",&edad);

    while (edad>99 || edad<0)
    {
        fflush(stdin);
        printf("\n**Edad Invalida**\n%s",mensaje);
        scanf("%d",&edad);
    };

    *var_dondeAsignar=edad;

    return;
}



void pedirFecha (int *dia, int* mes, int *anyo,char diaEnQue[],char mesEnQue[],char anyoEnQue[])
{

    int aux;

    do
    {
        aux=-1;
        fflush(stdin);
        printf("\nIngrese el dia en que %s:\n",diaEnQue);
        scanf("%d", &aux);

        if (aux > 31 || aux < 1)
        {
            printf("\n**Error, dia invalido**");
        };

    }
    while (aux > 31 || aux < 1);
    *dia=aux;

    do
    {
        aux=-1;
        fflush(stdin);
        printf("\nIngrese el mes en que %s (1 al 12):\n",mesEnQue);
        scanf("%d", &aux);

        if (aux > 12 || aux < 1)
        {
            printf("\n**Error, mes invalido**");
        };
    }
    while (aux > 12 || aux < 1);

    * mes = aux;

    do
    {
        aux=-1;
        fflush(stdin);
        printf("\nIngrese el anyo en que %s:\n",anyoEnQue);
        scanf("%d", &aux);

        if (aux > 2050 || aux < 1900)
        {
            printf("\n**Error, anyo invalido**");
        };
    }
    while (aux > 2050 || aux < 1900);

    * anyo = aux;

    return ;
}



int f_i_SioNo(char mensaje[])
{
    char r;
    printf("\n%s\n",mensaje);
    printf( "\n --S-- o --N-- \n");
    fflush(stdin);
    r = toupper(getche());
    printf("\n");

    while ( !((r=='S')||(r=='N')) )
    {
        printf ("\nError, ingrese (S/N)... \n");
        fflush(stdin);
        r = toupper(getche());
        printf("\n");
    };
    return (r=='S'); /*Devuelve 1 si se ingresa 'S'*/
}


void f_i_continuar(void)
{
    printf("\n\nPresione una tecla para continuar.\n");
    fflush(stdin);
    getch();
    return;
}


/*Funciones para otras funciones y general*/


void limpiar (void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void esperar (int ms)
{
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms*1000);
#endif
}


void noVeo (void)
{
    //system("color 0F");
    system("color F0");
}

/*Funciones de ordenamiento*/


void f_o_IniciarArrayInt (int var_dondeAsignar[],int asignarleEsteNumero,int cantidadElementos)
{
    int i;
    for (i=0; i<cantidadElementos; i++)
    {
        var_dondeAsignar[i]= asignarleEsteNumero;
    };
    return;
}


void f_o_IniciarArrayIntIncremental(int var_dondeAsignar[],int cantidadElementos)
{
    int i;
    for (i=0; i<cantidadElementos; i++)
    {

        var_dondeAsignar[i]= i+1;

    };
    return;
}


int f_o_BuscarIndicePrimerOcurrencia (int var_dondeAsignar[],int cantidadElementos,int indicadorPrimerOcurrencia)
{

    int i;
    for (i=0; i<cantidadElementos; i++)
    {

        if (var_dondeAsignar[i]==indicadorPrimerOcurrencia)
        {

            return i;

        };

    };
    return -1;
}


void f_o_OrdernarArrayMayorAMenor (int var_dondeAsignar[],int cantidadElementos)
{

    int i, j, aux;
    for(i=0; i<cantidadElementos-1; i++)
    {
        for(j=0; j<cantidadElementos-1; j++)
        {
            if(var_dondeAsignar[j] < var_dondeAsignar[j+1])
            {
                aux = var_dondeAsignar[j];
                var_dondeAsignar[j] = var_dondeAsignar[j+1];
                var_dondeAsignar[j+1] = aux;
            };
        };
    };
    return;
}


void f_o_OrdernarArrayMenorAMayor (int var_dondeAsignar[], int cantidadElementos)
{
    int i, j;
    int tmp;

    for (i = 1; i < cantidadElementos; i++)
    {
        tmp = var_dondeAsignar[i];
        j = i - 1;

        while ((j >= 0) && (tmp < var_dondeAsignar[j]))
        {

            var_dondeAsignar[j + 1] = var_dondeAsignar[j];
            j--;
        };

        var_dondeAsignar[j + 1] = tmp;

    };
}


void f_o_OrdenarArrayAlfabeticamente(int cantidadElementos,int longitudMaxString,
                                     char var_dondeAsignar[cantidadElementos][longitudMaxString])
{

    char auxiliar[longitudMaxString];

    int i,j;

    for(i=0; i<cantidadElementos-1; i++)
    {
        for(j=i+1; j<cantidadElementos; j++)
        {
            if(strcmp( var_dondeAsignar[i],var_dondeAsignar[j])>0)
            {
                strcpy(auxiliar,var_dondeAsignar[j]);
                strcpy(var_dondeAsignar[j], var_dondeAsignar[i]);
                strcpy(var_dondeAsignar[i], auxiliar);
            };
        };
    };
    return;
}


void f_o_ArreglarCaps (int cantidadElementos,int longitudMaxString,
                       char var_dondeAsignar[cantidadElementos][longitudMaxString])
{
    int i=0;
    for (i=0; i<cantidadElementos; i++)
    {
        strlwr(var_dondeAsignar[i]);
        var_dondeAsignar[i][0]= toupper(var_dondeAsignar[i][0]);
    };
    return;
}


