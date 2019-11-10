#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define TAMAUTOS 100
#define TAMMARCAS 5
#define TAMCOLORES 5
#define TAMSERVICIOS 5
#define TAMTRABAJOS 100
#define TAMCLIENTES 100

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int id;
    char descripcion [21];

} eMarca;

typedef struct
{
    int id;
    char nombreColor [21];

} eColor;

typedef struct
{
    int id;
    char patente [7];
    int idMarca;
    int idColor;
    int modelo;
    int idCliente;

} eAuto;

typedef struct
{
    int id;
    char descripcion [26];
    int precio;

} eServicio;

typedef struct
{
    int id;
    char patente[7];
    int idServicio;
    eFecha fecha;

} eTrabajo;

typedef struct
{
    int id;
    char nombre[21];
    char sexo[21];

} eCliente;

int menu();

int validarMarca(eMarca marcas[], int tamMarcas, int inputMarca);

int validarColor(eColor colores[], int tamColores, int inputColor);

int validarServicio(eServicio servicios[], int tamServicios, int inputServicio);

int validarPatente(eAuto autos[], int tamAutos, char inputPatente[], int tamPatente);

int listarMarcas(eMarca marcas [], int tam);

int listarColores(eColor colores [], int tam);

int listarServicios(eServicio servicios [], int tam);

int inicializarAutos(eAuto autos[], int tam);

int inicializarTrabajos(eTrabajo trabajos[], int tam);

int buscarLibre(eAuto autos[], int tam);

int buscarLibreTrabajo(eTrabajo trabajos[], int tam);

