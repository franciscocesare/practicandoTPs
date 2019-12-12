#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "validaciones.h"
#include "alquileres.h"

#define CLIENTES 100
#define ALQUILERES 100
#define JUEGOS 20
#define CATEGORIAS 5


//validaciones


//funciones clientes

int hardcodearClientes(eClientes vec[], int tamC, int cantidad);
int hardcodearAlquileres(eAlquileres vec[], int tamA, int cantidad);


//funciones alquileres


//funciones informes
void menuInformes(eJuego juegos[], int tamJ, eAlquileres alquileres[], int tamA, eCategoria categorias[], int tamCat, eClientes clientes[], int tamC);
void listarJuegosCatMesa(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);
void listarAlquileresCliente(eAlquileres alquileres[], int tamA, eClientes clientes[], int tamC);
void totalImportesCliente(eClientes clientes[], int tamC, eJuego juegos[], int tamJ, eAlquileres alquileres[], int tamA);
void listadoNoAlquila(eClientes clientes[], int tamC, eAlquileres alquileres[], int tamA);
void listaJuegoNoAlquilado(eJuego juegos[], int tamJ, eAlquileres alquileres[], int tamA, eCategoria categorias[], int tamCat);

int main()
{
    eJuego listaJ[]=
    {
        {10, "TEG",       200, 3},
        {12, "Clue",      350, 1},
        {13, "Poker",     500, 2},
        {14, "Pelotero", 1500, 4},
        {15, "Mago nego", 250, 5},
        {16, "Monopoly",  200, 1},
        {17, "Truco",     350, 2},
        {18, "Mil milla", 500, 3},
        {19, "Tobogan",  1500, 4},
        {11, "Brujas",    250, 5},
        {20, "Ajedrez",   200, 3},
        {21, "Clue Sim",  350, 1},
        {22, "BlackJack", 500, 2},
        {23, "Hamaca",   1500, 4},
        {24, "Magia",     250, 5},
        {25, "Estanciero",200, 1},
        {26, "Chinchon",  350, 2},
        {27, "Damas",     500, 3},
        {28, "Columpio", 1500, 4},
        {29, "Hechizo",   250, 5},
    };

    eCategoria listaCat[]=
    {
        {1,"mesa"},
        {2,"azar"},
        {3,"estrategia"},
        {4,"salon"},
        {5,"magia"},
    };



    eClientes listaC[CLIENTES];
    initClientes(listaC,CLIENTES);

    eAlquileres listaAlq[ALQUILERES];
    initAlquileres(listaAlq, ALQUILERES);



    int idCliente=1001;
    int idCodigoAlquiler=1;
    int option;
    char salir='n';
    char salirTot='n';

    idCodigoAlquiler+= hardcodearAlquileres(listaAlq, ALQUILERES, 20);
    idCliente+= hardcodearClientes(listaC, CLIENTES, 10);

    do{
        system("cls");
        printf("***ABM***\n\n");
        printf("1- Clientes\n");
        printf("2- Alquileres\n");
        printf("3- Informes\n");
        printf("5- Salir\n");
        printf("\nIngrese opcion: ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            do{
                system("cls");
                printf("***MENU CLIENTES***\n\n");
                printf("1- Alta\n");
                printf("2- Modificar\n");
                printf("3- Baja\n");
                printf("4- Listar\n");
                printf("5- Salir\n");
                printf("\nIngrese opcion: ");
                fflush(stdin);
                scanf("%d", &option);

                switch(option)
                {
                case 1:
                        if(altaCliente(listaC, CLIENTES, idCliente)){
                            idCliente++;
                        }

                    break;

                case 2:
                    if(loadedVector(listaC, CLIENTES)){
                        modificarCliente(listaC, CLIENTES);
                    }else{
                        printf("\nSe debe cargar primero algun cliente\n");
                        }
                    break;

                case 3:
                    if(loadedVector(listaC, CLIENTES)){
                        bajaCliente(listaC, CLIENTES);
                    }else{
                        printf("\nSe debe cargar primero algun cliente\n");
                        }
                    break;

                case 4:
                    if(loadedVector(listaC, CLIENTES)){
                        ordenarClientes(listaC, CLIENTES);
                        listarClientes(listaC, CLIENTES);
                    }else{
                        printf("\nSe debe cargar primero algun cliente\n");
                        }
                    break;

                case 5:
                    printf("\nConfirma la salida del sistema? (s/n): ");
                    fflush(stdin);
                    scanf("%c",&salir);
                    break;

                default:
                    printf("\n\nOPCION INVALIDA\n");
                    break;

                }

                system("pause");
            }while(salir == 'n');
        break;

        case 2:
            do{
                system("cls");
                printf("***MENU ALQUILERES***\n\n");
                printf("1- Alta\n");
                printf("2- Listar\n");
                printf("5- Salir\n");
                printf("\nIngrese opcion: ");
                fflush(stdin);
                scanf("%d", &option);

                switch(option)
                {
                case 1:
                    if(altaAlquiler(listaAlq, ALQUILERES, listaJ, JUEGOS, listaC, CLIENTES, idCodigoAlquiler)){
                        idCodigoAlquiler++;
                    }
                    break;

                case 2:
                    listarAlquileres(listaAlq, ALQUILERES);
                    break;

                case 5:
                    printf("\nConfirma la salida del sistema? (s/n): ");
                    fflush(stdin);
                    scanf("%c",&salir);
                    break;

                default:
                    printf("\n\nOPCION INVALIDA\n");
                    break;

                }

                system("pause");
            }while(salir == 'n');
            break;

        case 3:
            menuInformes(listaJ, JUEGOS, listaAlq, ALQUILERES, listaCat, CATEGORIAS, listaC, CLIENTES);
            break;


        case 5:
            printf("\nConfirma la salida del sistema? (s/n): ");
            fflush(stdin);
            scanf("%c",&salirTot);
            break;

        default:
            printf("\n\nOPCION INVALIDA");
            break;
        }

        printf("\n\n");
        system("pause");

    }while(salirTot == 'n');

    return 0;
}


