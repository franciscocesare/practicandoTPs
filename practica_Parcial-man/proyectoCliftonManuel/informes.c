#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "informes.h"
#include "biblioteca.h"

int menuInformes(){
    int option;

    system("cls");
    printf("\n******************** INFORMES ******************\n\n");

        printf("1- Mostra Juegos de Catetgoria MESA\n");
        printf("2- Mostrar Alquileres por Cliente Seleccionado\n");
        printf("3- Mostrar total de importes por Cliente Seleccionado\n");
        printf("4- Listar Clientes que no Alquilaron juegos\n");
        printf("5- Listar los juegos que no han sido alquilados\n");

        printf("6- Listar Clientes de una Localidad Determinada\n");
        printf("7- Juegos preferidos por Localidad\n");
        printf("8- Listar Juegos Alquilados por Mujeres\n");

        printf("0- CANCELAR\n\n");
        getIntRange(&option, "Ingrese Opcion: ", "Error. Reingrese Opcion: ", 0, 10);

    return option;
}

void mostrarInformes(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eCategoria categorias[], int tamCat, eJuego juegos[], int tamJuego, eLocalidad localidades[], int tamLoc){
    char salir = 'N';

    system("cls");
    printf("*********** INFORMES ************\n\n");

    do{
             switch( menuInformes()){
                case 1:
                        mostrarJuegosCategoriaMesa(juegos, tamJuego, categorias, tamCat);
                    break;
                case 2:
                        alquileresPorCliente(alquileres, tamAlq, clientes, tamCli, juegos, tamJuego, localidades, tamLoc);
                    break;
                case 3:
                        deudaPorCliente(clientes, tamCli, alquileres, tamAlq, juegos, tamJuego, localidades, tamLoc);
                    break;
                case 4:
                        clientesQueNoAlquilaron(clientes, tamCli, alquileres, tamAlq, localidades, tamLoc);
                    break;
                case 5:
                        juegosQueNoAlquilaron(juegos, tamJuego, alquileres, tamAlq, categorias, tamCat);
                    break;
                case 6:
                        mostrarClientePorLocalidad(localidades, tamLoc, clientes, tamCli);
                    break;
                case 7:
                        juegoPreferidoPorLocalidad(juegos, tamJuego, alquileres, tamAlq, categorias, tamCat, localidades, tamLoc, clientes, tamCli);
                    break;
                case 8:
                       juegosAlquialdosPorMujeres(alquileres, tamAlq, juegos, tamJuego, clientes, tamCli, categorias, tamCat);
                    break;
                case 0:
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


void alquileresPorCliente(eAlquiler alquileres[], int tamAlq, eCliente clientes[], int tamCli, eJuego juegos[], int tamJuego, eLocalidad localidades[], int tamLoc){
    int idCliente;
    int esta;

    system("cls");
    printf("***** MOSTRAR JUEGOS CATEGORIA MESA ******** \n\n");

    mostrarClientes(clientes, tamCli, localidades, tamLoc);

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

void deudaPorCliente(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eJuego juegos[], int tamJuego, eLocalidad localidades[], int tamLoc){
    float acumulador = 0;
    int idCliente;
    int esta;

    system("cls");
    printf("***** MOSTRAR DEUDA DE ALUMMNO SELECCIONADO ******** \n\n");

    mostrarClientes(clientes, tamCli, localidades, tamLoc);

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

void clientesQueNoAlquilaron(eCliente clientes[], int tamCli, eAlquiler alquileres[], int tamAlq, eLocalidad localidades[], int tamLoc){

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
               mostrarCliente(clientes[i], localidades, tamLoc);
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


void mostrarClientePorLocalidad(eLocalidad localidades[], int tamLoc, eCliente clientes[], int tamCli){
    int idLocalidad;
    int esta;

    system("cls");
    printf("***** MOSTRAR CLIENTES POR LOCALIDAD ******** \n\n");

    mostrarLocalidades(localidades, tamLoc);


    getInt(&idLocalidad, "\nIngrese ID: ", "Error. Reingrese ID: ");

    esta = buscarIdLocalidad(localidades, tamLoc, idLocalidad);

    while(esta == -1){
        getInt(&idLocalidad, "\nIngrese ID: ", "Error. Reingrese ID: ");
        esta = buscarIdLocalidad(localidades, tamLoc, idLocalidad);
    }

    printf(" ID    NOMBRE     APELLIDO   SEXO    TELEFONO    DOMICILIO       LOCALIDAD \n");

    for(int i=0; i<tamCli; i++){
        if(clientes[i].idLocalidad == idLocalidad){
            mostrarCliente(clientes[i], localidades, tamLoc);
        }
    }
}





int cantidadJuegosPorLocalidad(eAlquiler alquileres[], int tamAlq, int idJuego){

    int contador = 0;

            for(int i=0; i<tamAlq; i++){
                if(alquileres[i].idJuego == idJuego && alquileres[i].isEmpty == 0){
                            contador++;
                }
            }

    return contador;

}


void juegoPreferidoPorLocalidad(eJuego juegos[], int tamJuego, eAlquiler alquileres[], int tamAlq, eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamLoc, eCliente clientes[], int tamCli){

    int idLocalidad;
    int esta;
    int cantidad[tamJuego];
    int mayor;
    int flag = 0;

    system("cls");
    printf("***** JUEGOS PREFERIDO POR LOCALIDAD ******** \n\n");

    mostrarLocalidades(localidades, tamLoc);

    getInt(&idLocalidad, "\nIngrese ID: ", "Error. Reingrese ID: ");

    esta = buscarIdLocalidad(localidades, tamLoc, idLocalidad);

    while(esta == -1){
        getInt(&idLocalidad, "\nIngrese ID: ", "Error. Reingrese ID: ");
        esta = buscarIdLocalidad(localidades, tamLoc, idLocalidad);
    }


    for(int i=0; i<tamCli; i++){
        if(clientes[i].idLocalidad == idLocalidad && clientes[i].isEmpty == 0){
            for(int j=0; j<tamJuego; j++){
                cantidad[j] = cantidadJuegosPorLocalidad(alquileres, tamAlq, juegos[j].idJuego);
                printf("%d\n\n", cantidad[i]);
            }
        }
    }

    for(int i=0; i<tamJuego; i++){
            if(cantidad[i] > mayor || flag == 0){
                mayor = cantidad[i];
                flag = 1;
            }
    }

    printf("Juego preferido fue elegido %d veces. \n\n", mayor);

    for(int i=0; i<tamJuego; i++){
        if(cantidad[i] == mayor){
            mostrarJuego(juegos[i], categorias, tamCat);
        }
    }

}




void juegosAlquialdosPorMujeres(eAlquiler alquileres[], int tamAlq, eJuego juegos[], int tamJuego, eCliente clientes[], int tamCli, eCategoria categorias[], int tamCat){

    int flag=0;

    for(int i=0; i<tamAlq; i++){
        if(alquileres[i].isEmpty == 0){
            for(int k=0; k<tamCli; k++){
                if(clientes[k].sexo == 'F'){
                    for(int j=0; j<tamJuego; j++){
                        if(juegos[j].idJuego == alquileres[i].idJuego){
                            flag++;
                            if(flag!=0){
                                mostrarJuego(juegos[j], categorias, tamCat);
                            }
                        }
                }
            }
        }
    }
   }

}
















