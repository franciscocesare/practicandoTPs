#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "biblioteca.h"
#include "alquiler.h"
#include "categoria.h"
#include "cliente.h"
#include "juego.h"
#include "fecha.h"


#define TAMCAT 5
#define TAMJUEGO 10
#define TAMCLI  12
#define TAMALQ 12

///////////////////////// INFORMES
void mostrarInformes(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eCategoria categorias[], int tamCat, eJuego juegos[], int tamJuego);
void mostrarJuegosCategoriaMesa(eJuego juegos[], int tamJuego, eCategoria categorias[], int tamCat);
void alquileresPorCliente(eAlquiler alquileres[], int tamAlq, eCliente clientes[], int tamCli, eJuego juegos[], int tamJuego);
void deudaPorCliente(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eJuego juegos[], int tamJuego);
void clientesQueNoAlquilaron(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq);
int cantidadDeClietePorAlquiler( eAlquiler alquileres[], int tamAlq, int idCliente);
void juegosQueNoAlquilaron(eJuego juegos[], int tamJuego, eAlquiler alquileres[], int tamAlq, eCategoria categorias[], int tamCat);
int cantidadDeJuegosPorAlquiler( eAlquiler alquileres[], int tamAlq, int idJuego);

int menuInformes();


//////////////////////
char menu();


///////////////////////  MAIN
int main()
{
    char salir = 'N';
    int idAlquiler = 0;
    int idCliente = 0;
    int flag = 0;

    eCategoria categorias[TAMCAT]= {
        {1, "Mesa"},///id categoria, "descripcion"
        {2, "Azar"},
        {3, "Estrategia"},
        {4, "Salon"},
        {5, "Magia"}

    };

    eJuego juegos[TAMJUEGO]=  {
        {1, "MONOPOLI", 200, 1},///id juego, descrip, precio, idCategoria
        {2, "POKER", 250, 2},
        {3, "TEG", 300, 3},
        {4, "BOCHAS", 150, 4},
        {5, "LOL", 500, 5},
        {6, "LIFE", 200, 1},
        {7, "TRUCO", 250, 2},
        {8, "ARGENTUM", 300, 3},
        {9, "PING-PONG", 150, 4},
        {10, "MAGIC HAT", 500, 5}
    };

    eCliente clientes[TAMCLI];
    eAlquiler alquileres[TAMALQ];

    inicializarClientes(clientes, TAMCLI);
    inicializarAlquileres(alquileres, TAMALQ);
    idCliente = idCliente + hardcodearClientes(clientes, TAMCLI, 10);
    idAlquiler = idAlquiler + hardcodearAlquileres(alquileres, TAMALQ, 10);

     do{
        switch(menu()){
        case 'A':
            if(altaCliente(clientes, TAMCLI, idCliente)){
                idCliente++;
                flag++;
            }
            break;
        case 'B':
                // MODIFICAR
                modificarCliente(clientes, TAMCLI);
            break;
        case 'C':
                 // BAJA CLIENTE
                 bajaCliente(clientes, TAMCLI);
            break;
        case 'D':
                // LISTAR CLIENTES
                mostrarClientes(clientes, TAMCLI);
            break;
        case 'E':
                // LISTAR JUEGOS
                mostrarJuegos(juegos, TAMJUEGO, categorias, TAMCAT);
            break;
        case 'F':
                mostrarCategorias(categorias, TAMCAT);
            break;
        case 'G':
                altaAlquileres(alquileres, TAMALQ, idAlquiler, juegos, TAMJUEGO, categorias, TAMCAT, clientes, TAMCLI);
            break;
        case 'H':
                mostrarAlquileres(alquileres, TAMALQ, clientes, TAMCLI, juegos, TAMJUEGO);
            break;
        case 'I':
               // INFORMES
               mostrarInformes(clientes, TAMCLI, alquileres, TAMALQ, categorias, TAMCAT, juegos, TAMJUEGO);
            break;
        case 'J':
              getChar(&salir,"Desea Salir?  S o N: ","Error. Ingrese si S o N: ", 'S', 'N');
                    printf("\n\n");
            break;
        default:
            printf("\n\nOPCION INVALIDA!! \n\n");
            break;
        }
        system("pause");
     }while(salir == 'N');


    return 0;
}

///////////////////////////// DESARROLLO


char menu(){
    char option;

    system("cls");
    printf("************* PARCIAL *************\n");
    printf("*************   ABM   *************\n");
    printf("A- Alta Cliente\n");
    printf("B- Modificacion Cliente\n");
    printf("C- Baja Cliente\n");
    printf("D- Listar Clientes\n");
    printf("E- Listar Juegos\n");
    printf("F- Listar Categoria\n");
    printf("G- Alta Alquiler\n");
    printf("H- Listar Alquileres\n");
    printf("I- INFORMES\n");
    printf("J-  Salir\n\n");

    getCh(&option,"Ingrese Opcion: ", "Error. Ingrese Opcion: ");

    return option;
}

int menuInformes(){
    int option;

    system("cls");
    printf("\n******************** INFORMES ******************\n\n");

        printf("1- Mostra Juegos de Catetgoria MESA\n");
        printf("2- Mostrar Alquileres por Cliente Seleccionado\n");
        printf("3- Mostrar total de importes por Cliente Seleccionado\n");
        printf("4- Listar Clientes que no Alquilaron juegos\n");
        printf("5- Listar los juegos que no han sido alquilados\n");
        printf("6- CANCELAR\n\n");
        getIntRange(&option, "Ingrese Opcion: ", "Error. Reingrese Opcion: ", 1, 6);

    return option;
}

