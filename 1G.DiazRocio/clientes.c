#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputDiaz.h"
#include "clientes.h"

int harcodearClientes(eCliente vec[], int tam, int cant)
{
    int cont=0;
    eCliente clientes[]=
    {
        {1000,"juan","gomez",'m',"111111","mitre 451",0},
        {1001,"ana","perez",'f',"22222","alsina 415",0},
        {1002,"cristian","diaz",'m',"33333","mansilla 41",0},
        {1003,"abril","saa",'f',"44444","mitre 4564",0},
        {1004,"camila","rodriguez",'f',"55555","sarandi 2562",0},
        {1005,"lucas","sosa",'m',"66666","salvador 52",0}

    };

   if(cant<= tam && cant<=6)
   {
       for(int i=0; i<tam; i++)
        {
        vec[i]=clientes[i];
        cont++;
        }
   }

    return cont;
}
void inicializarClientes(eCliente vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}

int buscarLibreCliente(eCliente vec[],int tam)
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

void mostrarCliente(eCliente vec)
{

    printf(" %2d  %10s  %10s         %c      %10s      %10s\n",vec.id,vec.nombre,vec.apellido,
           vec.sexo,vec.telefono,vec.domicilio);
}

void mostrarClientes(eCliente vec[], int tam)
{
    int cont=0;

    system("cls");
    printf(" ID         NOMBRE       APELLIDO      SEXO      TELEFONO      DOMICILIO\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarCliente(vec[i]);
            cont++;
        }
    }

    if(cont==0)
    {
        printf("\nNo hay clientes en el sistema\n\n");
    }
}

int altaCliente(eCliente vec[], int tam,int id)
{
    int todoOk=0;
    int indice;

    system("cls");
    printf("  *** MENU ALTA CLIENTE ***  \n\n");

    indice=buscarLibreCliente(vec,tam);

    if(indice==-1)
    {
        printf("\nNo hay espacio disponible\n\n");
    }
    else
    {
        vec[indice].id=id;
        getStringAlpha(51,"Ingrese nombre: ",vec[indice].nombre);
        getStringAlpha(51,"Ingrese apellido: ",vec[indice].apellido);
        getSexo(&vec[indice].sexo,"Ingrese sexo f/m: ");
        pedirTelefono(vec[indice].telefono,21,"Ingrese telefono: ");
        getStringAlphaNum(51, "Ingrese domicilio con numero: ",vec[indice].domicilio);

        vec[indice].isEmpty=0;
        todoOk=1;
        printf("\nAlta realizada con exito\n\n");
    }

    return todoOk;
}

int buscarClienteId(eCliente vec[], int tam, int id)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0 && vec[i].id==id)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void bajaCliente(eCliente vec[], int tam)
{
    int confirma;
    int indice;
    int id;

    mostrarClientes(vec,tam);

    getIntRange(&id,1000,9999,"Ingrese id del cliente: ");

    indice=buscarClienteId(vec,tam,id);

    if(indice==-1)
    {
        /*getIntRange(&id,1000,9999,"Ingrese id de cliente valido: ");

        indice=buscarClienteId(vec,tam,id);*/

        printf("\nEl id ingresado es incorrecto\n\n");
    }
    if(indice !=-1)
    {
        confirma=confimarSalir("\n\nDar de baja cliente? s/n: ");

        if(confirma==1)
        {
            vec[indice].isEmpty=1;
            printf("\nOperacion realizada\n\n");
        }
        else
        {
            printf("\nOperacion cancelada\n\n");
        }
    }

}

void ordenarCliente(eCliente vec[], int tam)
{
    eCliente aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmpi(vec[i].apellido,vec[j].apellido)>0)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
            else
            {
                if(strcmpi(vec[i].apellido,vec[j].apellido)==0 && strcmpi(vec[i].nombre,vec[j].nombre)>0)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }
    }
}

int menuModificacion()
{
    int opcion;

    system("cls");
    printf("  ***  MENU DE MODIFICACION ***   \n\n");
    printf("1. Nombre\n");
    printf("2. Domicilio\n");
    printf("3. Telefono\n");
    printf("4. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void modificarCliente(eCliente vec[], int tam)
{
    int indice;
    int atras;
    int id;

    mostrarClientes(vec,tam);

    getIntRange(&id,1000,9999,"Ingrese id del cliente: ");

    indice=buscarClienteId(vec,tam,id);

    while(indice==-1)
    {
        getIntRange(&id,1000,9999,"Ingrese id de cliente valido: ");

        indice=buscarClienteId(vec,tam,id);
    }
    if(indice !=-1)
    {
        do
        {
            switch(menuModificacion())
            {
            case 1:
                getStringAlpha(51,"Ingrese nombre: ",vec[indice].nombre);
                break;

            case 2:
                getStringAlphaNum(51, "Ingrese domicilio con numero: ",vec[indice].domicilio);
                break;

            case 3:
                pedirTelefono(vec[indice].telefono,21,"Ingrese telefono: ");
                break;

            case 4:
                atras=confimarSalir("Volver al menu de opciones? s/n: ");
                break;
            }

        }
        while(atras != 1);
    }
}

void obtenerNomCliente(eCliente vec[], int tam, int id, char dondeAsigar[])
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].id == id)
        {
            strcpy(dondeAsigar,vec[i].apellido);
            strcat(dondeAsigar,", ");
            strcat(dondeAsigar,vec[i].nombre);
        }
    }
}

