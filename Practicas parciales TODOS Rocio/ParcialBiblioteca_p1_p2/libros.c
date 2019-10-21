#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "libros.h"


//*Inicializacion*//

void iniciarSociosIsEmpty ( STR_Socios iniciando[],int cantidadElementos,int numeroQueSeAsigna )
{
    int i;
    for(i=0; i < cantidadElementos ; i++)

    {
        iniciando[i].isEmpty = numeroQueSeAsigna;
    }

    return;
}


void inciarIncrementalIdSocios (STR_Socios iniciando[], int cantidadElementos )
{
    int i;
    for(i=0; i < cantidadElementos ; i++)
    {
        iniciando[i].id = i+1;
    }
    return;
}


void iniciarPrestamosIsEmpty ( STR_Prestamos iniciando[],int cantidadElementos,int numeroQueSeAsigna )
{
    int i;
    for(i=0; i < cantidadElementos ; i++)

    {
        iniciando[i].isEmpty = numeroQueSeAsigna;
        iniciando[i].idLibro = numeroQueSeAsigna;
        iniciando[i].idSocio = numeroQueSeAsigna;
    }

    return;
}

void iniciarIncrementalIdPrestamos (STR_Prestamos iniciando[], int cantidadElementos )
{
    int i;
    for(i=0; i < cantidadElementos ; i++)
    {
        iniciando[i].id = i+1;
    }
    return;
}


//*Busqueda*//

int buscarIdVacioSocio (STR_Socios socio[], int cantidadSocios)
{

    int i=0;
    for (i=0; i<cantidadSocios; i++)
    {
        if (socio[i].isEmpty == 1)
        {
            return i;
        }
    };
    return -1;
}

int buscarIndexPorIdSocio (STR_Socios socio[],int cantidadSocios,int id)
{

    int i;
    for (i=0; i<cantidadSocios; i++)
    {
        if (socio[i].id == id && socio[i].isEmpty == 0)
        {
            return i;
        }
    };

    return -1;
}

int haySocios (STR_Socios socio[], int cantidadSocios)
{

    //Veo si hay socios cargados//
    int hayUnSocio = 0, i;

    for (i=0 ; i< cantidadSocios ; i++)
    {
        if (socio[i].isEmpty == 0)
        {
            hayUnSocio = 1;
        };
    };

    //si NO hay socios
    if (hayUnSocio == 0)  //significa que no hay socios cargados
    {
        return 0;
    };

    return 1;
}


int buscarIdVacioPrestamo (STR_Prestamos prestamo[], int cantidadPrestamos)
{

    int i=0;
    for (i=0; i<cantidadPrestamos; i++)
    {
        if (prestamo[i].isEmpty == 1)
        {
            return i;
        }
    };
    return -1;
}

int buscarIndexPorIdPrestamo (STR_Prestamos prestamo[],int cantidadPrestamos,int id)
{

    int i;
    for (i=0; i<cantidadPrestamos; i++)
    {
        if (prestamo[i].id == id && prestamo[i].isEmpty == 0)
        {
            return i;
        }
    };

    return -1;
}

int hayPrestamos (STR_Prestamos prestamo [], int cantidadPrestamos)
{

    int hayUnPrestamo = 0,i;

    for (i=0 ; i< cantidadPrestamos ; i++)
    {
        if (prestamo[i].isEmpty == 0)
        {
            hayUnPrestamo = 1;
        };
    };

    //si NO hay socios
    if (hayUnPrestamo == 0)  //significa que no hay socios cargados
    {
        return 0;
    };

    return 1;
}



int buscarIndexPorIdLibro(STR_Libros libro[],int cantidadLibros,int id)
{
    int i;

    for (i=0; i<cantidadLibros; i++)
    {
        if (libro[i].id == id)
        {
            return i;
        }
    };

    return -1;
}



int buscarCantidadPrestamosCargados ( STR_Prestamos prestamo[],int cantidadPrestamos)
{
    int i,cantidadTotal = 0;
    //total general , cuento la cantidad de prestamos cargados//

    for (i=0; i<cantidadPrestamos; i++)
    {
        if(prestamo[i].isEmpty == 0)
        {
            cantidadTotal ++;
        };

    };

    return cantidadTotal;
}

float buscarPromedioDiarioPrestamos (STR_Prestamos prestamo [], int cantidadPrestamos)
{

    int cantidadTotal = 0 ;
    int diasUnicos = 0;
    float promedioDiario;

    ordenarPrestamosPorFecha(prestamo,cantidadPrestamos);

    cantidadTotal = buscarCantidadPrestamosCargados(prestamo,cantidadPrestamos);

    diasUnicos = buscarCantidadDiasUnicosPrestamos(prestamo,cantidadPrestamos);

    promedioDiario =  ( (float)cantidadTotal ) / ( (float) diasUnicos );

    return promedioDiario;
}

