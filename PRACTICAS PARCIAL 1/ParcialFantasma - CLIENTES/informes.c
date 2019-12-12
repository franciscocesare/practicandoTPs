#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "inputDiaz.h"
#include "entidad_1.h"
#include "entidad_2.h"
#include "entidad_3.h"
#include "entidad_4.h"
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

/** \brief muestra solo juegos de Mesa
 *
 * \param estructura juegos
 * \param tamanio de Juegos
 * \param estructura categorias
 * \param tamanio de Categorias
 *
 */
void mostrarJuegosMesa(eJuego juego[], int tamJ,eCategoria cat[], int tamC)
{
    char categoria[21];

    system("cls");
    printf("*******JUEGOS DE CATEGORIA MESA: ******\n\n");
    printf(" IDcat    NOMBRE    IMPORTE     CATEGORIA\n\n");

    for(int i=0; i<tamJ; i++)
    {
        for(int j=0; j<tamC; j++)
        {
            if(juego[i].idCategoria == cat[j].idCategoria)
            {
                obtenerNomCat(cat,tamC,juego[i].idCategoria,categoria);

                if(strcmpi(categoria,"mesa")==0)
                {
                    mostrarJuego(juego[i],cat,tamC);
                }
            }
        }
    }

}

/** \brief muestra los alquileres dados de alta por un cliente seleccionado
 *
 * \param estructura cliente
 * \param tamanio de estrcutura cliente
 * \param estructura alquiler
 * \param tamanio de estrcutura alquiler
 * \param estructura categorias
 * \param tamanio de estrcutura categorias
 * \param estructura juegos
 * \param tamanio de estrcutura juegos
 * \return listado de juegos alquilados por cliente selccionado
 *
 */
void mostrarAlquilerPorCliente(eCliente cliente[],int tam, eAlquileres alq[],int tamAl,
                               eCategoria cat[],int tamC, eJuego juegos[],int tamJ)
{

    int idCliente;
    int esta;

    mostrarClientes(cliente,tamC);
    getIntRange(&idCliente,1000,9999,"Ingrese el id del cliente: ");


    esta=buscarCliente(idCliente, cliente, tamC);

    while(esta==-1)
    {
        getIntRange(&idCliente,1000,9999,"Ingrese id de un cliente: ");


        esta=buscarCliente(idCliente, cliente, tamC);

    }
    if(esta != -1)
    {
        system("cls");
        printf("\n\nEl cliente numero %d Alquilo: \n\n",idCliente);
        printf("  ID  JUEGO     CLIENTE       FECHA_ALQUILER\n\n");

        for(int i=0; i<tamAl; i++)
        {
            if(alq[i].idCliente == idCliente && alq[i].isEmptyAlquiler == 0)
            {
                mostrarAlquiler(alq[i],juegos,tamJ,cliente,tamC);
            }
        }


    }

}

/** \brief muestra el importe total de los alquileres efectuados por un cliente seleccionado, busca por ID
 *
 * \param estructura cliente
 * \param tamanio de estrcutura cliente
 * \param estructura alquiler
 * \param tamanio de estrcutura alquiler
 * \param estructura categorias
 * \param tamanio de estrcutura categorias
 * \param estructura juegos
 * \param tamanio de estrcutura juegos
 * \return VOID, listado de importes por cliente seleccionado
 *
 */
void mostrarImporteCliente(eCliente cliente[],int tam, eAlquileres alq[],int tamAl,
                           eCategoria cat[],int tamC, eJuego juegos[],int tamJ)
{

    int idCliente;
    int esta;
    int cont=0;
    float total;

    mostrarClientes(cliente,tamC);
    getIntRange(&idCliente,1000,9999,"Ingrese id de cliente: ");
    esta=buscarCliente(idCliente, cliente, tamC);

    while(esta==-1)
    {
        getIntRange(&idCliente,1000,9999,"Ingrese id de un cliente : ");
        esta=buscarCliente(idCliente, cliente, tamC);

    }
    if(esta != -1)
    {
        system("cls");

        mostrarJuegos(juegos,tamJ,cat,tamC);
        printf("\n");


        printf("El cliente numero %d alquilo: \n\n",idCliente);
        printf("Id      Juego    Id Cliente    Fecha \n\n");

        for(int i=0; i<tamAl; i++)
        {
            if(alq[i].idCliente == idCliente && alq[i].isEmptyAlquiler == 0)
            {
                mostrarAlquiler(alq[i],juegos,tamJ,cliente,tamC);

                for(int j=0; j<tamJ; j++)
                {
                    if(juegos[j].idJuego == alq[i].idJuego)
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
            printf("\nNO HAY ALQUILERES DEL CLIENTE");
        }
        else
        {
            printf("\n\nImporte total del cliente %.2f \n\n",total);
        }


    }

}

/** \brief muestra clientes con o sin alquileres efectuados, buscando por ID
 *
 * \param id del cliente
 * \param estructura alquiler
 * \param tamanio de estrcutura alquiler
 * \return 1 para mostrar clientes con alquiler, 0 para mostrar clientes sin alquileres
 *
 */
int mostrarAlquileresClientes(int idCliente,eAlquileres vecAlquiler[],int tamAl)
{
    int alquiler=0;

    for(int i=0; i<tamAl; i++)
    {
        if(vecAlquiler[i].isEmptyAlquiler==0 && vecAlquiler[i].idCliente == idCliente)
        {
            alquiler=1;
        }
    }

    return alquiler;
}

/** \brief muestra clientes sin alquileres efectuados
 *
 * \param estructura cliente
 * \param tamanio de estrcutura cliente
 * \param estructura alquiler
 * \param tamanio de estrcutura alquiler
 * \return sin retorno
 *
 */
void clientesSinAlquiler(eCliente vecClientes[],int tamCl, eAlquileres vecAlquiler[],int tamAl)
{
    int cont=0;

    system("cls");
    printf("Clientes que no han alquilado juegos:\n\n");

    for(int i=0; i<tamCl; i++)
    {
        if(mostrarAlquileresClientes(vecClientes[i].idCliente,vecAlquiler,tamAl)==0)
        {
            mostrarCliente(vecClientes[i]);
            cont++;
        }


    }

    if(cont==0)
    {
        printf("\nNo hay clientes sin alquileres");
    }

}

/** \brief muestra juegos con o sin alquileres efectuados
 *
 * \param id del juego
 * \param estructura juegos
 * \param tamanio de estrcutura juegos
 * \return 1 para mostrar juegos con alquiler, 0 para mostrar juegos sin alquileres
 *
 */
int mostrarJuegosAlquilados(int idJuego,eAlquileres vec[],int tam)
{
    int alquiler=0;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmptyAlquiler==0 && vec[i].idJuego == idJuego)
        {
            alquiler=1;
        }
    }

    return alquiler;
}

