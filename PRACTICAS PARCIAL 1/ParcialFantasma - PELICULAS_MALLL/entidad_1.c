#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "entidad_2.h"
#include "entidad_3.h"
#include "entidad_1.h"

/*
ALTAS PELÍCULAS: Se ingresan los datos de una sola película. El id deberá
generarse de manera automática a partir del número 1000. Realizar las validaciones:
a) el id es incremental.
b) código: debe ser de tres cifras sin ceros a la izquierda
c) título : no puede ser solo un número , debe tener letras.
d) el actor debe ser uno existente,
2. LISTAR:
a) listar los datos de Películas sin actores
b) listar los datos de Películas con actores
*/

///VOID SI NO TIENE CAMPO IS EMPTY, SINO ES LA DE INT
/*void hardcodearPeliculas(ePelicula vec[], int tam)
{

    ePelicula peliculas[]= ///POR EJEM eVuelos vuelos[]=
    {
        ///ACA RESPETAR EL ORDEN DE LOS DATOS A HARDCODEAR
        {1000, 123, "GUASON",{12, 06, 2019},0},
        {1001,456, "ESPERANDO LA CARROZA",{06, 11, 2019},0},
        {1002,789, "STARWARS",{08, 08, 2019},0},
        {1003,678, "E.T.",{15, 07, 2019},0},
        {1004,325, "LA ODISEA DE LOS GILES",{12, 09 , 2019},0},
        {1005,356, "THE VISITORS",{25, 03, 2019},0},
         {1006,446, "TAXI",{03, 04, 2019},1},

    };

    for(int i=0; i<tam; i++)
    {
        vecDATO[i]=DATOS[i];
    }
}

*/

///INT SI TIENE CAMPO ISEMPTY

int hardcodearPeliculas(ePelicula vec[], int tam, int cant)  ///PARA HARDCODEAR SI TIENE IsEMPTY
{
    int cont=0;
    ePelicula peliculas[]= ///POR EJEM eVuelos vuelos[]=
    {
        {1000, 123, "GUASON",2,103,{12, 6, 2019},0},
        {1001,456, "ESPERANDO LA CARROZA",4,101,{6, 11, 2019},0},
        {1002,769, "STARWARS",1,100,{7, 7, 2019},0},
        {1003,677, "E.T.",2,102,{15, 7, 2019},0},
        {1004,325, "LA ODISEA DE LOS GILES",3, 101,{12, 9, 2019},0},
        {1005,356, "SANDRO DE AMERICA",5, 101,{25, 3, 2019},0},
        {1006,446, "TAXI",2,103,{3, 4, 2019},1},
    /*int idPelicula;
    int codigo;
    char titulo[50];
    int idActor;
    int idGenero;
    eFecha fechaEstreno;
    int estado;*/
    };

    if(cant<= tam && cant<=7) ///ACA VA CUANTOS QUIERO HARDCODEAR EN CANT
    {
        for(int i=0; i<tam; i++)
        {
            vec[i]=peliculas[i];
            cont++;
        }
    }

    return cont;
}


/// PONE EL ISEMPTY EN 1 PARA DAR ALTAS

void inicializarPeliculas(ePelicula vec[], int tam) ///PARA LAS ESTRUCTURAS QUE TIENEN IsEMPTY
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].estado = 1;
    }
}

/// BUSCAR LIBRE PARA DAR UN ALTA, ME DA EL INDICE DONDE DAR ALTA

int buscarLibre(ePelicula vec[], int tam) ///SE VA A USAR CUANDO DEMOS UN ALTA
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].estado == 1 ) ///ACA VERIFICA COMO ESTA ISEMPTY
        {
            indice = i;
            break;
        }
    }
    return indice;
}

//////////////////////////