int buscarCantidadDiasUnicosPrestamos(STR_Prestamos prestamo[], int cantidadPrestamos )
{

    int i,diasUnicos = 0;

    ordenarPrestamosPorFecha(prestamo,cantidadPrestamos);

    // ya con el array ordenado por fecha busco la cantidad de dias diferentes ( o dias en que se trabajo ) //

    for(i=0; i<cantidadPrestamos-1; i++)
    {
        if (    (prestamo[i].fecha_Prestamo.anyo != prestamo[i+1].fecha_Prestamo.anyo) ||
                (prestamo[i].fecha_Prestamo.mes != prestamo[i+1].fecha_Prestamo.mes) ||
                (prestamo[i].fecha_Prestamo.dia != prestamo[i+1].fecha_Prestamo.dia) )
        {
            diasUnicos ++ ;
        };
    }

    return diasUnicos;
}



//*Hardcode*//

void hardCodeLibros(STR_Libros lista[])
{
    int i;
    STR_Libros ejemplos[]=
    {
        {1, "Huckleberry Finn", 10},
        {2, "Hamlet", 9},
        {3, "La Iliada", 8},
        {4, "Cien Anyos de Soledad",7 },
        {5, "La divina comedia",6},
        {6, "Crimen y Castigo",5},
        {7, "1984",4},
        {8, "El Senyor de los Anillos", 2},
        {9, "Don Quijote de la Mancha", 1},
        {10, "El Principito", 3}
    };

    for(i=0; i < 10; i++)
    {
        lista[i] = ejemplos[i];
    };
}

void hardCodeAutores(STR_Autores lista[])
{
    int i;
    STR_Autores ejemplos[]=
    {
        {1, "Miguel", "De Cervantes"},
        {2, "J.R.R","Tolkien"},
        {3, "Antoine","de Saint Exupery"},
        {4, "George","Orwell"},
        {5, "Fiodor","Dostoievski"},
        {6, "Dante","Alighieri"},
        {7, "Gabriel","Garcia Marquez"},
        {8, "Homero"," "},
        {9, "William","Shakespeare"},
        {10,"Mark","Twain"},
    };

    for(i=0; i < 10; i++)
    {
        lista[i] = ejemplos[i];
    };
}

void hardCodeSocios (STR_Socios lista[])
{
    int i;
    STR_Fecha fecha = {1,4,2000};
    STR_Fecha fechab = {2,6,2010};

    STR_Socios ejemplo[]=
    {

        {10, "Pamela ", "Subizar",'F', "11111111","Pamela@gmail.com",fechab,0},
        {20, "Martina", "Sosa",'F', "18001210", "Martina@gmail.com",fechab,0},
        {30, "Benjamín", "Garcia",'M', "324234342", "Benjamín@gmail.com",fecha,0},
        {40, "Sofia", "Flores",'F',"32324342", "Sofia@gmail.com",fechab, 0},
        {50, "Juan Ignacio", "Acosta",'M', "67555656", "Juan@gmail.com",fecha, 0},
        {60, "Thiago ", "Suarez",'M'," 36663636","Thiago@gmail.com",fecha, 0},
        {70, "Valentina", "Garcia",'F'," 2622262", "Valentina@gmail.com",fechab,0},
        {80, "Romina", "Ruiz",'F', "262444445","Romina@gmail.com",fechab, 0},
        {90, "Antonio", "Garcia",'M', "8798978905","Antonio@gmail.com",fecha, 0},
        {100, "Julieta", "Villalba",'F', "456546545", "JulietaV@gmail.com",fechab,0}
    };

    for(i=0; i < 10; i++)
    {
        lista[i] = ejemplo[i];
    };

}

void hardCodePrestamos(STR_Prestamos lista [])
{

    int i;

    STR_Fecha fechab = {1,4,2000};
    STR_Fecha fechaa = {10,4,2000};
    STR_Fecha fechac = {22,4,2000};

    STR_Prestamos ejemplo []=
    {
        {1,1,10,fechaa,0},
        {2,2,20,fechaa,0},
        {3,3,30,fechac,0},
        {4,4,40,fechab,0},
        {5,5,50,fechab,0},
        {6,6,60,fechac,0},
        {7,7,70,fechab,0},
        {8,8,80,fechab,0},
        {9,9,90,fechac,0},
        {10,10,100,fechaa,0},
    };

    for(i=0; i < 10; i++)
    {
        lista[i] = ejemplo[i];
    };

}


//*orden*//

void ordenarPrestamosPorFecha (STR_Prestamos * prestamo, int cantidadPrestamos)
{

    //Promedio diario , tengo que sacar la cantidad de prestamos con dias diferentes//
    //para eso ordeno los prestamos en base a las fechas , por año , mes , y dia//
    int i, j ;
    STR_Prestamos prestamoAUX;
    for(i=0; i<cantidadPrestamos-1; i++)
    {
        for(j = i + 1; j<cantidadPrestamos; j++)
        {

            if(prestamo[i].fecha_Prestamo.anyo > prestamo[j].fecha_Prestamo.anyo)
            {
                prestamoAUX = prestamo[j];
                prestamo[j] = prestamo[i];
                prestamo[i] = prestamoAUX;
            }

            if ( prestamo[i].fecha_Prestamo.anyo ==  prestamo[j].fecha_Prestamo.anyo)
            {

                if(prestamo[i].fecha_Prestamo.mes > prestamo[j].fecha_Prestamo.mes)
                {
                    prestamoAUX = prestamo[j];
                    prestamo[j] = prestamo[i];
                    prestamo[i] = prestamoAUX;
                };

            };

            if (prestamo[i].fecha_Prestamo.mes == prestamo[j].fecha_Prestamo.mes)
            {
                if(prestamo[i].fecha_Prestamo.dia > prestamo[j].fecha_Prestamo.dia)
                {
                    prestamoAUX = prestamo[j];
                    prestamo[j] = prestamo[i];
                    prestamo[i] = prestamoAUX;
                };
            };

        };
    };

    return;
}

