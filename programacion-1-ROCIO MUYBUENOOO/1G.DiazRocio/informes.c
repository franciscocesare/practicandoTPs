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

/** \brief muestra el importe total de los alquileres efectuados por un cliente seleccionado
 *
 * \param estructura cliente
 * \param tamanio de estrcutura cliente
 * \param estructura alquiler
 * \param tamanio de estrcutura alquiler
 * \param estructura categorias
 * \param tamanio de estrcutura categorias
 * \param estructura juegos
 * \param tamanio de estrcutura juegos
 * \return sin retorno
 *
 */
void mostrarImporteCliente(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,
                           eCategoria cat[],int tamC, eJuego juegos[],int tamJ)
{

    int idCliente;
    int esta;
    int cont=0;
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


        printf("Alquileres de cliente numero %d: \n\n",idCliente);

        for(int i=0; i<tamAl; i++)
        {
            if(alq[i].idCliente == idCliente && alq[i].isEmpty == 0)
            {
                mostrarAlquiler(alq[i],juegos,tamJ,cliente,tamC);

                for(int j=0; j<tamJ; j++)
                {
                    if(juegos[j].codigo == alq[i].idJuego)
                    {
                        total=total+juegos[j].importe;
                        cont++;

                    }
                }
            }
        }

        if(cont == 0)
        {
            system("cls");
            printf("\nEste cliente no posee ningun alquiler");
        }
        else
        {
            printf("\n\nImporte total del cliente %.2f",total);
        }


    }

}

int mostrarAlquileresClientes(int idCliente,eAlquiler vec[],int tamAl)
{
    int alquiler=0;

    for(int i=0; i<tamAl; i++)
    {
        if(vec[i].isEmpty==0 && vec[i].idCliente == idCliente)
        {
            alquiler=1;
        }
    }

    return alquiler;
}

void clientesSinAlquiler(eCliente vecCl[],int tamCl, eAlquiler vecAl[],int tamAl)
{
    int cont=0;

    system("cls");
    printf("Clientes sin alquileres:\n\n");

    for(int i=0; i<tamCl; i++)
    {
        if(mostrarAlquileresClientes(vecCl[i].id,vecAl,tamAl)==0)
        {
            mostrarCliente(vecCl[i]);
            cont++;
        }

    }

    if(cont==0)
    {
        printf("\nNo hay clientes sin alquileres");
    }

}

int mostrarJuegosAlquilados(int idJuego,eAlquiler vec[],int tam)
{
    int alquiler=0;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0 && vec[i].idJuego == idJuego)
        {
            alquiler=1;
        }
    }

    return alquiler;
}


void juegosSinAlquiler(eJuego vecJ[],int tamJ, eAlquiler vecAl[],int tamAl, eCategoria vecCa[], int tamCa)
{
    int cont=0;

    system("cls");
    printf("Juegos sin alquileres:\n\n");

    for(int i=0; i<tamJ; i++)
    {
        if(mostrarJuegosAlquilados(vecJ[i].codigo,vecAl,tamAl)==0)
        {
            mostrarJuego(vecJ[i],vecCa,tamCa);
            cont++;
        }

    }

    if(cont == 0)
    {
        printf("\nNo hay juegos que no hayan sido alquilados");
    }

}






