#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "autos.h"
#include "trabajos.h"
#include "informes.h"

#define TAMAUTO 23
#define TAMMARCA 5
#define TAMCOLOR 5
#define TAMSERVICIO 5
#define TAMTRABAJO 50

void hardCodearAutos(eAuto vec[], int tam);
void hardCodearTrabajos(eTrabajo vec[], int tam);

int main()
{
    eAuto listaAuto[TAMAUTO];
    hardCodearAutos(listaAuto, TAMAUTO);

    eTrabajo listTrabajo[TAMTRABAJO];
    hardCodearTrabajos(listTrabajo, TAMTRABAJO);

    eMarca listaMarcas[TAMMARCA] =
    {
        {1000,"Renault"},
        {1001,"Fiat"},
        {1002,"Ford"},
        {1003,"Chevrolet"},
        {1004,"Peugeot"}
    };
    eColor listaColor[TAMCOLOR] =
    {
        {5000,"Negro"},
        {5001,"Blanco"},
        {5002,"Gris"},
        {5003,"Rojo"},
        {5004,"Azul"}
    };
    eServicio listaServicio[TAMSERVICIO] =
    {
        {20000,"Lavado",250},
        {20001,"Pulido",300},
        {20002,"Encerado",400},
        {20003,"Completo",600},
        {20004,"Aspirado",800}
    };

    char salir = 'n';
    char seguir= 's';

    do
    {
        switch(menuABM())
        {
        case 1:
            altaAuto(listaAuto, TAMAUTO, listaColor, TAMCOLOR, listaMarcas, TAMMARCA);
            break;
        case 2:
            modificarAuto(listaAuto, TAMAUTO, listaColor, TAMCOLOR, listaMarcas, TAMMARCA);
            break;
        case 3:
            bajaAuto(listaAuto, TAMAUTO, listaColor, TAMCOLOR, listaMarcas, TAMMARCA);
            break;
        case 4:
            ordenarAutos(listaAuto, TAMAUTO);
            mostrarAutos(listaAuto, TAMAUTO, listaColor, TAMCOLOR, listaMarcas, TAMMARCA);
            system("pause");
            break;
        case 5:
            mostrarMarcas(listaMarcas, TAMMARCA);
            system("pause");
            break;
        case 6:
            mostrarColores(listaColor, TAMCOLOR);
            system("pause");
            break;
        case 7:
            mostrarServicios(listaServicio, TAMSERVICIO);
            system("pause");
            break;
        case 8:
            altaTrabajo(listTrabajo, TAMTRABAJO, listaServicio, TAMSERVICIO, listaAuto, TAMAUTO, listaColor, TAMCOLOR, listaMarcas, TAMMARCA);
            system("pause");
            break;
        case 9:
            mostrarTrabajos(listTrabajo, TAMTRABAJO, listaServicio, TAMSERVICIO);
            system("pause");
            break;
        case 10:
            do
            {
                switch(menuInformes())
                {
                case 1:
                    mostrarAutosPorColor(listaAuto, TAMAUTO, listaColor, TAMCOLOR, listaMarcas, TAMMARCA);
                    system("pause");
                    break;
                case 2:
                    mostrarAutosPorMarca(listaAuto, TAMAUTO, listaColor, TAMCOLOR, listaMarcas, TAMMARCA);
                    system("pause");
                    break;
                case 3:
                    trabajosUnAuto(listaAuto, TAMAUTO, listaServicio, TAMSERVICIO, listTrabajo, TAMTRABAJO, listaColor, TAMCOLOR, listaMarcas, TAMMARCA);
                    system("pause");
                    break;
                case 4:
                    listarAutosSinTrabajos(listaAuto, TAMAUTO, listaMarcas, TAMMARCA, listaColor, TAMCOLOR, listTrabajo, TAMTRABAJO);
                    system("pause");
                    break;
                case 5:
                    importePorAuto(listaAuto, TAMAUTO, listaServicio, TAMSERVICIO, listTrabajo, TAMTRABAJO, listaColor, TAMCOLOR, listaMarcas, TAMMARCA);
                    system("pasue");
                    break;
                case 6:
                    servicioMasPedido(listTrabajo, TAMTRABAJO, listaServicio, TAMSERVICIO, listaAuto, TAMAUTO);
                    system("pause");
                    break;
                case 7:
                    totalPorFecha(listTrabajo, TAMTRABAJO, listaServicio, TAMSERVICIO);
                    system("pause");
                    break;
                case 8:
                    mostrarAutosPorTrabajo(listaAuto, TAMAUTO, listTrabajo, TAMTRABAJO, listaServicio, TAMSERVICIO);
                    system("pause");
                    break;
                case 9:
                    trabajosPorColor(listaServicio, TAMSERVICIO, listTrabajo, TAMTRABAJO, listaColor, TAMCOLOR, listaAuto, TAMAUTO);
                    system("pause");
                    break;
                case 10:
                    totalPorServicio(listTrabajo, TAMTRABAJO, listaServicio, TAMSERVICIO);
                    system("pause");
                    break;
                case 12:
                    autosConTrabajoXFecha(listaAuto, TAMAUTO, listTrabajo, TAMTRABAJO, listaColor, TAMCOLOR, listaMarcas, TAMMARCA);
                    system("pause");
                    break;
                case 13:
                    printf("\nDesea seguir? s/n: ");
                    fflush(stdin);
                    scanf("%c",&seguir);

                    if(tolower(seguir) == 's')
                    {
                        seguir = 's';
                    }
                    break;

                }
            }
            while(seguir == 's');
            break;

        case 11:
            printf("\nDesea salir? s/n: ");
            fflush(stdin);
            scanf("%c",&salir);

            if(tolower(salir) == 'n')
            {
                salir = 'n';
            }
            break;

        default:
            printf("\n\nNo se ha ingresado una opcion valida!!!!.\n\n");
            system("pause");
            menuABM();

        }
    }
    while(salir == 'n');

    return 0;
}