//*Menu*//

void menu ()
{
    limpiar();
    printf(           "**Menu**\n"
                      "Ingrese 1 para dar de Alta un socio -\n\n"
                      "Ingrese 2 para Modificar los datos de un socio -\n\n"
                      "Ingrese 3 para dar de baja un socio -\n\n"
                      "Ingrese 4 para listar los socios ordenados por Apellido y Nombre -\n\n"
                      "Ingrese 5 para listar los libros cargados-\n\n"
                      "Ingrese 6 para listar los autores cargados-\n\n"
                      "Ingrese 7 para dar de alta un prestamo-\n\n"
                      "Ingrese A para listar total y promedio diario de los prestamos-\n\n"
                      "Ingrese B para listar cantidad de dias por debajo del promedio-\n\n"
                      "Ingrese C para listar todos los socios que solicitaron un libro especifico\n\n"
                      "Ingrese D para listar todos los libros prestados a un socio especificio\n\n"
                      "Ingrese E para listar los libros menos solicitados en prestamo\n\n"
                      "Ingrese F para listar el/los socios que realizaron mas prestamos\n\n"
                      "Ingrese G para listar libros solicitados a prestamo en una fecha especifica\n\n"
                      "Ingrese H para listar socios que realizaron un prestamo en una fecha especifica\n\n"
                      "Ingrese I para listar todos los libros ordenados por titulo (descendente)\n\n"
                      "Ingrese J para listar todos los socios ordenados por apellido (ascendente)\n\n"

                      "Ingrese X para Salir -\n\n");

    return;
}

//*Listados*//

void listarLibros (STR_Autores autor[],int cantidadAutores,STR_Libros libro[], int cantidadLibros )
{


    //Muestro los libros//

    int i,j,indexAutor;

    printf("LIBROS:\n");
    printf("Codigo Nombre:                     Autor:\n\n");

    for(i=0; i<cantidadLibros; i++)
    {
        //Busco el index del nombre del autor por su id
        for (j=0; j<cantidadAutores; j++)
        {
            if(libro[i].idAutor == autor[j].id)
            {
                indexAutor = j;
                break;
            }
        };

        printf("%3d %30s %10s %s\n", libro[i].id, libro[i].nombre,autor[indexAutor].nombre, autor[indexAutor].apellido);

    };

    return;
}

void listarAutores(STR_Autores autor [],int cantidadAutores)
{

    int i;

    printf("AUTORES:\n");
    printf("Codigo: Nombre Autor:\n\n");

    for(i=0; i<cantidadAutores; i++)
    {
        printf("%3d %15s %s\n",autor[i].id, autor[i].nombre, autor[i].apellido);
    };

    return;
}

void listarSocios (STR_Socios socio [], int cantidadSocios)
{

    STR_Socios aux;

    int i,j;
    int invalido;

    //Veo si hay socios cargados//
    invalido = haySocios(socio,cantidadSocios);

    //si NO hay socios
    if (invalido == 0)  //significa que no hay socios cargados
    {
        printf("\nNo hay socios cargados\n");
        return;
    };

    //Ordeno los socios por Apellido , si tienen el mismo apellido , por nombre//

    for(i=0; i<cantidadSocios-1; i++)
    {

        for(j=i+1; j<cantidadSocios; j++)
        {
            if( strcmp (socio[i].apellido, socio[j].apellido)>0 )
            {
                aux = socio[j];
                socio[j] = socio[i];
                socio[i] = aux;
            };

            if ( strcmp(  socio[i].apellido,socio[j].apellido) == 0 )
            {

                if( strcmp( socio[i].nombre, socio[j].nombre)>0 )
                {
                    aux = socio[j];
                    socio[j] = socio[i];
                    socio[i] = aux;
                };
            };
        };
    };
    //Muestro los socios y sus datos//

    printf("SOCIOS :\n");
    printf("Codigo: Apellido y nombre:     Sexo:  Email:             Tel:    Fecha Asociado:\n");

    for (i=0; i<cantidadSocios ; i++)
    {
        if (socio[i].isEmpty == 0)
        {
            printf("%4d %10s %-15s %1c %20s %10s %2d/%2d/%4d\n",socio[i].id,socio[i].apellido,socio[i].nombre,
                   socio[i].sexo,socio[i].email,socio[i].telefono,socio[i].fecha_Asociado.dia,socio[i].fecha_Asociado.mes,
                   socio[i].fecha_Asociado.anyo);
        };
    };
    return;
}

void listarUnSocio (STR_Socios socio [], int id)
{

    printf("Codigo: Apellido y nombre:       Sexo:  Email:              Tel:    Fecha:\n");
    printf("%4d %10s %-15s %1c %20s %10s %2d/%2d/%4d\n",socio[id].id,socio[id].apellido,socio[id].nombre,
           socio[id].sexo,socio[id].email,socio[id].telefono,socio[id].fecha_Asociado.dia,socio[id].fecha_Asociado.mes,
           socio[id].fecha_Asociado.anyo);
    return;
}

