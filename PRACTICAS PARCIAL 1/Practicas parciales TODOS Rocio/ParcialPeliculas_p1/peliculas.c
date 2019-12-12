#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "generosActores.h"
#include "peliculas.h"

void inicilizarPeliculas(ePeliculas vec[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].estado=1;
    }
}

int buscarLibrePeliculas(ePeliculas vec[],int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].estado==1)
        {
            indice=i;
        }
    }

    return indice;


    return indice;
}

void mostrarPelicula(ePeliculas vec,eGenero vecG[], int tamG, eActores vecA[],int tamA)
{
    char actor[20];
    char genero[20];

    nombreActor(vecA,tamA,vec.idActor,actor);
    nombreGenero(vecG,tamG,vec.idGenero,genero);

    printf("%d     %d   %15s      %02d/%02d/%d     %20s    %10s\n",
           vec.idPelicula,vec.codigo,vec.titulo,vec.fechaEstreno.dia,
           vec.fechaEstreno.mes,vec.fechaEstreno.anio,actor,genero);

}

int mostrarPeliculas(ePeliculas vec[],int tam,eGenero vecG[], int tamG, eActores vecA[],int tamA)
{
    int cont=0;

    system("cls");
    printf("ID      CODIGO          TITULO       FECHA ESTRENO           ACTOR           GENERO \n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].estado==0)
        {
            mostrarPelicula(vec[i],vecG,tamG,vecA,tamA);
            cont++;
        }
    }

    if(cont == 0)
    {
        printf("\nNo hay peliculas cargadas en el sistema\n\n");
    }

    printf("\n\n");

    return cont;
}

int buscarCodigo(ePeliculas vec[],int tam,int codigo)
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

int altaPelicula(ePeliculas vec[],int tam,eActores vecA[], int tamA,eGenero vecG[],int tamG,int id)
{
    int indice;
    int codigo;
    int esta;
    int todoOk=0;

    system("cls");
    printf("**** MENU ALTA PELICULA ****\n\n");

    indice=buscarLibrePeliculas(vec,tam);

    if(indice==-1)
    {
        printf("No hay mas lugar en el sistema\n\n");
    }
    else
    {
        getIntRange(&codigo,100,999,"Ingresar codigo entre 100/999: ");

        esta=buscarCodigo(vec,tam,codigo);

        if(esta != -1)
        {
            printf("Ya existe una pelicula con ese codigo\n\n");
            mostrarPelicula(vec[esta],vecG,tamG,vecA,tamA);
        }
        else
        {
            vec[indice].idPelicula=id;
            vec[indice].codigo=codigo;

            getStringAlphaNum(50,"Ingrese nombre pelicula: ",vec[indice].titulo);

            printf("\nFECHA DE ESTRENO\n");

            getIntRange(&vec[indice].fechaEstreno.dia,1,31,"Ingrese dia: ");
            getIntRange(&vec[indice].fechaEstreno.mes,1,12,"Ingrese mes: ");
            getIntRange(&vec[indice].fechaEstreno.anio,1999,2020,"Ingrese anio: ");

            vec[indice].idActor=validarActor(vecA,tamA);
            vec[indice].idGenero=validarGenero(vecG,tamG);

            vec[indice].estado=0;
            printf("\nOperacion realizada con con exito\n\n");

            todoOk=1;
        }
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


int modificarPelicula(ePeliculas vec[],int tam,eActores vecA[], int tamA,eGenero vecG[],int tamG)
{
    int todoOk=0;
    int esta;
    int salir;
    int codigo;

    system("cls");
    printf("**** MENU ALTA PELICULA ****\n\n");

    mostrarPeliculas(vec,tam,vecG,tamG,vecA,tamA);

    getIntRange(&codigo,100,999,"Ingrese codigo de pelicula: ");

    esta=buscarCodigo(vec,tam,codigo);

    while(esta == -1)
    {
        printf("No existe pelicula con ese codigo.\n\n");
        getIntRange(&codigo,100,999,"Ingrese codigo de pelicula: ");

        esta=buscarCodigo(vec,tam,codigo);
    }
    if(esta != -1)
    {
        do
        {
            switch(menuModificacion())
            {
            case 1:
                vec[esta].idGenero=validarGenero(vecG,tamG);
                printf("Cambio realizado con exito.\n\n");
                break;

            case 2:
                vec[esta].idActor=validarActor(vecA,tamA);
                 printf("Cambio realizado con exito.\n\n");
                break;

            case 3:
                printf("\nFECHA DE ESTRENO\n");

                getIntRange(&vec[esta].fechaEstreno.dia,1,31,"Ingrese dia: ");
                getIntRange(&vec[esta].fechaEstreno.mes,1,12,"Ingrese mes: ");
                getIntRange(&vec[esta].fechaEstreno.anio,1999,2020,"Ingrese anio: ");
                 printf("Cambio realizado con exito.\n\n");
                break;

            case 4:
                getStringAlphaNum(50,"Ingrese nombre pelicula: ",vec[esta].titulo);
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

int bajaPelicula(ePeliculas vec[],int tam,eActores vecA[], int tamA,eGenero vecG[],int tamG)
{
    int todoOk=0;
    int esta;
    int codigo;

    system("cls");
    printf("**** MENU BAJA PELICULA ****\n\n");

    mostrarPeliculas(vec,tam,vecG,tamG,vecA,tamA);

    getIntRange(&codigo,100,999,"Ingrese codigo de pelicula: ");

    esta=buscarCodigo(vec,tam,codigo);

    while(esta == -1)
    {
        printf("No existe pelicula con ese codigo.\n\n");
        getIntRange(&codigo,100,999,"Ingrese codigo de pelicula: ");

        esta=buscarCodigo(vec,tam,codigo);
    }
    if(esta != -1)
    {
        vec[esta].estado=1;
        todoOk=1;
        printf("\nPelicula dada de baja con exito.\n\n");
    }

    return todoOk;
}

int hardcodeoPeliculas(ePeliculas vec[],int tam, int cantidad)
{
    int cont=0;
    ePeliculas aux[]=
    {
        {1000,482,"Thor",{3,3,2015},3,102,0},
        {1001,746,"Chucky",{3,6,2001},2,100,0},
        {1002,524,"American pie",{5,6,2011},2,101,0},
        {1003,134,"Guason",{15,2,2019},1,103,0},
        {1004,744,"Star wars",{22,12,1997},5,102,0},
        {1005,513,"It",{5,11,2018},3,100,0},
        {1006,241,"¿Que paso ayer?",{13,7,2014},4,101,0},
        {1007,252,"El cisne negro",{16,10,2010},5,103,0},
        {1008,365,"El resplandor",{27,3,1997},4,100,0},
        {1009,968,"Virgen a los 40",{30,5,2008},1,101,0},
        {1010,586,"Avengers",{31,3,2012},3,102,0}

    };

    if(cantidad <= tam && cantidad >=11)
    {
        for(int i=0; i<tam; i++)
        {
            vec[i]=aux[i];
            cont++;
        }
    }


    return cont;
}

int menuPrincipal()
{
    int opcion;

    system("cls");

    printf("**** MENU PRINCIPAL ****\n\n");
    printf("1. Alta pelicula\n");
    printf("2. Modificar pelicula\n");
    printf("3. Baja pelicula\n");
    printf("4. Listar generos\n");
    printf("5. Listar actores\n");
    printf("6. Listar peliculas\n\n");
    printf("7. Salir.\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