int hardcodearClientes( eClientes vec[], int tamC, int cantidad)
{
    int cont = 0;

    eClientes suplentes[]=
    {
        {1001, "Esteban", "Mato",      'm', "1154770922", "peru 1225",0},
        {1002, "Alberto", "Rodriguez", 'm', "1154770922", "peru 1225",0},
        {1003, "Ana", "Luaccino",      'f', "1154770922", "peru 1225",0},
        {1004, "Luis", "Veliz",        'm', "1154770922", "peru 1225",0},
        {1005, "Alicia", "Mendoza",    'f', "1154770922", "peru 1225",0},
        {1006, "Diego", "Aaron",       'm', "1154770922", "peru 1225",0},
        {1007, "Sofia", "Zotela",      'f', "1154770922", "peru 1225",0},
        {1008, "Clara", "Abbe",        'm', "1154770922", "peru 1225",0},
        {1009, "Maria", "Mas ",        'f', "1154770922", "peru 1225",0},
        {1010, "Ricardo", "Gimenez",   'm', "1154770922", "peru 1225",0},
    };

    if( cantidad <= 10 && tamC >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vec[i] = suplentes[i];
            cont++;
        }
    }
    return cont;
}

int hardcodearAlquileres(eAlquileres vec[], int tamA, int cantidad)
{
    int cont = 0;

    eAlquileres suplentes[]=
    {
        {1, 10, 1001, {22, 12, 1993},0},
        {2, 11, 1002, {22, 12, 1993},0},
        {3, 12, 1004, {22, 12, 1993},0},
        {4, 13, 1005, {22, 12, 1993},0},
        {5, 14, 1001, {22, 12, 1993},0},
        {6, 15, 1008, {22, 12, 1993},0},
        {7, 16, 1009, {22, 12, 1993},0},
        {8, 17, 1001, {22, 12, 1993},0},
        {9, 18, 1002, {22, 12, 1993},0},
        {10, 19, 1004, {22, 12, 1993},0},
        {11, 11, 1005, {22, 12, 1993},0},
        {12, 12, 1005, {22, 12, 1993},0},
        {13, 13, 1008, {22, 12, 1993},0},
        {14, 14, 1009, {22, 12, 1993},0},
        {15, 15, 1002, {22, 12, 1993},0},
        {16, 16, 1003, {22, 12, 1993},0},
        {17, 17, 1004, {22, 12, 1993},0},
        {18, 18, 1008, {22, 12, 1993},0},
        {19, 19, 1008, {22, 12, 1993},0},
        {20, 20, 1002, {22, 12, 1993},0},
    };

    if( cantidad <= 20 && tamA >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vec[i] = suplentes[i];
            cont++;
        }
    }
    return cont;
}

void menuInformes(eJuego juegos[], int tamJ, eAlquileres alquileres[], int tamA, eCategoria categorias[], int tamCat, eClientes clientes[], int tamC)
{
    int option;
    char salir='n';

    do{
        system("cls");
        printf("***MENU INFORMES***\n\n");
        printf("1- Mostrar juegos categoria mesa\n");
        printf("2- Mostrar alquileres por cliente seleccionado\n");
        printf("3- Mostar total de importe pagado por cliente seleccionado\n");
        printf("4- Listado clientes que no alquilaron juegos\n");
        printf("5- Listado de juegos no alquilados\n");
        printf("9- Salir\n");
        printf("\nIngrese opcion: ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            listarJuegosCatMesa(juegos, tamJ, categorias, tamC);
            break;

        case 2:
            listarAlquileresCliente(alquileres, tamA, clientes, tamC);
            break;

        case 3:
            totalImportesCliente(clientes, tamC, juegos, tamJ, alquileres, tamA);
            break;

        case 4:
            listadoNoAlquila(clientes, tamC, alquileres, tamA);
            break;

        case 5:
            listaJuegoNoAlquilado(juegos, tamJ, alquileres, tamA, categorias, tamCat);
            break;

        case 9:
                printf("\nConfirma la salida del sistema? (s/n): ");
                fflush(stdin);
                scanf("%c",&salir);
                break;

            default:
                printf("\n\nOPCION INVALIDA");
                break;
        }

        printf("\n\n");
        system("pause");
    }while(salir == 'n');

}