void listarPrestamos (STR_Prestamos prestamo[], int cantidadPrestamos,STR_Socios socio[], int cantidadSocios, STR_Libros libro[], int cantidadLibros)
{

    int i, invalido;
    int indexSocio, indexLibro;

    //Veo que haya almenos UN prestamo cargado.
    invalido = hayPrestamos(prestamo,cantidadPrestamos);

    //Si NO hay

    if (invalido == 0)
    {
        printf("No hay prestamos cargados");
        return;
    };
    //Si SI hay , los listo

    ordenarPrestamosPorFecha(prestamo,cantidadPrestamos);

    printf("\nPRESTAMOS CARGADOS:\n");
    printf("Codigo Socio:                   Libro:                        Fecha:\n\n");
    for(i=0; i < cantidadPrestamos ; i++)
    {

        if (prestamo[i].isEmpty == 0)
        {

            indexSocio = buscarIndexPorIdSocio(socio,cantidadSocios,prestamo[i].idSocio);

            indexLibro = buscarIndexPorIdLibro(libro,cantidadLibros,prestamo[i].idLibro);


            if (indexSocio != -1) // no se muestran los prestamos de los socios dados de baja  , el lugar sigue ocupado igual
            {
                printf("%4d %10s %-15s %-30s %2d/%2d/%2d\n",prestamo[i].id, socio[indexSocio].apellido, socio[indexSocio].nombre,
                       libro[indexLibro].nombre, prestamo[i].fecha_Prestamo.dia, prestamo[i].fecha_Prestamo.mes,
                       prestamo[i].fecha_Prestamo.anyo);
            };
        };
    };

    return;

}

void listarTotalYPromedio(STR_Prestamos prestamo[],int cantidadPrestamos)
{
    int cantidadTotal = 0, diasUnicos= 0;

    float promedioDiario=0;

    ordenarPrestamosPorFecha(prestamo,cantidadPrestamos);

    promedioDiario = buscarPromedioDiarioPrestamos(prestamo,cantidadPrestamos);

    cantidadTotal = buscarCantidadPrestamosCargados(prestamo,cantidadPrestamos);

    diasUnicos = buscarCantidadDiasUnicosPrestamos(prestamo,cantidadPrestamos);

    //Imprimo los datos

    printf("\n\nTOTAL PRESTAMOS : %d \n\nCantidad de dias en los que se realizaron prestamos: %d \n\nEl promedio diario es de %.2f prestamos por dia\n\n",
           cantidadTotal,diasUnicos,promedioDiario);

    return;
}


void listarDiasPorDebajoPromedio(STR_Prestamos prestamo [], int cantidadPrestamos )
{
    int   i = 0,j = 0, cantidadPorDebajo = 0,prestamosEseDia = 1 ;
    float promedioDiario;

    ordenarPrestamosPorFecha(prestamo,cantidadPrestamos);
    promedioDiario = buscarPromedioDiarioPrestamos(prestamo,cantidadPrestamos);

    for(i = 0 ; i<cantidadPrestamos ; i++)
    {
        if(prestamo[i].isEmpty == 0)
        {

            prestamosEseDia = 1;

            for(j = i ; j<cantidadPrestamos ; j++)
            {
                if(prestamo[j].isEmpty == 0)
                {

                    if(  (prestamo[i].fecha_Prestamo.dia == prestamo[j].fecha_Prestamo.dia)&&
                            (prestamo[i].fecha_Prestamo.anyo == prestamo[j].fecha_Prestamo.anyo)&&
                            (prestamo[i].fecha_Prestamo.mes == prestamo[j].fecha_Prestamo.mes)  )
                    {
                        prestamosEseDia ++ ;
                    }
                    else
                    {
                        //es otro dia
                        i = j-1;
                        break;
                    }
                }
            }
            if (  ((float)prestamosEseDia) < promedioDiario )
            {
                cantidadPorDebajo++;
            }
        }
    }

    //Busco y muestro los dias que no superan el promedio
    printf("Cantidad de dias en los que no se supero el promedio de prestamos: %d \n",cantidadPorDebajo);
    return;

}



void listarPrestamosDeUnLibro(STR_Prestamos prestamo[],int cantidadPrestamos,STR_Socios socio[],int cantidadSocios,STR_Libros libro[],int cantidadLibros,
                              STR_Autores autor[],int cantidadAutores)
{

    int i,invalido,seleccionUsuario;
    int indexSocio;

    //Veo que haya almenos UN prestamo cargado.
    invalido = hayPrestamos(prestamo,cantidadPrestamos);

    //Si NO hay
    if (invalido == 0)
    {
        printf("No hay prestamos cargados");
        return;
    };

    //Listo y pido un libro//

    listarLibros(autor,cantidadAutores,libro,cantidadLibros);
    fflush(stdin);
    f_i_PedirIntEntre(&seleccionUsuario,1,cantidadLibros,"Ingrese el codigo del libro para filtrar:");

    //Listo socios que pidieron ese libro//

    limpiar();
    invalido = 1;

    printf("Prestamos del libro - %d - \nCodigo de prestamo , socio  y fecha de prestamo:\n",seleccionUsuario);

    for (i=0; i<cantidadPrestamos; i++)
    {

        if (seleccionUsuario == prestamo[i].idLibro && prestamo[i].isEmpty == 0 )
        {

            indexSocio = buscarIndexPorIdSocio(socio,cantidadSocios,prestamo[i].idSocio);

            if (indexSocio != -1)
            {
                printf("%4d %10s %-15s %2d/%2d/%2d\n",prestamo[i].id, socio[indexSocio].apellido, socio[indexSocio].nombre,
                       prestamo[i].fecha_Prestamo.dia, prestamo[i].fecha_Prestamo.mes,
                       prestamo[i].fecha_Prestamo.anyo);

                invalido = 0;
            }
        }
    }

    if (invalido == 1)
    {
        printf("\nNingun socio pidio ese libro");
    };

    return;

}