int altaAuto(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

int altaTrabajo(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios, eAuto autos[], int tamAutos);

int buscarAutoPorPatente(eAuto autos[], int tam, char patente[]);

int obtenerMarca(eMarca marcas[], int tamMarcas, int idMarca, char desc[]);

int obtenerColor(eColor colores[], int tamColores, int idColor, char desc[]);

int obtenerServicio(eServicio servicios[], int tamServicios, int idServicio, char desc[]);

int obtenerPrecioServicio(eServicio servicios[], int tamServicios, int idServicio);

int modificarAuto(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores);

int bajaAuto(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores);

int ordenarAutos(eAuto autos[], int tam);

int ordenarTrabajos(eTrabajo trabajos[], int tam);

int listarAutos(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

int listarTrabajos(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios);

int listarAutosPorColor(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores);

int listarAutosPorMarca(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores);

int listarTrabajosPorAuto(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios, eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

int listarAutosSinTrabajos(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eTrabajo trabajos[], int tamTrabajos);

int listarImportesPorAuto(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios, eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

int listarServicioMasPedido(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios);

int obtenerNombreCliente(eCliente clientes[], int tamClientes, int idCliente, char nombreCliente[]);

int obtenerSexoCliente(eCliente clientes[], int tamClientes, int idCliente, char sexoCliente[]);

int listarRecaudacionPorFecha(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios);

int listarAutosPorTrabajo(eServicio servicios[], int tamServicios, eTrabajo trabajos[], int tamTrabajos);

int listarTrabajosPorColorDeAuto(eAuto autos[], int tam, eColor colores[], int tamColores, eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicios);

int listarImporteTotalPorServicio(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios);

int listarMarcasConMasCompletos(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios, eAuto autos[], int tamAutos);

int listarAutosPorFechaDeTrabajo(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios, eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores);

int main()
{
    eMarca marcas [TAMMARCAS] = {
                        {1000, "Renault"},
                        {1001, "Fiat"},
                        {1002, "Ford"},
                        {1003, "Chevrolet"},
                        {1004, "Peugeot"}
                        };

    eColor Colores [TAMCOLORES] = {
                        {5000, "Negro"},
                        {5001, "Blanco"},
                        {5002, "Gris"},
                        {5003, "Rojo"},
                        {5004, "Azul"}
                        };

    eServicio Servicios [TAMSERVICIOS] = {
                             {20000, "Lavado", 250},
                             {20001, "Pulido", 300},
                             {20002, "Encerado", 400},
                             {20003, "Completo", 600},
                             {20004, "Teflonado", 800},
                             };

   eAuto autos [TAMAUTOS] = {
                                {1, "AAA201", 1000, 5001, 1995, 3001},
                                {2, "DFR234", 1003, 5000, 2002, 3002},
                                {3, "GFT564", 1002, 5003, 2007, 3003},
                                {4, "ACD321", 1002, 5003, 1995, 3004},
                                {5, "HTD656", 1004, 5002, 2008, 3005},
                                {6, "QSZ435", 1003, 5001, 1994, 3006},
                                {7, "LGX201", 1001, 5000, 2012, 3007},
                                {8, "SUZ324", 1001, 5002, 1991, 3008},
                                {9, "HCU762", 1000, 5003, 2008, 3009},
                                {10, "DYC735", 1003, 5001, 2002, 3010},
                                {11, "JJK879", 1003, 5001, 2010, 3011},
                                {12, "FED322", 1004, 5002, 2006, 3012},
                                {13, "GHV332", 1001, 5003, 2007, 3013},
                                {14, "BDE221", 1000, 5004, 1996, 3014},
                                {15, "OPD332", 1000, 5001, 2014, 3015},
                                {16, "PPD121", 1002, 5001, 2015, 3016},
                                {17, "IIT230", 1001, 5000, 2009, 3017},
                                {18, "KOD220", 1004, 5002, 2011, 3018},
                                {19, "QSZ305", 1004, 5002, 1993, 3019},
                                {20, "SSD128", 1002, 5003, 1992, 3020},
                                {21, "SSD240", 1003, 5004, 1992, 3021},
                                {22, "EDF213", 1001, 5000, 2001, 3022}
                                };

    eTrabajo trabajos [TAMTRABAJOS] = {
                            {1, "AAA201", 20000, {12,3,2019}},
                            {2, "DFR234", 20000, {2,4,2019}},
                            {3, "GFT564", 20001, {7,1,2019}},
                            {4, "ACD321", 20002, {9,11,2019}},
                            {5, "HTD656", 20003, {12,12,2019}},
                            {6, "QSZ435", 20001, {21,7,2019}},
                            {7, "LGX201", 20001, {29,8,2019}},
                            {8, "SUZ324", 20004, {31,5,2019}},
                            {9, "HCU762", 20004, {2,2,2019}},
                            {10, "DYC735", 20000, {18,2,2019}},
                            {11, "JJK879", 20001, {17,3,2019}},
                            {12, "AAA201", 20000, {17,4,2019}},
                            {13, "DFR234", 20000, {2,6,2019}},
                            {14, "GFT564", 20001, {7,3,2019}},
                            {15, "ACD321", 20002, {21,7,2019}},
                            {16, "HTD656", 20003, {11,9,2019}},
                            {17, "QSZ435", 20001, {3,7,2019}},
                            {18, "LGX201", 20001, {21,8,2019}},
                            {19, "SUZ324", 20004, {28,5,2019}},
                            {20, "HCU762", 20004, {2,8,2019}},
                            {21, "DYC735", 20000, {8,2,2019}},
                            {22, "JJK879", 20001, {17,3,2019}},
                            {23, "KOD220", 20003, {17,4,2019}},
                            {24, "QSZ305", 20000, {21,3,2019}},
                            {25, "SSD128", 20002, {16,4,2019}},
                            {26, "SSD240", 20000, {17,4,2019}},
                            {27, "EDF213", 20001, {23,3,2019}},
                            {28, "AAA201", 20000, {12,2,2019}},
                            {29, "DFR234", 20000, {2,3,2019}},
                            {30, "GFT564", 20001, {7,2,2019}},
                            {31, "ACD321", 20002, {9,12,2019}},
                            {32, "HTD656", 20003, {12,9,2019}},
                            {33, "QSZ435", 20001, {21,5,2019}},
                            {34, "HTD656", 20002, {12,2,2019}},
                            {35, "QSZ435", 20000, {21,1,2019}},
                             };

    eCliente clientes [TAMCLIENTES] = {
                                        {3001, "Juan", "masculino"},
                                        {3002, "Martina", "femenino"},
                                        {3003, "Pedro", "masculino"},
                                        {3004, "Susana", "femenino"},
                                        {3005, "Julian", "masculino"},
                                        {3006, "Silvia", "femenino"},
                                        {3007, "Federico", "masculino"},
                                        {3008, "Mia", "femenino"},
                                        {3009, "Martin", "masculino"},
                                        {3010, "Romina", "femenino"},
                                        {3011, "Ricardo", "masculino"},
                                        {3012, "Cristina", "femenino"},
                                        {3013, "Mauricio", "masculino"},
                                        {3014, "Catalina", "femenino"},
                                        {3015, "Jose", "masculino"},
                                        {3016, "Graciela", "femenino"},
                                        {3017, "Homero", "masculino"},
                                        {3018, "Mariana", "femenino"},
                                        {3019, "Carlos", "masculino"},
                                        {3020, "Florencia", "femenino"},
                                        {3021, "Dante", "masculino"},
                                        {3022, "Maria", "femenino"},

                                      };


    char seguir = 's';
    char confirma;
    //eAuto autos [TAMAUTOS];
    //inicializarAutos(autos, TAMAUTOS);
    //eTrabajo trabajos[TAMTRABAJOS];
    //inicializarTrabajos(trabajos, TAMTRABAJOS);

    do{

        switch(menu())
        {
        case 1:

            altaAuto(autos, TAMAUTOS, marcas, TAMMARCAS, Colores, TAMCOLORES, clientes, TAMCLIENTES);
            system("pause");
            break;

        case 2:

            listarAutos(autos, TAMAUTOS, marcas, TAMMARCAS, Colores, TAMCOLORES, clientes, TAMCLIENTES);
            modificarAuto(autos, TAMAUTOS, marcas, TAMMARCAS, Colores, TAMCOLORES);
            system("pause");
            break;

        case 3:

            listarAutos(autos, TAMAUTOS, marcas, TAMMARCAS, Colores, TAMCOLORES, clientes, TAMCLIENTES);
            bajaAuto(autos, TAMAUTOS, marcas, TAMMARCAS, Colores, TAMCOLORES);
            system("pause");
            break;

        case 4:

            ordenarAutos(autos, TAMAUTOS);
            listarAutos(autos, TAMAUTOS, marcas, TAMMARCAS, Colores, TAMCOLORES, clientes, TAMCLIENTES);
            system("pause");
            break;

        case 5:

            listarMarcas(marcas, TAMMARCAS);
            system("pause");
            break;

        case 6:

            listarColores(Colores, TAMCOLORES);
            system("pause");
            break;

        case 7:

            listarServicios(Servicios, TAMSERVICIOS);
            system("pause");
            break;

        case 8:

            altaTrabajo(trabajos, TAMTRABAJOS, Servicios, TAMSERVICIOS, autos, TAMAUTOS);
            system("pause");
            break;

        case 9:

            ordenarTrabajos(trabajos, TAMTRABAJOS);
            listarTrabajos(trabajos, TAMTRABAJOS, Servicios, TAMSERVICIOS);
            system("pause");
            break;

        case 10:

            listarAutosPorColor(autos, TAMAUTOS, marcas, TAMMARCAS, Colores, TAMCOLORES);
            system("pause");
            break;

        case 11:

            listarAutosPorMarca(autos, TAMAUTOS, marcas, TAMMARCAS,Colores, TAMCOLORES);
            system("pause");
            break;

        case 12:

            listarTrabajosPorAuto(trabajos, TAMTRABAJOS, Servicios, TAMSERVICIOS, autos, TAMAUTOS, marcas, TAMMARCAS, Colores, TAMCOLORES, clientes, TAMCLIENTES);
            system("pause");
            break;

        case 13:

            listarAutosSinTrabajos(autos, TAMAUTOS, marcas, TAMMARCAS, Colores, TAMCOLORES, trabajos, TAMTRABAJOS);
            system("pause");
            break;

        case 14:

            listarImportesPorAuto(trabajos, TAMTRABAJOS, Servicios, TAMSERVICIOS, autos, TAMAUTOS, marcas, TAMMARCAS, Colores, TAMCOLORES, clientes, TAMCLIENTES);
            system("pause");
            break;

        case 15:

            ordenarTrabajos(trabajos, TAMTRABAJOS);
            listarServicioMasPedido(trabajos, TAMTRABAJOS, Servicios, TAMSERVICIOS);
            system("pause");
            break;

        case 16:

            ordenarTrabajos(trabajos, TAMTRABAJOS);
            listarRecaudacionPorFecha(trabajos, TAMTRABAJOS, Servicios, TAMSERVICIOS);
            system("pause");
            break;

        case 17:

            listarAutosPorTrabajo(Servicios, TAMSERVICIOS, trabajos, TAMTRABAJOS);
            system("pause");
            break;

        case 18:

            listarTrabajosPorColorDeAuto(autos, TAMAUTOS, Colores, TAMCOLORES, trabajos, TAMTRABAJOS, Servicios, TAMSERVICIOS);
            system("pause");
            break;

        case 19:

            listarImporteTotalPorServicio(trabajos, TAMTRABAJOS, Servicios, TAMSERVICIOS);
            system("pause");
            break;

        case 20:

            listarMarcasConMasCompletos(trabajos, TAMTRABAJOS, Servicios, TAMSERVICIOS, autos, TAMAUTOS);
            system("pause");
            break;

        case 21:

            listarAutosPorFechaDeTrabajo(trabajos, TAMTRABAJOS, Servicios, TAMSERVICIOS, autos, TAMAUTOS, marcas, TAMMARCAS, Colores, TAMCOLORES);
            system("pause");
            break;

        case 22:

            printf("\nConfirma salida? s/n: \n");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:

            printf("Opcion invalida\n");
            fflush(stdin);
            system ("pause");
            break;
        }

    }while(seguir == 's');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("  *** LAVADERO DE AUTOS ***\n\n");
    printf("1-  ALTA AUTO\n");
    printf("2-  MODIFICAR AUTO\n");
    printf("3-  BAJA AUTO\n");
    printf("4-  LISTAR AUTOS\n");
    printf("5-  LISTAR MARCAS\n");
    printf("6-  LISTAR COLORES\n");
    printf("7-  LISTAR SERVICIOS\n");
    printf("8-  ALTA TRABAJO\n");
    printf("9-  LISTAR TRABAJOS\n");
    printf("10- LISTAR AUTOS POR COLOR\n");
    printf("11- LISTAR AUTOS POR MARCA\n");
    printf("12- LISTAR TRABAJOS POR AUTO\n");
    printf("13- LISTAR AUTOS SIN TRABAJOS\n");
    printf("14- LISTAR IMPORTES POR AUTO\n");
    printf("15- LISTAR SERVICIO MAS PEDIDO\n");
    printf("16- LISTAR RECAUDACION POR FECHA\n");
    printf("17- LISTAR AUTOS POR SERVICIO\n");
    printf("18- LISTAR TRABAJOS POR COLOR DE AUTO\n");
    printf("19- LISTAR IMPORTE TOTAL POR SERVICIO\n");
    printf("20- LISTAR MARCA DE AUTO CON MAS LAVADOS COMPLETOS\n");
    printf("21- LISTAR AUTOS POR FECHA DE TRABAJO\n");
    printf("22- SALIR\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int validarMarca(eMarca marcas[], int tamMarcas, int inputMarca)
{
    int i;
    int todoOk = 0;

    for(i=0;i<tamMarcas;i++)
    {
        if(marcas[i].id == inputMarca)
        {
            todoOk = 1;
        }
    }

    return todoOk;
}

int validarColor(eColor colores[], int tamColores, int inputColor)
{
    int i;
    int todoOk = 0;

    for(i=0;i<tamColores;i++)
    {
        if(colores[i].id == inputColor)
        {
            todoOk = 1;
        }
    }

    return todoOk;
}

int validarServicio(eServicio servicios[], int tamServicios, int inputServicio)
{
    int i;
    int todoOk = 0;

    for(i=0;i<tamServicios;i++)
    {
        if(servicios[i].id == inputServicio)
        {
            todoOk = 1;
        }
    }

    return todoOk;
}

int validarPatente(eAuto autos[], int tamAutos, char inputPatente[], int tamPatente)
{
    int i;
    int todoOk = 0;

    for(i=0;i<tamAutos;i++)
    {
        if(strcmp(inputPatente, autos[i].patente)==0)
        {
            todoOk = 1;
        }
    }

    return todoOk;
}

int inicializarAutos(eAuto autos[], int tam)
{
    int todoOk = 0;
    int i;

    for(i=0; i < tam; i++)
    {
        autos[i].id = 0;
    }

    todoOk = 1;

    return todoOk;
}

int inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    int todoOk = 0;
    int i;

    for(i=0; i < tam; i++)
    {
        trabajos[i].id = 0;
    }

    todoOk = 1;

    return todoOk;
}

int buscarLibre(eAuto autos[], int tam)
{

    int indice = -1;
    int i;

    for(i=0; i < tam; i++)
    {
        if(autos[i].id == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tam)
{

    int indice = -1;
    int i;

    for(i=0; i < tam; i++)
    {
        if(trabajos[i].id == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int listarMarcas(eMarca marcas [], int tam)
{
    int i;
    int todoOk = 0;

    system("cls");

    printf("\n ID                MARCA\n");
    printf(" --                -----\n");

    for(i=0; i<tam; i++)
    {
        printf("\n %d              %s\n\n", marcas[i].id, marcas[i].descripcion);
    }

    todoOk = 1;

    return todoOk;
}

int listarColores(eColor colores [], int tam)
{
    int i;
    int todoOk = 0;

    system("cls");

    printf("\n ID                COLORES\n");
    printf(" --                -------\n");

    for(i=0; i<tam; i++)
    {
        printf("\n %d              %s\n\n", colores[i].id, colores[i].nombreColor);
    }

    todoOk = 1;

    return todoOk;
}

int listarServicios(eServicio servicios [], int tam)
{
    int i;
    int todoOk = 0;

    system("cls");

    printf("\n ID                   SERVICIO            PRECIO\n");
    printf(" --                   --------            ------\n");

    for(i=0; i<tam; i++)
    {
        printf("\n %5d              %10s           %5d\n\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
    }

    todoOk = 1;

    return todoOk;
}


int altaAuto(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes)
{

    int indice;
    int todoOk = 0;

    int auxMarca;
    int resultadoValidacionMarca;

    int auxColor;
    int resultadoValidacionColor;

    indice = buscarLibre(autos, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        autos[indice].id = indice + 1;

        printf("\n*** ALTA DE AUTO ***\n\n");

        printf("Ingrese patente :\n\n");
        fflush(stdin);
        gets(autos[indice].patente);

        listarMarcas(marcas, tamMarcas);

        printf("Ingrese ID de la marca: \n\n");
        fflush(stdin);
        scanf("%d", &auxMarca);

        resultadoValidacionMarca = validarMarca(marcas, tamMarcas, auxMarca);

        while(resultadoValidacionMarca != 1)
        {
            printf("\nId de marca invalido. Ingrese id nuevamente :\n\n");
            fflush(stdin);
            scanf("%d", &auxMarca);

            resultadoValidacionMarca = validarMarca(marcas, tamMarcas, auxMarca);

        }

        autos[indice].idMarca = auxMarca;

        listarColores(colores, tamColores);

        printf("Ingrese ID del color: \n\n");
        fflush(stdin);
        scanf("%d", &auxColor);

        resultadoValidacionColor = validarColor(colores, tamColores, auxColor);

        while(resultadoValidacionColor != 1)
        {
            printf("\nId del color invalido. Ingrese id nuevamente :\n\n");
            fflush(stdin);
            scanf("%d", &auxColor);

            resultadoValidacionColor = validarColor(colores, tamColores, auxColor);

        }

        autos[indice].idColor = auxColor;

        printf("\nIngrese modelo (Anio de fabricacion): \n\n");
        fflush(stdin);
        scanf("%d", &autos[indice].modelo);

        autos[indice].idCliente = indice + 3001;

        clientes[indice].id = indice + 3001;

        printf("\nIngrese nombre del cliente: \n\n");
        fflush(stdin);
        gets(clientes[indice].nombre);


        printf("\nIngrese sexo del cliente: -femenino o masculino-\n\n");
        fflush(stdin);
        gets(clientes[indice].sexo);

        printf("\nAlta de auto exitosa!\n\n");

    }

    todoOk = 1;

    return todoOk;
}

int buscarAutoPorPatente(eAuto autos[], int tam, char patente[])
{
    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if( stricmp(autos[i].patente, patente) == 0 && autos[i].id != 0 )
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int obtenerNombreCliente(eCliente clientes[], int tamClientes, int idCliente, char nombreCliente[])
{
    int todoOk = 0;
    int i;

    for(i=0; i < tamClientes; i++)
    {
        if(idCliente == clientes[i].id)
        {

            strcpy(nombreCliente, clientes[i].nombre);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

int obtenerSexoCliente(eCliente clientes[], int tamClientes, int idCliente, char sexoCliente[])
{
    int todoOk = 0;
    int i;

    for(i=0; i < tamClientes; i++)
    {
        if(idCliente == clientes[i].id)
        {

            strcpy(sexoCliente, clientes[i].sexo);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

int obtenerMarca(eMarca marcas[], int tamMarcas, int idMarca, char desc[])
{
    int todoOk = 0;
    int i;

    for(i=0; i < tamMarcas; i++)
    {
        if(idMarca == marcas[i].id)
        {

            strcpy(desc, marcas[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

int obtenerColor(eColor colores[], int tamColores, int idColor, char desc[])
{
    int todoOk = 0;
    int i;

    for(i=0; i < tamColores; i++)
    {
        if(idColor == colores[i].id)
        {
            strcpy(desc, colores[i].nombreColor);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

int obtenerServicio(eServicio servicios[], int tamServicios, int idServicio, char desc[])
{
    int todoOk = 0;
    int i;

    for(i=0; i < tamServicios; i++)
    {
        if(idServicio == servicios[i].id)
        {
            strcpy(desc, servicios[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

int obtenerPrecioServicio(eServicio servicios[], int tamServicios, int idServicio)
{
    int precio;
    int i;

    for(i=0; i < tamServicios; i++)
    {
        if(idServicio == servicios[i].id)
        {
            precio = servicios[i].precio;
            break;
        }
    }

    return precio;
}

int modificarAuto(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
{
    int todoOk = 0;
    char patente [21];
    int esta;
    int opcion;
    int seguir = 's';
    char nombreMarca[21];
    char nombreColor[21];

    printf("\n*** MODIFICAR AUTO ***\n\n");

    printf("Ingrese patente :\n\n");
    fflush(stdin);
    gets(patente);

    esta = buscarAutoPorPatente(autos, tam, patente);

    if(esta == -1)
    {
        printf("\nLa patente %s no esta registrada en el sistema\n\n", patente);
    }
    else
    {
        obtenerMarca(marcas, tamMarcas, autos[esta].idMarca, nombreMarca);

       do
       {

        obtenerColor(colores, tamColores, autos[esta].idColor, nombreColor);

        system("cls");

        printf("\n*** MODIFICAR AUTO ***\n\n");
        printf("ID :          %d\n",autos[esta].id);
        printf("PATENTE:      %s\n",autos[esta].patente);
        printf("MARCA:        %s\n",nombreMarca);
        printf("COLOR:        %s\n",nombreColor);
        printf("MODELO:       %d\n",autos[esta].modelo);

        printf("\nIngrese la opcion a modificiar: \n");
        printf("\n1-COLOR\n");
        printf("2-MODELO\n");
        printf("3-VOLVER AL MENU PRINCIPAL\n");
        printf("\nIngrese opcion: \n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
                listarColores(colores, tamColores);

                printf("Ingrese ID del color: \n\n");
                fflush(stdin);
                scanf("%d", &autos[esta].idColor );
                break;

        case 2:
                printf("\nIngrese modelo (Anio de fabricacion): \n\n");
                fflush(stdin);
                scanf("%d", &autos[esta].modelo);
                break;

        case 3:
                printf("Fin modificacion\n");
                seguir = 'n';
                break;

        default:

            printf("Opcion invalida\n");
            fflush(stdin);
            system ("pause");
            break;
        }

       } while(seguir == 's');
    }

    todoOk = 1;

    return todoOk;
}

int bajaAuto(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
{
    int todoOk = 0;
    char confirma;
    int esta;
    char patente[21];
    char nombreMarca[21];
    char nombreColor[21];

    printf("\n*** BAJA AUTO ***\n\n");

    printf("Ingrese patente :\n\n");
    fflush(stdin);
    gets(patente);

    esta = buscarAutoPorPatente(autos, tam, patente);

    if(esta == -1)
    {
        printf("\nLa patente %s no esta registrada en el sistema.\n\n", patente);
    }
    else
    {
        obtenerMarca(marcas, tamMarcas, autos[esta].idMarca, nombreMarca);
        obtenerColor(colores, tamColores, autos[esta].idColor, nombreColor);

        printf("\nID :          %d\n",autos[esta].id);
        printf("PATENTE:      %s\n",autos[esta].patente);
        printf("MARCA:        %s\n",nombreMarca);
        printf("COLOR:        %s\n",nombreColor);
        printf("MODELO:       %d\n\n",autos[esta].modelo);

        printf("Confirma eliminacion? s/n\n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's')
        {
            autos[esta].id = 0;

            printf("\n\nEliminacion exitosa.\n");
        }
        else
        {
            printf("\n\nEliminacion cancelada.\n");
        }
    }

    todoOk = 1;

    return todoOk;
}

int ordenarAutos(eAuto autos[], int tam)
{
    int todoOk = 0;
    int i;
    int j;

    eAuto aux;

    for(i=0; i<tam - 1; i++)
    {
        if(autos[i].id == 0)
        {
            continue;
        }

        for(j=i+1; j<tam; j++)
        {
            if(autos[j].id == 0)
            {
                continue;
            }
            else
            {
                if(autos[i].idMarca > autos[j].idMarca)
                {
                    aux = autos[j];
                    autos[j] = autos[i];
                    autos[i] = aux;


                }
                else if(autos[i].idMarca == autos[j].idMarca && stricmp(autos[i].patente, autos[j].patente)>0)
                {
                    aux = autos[j];
                    autos[j] = autos[i];
                    autos[i] = aux;
                }
            }
        }
    }

    todoOk = 1;

    return todoOk;
}

int listarAutos(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes)
{
    int todoOk = 0;
    int i;

    int contador = 0;
    char nombreMarca[21];
    char nombreColor[21];
    char nombreCliente[21];
    char sexoCliente[21];


    system("cls");

    printf(" ID-AUTO    PATENTE         MARCA       COLOR        MODELO      ID-CLIENTE\n");
    printf(" -------    -------         -----       -----        ------      ----------\n");

    for(i=0; i < tam; i++)
    {
        if(autos[i].id != 0)
        {
            obtenerMarca(marcas, tamMarcas, autos[i].idMarca, nombreMarca);
            obtenerColor(colores, tamColores, autos[i].idColor, nombreColor);

             printf("%5d      %8s    %10s    %8s    %8d    %8d\n", autos[i].id, autos[i].patente, nombreMarca, nombreColor, autos[i].modelo, autos[i].idCliente);
             contador++;
        }
    }

    printf("\n   CLIENTE         SEXO         ID-CLIENTE\n");
    printf("   -------         ----         ----------\n");

    for(i=0; i < tam; i++)
    {
        if(clientes[i].id != 0)
        {
            obtenerNombreCliente(clientes, tamClientes, clientes[i].id, nombreCliente);
            obtenerSexoCliente(clientes, tamClientes, clientes[i].id, sexoCliente);

             printf("%10s     %10s         %5d\n", nombreCliente, sexoCliente, clientes[i].id);
             contador++;

        }
    }

    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay autos que mostrar\n");
    }

    todoOk = 1;

    return todoOk;

}

int altaTrabajo(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios, eAuto autos[], int tamAutos)
{

    int todoOk = 0;
    int indice;

    int auxServicio;
    int resultadoValidacionServicio;

    char auxPatente[21];
    int tamPatente = 21;
    int resultadoValidacionPatente;

    indice = buscarLibreTrabajo(trabajos, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        trabajos[indice].id = indice + 1;

        printf("\n*** ALTA DE TRABAJO ***\n\n");

        printf("Ingrese patente :\n\n");
        fflush(stdin);
        gets(auxPatente);

        resultadoValidacionPatente = validarPatente(autos, tamAutos, auxPatente, tamPatente);

        while(resultadoValidacionPatente != 1)
        {
            printf("\nPatente invalida . Ingrese una patente existente :\n\n");
            fflush(stdin);
            gets(auxPatente);

            resultadoValidacionPatente = validarPatente(autos, tamAutos, auxPatente, tamPatente);

        }

        strcpy(trabajos[indice].patente, auxPatente);

        listarServicios(servicios, tamServicios);

        printf("Ingrese ID del servicio: \n\n");
        fflush(stdin);
        scanf("%d", &auxServicio);

        resultadoValidacionServicio = validarServicio(servicios, tamServicios, auxServicio);

        while(resultadoValidacionServicio != 1)
        {
            printf("\nId de servicio invalido. Ingrese id nuevamente :\n\n");
            fflush(stdin);
            scanf("%d", &auxServicio);

            resultadoValidacionServicio = validarServicio(servicios, tamServicios, auxServicio);

        }

        trabajos[indice].idServicio = auxServicio;

        printf("\nIngrese fecha dd/mm/aaaa: \n");
        scanf("%d %d %d", &trabajos[indice].fecha.dia, &trabajos[indice].fecha.mes, &trabajos[indice].fecha.anio);

        printf("\nAlta de trabajo exitosa!\n\n");
    }

    todoOk = 1;

    return todoOk;
}

int ordenarTrabajos(eTrabajo trabajos[], int tam)
{
    int todoOk = 0;
    int i;
    int j;

    eTrabajo aux;

    for(i=0; i<tam - 1; i++)
    {
        if(trabajos[i].id == 0)
        {
            continue;
        }

        for(j=i+1; j<tam; j++)
        {
            if(trabajos[j].id == 0)
            {
                continue;
            }
            else
            {
                if(trabajos[i].idServicio > trabajos[j].idServicio)
                {
                    aux = trabajos[j];
                    trabajos[j] = trabajos[i];
                    trabajos[i] = aux;
                }
                else if(trabajos[i].idServicio == trabajos[j].idServicio && stricmp(trabajos[i].patente, trabajos[j].patente)>0)
                {
                    aux = trabajos[j];
                    trabajos[j] = trabajos[i];
                    trabajos[i] = aux;
                }
            }
        }
    }

    todoOk = 1;

    return todoOk;
}

int listarTrabajos(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios)
{
    int todoOk = 0;
    int contador = 0;
    char nombreServicio[21];
    int i;

    system("cls");

    printf(" ID      PATENTE        SERVICIO        FECHA\n");
    printf(" --      -------        --------        -----\n");

    for(i=0; i < tam; i++)
    {
        if(trabajos[i].id != 0)
        {
            obtenerServicio(servicios, tamServicios, trabajos[i].idServicio, nombreServicio);

             printf(" %2d   %10s     %10s     %02d   %02d   %4d\n", trabajos[i].id, trabajos[i].patente, nombreServicio, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay trabajos que mostrar\n");
    }

    todoOk = 1;

    return todoOk;
}

int listarAutosPorColor(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
{
    int todoOk = 0;
    int i;
    int contador = 0;
    char nombreMarca[21];
    char nombreColor[21];
    int idColor;

    listarColores(colores, tamColores);

    printf("\nIngrese el ID del color deseado \n");
    fflush(stdin);
    scanf("%d", &idColor);

    system("cls");

    printf(" ID      PATENTE          MARCA          COLOR       MODELO\n");
    printf(" --      -------          -----          -----       ------\n");

    for(i=0; i < tam; i++)
    {
        if(autos[i].id != 0 && autos[i].idColor == idColor)
        {
            obtenerMarca(marcas, tamMarcas, autos[i].idMarca, nombreMarca);
            obtenerColor(colores, tamColores, autos[i].idColor, nombreColor);

            printf(" %2d   %10s     %10s     %10s     %7d\n", autos[i].id, autos[i].patente, nombreMarca, nombreColor, autos[i].modelo);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay autos que mostrar\n");
    }

    todoOk = 1;

    return todoOk;
}

int listarAutosPorMarca(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
{
    int todoOk = 0;
    int i;
    int contador = 0;
    char nombreMarca[21];
    char nombreColor[21];
    int IdMarca;

    listarMarcas(marcas, tamMarcas);

    printf("\nIngrese el ID de la marca deseada \n");
    fflush(stdin);
    scanf("%d", &IdMarca);

    system("cls");

    printf(" ID      PATENTE          MARCA          COLOR       MODELO\n");
    printf(" --      -------          -----          -----       ------\n");

    for(i=0; i < tam; i++)
    {
        if(autos[i].id != 0 && autos[i].idMarca == IdMarca)
        {
            obtenerMarca(marcas, tamMarcas, autos[i].idMarca, nombreMarca);
            obtenerColor(colores, tamColores, autos[i].idColor, nombreColor);

             printf(" %2d   %10s     %10s     %10s     %7d\n", autos[i].id, autos[i].patente, nombreMarca, nombreColor, autos[i].modelo);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay autos negros que mostrar\n");
    }

    todoOk = 1;

    return todoOk;
}

int listarTrabajosPorAuto(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios, eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes)
{
    int todoOk = 0;
    int i;
    int contador = 0;
    char nombreServicio[21];
    char patente [21];

    ordenarAutos(autos, tam);
    listarAutos(autos, tamAutos, marcas, tamMarcas, colores, tamColores, clientes, tamClientes);

    printf("\nIngrese la patente del auto deseado \n");
    fflush(stdin);
    gets(patente);

    system("cls");

    printf(" ID      PATENTE       SERVICIO         FECHA\n");
    printf(" --      -------       --------         -----\n");

    for(i=0; i < tam; i++)
    {
        if(trabajos[i].id != 0 && strcmp(trabajos[i].patente ,patente) == 0)
        {
            obtenerServicio(servicios, tamServicios, trabajos[i].idServicio, nombreServicio);

             printf(" %2d   %10s     %10s     %02d   %02d   %4d\n", trabajos[i].id, trabajos[i].patente, nombreServicio, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay trabajos que mostrar\n");
    }

    todoOk = 1;

    return todoOk;
}

int listarAutosSinTrabajos(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eTrabajo trabajos[], int tamTrabajos)
{
    int todoOk = 0;
    int i;
    int j;
    int flag;
    int contador = 0;
    char nombreMarca[21];
    char nombreColor[21];
    char aux[21];
    int auxComp;

    ordenarAutos(autos, tam);

    system("cls");

    printf(" ID        PATENTE           MARCA          COLOR      MODELO\n");
    printf(" --        -------           -----          -----      ------\n");

    for(i=0; i < tam; i++)
    {
        if(autos[i].id != 0)
        {
            strcpy(aux ,autos[i].patente);
        }

        flag = 0;

        for(j=0; j<tamTrabajos; j++)
        {
            if(trabajos[j].id != 0)
            {
                auxComp = strcmp(trabajos[j].patente, aux);

                if(auxComp == 0)
                {
                    flag = 1;

                }
            }
        }

        if(flag == 0)
        {
             obtenerMarca(marcas, tamMarcas, autos[i].idMarca, nombreMarca);
             obtenerColor(colores, tamColores, autos[i].idColor, nombreColor);

             printf(" %2d     %10s      %10s     %10s     %7d\n", autos[i].id, autos[i].patente, nombreMarca, nombreColor, autos[i].modelo);
             contador++;
        }
    }

    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay autos que mostrar\n");
    }

    todoOk = 1;

    return todoOk;
}

int listarImportesPorAuto(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios, eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes)
{
    int todoOk = 0;
    int i;
    int contador = 0;
    int importeServicio;
    int importeTotal = 0;
    char nombreServicio[21];
    char patente [21];

    ordenarAutos(autos, tam);
    listarAutos(autos, tamAutos, marcas, tamMarcas, colores, tamColores, clientes, tamClientes);

    printf("\nIngrese la patente del auto deseado \n");
    fflush(stdin);
    gets(patente);

    system("cls");

    printf(" ID      PATENTE       SERVICIO      PRECIO         FECHA\n");
    printf(" --      -------       --------      ------         -----\n");

    for(i=0; i < tam; i++)
    {
        if(trabajos[i].id != 0 && strcmp(trabajos[i].patente ,patente) == 0)
        {
            obtenerServicio(servicios, tamServicios, trabajos[i].idServicio, nombreServicio);
            importeServicio = obtenerPrecioServicio(servicios, tamServicios, trabajos[i].idServicio);

             printf(" %2d   %10s     %10s     %5d       %02d   %02d   %4d\n", trabajos[i].id, trabajos[i].patente, nombreServicio, importeServicio, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
             contador++;

            importeTotal += importeServicio;

        }
    }

    printf("\nEl importe total de los trabajos realizados es: %d", importeTotal);

    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo se realizaron trabajos en este auto\n\n");
    }

    todoOk = 1;

    return todoOk;
}

int listarServicioMasPedido(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios)
{
    int todoOk = 0;
    char nombreServicio[21];
    int i;
    int j;
    int aux;
    int contador = 0;

    int contadorLavado = 0;
    int contadorPulido = 0;
    int contadorEncerado = 0;
    int contadorCompleto = 0;
    int contadorTeflonado = 0;

    system("cls");

    printf(" ID      PATENTE        SERVICIO        FECHA\n");
    printf(" --      -------        --------        -----\n");

    for(i=0; i < tam; i++)
    {
        if(trabajos[i].id != 0)
        {
            obtenerServicio(servicios, tamServicios, trabajos[i].idServicio, nombreServicio);

            printf(" %2d   %10s     %10s     %02d   %02d   %4d\n", trabajos[i].id, trabajos[i].patente, nombreServicio, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay trabajos que mostrar\n");
    }

    for(j=0; j < tam; j++)
    {
        if(trabajos[j].id != 0 && trabajos[j].idServicio == 20000)
        {
            contadorLavado++;
        }
        else
        {
            if(trabajos[j].id != 0 && trabajos[j].idServicio == 20001)
            {
                contadorPulido++;
            }
            else
            {
               if(trabajos[j].id != 0 && trabajos[j].idServicio == 20002)
                {
                    contadorEncerado++;
                }
                else
                {
                   if(trabajos[j].id != 0 && trabajos[j].idServicio == 20003)
                    {
                        contadorCompleto++;
                    }
                    else
                    {
                        if(trabajos[j].id != 0 && trabajos[j].idServicio == 20004)
                        {
                            contadorTeflonado++;
                        }
                    }
                }
            }
        }
    }

    int vec[] = {contadorPulido, contadorEncerado, contadorCompleto, contadorTeflonado, contadorLavado};

    for( i=0; i < 5 - 1;  i++)
    {
        for( j = i +1; j < 5;  j++)
        {
            if( vec[i] < vec[j])
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;

            }
        }
    }

    printf("CANTIDAD DE SERVICIOS PEDIDOS\n");
    printf("-----------------------------\n");

    printf("\nLa cantidad de lavados fue de: %d\n", contadorLavado);
    printf("La cantidad de pulidos fue de: %d\n", contadorPulido);
    printf("La cantidad de encerados fue de: %d\n", contadorEncerado);
    printf("La cantidad de completos fue de: %d\n", contadorCompleto);
    printf("La cantidad de teflonados fue de: %d\n\n", contadorTeflonado);

    printf("SERVICIOS MAS PEDIDOS\n");
    printf("---------------------\n\n");

    if(contadorLavado == vec[0])
    {
        printf("Lavado : %d pedidos\n", contadorLavado);
    }

    if(contadorPulido == vec[0])
    {
        printf("Pulido : %d pedidos\n", contadorPulido);
    }

    if(contadorEncerado == vec[0])
    {
        printf("Encerado : %d pedidos\n", contadorEncerado);
    }

    if(contadorCompleto == vec[0])
    {
        printf("Lavado Completo : %d pedidos\n", contadorCompleto);
    }

    if(contadorTeflonado == vec[0])
    {
        printf("Teflonado : %d pedidos\n", contadorTeflonado);
    }

    printf("\n");

    todoOk = 1;

    return todoOk;

}

int listarRecaudacionPorFecha(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios)
{
    int todoOk = 0;
    int i;

    int dia;
    int mes;
    int anio;

    int precio;
    int precioTotal = 0;

    listarTrabajos(trabajos, tam, servicios, tamServicios);

    printf("\nIngrese fecha dd/mm/aaaa: \n");
    scanf("%d %d %d", &dia, &mes, &anio);

    for(i=0; i<tam; i++)
    {
        if(dia == trabajos[i].fecha.dia && mes == trabajos[i].fecha.mes && anio == trabajos[i].fecha.anio)
        {
            precio = obtenerPrecioServicio(servicios, tamServicios, trabajos[i].idServicio);

            precioTotal = precioTotal + precio;

        }

    }

    printf("\nLa recaudacion de la fecha ingresada es %d\n", precioTotal);

    todoOk = 1;

    return todoOk;

}

int listarAutosPorTrabajo(eServicio servicios[], int tamServicios, eTrabajo trabajos[], int tamTrabajos)
{
    int todoOk = 0;
    int i;
    int contador = 0;
    int idServicio;
    char nombreServicio[21];

    printf("\n ID                   SERVICIO            PRECIO\n");
    printf(" --                   --------            ------\n");

    for(i=0; i<tamServicios; i++)
    {
        printf("\n %5d              %10s           %5d\n\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
    }

    printf("\nIngrese el ID del servicio deseado \n");
    fflush(stdin);
    scanf("%d", &idServicio);

    system("cls");

    printf(" ID      PATENTE        FECHA          SERVICIO\n");
    printf(" --      -------        -----          --------\n");

    for(i=0; i < tamTrabajos; i++)
    {
        if(trabajos[i].id != 0 && trabajos[i].idServicio == idServicio)
        {
            obtenerServicio(servicios, tamServicios, trabajos[i].idServicio, nombreServicio);

            printf("%3d  %10s     %02d   %02d   %4d   %10s\n", trabajos[i].id, trabajos[i].patente, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio, nombreServicio);
            contador++;
        }
    }

    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay autoS que mostrar\n");
    }

    todoOk = 1;

    return todoOk;
}

int listarTrabajosPorColorDeAuto(eAuto autos[], int tam, eColor colores[], int tamColores, eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicios)
{
    int todoOk = 0;
    int i;
    int j;
    int contador = 0;
    char aux[21];
    char nombreServicio[21];
    int auxComp;
    int idColor;

    printf("\n ID                COLORES\n");
    printf(" --                -------\n");

    for(i=0; i<tamColores; i++)
    {
        printf("\n %d              %s\n\n", colores[i].id, colores[i].nombreColor);
    }

    printf("Ingrese ID del color deseado: \n\n");
    fflush(stdin);
    scanf("%d", &idColor );

    ordenarAutos(autos, tam);

    system("cls");

    printf(" ID      PATENTE        SERVICIO        FECHA\n");
    printf(" --      -------        --------        -----\n");

    for(i=0; i < tam; i++)
    {
        if(autos[i].id != 0 && autos[i].idColor == idColor)
        {
            strcpy(aux ,autos[i].patente);

            for(j=0; j<tamTrabajos; j++)
            {
                if(trabajos[j].id != 0)
                {
                    auxComp = strcmp(trabajos[j].patente, aux);

                    if(auxComp == 0)
                    {
                        obtenerServicio(servicios, tamServicios, trabajos[j].idServicio, nombreServicio);

                        printf(" %2d   %10s     %10s     %02d   %02d   %4d\n", trabajos[j].id, trabajos[j].patente, nombreServicio, trabajos[j].fecha.dia, trabajos[j].fecha.mes, trabajos[j].fecha.anio);
                        contador++;
                    }
                }
            }
        }
    }

    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay autos que mostrar\n");
    }

    todoOk = 1;

    return todoOk;
}

int listarImporteTotalPorServicio(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios)
{
    int todoOk = 0;
    int i;
    int contador = 0;
    char nombreServicio[21];
    int idServicio;
    int importe;
    int importeTotal = 0;

    printf("\n ID                   SERVICIO            PRECIO\n");
    printf(" --                   --------            ------\n");

    for(i=0; i<tamServicios; i++)
    {
        printf("\n %5d              %10s           %5d\n\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
    }

    printf("Ingrese ID del servicio deseado\n");
    fflush(stdin);
    scanf("%d", &idServicio);

    system("cls");

    printf(" ID      PATENTE       SERVICIO         FECHA\n");
    printf(" --      -------       --------         -----\n");

    for(i=0; i < tam; i++)
    {
        if(trabajos[i].id != 0 && trabajos[i].idServicio == idServicio)
        {
            obtenerServicio(servicios, tamServicios, trabajos[i].idServicio, nombreServicio);
            importe = obtenerPrecioServicio(servicios, tamServicios, idServicio);

            printf(" %2d   %10s     %10s     %02d   %02d   %4d\n", trabajos[i].id, trabajos[i].patente, nombreServicio, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
            importeTotal = importeTotal + importe;
            contador++;
        }
    }
    printf("\n\n");

    printf("El importe total por todos los trabajos de %s es %d\n", nombreServicio, importeTotal);

    if( contador == 0)
    {
        printf("\nNo hay trabajos que mostrar\n");
    }

    todoOk = 1;

    return todoOk;
}

int listarMarcasConMasCompletos(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios, eAuto autos[], int tamAutos)
{
    int todoOk = 0;
    char nombreServicio[21];
    int i;
    int j;
    int aux;
    int contador = 0;
    int auxComp;
    char auxPatente[21];

    int contadorRenault = 0;
    int contadorFiat = 0;
    int contadorFord = 0;
    int contadorChevrolet = 0;
    int contadorPeugot = 0;

    system("cls");

    printf(" ID      PATENTE        SERVICIO        FECHA\n");
    printf(" --      -------        --------        -----\n");

    for(i=0; i < tam; i++)
    {
        if(trabajos[i].id != 0)
        {
            obtenerServicio(servicios, tamServicios, trabajos[i].idServicio, nombreServicio);

            printf(" %2d   %10s     %10s     %02d   %02d   %4d\n", trabajos[i].id, trabajos[i].patente, nombreServicio, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay trabajos que mostrar\n");
    }

    for(i=0 ; i < tam ; i++)
    {
        if(trabajos[i].id != 0 && trabajos[i].idServicio == 20003)
        {
            strcpy(auxPatente ,trabajos[i].patente);

            for(j=0 ; j < tamAutos ; j++)
            {
                if(autos[j].id != 0)
                {
                    auxComp = strcmp(autos[j].patente, auxPatente);

                    if(auxComp == 0)
                    {

                        if(autos[j].idMarca == 1000)
                        {
                            contadorRenault++;
                        }
                        else
                        {
                            if(autos[j].idMarca == 1001)
                            {
                                contadorFiat++;
                            }
                            else
                            {
                                if(autos[j].idMarca == 1002)
                                {
                                    contadorFord++;
                                }
                                else
                                {
                                    if(autos[j].idMarca == 1003)
                                    {
                                        contadorChevrolet++;
                                    }
                                    else
                                    {
                                        if(autos[j].idMarca == 1004)
                                        {
                                            contadorPeugot++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int vec[] = {contadorRenault, contadorFiat, contadorFord, contadorChevrolet, contadorPeugot};

    for( i=0; i < 5 - 1;  i++)
    {
        for( j = i +1; j < 5;  j++)
        {
            if( vec[i] < vec[j])
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;

            }
        }
    }

    printf("CANTIDAD DE LAVADOS COMPLETOS POR MARCA\n");
    printf("---------------------------------------\n\n");

    printf("Completos de autos de marca Renault: %d\n", contadorRenault);
    printf("Completos de autos de marca Fiat: %d\n", contadorFiat);
    printf("Completos de autos de marca Ford: %d\n", contadorFord);
    printf("Completos de autos de marca Chevrolet: %d\n", contadorChevrolet);
    printf("Completos de autos de marca Peugot: %d\n\n", contadorPeugot);

    printf("MARCAS CON MAS LAVADOS COMPLETOS\n");
    printf("--------------------------------\n\n");

    if(contadorRenault == vec[0])
    {
        printf("Renault: %d\n", contadorRenault);
    }

    if(contadorFiat == vec[0])
    {
        printf("Fiat: %d\n", contadorFiat);
    }

    if(contadorFord == vec[0])
    {
        printf("Ford: %d\n", contadorFord);
    }

    if(contadorChevrolet == vec[0])
    {
        printf("Chevrolet: %d\n", contadorChevrolet);
    }

    if(contadorPeugot == vec[0])
    {
        printf("Peugot: %d\n\n\n", contadorPeugot);
    }

    printf("\n");

    todoOk = 1;

    return todoOk;

}

int listarAutosPorFechaDeTrabajo(eTrabajo trabajos[], int tam, eServicio servicios[], int tamServicios, eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
{
    int todoOk = 0;
    int i;
    int j;
    int auxComp;
    int contador = 0;

    int dia;
    int mes;
    int anio;

    char auxPatente[21];
    char nombreMarca[21];
    char nombreColor[21];

    listarTrabajos(trabajos, tam, servicios, tamServicios);

    printf("\nIngrese fecha dd/mm/aaaa: \n");
    scanf("%d %d %d", &dia, &mes, &anio);

    system("cls");

    printf(" ID-AUTO       PATENTE          MARCA          COLOR      MODELO\n");
    printf(" -------       -------          -----          -----      ------\n");

    for(i=0; i<tam; i++)
    {
        if(dia == trabajos[i].fecha.dia && mes == trabajos[i].fecha.mes && anio == trabajos[i].fecha.anio)
        {
            strcpy(auxPatente ,trabajos[i].patente);

            for(j=0 ; j < tamAutos ; j++)
            {
                if(autos[j].id != 0)
                {
                    auxComp = strcmp(autos[j].patente, auxPatente);

                    if(auxComp == 0)
                    {
                        obtenerMarca(marcas, tamMarcas, autos[j].idMarca, nombreMarca);
                        obtenerColor(colores, tamColores, autos[j].idColor, nombreColor);

                        printf("   %2d       %10s     %10s     %10s     %7d\n", autos[j].id, autos[j].patente, nombreMarca, nombreColor, autos[j].modelo);
                        contador++;
                    }
                }
            }
        }
    }

    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay autos que mostrar\n\n");
    }

    todoOk = 1;

    return todoOk;
}