void hardCodearAutos(eAuto vec[], int tam)
{
    eAuto autos [23]=
    {
        {1,"AAA-201",1000,5001,1995,"sofia",'f',1},
        {2,"DFR-234",1003,5000,2002,"rocio",'f',1},
        {3,"GFT-564",1002,5003,2007,"pepe",'m',1},
        {4,"ACD-321",1002,5003,1995,"juan",'m',1},
        {5,"HTD-656",1004,5002,2008,"eva",'f',1},
        {6,"QSZ-435",1003,5001,1994,"pablo",'m',1},
        {7,"LGX-201",1001,5000,2012,"juana",'f',1},
        {8,"SUZ-324",1001,5002,1991,"mariela",'f',1},
        {9,"HCU-762",1000,5003,2008,"sandra",'f',1},
        {10,"DYC-735",1003,5001,2002,"diego",'m',1},
        {11,"JJK-879",1003,5001,2010,"ana",'f',1},
        {12,"FED-322",1004,5002,2006,"abril",'f',1},
        {13,"GHV-332",1001,5003,2007,"santiago",'m',1},
        {14,"BDE-221",1000,5004,1996,"lujan",'f',1},
        {15,"OPD-332",1000,5001,2014,"luis",'m',1},
        {16,"PPD-121",1002,5001,2015,"lucas",'m',1},
        {17,"IIT-230",1001,5000,2009,"mario",'m',1},
        {18,"KOD-220",1004,5002,2011,"gustavo",'m',1},
        {19,"QSZ-305",1004,5002,1993,"martina",'f',1},
        {20,"SSD-128",1002,5003,1992,"agustina",'f',1},
        {21,"SSD-240",1003,5004,1992,"carlos",'m',1},
        {22,"EDF-213",1001,5000,2001,"roberto",'m',1},
    };

    for(int i=0; i<tam; i++)
    {
        vec[i] = autos[i];
    }
}

void hardCodearTrabajos(eTrabajo vec[], int tam)
{
    eTrabajo trabajo [36]=
    {
        {1,"AAA-201",20000,{12,3,2019},1},
        {2,"DFR-234",20000,{2,4,2019},1},
        {3,"GFT-564",20001,{7,1,2019},1},
        {4,"ACD-321",20002,{9,11,2019},1},
        {5,"HTD-656",20003,{12,12,2019},1},
        {6,"QSZ-435",20001,{21,7,2019},1},
        {7,"LGX-201",20001,{29,8,2019},1},
        {8,"SUZ-324",20004,{31,5,2019},1},
        {9,"HCU-762",20004,{2,2,2019},1},
        {10,"DYC-735",20000,{18,2,2019},1},
        {11,"JJK-879",20001,{17,3,2019},1},
        {12,"AAA-201",20000,{17,4,2019},1},
        {13,"DFR-234",20000,{2,6,2019},1},
        {14,"GFT-564",20001,{7,3,2019},1},
        {15,"ACD-321",20002,{21,7,2019},1},
        {16,"HTD-656",20003,{11,9,2019},1},
        {17,"QSZ-435",20001,{3,7,2019},1},
        {18,"LGX-201",20001,{21,8,2019},1},
        {19,"SUZ-324",20004,{28,5,2019},1},
        {20,"HCU-762",20004,{2,8,2019},1},
        {21,"DYC-735",20000,{8,2,2019},1},
        {22,"JJK-879",20001,{17,3,2019},1},
        {23,"KOD-220",20003,{17,4,2019},1},
        {24,"QSZ-305",20000,{21,3,2019},1},
        {25,"SSD-128",20002,{16,4,2019},1},
        {26,"SSD-240",20000,{17,4,2019},1},
        {27,"EDF-213",20001,{23,3,2019},1},
        {28,"AAA-201",20000,{12,2,2019},1},
        {29,"DFR-234",20000,{2,3,2019},1},
        {30,"GFT-564",20001,{7,2,2019},1},
        {31,"ACD-321",20002,{9,12,2019},1},
        {32,"HTD-656",20003,{12,9,2019},1},
        {33,"QSZ-435",20001,{21,5,2019},1},
        {34,"HTD-656",20002,{12,2,2019},1},
        {35,"QSZ-435",20000,{21,1,2019},1},
    };

    for(int i=0; i<tam; i++)
    {
        vec[i]= trabajo[i];
    }
}