void listarPrestamosDeUnSocio(STR_Prestamos prestamo[],int cantidadPrestamos,STR_Socios socio[],int cantidadSocios,STR_Libros libro[],int cantidadLibros)
{
    int i,invalido,seleccionUsuario;
    int indexLibro,indexSocio;

    //Veo que haya almenos UN prestamo cargado.
    invalido = hayPrestamos(prestamo,cantidadPrestamos);

    //Si NO hay
    if (invalido == 0)
    {
        printf("No hay prestamos cargados");
        return;
    };

    //Listo y pido un socio//

    listarSocios(socio,cantidadSocios);
    fflush(stdin);
    f_i_PedirIntEntre(&seleccionUsuario,1,cantidadSocios,"Ingrese el codigo del socio para filtrar:");

    //Listo libros que pidio ese socio//

    limpiar();
    invalido = 1;

    printf("Prestamos del socio - %d - \nCodigo de prestamo , libro  y fecha de prestamo:\n",seleccionUsuario);

    for (i=0; i<cantidadPrestamos; i++)
    {
        indexSocio = buscarIndexPorIdSocio(socio,cantidadSocios,seleccionUsuario);

        if (seleccionUsuario == prestamo[i].idSocio && prestamo[i].isEmpty == 0 && socio[indexSocio].isEmpty == 0)
        {

            indexLibro = buscarIndexPorIdLibro(libro,cantidadLibros,prestamo[i].idLibro);

            if (indexLibro != -1)
            {

                printf("%4d %10s %2d/%2d/%2d\n",prestamo[i].id, libro[indexLibro].nombre,
                       prestamo[i].fecha_Prestamo.dia, prestamo[i].fecha_Prestamo.mes,
                       prestamo[i].fecha_Prestamo.anyo);
                invalido = 0;
            }
        }
    }

    if (invalido == 1)
    {
        printf("\nNo hay ningun prestamos afiliado a ese socio");
    };

    return;

}



void listarLibrosPorFechaPrestamo (STR_Prestamos prestamo [],int cantidadPrestamos, STR_Libros libro[],int cantidadLibros)
{

    int i, indexLibro, invalido;
    int dia,mes,anyo;

    //Veo que haya almenos UN prestamo cargado.
    invalido = hayPrestamos(prestamo,cantidadPrestamos);

    //Si NO hay
    if (invalido == 0)
    {
        printf("No hay prestamos cargados");
        return;
    };

    //Pido Fecha
    pedirFecha(&dia,&mes,&anyo,"se realizo el prestamo","se realizo el prestamo","se realizo el prestamo");

    //Listo
    limpiar();
    invalido = 1;
    printf("Libros pedidos el %d-%d-%d:\n\n",dia,mes,anyo);
    printf("Codigo prestamo , Codigo Libro  y nombre:\n\n");

    for(i=0; i<cantidadPrestamos; i++)
    {

        if (( prestamo[i].fecha_Prestamo.dia == dia) && (prestamo[i].fecha_Prestamo.mes == mes ) &&(prestamo[i].fecha_Prestamo.anyo == anyo))
        {
            indexLibro = buscarIndexPorIdLibro(libro,cantidadLibros,prestamo[i].idLibro);

            printf("%4d              %3d- %s\n", prestamo[i].id, libro[i].id,libro[indexLibro].nombre);

            invalido = 0;
        };
    };

    if (invalido == 1)
    {
        printf("\n*No se pidio ningun prestamo en esta fecha* \n");
    }

    return;
}

void listarSociosPorFechaPrestamo (STR_Prestamos prestamo [],int cantidadPrestamos, STR_Socios socio[], int cantidadSocios)
{
    int i, indexSocio, invalido;
    int dia,mes,anyo;

    //Veo que haya almenos UN prestamo cargado.
    invalido = hayPrestamos(prestamo,cantidadPrestamos);

    //Si NO hay
    if (invalido == 0)
    {
        printf("No hay prestamos cargados");
        return;
    };

    //Pido Fecha
    pedirFecha(&dia,&mes,&anyo,"se realizo el prestamo","se realizo el prestamo","se realizo el prestamo");

    //Listo
    limpiar();
    invalido = 1;
    printf("Socios que realizaron pedidos pedidos el %d-%d-%d:\n\n",dia,mes,anyo);

    printf("Codigo prestamo , Codigo Socio y nombre:\n\n");

    for(i=0; i<cantidadPrestamos; i++)
    {

        indexSocio = buscarIndexPorIdSocio(socio,cantidadSocios,prestamo[i].idSocio);

        if (( prestamo[i].fecha_Prestamo.dia == dia) && (prestamo[i].fecha_Prestamo.mes == mes ) &&(prestamo[i].fecha_Prestamo.anyo == anyo)
                && socio[indexSocio].isEmpty == 0)
        {

            printf("%4d              %3d- %s %s\n", prestamo[i].id,socio[i].id, socio[indexSocio].nombre, socio[indexSocio].apellido );

            invalido = 0;
        };
    };

    if (invalido == 1)
    {
        printf("\n*No se pidio ningun prestamo en esta fecha* \n");
    }
    return;
}