/** \brief muestra juegos sin alquilear
 *
 * \param estructura Juegos
 * \param tamanio juegos
* \param estructura Alquiler
 * \param tamanio Alquiler
 * \param estructura categorias
 * \param tamanio categorias
 *\return VOID, imprime listado de juegos sin alquilar
 */

void juegosSinAlquiler(eJuego vecJ[],int tamJ, eAlquileres vecAl[],int tamAl, eCategoria vecCa[], int tamCa)
{
    int cont=0;

    system("cls");
    printf("ESTOS JUEGOS NO FUERON ALQUILADOS:\n\n");

    for(int i=0; i<tamJ; i++)
    {
        if(mostrarJuegosAlquilados(vecJ[i].idJuego,vecAl,tamAl)==0)///si no fueron alquilados
        {
            mostrarJuego(vecJ[i],vecCa,tamCa);
            cont++;
        }

    }

    if(cont == 0)
    {
        printf("\nTODOS LOS JUEGOS TUVIERON ALGUN ALQUILER");
    }

}

///informes extras con localidad

/*
void obtenerDatosAlquilerJuego (eJuego juegos[], int tamJuegos, eAlquileres vecAlqui[], int tamAlq, eCategoria cat[], int tamCat,eCliente clientes[], int tamCl)
{
    int idJuego;
    system("cls");
    mostrarJuegos(juegos, tamJuegos, cat, tamCat);

    getIntRange(&idJuego, 100, 105, "\nINGRESE EL ID DEL JUEGO: \n");

    for (int i=0; i<tamAlq; i++)
    {
        if(idJuego==vecAlqui[i].idJuego)

            mostrarDatosAlquilerJuego(vecAlqui[i],clientes, tamCl);

        // mostrarAlquileres(vecAlqui, tamAlq, juegos, tamJuegos, clientes, tamCl);

    }

}


void mostrarDatosAlquilerJuego(eAlquileres alquiler, eCliente clientes[], int tamCl)
{
    char nombre[30];
    char apellido[30];

    for (int i=0; i<tamCl; i++)
    {
        if(alquiler.idCliente==clientes[i].idCliente)
        {
            strcpy(nombre, clientes[i].nombre);
            strcpy(apellido, clientes[i].apellido);
        }
    }
    system("cls");
    printf("\nNOMBRE y APELLIDO CLIENTE            FECHA ALQUILER  \n ");
    printf("%s %10s             %02d/%02d/%d\n ",nombre, apellido, alquiler.fechaAlquiler.dia, alquiler.fechaAlquiler.mes, alquiler.fechaAlquiler.anio);

}

///Clientes de determinada localidad

void clientesDeterminadaLocalidad(eCliente vecClientes[],int tamCl, eLocalidad vecLoc[],int tamLoc)
{
    int auxIdLocalidad;

    system("cls");
    mostrarLocalidades(vecLoc, tamLoc);

    getIntRange(&auxIdLocalidad, 100, 110, "\nINGRESE EL ID DE LA LOCALIDAD PARA VER LOS CLIENTES: \n");
    system("pause");
    for(int i=0; i<tamCl; i++)
    {
        if(vecClientes[i].idLocalidad == auxIdLocalidad)
        {
           system("cls");
           printf("  ID   APELLIDO        NOMBRE         SEXO      DOMICILIO            LOCALIDAD     TELEFONO");
           printf("\n\n");
           mostrarCliente(vecClientes[i], vecLoc, tamLoc);
        }
    }
}



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

*/