void listarJuegosCatMesa(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC)
{
    for(int i=0; i<tamJ; i++)
    {
        if(juegos[i].idCategoria == 1)
        {
            printf("\nCod    Descrip Importe");
            printf("\n%d  %10s   %5d %s",juegos[i].codigo, juegos[i].descripcion, juegos[i].importe, categorias[juegos[i].idCategoria-1].descrpcion );
        }
    }
}

void listarAlquileresCliente(eAlquileres alquileres[], int tamA, eClientes clientes[], int tamC)
{

    int codCliente;
    int flag=-1;

    printf("\nIngrese codigo de cliente: ");
    fflush(stdin);
    scanf("%d", &codCliente);

    while(!validarCodCliente(clientes, tamC, codCliente))
    {
        printf("\nERROR. No existe el codigo de empleado ingresado, ingrese nuevamente: ");
        fflush(stdin);
        scanf("%d", &codCliente);
    }

    printf("\n\nCod Alq   Juego   Cliente   Fecha de alquiler ");

    for(int i=0; i<tamA; i++)
    {
        if(codCliente==alquileres[i].codCliente)
        {
            printf("\n%02d        %02d      %4d      %02d/%02d/%d ", alquileres[i].codAlquiler, alquileres[i].codJuego, alquileres[i].codCliente, alquileres[i].fecha.dia, alquileres[i].fecha.mes, alquileres[i].fecha.anio);
            flag=1;
        }
    }

    if(flag==-1){
        printf("\n\nNo hay alquileres realizados por este cliente");
    }
}

void totalImportesCliente(eClientes clientes[], int tamC, eJuego juegos[], int tamJ, eAlquileres alquileres[], int tamA)
{
    int totalImportes=0;
    int codCliente;

    printf("\nIngrese codigo de cliente: ");
    fflush(stdin);
    scanf("%d", &codCliente);

    while(!validarCodCliente(clientes, tamC, codCliente))
    {
        printf("\nERROR. No existe el codigo de empleado ingresado, ingrese nuevamente: ");
        fflush(stdin);
        scanf("%d", &codCliente);
    }

    for(int i=0; i<tamA; i++)
    {
        if(codCliente==alquileres[i].codCliente)
        {
            for(int j=0; j<tamJ; j++)
            {
                if(alquileres[i].codJuego==juegos[j].codigo)
                {
                    totalImportes += juegos[j].importe;
                }
            }
        }
    }

    printf("\nEl total de los importes pagados por el cliente es: %d", totalImportes);
}

void listadoNoAlquila(eClientes clientes[], int tamC, eAlquileres alquileres[], int tamA)
{
    int flag=2;
    int contador=0;

    printf("\nLos clientes que no alquilaron ningun juego son: \n");
    for (int i=0; i<tamC; i++)
    {
        flag=0;
        for(int j=0; j<tamA; j++)
        {
            if(clientes[i].codigo==alquileres[j].codCliente){
                flag=1;
                break;
            }
        }
        if(!flag && clientes[i].isEmpty==0)
        {

            listarCliente(clientes[i]);
            contador++;
        }
    }

    if(!contador){
        printf("\nNo hay clientes que no hayan alquilado al menos un juego\n");
    }
}

void listaJuegoNoAlquilado(eJuego juegos[], int tamJ, eAlquileres alquileres[], int tamA, eCategoria categorias[], int tamCat)
{
    int flag;
    int contador=0;

    printf("\nLos juegos que no se alquilaron son: \n");
    printf("\nCod    Descrip Importe Categoria");
    for (int i=0; i<tamJ; i++)
    {
        flag=0;
        for(int j=0; j<tamA; j++)
        {
            if(juegos[i].codigo==alquileres[j].codJuego){
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            printf("\n%d  %10s   %5d %s",juegos[i].codigo, juegos[i].descripcion, juegos[i].importe, categorias[juegos[i].idCategoria-1].descrpcion );
        }
    }

    if(!contador){
        printf("\nNo hay juegos que no hayan sido alquilados\n");
    }
}