void listarSociosInsercion (STR_Socios socio[],int cantidadSocios)
{

    int i,j;
    STR_Socios temp;

    //Ordeno por insercion

    for(i=1 ; i<cantidadSocios ; i++)
    {

        temp = socio[i];

        j=i-1;

        while(j>=0 && (strcmp (temp.apellido,socio[j].apellido) < 0) )
        {

            socio[j+1] = socio[j];
            j--;
        }

        socio[j+1]=temp;

    }

    //Muestro los socios y sus datos//

    printf("SOCIOS :\n");
    printf("Codigo: Apellido y nombre:       Sexo:  Email:              Tel:    Fecha:\n");

    for (i=0; i<cantidadSocios ; i++)
    {

        if (socio[i].isEmpty == 0)
        {
            printf("%4d %10s %-15s %1c %20s %10s %2d/%2d/%4d\n",socio[i].id,socio[i].apellido,socio[i].nombre,
                   socio[i].sexo,socio[i].email,socio[i].telefono,socio[i].fecha_Asociado.dia,socio[i].fecha_Asociado.mes,
                   socio[i].fecha_Asociado.anyo);
        };
    };

    return;
}


void listarLibrosBurbujeo(STR_Libros libro[], int cantidadLibros)
{

    int j,i;
    STR_Libros aux;
    int flagNoEstaOrdenado = 1;

    while (flagNoEstaOrdenado==1)
    {
        flagNoEstaOrdenado = 0;
        for (j = 1; j < cantidadLibros ; j++)
        {

            if ( strcmp( libro[j].nombre, libro[j-1].nombre)>0)
            {
                aux = libro[j];
                libro[j] = libro[j-1];
                libro[j-1] = aux;
                flagNoEstaOrdenado = 1;
            }
        }
    }

    printf("LIBROS:\n");
    printf("Codigo  Nombre:\n\n");

    for(i=0; i<cantidadLibros; i++)
    {

        printf("%3d-     %s\n", libro[i].id,libro[i].nombre);

    };
}



void listarLibrosMenosSolicitados (STR_Prestamos*prestamo,int cantidadPrestamos,STR_Libros * libro,int cantidadLibros)
{

//validar que haya prestamos cargados

    int i,j,invalido;
    int valorMenosPedido = 0;
    int cuantasVecesSePidioElLibro;

    //Veo que haya almenos UN prestamo cargado.
    invalido = hayPrestamos(prestamo,cantidadPrestamos);

    //Si NO hay
    if (invalido == 0)
    {
        printf("No hay prestamos cargados");
        return;
    };



    //Busco el valor la menor cantidad de pedidos//

    for (i = 0 ; i<cantidadLibros ; i++)
    {

        cuantasVecesSePidioElLibro=0;

        for (j=0; j<cantidadPrestamos ; j++)
        {
            if (prestamo[j].isEmpty==0)
            {

                if(prestamo[j].idLibro == libro[i].id)
                {
                    cuantasVecesSePidioElLibro ++;
                }
            }
        }
        if(i==0)
        {
            valorMenosPedido=cuantasVecesSePidioElLibro;
        }

        if(valorMenosPedido > cuantasVecesSePidioElLibro)
        {
            valorMenosPedido = cuantasVecesSePidioElLibro;
        }

    }
    /////
    //ya sabiendo el valor de la menor cantidad de pedidos a un libro, listo los que fueron pedidos esa cantidad de veces.

    printf("Libros Menos pedidos (prestados %d veces)\n",valorMenosPedido);

    printf("Codigo: Nombre:\n\n");

    for (i = 0 ; i<cantidadLibros ; i++)
    {
        cuantasVecesSePidioElLibro=0;

        for (j=0; j<cantidadPrestamos ; j++)
        {
            if (prestamo[j].isEmpty==0)
            {

                if(prestamo[j].idLibro == libro[i].id)
                {
                    cuantasVecesSePidioElLibro ++;
                }
            }
        }

        if(cuantasVecesSePidioElLibro == valorMenosPedido)
        {
            printf("%3d - %s\n",libro[i].id,libro[i].nombre);
        }


    }

    return;

}


