#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "entidad_2.h"
#include "entidad_3.h"
#include "entidad_1.h"



///VOID SI NO TIENE CAMPO IS EMPTY, SINO ES LA DE INT
void hardcodearDATOS(eENTIDAD_1 vecDATO[], int tam)
{

    eENTIDAD_1 DATOS[]= ///POR EJEM eVuelos vuelos[]=
    {
        ///ACA RESPETAR EL ORDEN DE LOS DATOS A HARDCODEAR
        {100,"LAUTARO ACOSTA"},
        {101,"PEPE SAND"},
        {102,"MARCELINO MORENO"},
        {103,"PEPO DE LA VEGA"},
        {104,"DIEGO VALERI"},

    };

    for(int i=0; i<tam; i++)
    {
        vecDATO[i]=DATOS[i];
    }
}



///INT SI TIENE CAMPO ISEMPTY

int hardcodearDATOS_INT(eENTIDAD_1 vec[], int tam, int cant)///PARA HARDCODEAR SI TIENE IsEMPTY
{
    int cont=0;
    eENTIDAD_1 DATOS[]= ///POR EJEM eVuelos vuelos[]=
    {
        {1000,1,100,14,19,"activo",0},  ///OJO EN EL HARDCODEO PONER LOS CAMPOS EN EL MISMO ORDEN QUE LA ESTRUCTURA
        {1001,3,102,12,15,"suspendido",0},
        {1002,2,103,13,23,"cancelado",0},
        {1003,2,103,15,22,"activo",0},
        {1004,4,104,05,10,"demorado",0},
        {1005,4,104,10,19,"suspendido",0},
        {1006,3,102,16,19,"activo",0},
        {1007,2,103,13,15,"activo",1},
        {1008,1,105,14,17,"activo",1},

    };

    if(cant<= tam && cant<=7) ///ACA VA CUANTOS QUIERO HARDCODEAR EN CANT
    {
        for(int i=0; i<tam; i++)
        {
            vec[i]=DATOS[i];
            cont++;
        }
    }

    return cont;
}


/// PONE EL ISEMPTY EN 1 PARA DAR ALTAS

void inicializarEstructura(STRUCT_NAME vec[], int tam) ///PARA LAS ESTRUCTURAS QUE TIENEN IsEMPTY
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

/// BUSCAR LIBRE PARA DAR UN ALTA, ME DA EL INDICE DONDE DAR ALTA

int buscarLibre(STRUCT_NAME vec[], int tam) ///SE VA A USAR CUANDO DEMOS UN ALTA
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 ) ///ACA VERIFICA COMO ESTA ISEMPTY
        {
            indice = i;
            break;
        }
    }
    return indice;
}

//////////////////////////

void mostrarDATO(STRUCT_NAME dato) ///NOMOBRE DE LA ESTRUCTURA Y DE UN DATO. si van mas estruct voy a tener que obtener los datos de cada una
{

    ///char DATO_A_OBTENER [30]; ACA VOY A CARGAR LOS DATOS A OBTENER
    ///char DATO_A_OBTENER_2 [30];

   /// obtenerNomPiloto(piloto, tamPil,vecVue.idPiloto, nomPiloto); SI TENGO QUE OBTENER DATOS DE OTRA ESTRUCTURA
   /// obtenerNomDestino(destino, tamD, vecVue.idDestino, nomDestino); SI TENGO QUE OBTENER DATOS DE OTRA ESTRUCTURA

    printf("  %d     %s     %d  %c  %02d/%02d/%d\n",
           dato.legajo,
           dato.nombre,
           dato.edad,
           dato.sexo,
           dato.fecha.dia,
           dato.fecha.mes,
           dato.fecha.anio);
}
/*
void mostrarVuelo(eVuelo vecVue, eDestino destino[], int tamD, ePiloto piloto[], int tamPil)
{
    char nomDestino[30];
    char nomPiloto[51];

    obtenerNomPiloto(piloto, tamPil,vecVue.idPiloto, nomPiloto);
    obtenerNomDestino(destino, tamD, vecVue.idDestino, nomDestino);

    printf(" %2d  %17s  %10s  %4d   %4d   %10s  \n",vecVue.idVuelo,nomPiloto,nomDestino, vecVue.horaPartida, vecVue.horaLlegada, vecVue.estado);

}
*/
/// PARA OBTENER EL DATO QUE VOY A USAR EN MOSTRAR SI SE VINCULAN ESTRUCTURAS
/*
void obtenerNomPiloto(ePiloto vecPil[], int tamPil, int id, char dondeAsigar[])
{
    for(int i=0; i<tamPil; i++) ///RECORRO EL VEC QUE QUIERO OBTNER DATO
    {
        if(vecPil[i].idPiloto == id) ///SI EL ID COINCIDE, CARGO EL DATO EN LA VAR DONDE ASGINAR
        {
            strcpy(dondeAsigar,vecPil[i].nombre);
            ///strcat(dondeAsigar,", ");
            ///strcat(dondeAsigar,vec[i].nombre);
        }
    }
}
*/

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


