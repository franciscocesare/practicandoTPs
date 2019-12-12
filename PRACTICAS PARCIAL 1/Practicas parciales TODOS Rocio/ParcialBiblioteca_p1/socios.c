#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "socios.h"
#include "inputDiaz.h"

int hardCodeSocios (eSocio lista[],int tam, int cant)
{
    int cont=0;
    eSocio ejemplo[]=
    {
        {100, "Pamela ", "Subizar",'F', "11111111","Pamela@gmail.com",{27,6,2016},0},
        {101, "Martina", "Sosa",'F', "18001210", "Martina@gmail.com",{5,7,2014},0},
        {102, "Benjamín", "Garcia",'M', "324234342", "Benjamín@gmail.com",{8,15,2018},0},
        {103, "Sofia", "Flores",'F',"32324342", "Sofia@gmail.com",{6,6,2015},0},
        {104, "Juan Ignacio", "Acosta",'M', "67555656", "Juan@gmail.com",{12,5,2013}, 0},
        {105, "Thiago ", "Suarez",'M'," 36663636","Thiago@gmail.com",{22,15,2019}, 0},
        {106, "Valentina", "Garcia",'F'," 2622262", "Valentina@gmail.com",{26,17,2018},0},
        {107, "Romina", "Ruiz",'F', "262444445","Romina@gmail.com",{11,26,2010}, 0},
        {108, "Antonio", "Garcia",'M', "8798978905","Antonio@gmail.com",{20,7,2016}, 0},
        {109, "Julieta", "Villalba",'F', "456546545", "JulietaV@gmail.com",{2,10,2013},0}
    };

    if(cant <= tam && cant >=10)
    {
        for(int i=0; i <tam; i++)
        {
            lista[i] = ejemplo[i];
            cont++;
        }
    }

    return cont;
}

void iniciarlizarSocios(eSocio vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}

int buscarLibreSocio(eSocio vec[], int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void mostrarSocio(eSocio socio)
{
    printf(" %d  %12s   %10s         %c          %10s    %20s     %02d/%02d/%d\n",socio.id,socio.Apellido,
           socio.nombre,socio.sexo,socio.telefono,socio.mail,socio.asociado.dia,
           socio.asociado.mes,socio.asociado.anio);
}

void mostrarSocios(eSocio vec[],int tam)
{
    int cont=0;

    system("cls");
    printf(" ID        NOMBRE        APELLIDO      SEXO          TELEFONO           MAIL           FECHA_ASOCIADO\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarSocio(vec[i]);
            cont++;
        }
    }

    if(cont ==0)
    {
        printf("\nNo hay socios para mosrar\n\n");
    }

}

void ordenarSocios(eSocio vec[], int tam)
{
    eSocio aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmpi(vec[i].Apellido,vec[j].Apellido) >0)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
            else
            {
                if(strcmpi(vec[i].Apellido,vec[j].Apellido)==0 && strcmpi(vec[i].nombre,vec[j].nombre) >0)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }
    }
}

int buscarSocioId(eSocio vec[], int tam, int codigo)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty ==0 && vec[i].id==codigo)
        {
            indice=i;
            break;
        }
    }


    return indice;
}

void bajaSocio(eSocio vec[], int tam)
{
    int indice;
    int codigo;
    int confirma;

    mostrarSocios(vec,tam);

    getIntRange(&codigo,100,999,"Ingrese codigo de socio: ");

    indice=buscarSocioId(vec,tam,codigo);

    while(indice == -1)
    {
        getIntRange(&codigo,100,999,"Ingrese codigo de socio: ");

        indice=buscarSocioId(vec,tam,codigo);
    }
    if(indice !=-1)
    {
        system("cls");
        mostrarSocio(vec[indice]);

        confirma=confimarSalir("\nDesea dar de baja este socio? s/n: ");

        if(confirma==1)
        {
            vec[indice].isEmpty=1;
            printf("\nOperacion realizada.\n\n");
        }
        else
        {
            printf("\nOperacion cancelada.\n\n");
        }

    }
}

int altaSocio(eSocio vec[],int tam,int codigo)
{
    int todoOk=0;
    int indice;

    system("cls");
    printf("*** MENU DE ALTA ***\n\n");

    indice=buscarLibreSocio(vec,tam);

    if(indice ==-1)
    {
        printf("\nNo hay mas espacio en el sistema\n\n");
    }
    else
    {
        vec[indice].id=codigo;
        getStringAlpha(31,"Ingrese nombre: ",vec[indice].nombre);
        getStringAlpha(31,"Ingrese apellido: ",vec[indice].Apellido);
        getSexo(&vec[indice].sexo,"Ingrese sexo: f/m: ");
        pedirTelefono(vec[indice].telefono,16,"Ingrese numero telefono: ");
        pedirEmail(vec[indice].mail,31,"Ingrese mail: ");
        getIntRange(&vec[indice].asociado.dia,1,31,"Ingrese dia de asociacion: ");
        getIntRange(&vec[indice].asociado.mes,1,12,"Ingrese mes de asociacion: ");
        getIntRange(&vec[indice].asociado.anio,2019,2020,"Ingrese anio de asociacion: ");

        vec[indice].isEmpty=0;

        printf("\nSocio dado de alta con exito\n\n");
        todoOk=1;
    }

    return todoOk;
}

int menuModificacion()
{
    int opcion;

    system("cls");

    printf("*** MENU DE MODIFICACION ***\n\n");
    printf("1_ Apellido\n");
    printf("2_ Nombre\n");
    printf("3_ Sexo\n");
    printf("4_ Telefono\n");
    printf("5_ Mail\n\n");
    printf("6_ Atras\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void modificarSocio(eSocio vec[],int tam)
{
    int atras;
    int indice;
    int codigo;
    int confirma;

    mostrarSocios(vec,tam);

    getIntRange(&codigo,100,999,"Ingrese id del socio a modificar: ");
    indice=buscarSocioId(vec,tam,codigo);

    while(indice == -1)
    {
        getIntRange(&codigo,100,999,"Ingrese id valido del socio a modificar: ");
        indice=buscarSocioId(vec,tam,codigo);
    }
    if(indice != -1)
    {
        system("cls");
        mostrarSocio(vec[indice]);

        confirma=confimarSalir("\nModificar este socio?: ");

        if(confirma == 1)
        {
            do
            {
                switch(menuModificacion())
                {
                case 1 :
                    getStringAlpha(31,"Ingrese nuevo nombre: ",vec[indice].nombre);
                    break;

                case 2 :
                    getStringAlpha(31,"Ingrese nuevo apellido: ",vec[indice].Apellido);
                    break;

                case 3 :
                    getSexo(&vec[indice].sexo,"Ingrese nuevo sexo: f/m: ");
                    break;

                case 4 :
                    pedirTelefono(vec[indice].telefono,16,"Ingrese nuevo numero telefono: ");
                    break;

                case 5 :
                    pedirEmail(vec[indice].mail,31,"Ingrese mail: ");
                    break;

                case 6 :
                    atras=confimarSalir("\nVolver al menu de opciones? s/n: ");
                    break;

                default:
                    printf("\nOpcion invalida\n\n");
                }

            }
            while(atras != 1);
        }
        else
        {
            printf("\nOperacion cancelada\n\n");
        }

    }


}

void obtenerNomSocio(eSocio vec[],int tam, int id, char dondeAsignar[])
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0 && vec[i].id == id)
        {
            strcpy(dondeAsignar,vec[i].Apellido);
            strcat(dondeAsignar,", ");
            strcat(dondeAsignar,vec[i].nombre);
        }

    }
}