void listarSociosConMasPrestamos (STR_Prestamos*prestamo,int cantidadPrestamos,STR_Socios * socio,int cantidadSocios)
{

//validar que haya prestamos cargados

    int i,j,invalido;
    int valorMasPrestamos = 0;
    int cuantasVecesPidioPrestamo;

    //Veo que haya almenos UN prestamo cargado.
    invalido = hayPrestamos(prestamo,cantidadPrestamos);

    //Si NO hay
    if (invalido == 0)
    {
        printf("No hay prestamos cargados");
        return;
    };



    //Busco el valor la menor cantidad de pedidos//

    for (i = 0 ; i < cantidadSocios ; i++)
    {

        cuantasVecesPidioPrestamo=0;

        if (socio[i].isEmpty==0)
        {

            for (j=0; j < cantidadPrestamos ; j++)
            {
                if (prestamo[j].isEmpty==0)
                {

                    if(prestamo[j].idSocio == socio[i].id)
                    {
                        cuantasVecesPidioPrestamo ++;
                    }
                }
            }
            if(i==0)
            {
                valorMasPrestamos = cuantasVecesPidioPrestamo;
            }

            if(valorMasPrestamos < cuantasVecesPidioPrestamo)
            {
                valorMasPrestamos = cuantasVecesPidioPrestamo;
            }
        }

    }

    //ya sabiendo la mayor cantidad de prestamos realizados, listo los socios que pidieron esa cantidad de prestamos



    printf("Socios que mas prestamos pidieron(total de %d prestamos)\n",valorMasPrestamos);

    printf("Codigo Socio: Apellido y nombre:\n\n");

    for (i = 0 ; i < cantidadSocios ; i++)
    {

        cuantasVecesPidioPrestamo=0;

        if (socio[i].isEmpty==0)
        {

            for (j=0; j < cantidadPrestamos ; j++)
            {
                if (prestamo[j].isEmpty==0)
                {

                    if(prestamo[j].idSocio == socio[i].id)
                    {
                        cuantasVecesPidioPrestamo ++;
                    }
                }
            }

            if(cuantasVecesPidioPrestamo == valorMasPrestamos)
            {
                printf("%4d      - %s %s\n",socio[i].id, socio[i].apellido, socio[i].nombre);
            }
        }

    }

    return;

}



//*Altas*//

void altaSocio (STR_Socios socio [], int cantidadSocios)
{

    char auxName [31];
    char auxLastName[31];
    char auxSexo;
    char auxEmail[31];
    char auxTelef[16];
    STR_Fecha auxfecha;
    int invalido, id;

    invalido = buscarIdVacioSocio(socio, cantidadSocios);  //Busco el primer id vacio

    if (invalido == -1) // si NO se encuentra un id vacio
    {
        printf("\nNo queda lugar\n");
        return;
    };

    //si SI se encuentra un id vacio le cargo los datos//

    id = invalido;
    limpiar();
    f_i_PedirNombre(auxName, 31, "\nIngrese el Nombre del socio:");
    limpiar();
    fflush(stdin);
    f_i_PedirNombre(auxLastName, 31, "\nIngrese el Apellido del socio:");
    limpiar();
    f_i_PedirSexo(&auxSexo, "\nIngrese el sexo del socio:");
    limpiar();
    f_i_PedirTelefono(auxTelef,16,"\nIngrese el telefono del socio:");
    limpiar();
    f_i_PedirEmail(auxEmail, 31, "\nIngrese el email del socio:");
    limpiar();
    pedirFecha(&auxfecha.dia,&auxfecha.mes,&auxfecha.anyo,"Se registro el socio","Se registro el socio","Se registro el socio");
    limpiar();

    strcpy(socio[id].nombre, auxName);
    strcpy(socio[id].apellido, auxLastName);
    socio[id].sexo = auxSexo;
    strcpy(socio[id].telefono, auxTelef);
    strcpy(socio[id].email, auxEmail);
    socio[id].fecha_Asociado = auxfecha;
    socio[id].isEmpty = 0;

    printf("\nSocio cargado correctamente\n");

    fflush(stdin);
    return;
}


void altaPrestamo( STR_Prestamos prestamo[], STR_Libros libro [],int cantidadLibros, STR_Socios socio[],int cantidadSocios, STR_Autores autor[],int cantidadAutores)
{

    int invalido = 1, indexPrestamo, seleccionUsuario,auxIdSocio;
    STR_Fecha auxFecha;

    //Veo si hay socios cargados//

    invalido = haySocios(socio,cantidadSocios);

    //si NO hay socios
    if (invalido == 0)  //significa que no hay socios cargados
    {
        printf("\nNo hay socios cargados\n");
        return;
    };

    //si SI hay socios cargados, veo si hay lugar para prestamos

    invalido = buscarIdVacioPrestamo(prestamo, cantidadSocios);  //Busco el primer id vacio

    if (invalido == -1) // si NO se encuentra un id vacio
    {
        printf("\nNo queda lugar\n");
        return;
    };

    //si SI se encuentra un id vacio, cargo los datos//

    indexPrestamo = invalido;

    //Pido codigo Socio
    limpiar();

    listarSocios(socio,cantidadSocios);
    f_i_PedirIntEntre(&seleccionUsuario,1, cantidadSocios,"\nIngrese el codigo del socio que realizo el prestamo:");

    auxIdSocio = seleccionUsuario; // guardo el valor del id del socio

    //valido que exista y saco el index del socio

    seleccionUsuario = buscarIndexPorIdSocio(socio,cantidadSocios,seleccionUsuario);

    //si no existe
    if (seleccionUsuario == -1)
    {
        limpiar();
        printf("Codigo de socio invalido");
        return;
    };

    //si si existe
    prestamo[indexPrestamo].idSocio = auxIdSocio; //uso este porque seleccionUsuario es el valor del index del socio , no del id.

    //Pido codigo de libro//
    limpiar();
    listarLibros(autor,cantidadAutores,libro,cantidadLibros);
    f_i_PedirIntEntre(&seleccionUsuario, 1, cantidadLibros,"\nIngrese el codigo del libro prestado:");
    prestamo[indexPrestamo].idLibro = seleccionUsuario;

    //Pido fecha de prestamo
    limpiar();
    pedirFecha(&auxFecha.dia,&auxFecha.mes,&auxFecha.anyo,"se realizo el prestamo","se realizo el prestamo","se realizo el prestamo");
    prestamo[indexPrestamo].fecha_Prestamo = auxFecha;

    prestamo[indexPrestamo].isEmpty = 0 ; // ocupo el prestamo

    limpiar();
    printf("\nPrestamo cargado correctamente");
    return;
}


