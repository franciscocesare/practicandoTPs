#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputDiaz.h"
#include "clientes.h"
/*
int harcodearVuelos(eVuelo vecVue[], int tamVue, int cant)///tiene que tener de estado CHAR
{
    int cont=0;
    eVuelo Vuelos[]=
    {
        {1000,1,100,14,19,"activo",0},
        {1001,3,102,12,15,"suspendido",0},
        {1002,2,103,13,23,"cancelado",0},
        {1003,4,101,10,19,"demorado",0},
        {1004,3,102,16,19,"activo",0},

   if(cant<= tamVue && cant<=5)
   {
       for(int i=0; i<tamVue; i++)
        {
        vecVue[i]=Vuelos[i];
        cont++;
        }
   }

    return cont;
}
*/

void harcodearPilotos(ePiloto vecPil[], int tamPil)
{
    ePiloto Pilotos[]=
    {
        {100,"LAUTARO ACOSTA"},
        {101,"PEPE SAND"},
        {102,"MARCELINO MORENO"},
        {103,"PEPO DE LA VEGA"},
        {104,"DIEGO VALERI"},

    };

    for(int i=0; i<tamPil; i++)
    {
        vecPil[i]=Pilotos[i];
    }
}

/*void inicializarClientes(eCliente vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}
*/
/*int buscarLibrePiloto(ePiloto vecPil[],int tamPil)
{
    int indice=-1;

    for(int i=0; i<tamPil; i++)
    {
        if(vecPil[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
*/
void mostrarPiloto(ePiloto vecPil)

{
        printf(" %2d  %17s  \n",vecPil.idPiloto,vecPil.nombre);

    ///printf(" %2d  %10s  %10s         %c      %10s      %10s\n",vec.id,vec.nombre,vec.apellido,
           ///vec.sexo,vec.telefono,vec.domicilio);
}

void mostrarPilotos(ePiloto vecPil[], int tamPil)
{

    printf(" ID     NOMBRE     \n\n");

    for(int i=0; i<tamPil; i++)
    {
        ordenarPilotos(vecPil, tamPil);
        mostrarPiloto(vecPil[i]);
        /*if(vec[i].isEmpty==0)
        {
            mostrarCliente(vec[i]);
            cont++;
        }*/
    }

    /*if(cont==0)
    {
        printf("\nNo hay clientes en el sistema\n\n");
    }
    */
}

/*int altaCliente(eCliente vec[], int tam,int id)
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
*/

/*
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
        getIntRange(&id,1000,9999,"Ingrese id de cliente valido: ");

        indice=buscarClienteId(vec,tam,id);

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
*/

void ordenarPilotos(ePiloto vecPil[], int tamPil)
{
    ePiloto aux;

    for(int i=0; i<tamPil-1; i++)
    {
        for(int j=i+1; j<tamPil; j++)
        {
            if(strcmpi(vecPil[i].nombre,vecPil[j].nombre)>0)
            {
                aux=vecPil[i];
                vecPil[i]=vecPil[j];
                vecPil[j]=aux;
            }
        }
    }
}

/*int menuModificacion()
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
*/


/*void modificarCliente(eCliente vec[], int tam)
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
*/


void obtenerNomPiloto(ePiloto vecPil[], int tamPil, int id, char dondeAsigar[])
{
    for(int i=0; i<tamPil; i++)
    {
        if(vecPil[i].idPiloto == id)
        {
            strcpy(dondeAsigar,vecPil[i].nombre);
            /*strcat(dondeAsigar,", ");
            strcat(dondeAsigar,vec[i].nombre);*/
        }
    }
}