void mostrarPelicula(ePelicula peli, eGenero vecGen [], int tamG, eActores vecAc [], int tamA) ///NOMOBRE DE LA ESTRUCTURA Y DE UN DATO. si van mas estruct voy a tener que obtener los datos de cada una
{

    char genero [20];
    char nombreActor [50];

    obtenerNombreActor(vecAc, tamA,peli.idActor, nombreActor); ///SI TENGO QUE OBTENER DATOS DE OTRA ESTRUCTURA
    obtenerGenero(vecGen, tamG, peli.idGenero, genero); ///SI TENGO QUE OBTENER DATOS DE OTRA ESTRUCTURA

    printf("%2d  %2d   %10s    %10s    %10s   %02d/%02d/%d\n",
           peli.idPelicula,
           peli.codigo,
           peli.titulo,
           genero,
           nombreActor,
           peli.fechaEstreno.dia,
           peli.fechaEstreno.mes,
           peli.fechaEstreno.anio);
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

void mostrarPeliculas(ePelicula peli[], int tam, eGenero vecGen [], int tamG, eActores vecAc [], int tamA)
{
    int flag = 0;
    system("cls");

    printf("IdPeli    CODIGO  TITULO   GENERO   ACTOR   FECHA DE ESTRENO\n");

    for(int i=0; i < tam; i++)
    {
        if( peli[i].estado == 0)
        {
            mostrarPelicula(peli[i], vecGen, tamG, vecAc, tamA);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay peliculas que mostrar\n");
    }

    printf("\n\n");
}


int altaPelicula(ePelicula peli[], int tam, eGenero vecGen [], int tamG, eActores vecAc [], int tamA)///agregar la estructura piltos para ver los Id
///en los parametros van a ir los vec que influyen para el ALTA
{


    int todoOk = 0;
    int index;
    int esta;
    int idPelicula;
    int codigo;
    int idGenero;
    int idActor;
    char titulo[30];
    ///char genero[30];
    ///char nombreActor[30];
    ///char estado[30]
    int estado;

    system("cls");

    printf("*****ALTA DE UNA PELICULA*****\n\n");

    index = buscarLibre(peli, tam); ///a ver si hay lugar libre, lo guarda en index 1 si hay, -1 sino


    if( index == -1) ///ver de tener en el harcodeo algunos con isEmpty en 1
    {
        printf("\nEl Sistema Esta Completo\n\n");
        system("pause");
    }
    else
    {
         getIntRange(&codigo,100,999,"Ingresar codigo entre 100/999: ");

        esta=buscarCodigo(peli,tam,codigo);

        if(esta != -1)
        {
            printf("Ya existe una pelicula con ese codigo\n\n");
            mostrarPelicula(peli[esta],vecGen,tamG,vecAc,tamA);
        }

        peli[index].idPelicula = idPelicula;
        peli[index].codigo=codigo;

        mostrarGeneros(vecGen, tamG);
        getIntRange(&idGenero,100, 103, "\nIngrese el Id del genero: \n");

        mostrarActores(vecAc, tamA);
        getIntRange(&idActor, 1, 5, "Ingrese el Id del actor: \n");


        getStringAlpha(30, "\nIngrese eltirulo de la pelicula \n", titulo);
        strupr(titulo);

            getIntRange(&peli[index].fechaEstreno.dia,1,31,"Ingrese dia: ");
            getIntRange(&peli[index].fechaEstreno.mes,1,12,"Ingrese mes: ");
            getIntRange(&peli[index].fechaEstreno.anio,2019,2025,"Ingrese anio: ");

        peli[index].estado = 0;

        todoOk = 1;
        printf("\nSe ha realizado el alta de la pelicula\n\n");
        system("pause");

    }

    return todoOk;
}

/*ePelicula newPelicula( /// eDATO newDATO, abajo los campos que tiene

    int idPelicula,
    int codigo,
    int idPiloto,
    int partida,
    int llegada,
    char titulo[]) ///LOS CHAR LLEVAN LOS CORCHETES

{
    eVuelo vuelo;
    vuelo.idVuelo= idVuelo; ///esto para los INT carga cada dato en el campo de la est
    vuelo.idDestino=idDestino;///esto para los INT
    vuelo.idPiloto=idPiloto;///esto para los INT
    vuelo.horaPartida= partida;///esto para los INT
    vuelo.horaLlegada=llegada;
    strcpy(vuelo.estado,estado); ///esto para los char
    vuelo.isEmptyVuelos = 0;///PONE EL ISEMTPY EN 0, ACTIVO

    return vuelo;
}
*/

int buscarCodigo(ePelicula vec[],int tam,int codigo)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].estado == 0 && vec[i].codigo ==codigo)
        {
            indice=i;
        }
    }

    return indice;
}

