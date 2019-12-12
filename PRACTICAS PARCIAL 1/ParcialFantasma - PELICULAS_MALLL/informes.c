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

/*int ordenarEstructura(STRUCT_NAME vec[], int tam)
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
*/
/////////////////////////////////////////////////////

/// INFORMES PARA TOMAR DE EJEMPLO!!!!
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

*/
/////////////////////////////////////////////
///TOMA DATO DE LA FUNCION DE ARRIBA

/*void mostrarDatosAlquilerJuego(eAlquileres alquiler, eCliente clientes[], int tamCl)
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
*/


////////////////////////////////////////////////////////
///DATO DE DETERMINADO CAMPO DE OTRA ESTRUCTURA

/*
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



//////////////////////////////////////////
*/

/*
void mostrarJuegosMesa(eJuego juego[], int tamJ,eCategoria cat[], int tamC)///RECIBE Y VINCULA ARRAY DE JUEGOS Y DE CATEGGORIAS
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

/////////////////////////////////////////////

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

//////////////////////////////////////

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


//////////////////////////////7


/*int mostrarAlquileresClientes(int idCliente,eAlquiler vec[],int tamAl)
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


////////////////////////////////////

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

/////////////////////////////////////////////////////

/*int mostrarJuegosAlquilados(int idJuego,eAlquiler vec[],int tam)
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
///////////////////////////////////////////////
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

////////////////////////////////////////////////////

/*
void mostrarJuegosMesa(eJuego juego[], int tamJ,eCategoria cat[], int tamC)///RECIBE Y VINCULA ARRAY DE JUEGOS Y DE CATEGGORIAS
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
/////////////////////////////////////////////

/*
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

*/