void mostrarInformes(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eCategoria categorias[], int tamCat, eJuego juegos[], int tamJuego){
    char salir = 'N';

    system("cls");
    printf("*********** INFORMES ************\n\n");

    do{
             switch( menuInformes()){
                case 1:
                        mostrarJuegosCategoriaMesa(juegos, tamJuego, categorias, tamCat);
                    break;
                case 2:
                        alquileresPorCliente(alquileres, tamAlq, clientes, tamCli, juegos, tamJuego);
                    break;
                case 3:
                        deudaPorCliente(clientes, tamCli, alquileres, tamAlq, juegos, tamJuego);
                    break;
                case 4:
                        clientesQueNoAlquilaron(clientes, tamCli, alquileres, tamAlq);
                    break;
                case 5:
                        juegosQueNoAlquilaron(juegos, tamJuego, alquileres, tamAlq, categorias, tamCat);
                    break;
                case 6:
                    //printf("Confirma salir?:");
                    //fflush(stdin);
                    //salir = getchar();
                    //printf("\n\n");
                    getChar(&salir, "Confirma Salir ?  S o N: ", "Error. Confirma Salir ?  S o N: ",'S','N');
                    break;
                default:
                    printf("\nOpcion Invalida!\n\n");
                    break;
             }
        system("pause");
    }while(salir == 'N');
}


void mostrarJuegosCategoriaMesa(eJuego juegos[], int tamJuego, eCategoria categorias[], int tamCat){

    system("cls");
    printf("***** MOSTRAR JUEGOS CATEGORIA MESA ******** \n\n");

    for(int i=0; i<tamJuego; i++){
        if(juegos[i].idCategoria == 1){
            mostrarJuego(juegos[i], categorias, tamCat);
        }
    }
}


void alquileresPorCliente(eAlquiler alquileres[], int tamAlq, eCliente clientes[], int tamCli, eJuego juegos[], int tamJuego){
    int idCliente;
    int esta;

    system("cls");
    printf("***** MOSTRAR JUEGOS CATEGORIA MESA ******** \n\n");

    mostrarClientes(clientes, tamCli);

    getInt(&idCliente, "\nIngrese ID: ", "Error. Reingrese ID: ");

    esta = buscarIdCliente(clientes, tamCli, idCliente);

    while(esta == -1){
        getInt(&idCliente, "\nIngrese ID: ", "Error. Reingrese ID: ");
        esta = buscarIdCliente(clientes, tamCli, idCliente);
    }

    printf("  ID        JUEGO           CLIENTE       FECHA \n");

    for(int i=0; i<tamAlq; i++){
        if(alquileres[i].idCliente == idCliente){
            mostrarAlquiler(alquileres[i], juegos, tamJuego, clientes, tamCli);
        }
    }
}

void deudaPorCliente(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eJuego juegos[], int tamJuego){
    float acumulador = 0;
    int idCliente;
    int esta;

    system("cls");
    printf("***** MOSTRAR DEUDA DE ALUMMNO SELECCIONADO ******** \n\n");

    mostrarClientes(clientes, tamCli);

    getInt(&idCliente, "Ingrese ID: ", "Error, Reingrese ID: ");

    esta = buscarIdCliente(clientes, tamCli, idCliente);

    if(esta == -1){
        printf("\n NO EXISTE EL CLIENTE INDICADO\n\n");
    }
    else{
        for(int i=0; i<tamAlq; i++){
            if(alquileres[i].idCliente == idCliente){
                for(int j=0; j<tamJuego; j++){
                    if(juegos[j].idJuego == alquileres[i].idJuego){
                        acumulador+=juegos[j].importe;
                    }
                }
            }
        }
        printf("El Cliente debe: $%.2f ", acumulador );
    }
}

int cantidadDeClietePorAlquiler( eAlquiler alquileres[], int tamAlq, int idCliente){
    int contador = 0;

                for(int j=0; j<tamAlq; j++){
                    if(  alquileres[j].idCliente == idCliente && alquileres[j].isEmpty == 0){
                        contador++;
                    }
                }
    return contador;
}

void clientesQueNoAlquilaron(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq){

    int cantidad[tamCli];

    system("cls");
    printf("***** CLIENTES QUE NO ALQUILARON NADA ******** \n\n");

    for(int i=0; i<tamCli; i++){
        if(clientes[i].isEmpty == 0){
            cantidad[i] = cantidadDeClietePorAlquiler(alquileres, tamAlq, clientes[i].idCliente);
        }

    }

    for(int i=0; i<tamCli; i++){
            if(cantidad[i] == 0){
               mostrarCliente(clientes[i]);
            }
    }
}


int cantidadDeJuegosPorAlquiler( eAlquiler alquileres[], int tamAlq, int idJuego){
    int contador = 0;

                for(int j=0; j<tamAlq; j++){
                    if(  alquileres[j].idJuego == idJuego && alquileres[j].isEmpty == 0){
                        contador++;
                    }
                }
    return contador;
}

void juegosQueNoAlquilaron(eJuego juegos[], int tamJuego, eAlquiler alquileres[], int tamAlq, eCategoria categorias[], int tamCat){

    int cantidad[tamJuego];

    system("cls");
    printf("***** JUEGOS QUE NO SE ALQUILARON ******** \n\n");

    for(int i=0; i<tamJuego; i++){
        if(juegos[i].isEmpty == 0){
            cantidad[i] = cantidadDeJuegosPorAlquiler(alquileres, tamAlq, juegos[i].idJuego);
        }

    }

    for(int i=0; i<tamJuego; i++){
            if(cantidad[i] == 0){
               mostrarJuego(juegos[i], categorias, tamCat);
            }
    }
}