int altaDATO(eVuelo vuelo[], int tamV,ePiloto piloto[], int tamPil, eDestino destino[], int tamD, int idVuelo)///agregar la estructura piltos para ver los Id
///en los parametros van a ir los vec que influyen para el ALTA
{


    int todoOk = 0;
    int index;
    int idDestino;
    int idPiloto;
    int partida;
    int llegada;
    char estado[30];

    system("cls");

    printf("*****ALTA DE UN VUELO*****\n\n");

    index = buscarLibreVue(vuelo, tamV); ///a ver si hay lugar libre, lo guarda en index 1 si hay, -1 sino


    if( index == -1) ///ver de tener en el harcodeo algunos con isEmpty en 1
    {
        printf("\nEl Sistema Esta Completo\n\n");
        system("pause");
    }
    else ///aca va a ir completando los campos para el ALTA
    {
        vuelo[index].idVuelo = idVuelo;

        ///mostrarPilotos(piloto, tamPil);
        ///getIntRange(&idPiloto,100, 999, "\nIngrese el Id del Piloto: \n");

        ///mostrarDestinos(destino, tamD);
       ///getIntRange(&idDestino, 1, 100, "Ingrese el Id del destino: \n");

       /// getIntRange(&partida,00,24, "\nIngrese el horario de partida \n");
        ///getIntRange(&llegada,00,24, "\nIngrese el horario de llegada \n");

        ///getStringAlpha(30, "\nIngrese el estado del vuelo: \n", estado);
        ///strlwr(estado); COMO MODIFICA EL ESTADO ME LLEVA TODO A MINUSCULA

        ///vuelo[index] = newVuelo(idVuelo,idDestino,idPiloto,partida,llegada, estado);

        todoOk = 1;
        printf("\nSe ha realizado el alta del vuelo\n\n");
        system("pause");

    }

    return todoOk;
}

eSTRUC_NAME newVuelo( /// eDATO newDATO, abajo los campos que tiene

    int idVuelo,
    int idDestino,
    int idPiloto,
    int partida,
    int llegada,
    char estado[]) ///LOS CHAR LLEVAN LOS CORCHETES

{
    eVuelo vuelo;
    vuelo.idVuelo= idVuelo; ///esto para los INT carga cada dato en el campo de la est
    vuelo.idDestino=idDestino;///esto para los INT
    vuelo.idPiloto=idPiloto;///esto para los INT
    vuelo.horaPartida= partida;///esto para los INT
    vuelo.horaLlegada=llegada;
    strcpy(vuelo.estado ,estado);///esto para los char
    vuelo.isEmptyVuelos = 0;///PONE EL ISEMTPY EN 0, ACTIVO

    return vuelo;
}

////// BAJA!!!!

void bajaDATO(eVuelo vecVue[], int tamVue, eDestino vecDest [], int tamD, ePiloto pil [], int tamPil)
{
    int confirma;
    int indice;
    int id;

    // mostrarClientes(vec,tam);
    mostrarVuelos(vecVue, tamVue, vecDest, tamD, pil, tamPil);

    getIntRange(&id,1000,1100,"Ingrese id del vuelo: ");

    //indice=buscarClienteId(vec,tam,id);
    indice=buscarVueloPorId(id, vecVue, tamVue);

    if(indice==-1)
    {
        getIntRange(&id,1000,1100,"Ingrese id de vuelo valido: ");

        indice=buscarVueloPorId(id, vecVue, tamVue);

        printf("\nEl id ingresado es incorrecto\n\n");
    }
    if(indice !=-1)
    {
        confirma=confimarSalir("\n\nDar de baja el Vuelo? s/n: ");

        if(confirma==1)
        {
            vecVue[indice].isEmptyVuelos=1;
            printf("\nOperacion realizada\n\n");
        }
        else
        {
            printf("\nOperacion cancelada\n\n");
        }
    }

}

/// MODIFICAR ALGUN DATO EN ALGUNA ESTRU, MUESTRO LA ESTR Y ACCEDO BUSCANDO POR ID, DESPUES QUE CAMPO MODIFICAR

int modificarDATO(eVuelo vec[], int tam, eDestino dest[], int tamD, ePiloto pil[], int tamP) ///ACA VAN LAS ESTRUC QUE INFLUYEN EN LA MODIFICACION,A VACES ES UNA SOLA
{
    int indice;
    int todoOk=0;
    int id;


    mostrarVuelos(vec, tam, dest,tamD, pil, tamP); ///MUESTRO LOS DATOS DE LO QUE QUIERO MODIFICAR

    getIntRange(&id,1000,1100,"Ingrese id del vuelo: ");///INGRESO EL ID DE LO QUE QUIERO MODIFICAR

    indice=buscarVueloPorId(id, vec, tam); ///ME DA EL INDICE DEL ID QUE BUSQUE

    while(indice==-1)
    {
        getIntRange(&id,1000,1100,"Ingrese id de vuelo valido: "); ///SI NO EXISTE EL ID, INDICE -1

        indice=buscarVueloPorId(id, vec, tam);///BUSCA DE NUEVO
    }
    if(indice !=-1) ///SI LO ENCONTRO. ACA VA EL DATO A MODIFICAR
    {
        getStringAlpha(51,"Ingrese el nuevo estado: ",vec[indice].estado);
    }
    return todoOk=1;
}


/// BUSCAR ALGO POR ID, PARA SELECCIONARLO CUANDO MUESTRO, POR EJ PARA MODIFICAR

int buscarPersonaPOR_ID(int VALOR_A_BUSCAR, STRUCT_NAME vec[], int tam)
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

//////////////////

int menuOrdenar() ///esta va en el .H
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

/// SI QUIERO ORDENAR SOLO POR NOMBRE POR EJEMPLO
/*
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
*/

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