////// BAJA!!!!

/*void bajaDATO(eVuelo vecVue[], int tamVue, eDestino vecDest [], int tamD, ePiloto pil [], int tamPil)
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

*/
/// MODIFICAR ALGUN DATO EN ALGUNA ESTRU, MUESTRO LA ESTR Y ACCEDO BUSCANDO POR ID, DESPUES QUE CAMPO MODIFICAR


int modificarPelicula(ePelicula peli[], int tam, eGenero vecGen [], int tamG, eActores vecAc [], int tamA) ///ACA VAN LAS ESTRUC QUE INFLUYEN EN LA MODIFICACION,A VACES ES UNA SOLA
{
    int todoOk=0;
    int esta;
    int salir;
    int codigo;

    system("cls");
    printf("**** MENU MODIFICAR PELICULA ****\n\n");

    mostrarPeliculas(peli,tam,vecGen,tamG,vecAc,tamA);

    getIntRange(&codigo,100,999,"Ingrese codigo de pelicula: ");

    esta=buscarCodigo(peli,tam,codigo);

    while(esta == -1)
    {
        printf("No existe pelicula con ese codigo.\n\n");
        getIntRange(&codigo,100,999,"Ingrese codigo de pelicula: ");

        esta=buscarCodigo(peli,tam,codigo);
    }
    if(esta != -1)
    {
        do
        {
            switch(menuModificacion())
            {
            case 1:
                /*peli[esta].idGenero=validarGenero(vecG,tamG);
                printf("Cambio realizado con exito.\n\n");
                */
                mostrarGeneros(vecGen, tamG);
                getIntRange(peli[esta].idGenero,100, 103, "ingrese el nuevo genero\n");
                break;

            case 2:
                /*vec[esta].idActor=validarActor(vecA,tamA);
                 printf("Cambio realizado con exito.\n\n");
                */
                mostrarActores(vecAc, tamA);
                getIntRange(&peli[esta].idActor, 1,5, "ingrese el nuevo actor\n");
                break;

            case 3:
                printf("\nFECHA DE ESTRENO\n");

                getIntRange(&peli[esta].fechaEstreno.dia,1,31,"Ingrese dia: ");
                getIntRange(&peli[esta].fechaEstreno.mes,1,12,"Ingrese mes: ");
                getIntRange(&peli[esta].fechaEstreno.anio,2019,2025,"Ingrese anio: ");
                 printf("Cambio realizado con exito.\n\n");
                break;

            case 4:
                getStringAlphaNum(50,"Ingrese nombre pelicula: ",peli[esta].titulo);
                 printf("Cambio realizado con exito.\n\n");
                break;

            case 5:
                salir=confimarSalir("Volver al menu principal? s/n: ");
                break;
            }

            system("pause");

        }
        while(salir != 1);

        todoOk=1;
    }


    return todoOk;
}


int menuModificacion()
{
    int opcion;

    system("cls");

    printf("**** MENU MODIFICACION ****\n\n");
    printf("1. Genero\n");
    printf("2. Actor principal\n");
    printf("3. Fecha estreno\n");
    printf("4. Nombre pelicula\n");;
    printf("5. Salir.\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    while(opcion < 1 || opcion > 5)
    {
        printf("\nIngrese opcion valida: ");
        scanf("%d",&opcion);
    }


    return opcion;
}



/// BUSCAR ALGO POR ID, PARA SELECCIONARLO CUANDO MUESTRO, POR EJ PARA MODIFICAR

/*int buscarPersonaPOR_ID(int VALOR_A_BUSCAR, STRUCT_NAME vec[], int tam)
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
*/
//////////////////
/*
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
*/
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
