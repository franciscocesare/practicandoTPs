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
    printf("1. Todos los Vuelos de un Piloto Seleccionado\n");
    printf("2. Todos los pilotos que volaron a un destino especifico\n");
    printf("3. Recaudacion por cada Piloto\n");
    printf("4. Destino mas elegido\n");
    printf("5. Atras\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

/*void mostrarJuegosMesa(eJuego juego[], int tamJ,eCategoria cat[], int tamC)///RECIBE Y VINCULA ARRAY DE JUEGOS Y DE CATEGGORIAS
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
*/


void vuelosPilotoSeleccionado(eVuelo vuelos[], int tamVue, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDest)
{
    int flag=0;

    int idPiloto;

    mostrarPilotos(pilotos, tamPil);

    getIntRange(&idPiloto,100,110, "INGRESE EL ID PILOTO PARA VER SUS VUELOS\n");
    system("cls");
    printf("\n\nELIGIO: %d \n\n ", idPiloto);

    for (int i=0; i<tamVue; i++)
    {
        if (vuelos[i].idPiloto==idPiloto && vuelos[i].isEmptyVuelos==0)

        {
            printf("\n  ID         PILOTO        DESTINO   PARTIDA / LLEGADA ESTADO\n\n");
            mostrarVuelo(vuelos[i], destinos, tamDest, pilotos, tamPil);
            flag=1;
        }

    }
    if(flag==0)
    {

        printf("NO HAY VUELOS DE ESE PILOTO");
    }


}

//Todos los pilotos que volaron a un destino especifico
void pilotosDestinoSeleccionado(eVuelo vuelos[], int tamVue, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDest)
{
    system("cls");

    int idDestino;
    int idPiloto;
    int flag=0;

    mostrarDestinos(destinos, tamDest);
    getIntRange(&idDestino, 1, 100, "INGRESE EL ID DEL DESTINO PARA VER LOS PILOTOS QUE VOLARON");


    for (int i=0; i<tamVue; i++)
    {
        idPiloto=vuelos[i].idPiloto;
        for (int j=0; j<tamPil; j++)
        {
            if(destinos[i].iDdestino==idDestino&&vuelos[i].idPiloto==pilotos[j].idPiloto)

            {
                printf(" EL PILOTO QUE VIAJO ES: \n\n");
                mostrarPiloto(pilotos[j]);
                flag=1;
            }
        }
    }



    if(flag==0)

    {

        printf("NO HAY VUELOS DE ESE PILOTO");
    }


}

//void ordenarVuelos(eVuelo vue[], int tamVuelo)

/*void destMasElegido2{eDestino[], int Des) ///ordena
{

    eVuelo aux;

        for(int i=0; i<tamVuelo-1; i++){
            for(int j=i+1; j<tamVuelo; j++){
                if(vue[i].idVuelo > vue[j].idVuelo){
                    aux = vue[i];
                    vue[i] = vue[j];
                    vue[j] = aux;
                }
            }
        }
}

*/

///DESTINO MAS ELEGIDO DE MANU

int cantidadDestinos(int idDestino, eVuelo vuelos[], int tamVuelo){

    int contador = 0;

        for(int j=0; j<tamVuelo; j++){
            if(vuelos[j].idDestino == idDestino && vuelos[j].isEmptyVuelos == 0){
                contador++;
            }
        }

    return contador;
}


void destinoMasElegido(eDestino destinos[], int tamDes, eVuelo vuelos[], int tamVuelo){

///recibe el contador

    int cantidad[tamDes];
    int mayor=0;
    int flag=0;

    system("cls");
    printf("***** DESTINO PREFERIDO ******** \n\n");

    for(int i=0; i<tamDes; i++)
    {
        cantidad[i] = cantidadDestinos(destinos[i].iDdestino, vuelos, tamVuelo);
    }

    for(int i=0; i<tamDes; i++)
    {
            if(cantidad[i] > mayor || flag == 0){
                mayor = cantidad[i];
                flag = 1;
            }
    }

        printf("Destino preferido fue elegido %d veces. \n\n", mayor);

        for(int i=0; i<tamDes; i++)
        {
            if(cantidad[i] == mayor){

                printf("ID    MAS ELEGIDO    IMPORTE\n\n");
                mostrarDestino(destinos[i]);
            }
        }
}

///DESTINO MAS ELEGIDO MIO, FUNCIONA MAL

/*void destinoMasElegido(eVuelo vue[], int tamVue,eDestino des[], int tamD)
{

    int flag=0;
    int mayor;
    int destinoMasElegido[tamD];
    int contadorDestino=0;

    for (int i=0; i<tamVue; i++)
    {
        for(int j=0; j<tamD; j++)
        {
            if(vue[i].idDestino == des[j].iDdestino && vue[i].isEmptyVuelos==0 )
            {
                ///+=destino[i].importe;
               contadorDestino ++;
               destinoMasElegido[i]=contadorDestino;
            }
        }

    }
    system("cls");
    printf("***** DESTINO PREFERIDO ******** \n\n");

   // for(int i=0; i<tamD; i++)
    //{
      //  destinoMasElegido[i] = contadorDestino;
    //}

    for(int i=0; i<tamD; i++)
    {
            if(destinoMasElegido[i] > mayor || flag == 0){
                mayor = destinoMasElegido[i];
                flag = 1;
            }
    }

        printf("Destino preferido fue elegido %d veces. \n\n", mayor);

        for(int i=0; i<tamD; i++)
        {
            if(destinoMasElegido[i] == mayor){
                mostrarDestino(des[i]);
            }
        }
}

*/


/// Recaudacion por cada Piloto

void recaudacionPilotoSeleccionado(ePiloto piloto [], int tamPil, eVuelo vuelo [], int tamVue, eDestino destino [], int tamD)

{
    system("cls");

    float recauPiloto=0;
    int idPiloto;
    int flag=0;

    mostrarPilotos(piloto, tamPil);
    getIntRange(&idPiloto, 100, 199, "\n\nINGRESE EL ID DEL PILOTO PARA VER RECAUDACION: \n\n");



    for (int j=0; j<tamVue; j++)
    {
        if(vuelo[j].idPiloto == idPiloto && vuelo[j].isEmptyVuelos==0)
        {
            for(int i=0; i<tamD; i++)
            {

                if(destino[i].iDdestino==vuelo[j].idDestino)
                {
                    recauPiloto+=destino[i].importe;
                    flag ++;
                }
            }
        }

    }
    if (flag==0)

        printf("\n\nESE PILOTO NO RECAUDO\n\n");


    else

        printf("\nEL PILOTO RECAUDO: %.2f \n", recauPiloto);


}

/*
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
*/

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

/*void mostrarImporteCliente(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,
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

*/

/*
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

*/

/*
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


*/

/*

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
*/