//*Modificacion*//

void modificarSocio (STR_Socios socio [], int cantidadSocios)
{


    int invalido, id;

    //Veo si hay socios cargados//
    invalido = haySocios(socio,cantidadSocios);

    //si NO hay socios
    if (invalido == 0)  //significa que no hay socios cargados
    {
        printf("\nNo hay socios cargados\n");
        return;
    };


    //Si SI hay socios cargados , los listo//
    listarSocios(socio,cantidadSocios);

    //pido el id del socio a modificar//
    f_i_PedirIntEntre(&id,1,cantidadSocios,"Ingrese el codigo del socio a modificar");

    //Busco si hay un socio cargado en ese id//
    invalido = buscarIndexPorIdSocio(socio,cantidadSocios,id);

    if (invalido == -1) // si no se encuentra el id ingresado
    {
        limpiar();
        printf("\nCodigo de socio invalido\n");
        return;
    };

    //si SI se encuentra//
    id = invalido;
    //confirmo
    limpiar();
    listarUnSocio(socio,id);
    invalido = f_i_SioNo("Desea modificar este socio?");

    if (invalido == 0)
    {
        limpiar();
        printf("\nNo se modifico el socio");
        return;
    };

    //Si se ingresa S , modifico los datos//

    int opcion;
    char auxName [31];
    char auxLastName[31];
    char auxSexo;
    char auxEmail[31];
    char auxTelef[16];
    STR_Fecha auxfecha;

    limpiar();
    f_i_PedirIntEntre(&opcion,1,7,"1-Modificar Nombre\n2-Modificar Apellido\n3-Modificar Sexo\n"
                      "4-Modificar Telefono\n5-Modificar Email\n6-Modificar Fecha de asociado\n7-Salir\nOpcion: ");

    switch (opcion)
    {

    case 1 :
        limpiar();
        f_i_PedirNombre(auxName,31,"\nIngrese el Nombre del Socio:\n");
        strcpy(socio[id].nombre,auxName);
        break;

    case 2 :
        limpiar();
        f_i_PedirNombre(auxLastName,31,"\nIngrese el Apellido del Socio:\n");
        strcpy(socio[id].apellido,auxLastName);
        break;

    case 3 :
        limpiar();
        f_i_PedirSexo(&auxSexo,"\nIngrese el sexo del Socio:\n");
        socio[id].sexo = auxSexo;
        break;

    case 4 :
        limpiar();
        f_i_PedirTelefono(auxTelef,16,"\nIngrese el Telefono del Socio:\n");
        strcpy(socio[id].telefono,auxTelef);
        break;

    case 5 :
        limpiar();
        f_i_PedirEmail(auxEmail,31,"\nIngrese el Email del Socio:\n");
        strcpy(socio[id].email,auxEmail);
        break;

    case 6 :
        limpiar();
        pedirFecha(&auxfecha.dia,&auxfecha.mes,&auxfecha.anyo,"Se registro el socio","Se registro el socio","Se registro el socio");
        socio[id].fecha_Asociado = auxfecha;
        break;
    case 7:
        return;
    }
    limpiar();
    printf("\n*Socio Modificado Correctamente*\n");
    return;


}


//*Baja*//

void bajaSocio(STR_Socios socio [], int cantidadSocios)
{

    int invalido, id;

    //Veo si hay socios cargados//

    invalido = haySocios(socio,cantidadSocios);

    //si NO hay socios
    if (invalido == 0)  //significa que no hay socios cargados
    {
        printf("\nNo hay socios cargados\n");
        return;
    };

    //Si SI hay socios cargados , los listo//
    listarSocios(socio,cantidadSocios);

    //pido el id del socio a modificar//
    f_i_PedirIntEntre(&id,1,cantidadSocios,"Ingrese el codigo del socio a dar de baja");

    //Busco si hay un socio cargado en ese id//
    invalido = buscarIndexPorIdSocio(socio,cantidadSocios,id);

    if (invalido == -1) // si no se encuentra el id ingresado
    {
        limpiar();
        printf("\nCodigo de socio invalido\n");
        return;
    };

    //si SI se encuentra//
    id = invalido;
    //confirmo
    limpiar();
    listarUnSocio(socio,id);
    invalido = f_i_SioNo("Desea dar de baja este socio?");

    if (invalido == 0)
    {
        limpiar();
        printf("\nNo se dio de baja el socio");
        return;
    };

    limpiar();
    socio[id].isEmpty = 1;
    printf("\nSe dio de baja el socio");
    return;


}



