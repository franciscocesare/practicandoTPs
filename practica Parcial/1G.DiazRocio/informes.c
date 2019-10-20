#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "categoria.h"
#include "juego.h"
#include "clientes.h"
#include "alquileres.h"
#include "informes.h"

int menuInformes()
{
    int opcion;

    system("cls");
    printf("  ***  MENU DE INFORMES ***   \n\n");
    printf("1. Mostrar juegos de categoria mesa\n");
    printf("2. Mostrar alquileres efectuados por algun cliente\n");
    printf("3. Mostrar total de todos los importes pagados por el cliente seleccionado\n");
    printf("4. Listar clientes que no alquilaron juegos\n");
    printf("5. Listar juegos que no han sido alquilados\n");
    printf("6. Atras\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void mostrarAlquilerPorCliente(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,
                               eCategoria cat[],int tamC, eJuego juegos[],int tamJ)
{

    int idCliente;
    int esta;

    mostrarClientes(cliente,tamC);
    getIntRange(&idCliente,1000,9999,"Ingrese id de cliente: ");

    esta=buscarClienteId(cliente,tamC,idCliente);

    while(esta==-1)
    {
        getIntRange(&idCliente,1000,9999,"Ingrese id de cliente valido: ");

        esta=buscarClienteId(cliente,tamC,idCliente);

    }
    if(esta != -1)
    {
        system("cls");

        printf("  ID         JUEGO               CLIENTE               FECHA_ALQUILER\n\n");

        for(int i=0; i<tamAl; i++)
        {
            if(alq[i].idCliente == idCliente && alq[i].isEmpty == 0)
            {
                mostrarAlquiler(alq[i],juegos,tamJ,cliente,tamC);
            }
        }

        printf("\n\nAlquileres dados a cliente numero %d",idCliente);
    }

}


void mostrarImporteCliente(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,
                           eCategoria cat[],int tamC, eJuego juegos[],int tamJ)
{

    int idCliente;
    int esta;
    float total;

    mostrarClientes(cliente,tamC);
    getIntRange(&idCliente,1000,9999,"Ingrese id de cliente: ");

    esta=buscarClienteId(cliente,tamC,idCliente);

    while(esta==-1)
    {
        getIntRange(&idCliente,1000,9999,"Ingrese id de cliente valido: ");

        esta=buscarClienteId(cliente,tamC,idCliente);

    }
    if(esta != -1)
    {
        system("cls");


        mostrarJuegos(juegos,tamJ,cat,tamC);
        printf("\n\n");

        for(int i=0; i<tamAl; i++)
        {
            if(alq[i].idCliente == idCliente && alq[i].isEmpty == 0)
            {
                mostrarAlquiler(alq[i],juegos,tamJ,cliente,tamC);

                for(int j=0; j<tamJ; j++)
                {
                    if(juegos[j].codigo == alq[i].idJuego)
                    {
                        total+=(float)juegos[j].importe;
                    }
                }
            }
        }

        printf("\n\nImporte total del cliente %.2f",total);
    }

}

void mostrarJuegosMesa(eJuego juego[], int tamJ,eCategoria cat[], int tamC)
{
    char cate[21];

    system("cls");
    printf(" ID    DESCRIPCION     IMPORTE     CATEGORIA\n\n");

    for(int i=0; i<tamJ; i++)
    {
        for(int j=0; j<tamC; j++)
        {
            if(juego[i].idCategoria == cat[j].id)
            {
                obtenerNomCat(cat,tamC,juego[i].idCategoria,cate);

                if(strcmpi(cate,"mesa")==0)
                {

                    mostrarJuego(juego[i],cat,tamC);
                }
            }
        }
    }

}






