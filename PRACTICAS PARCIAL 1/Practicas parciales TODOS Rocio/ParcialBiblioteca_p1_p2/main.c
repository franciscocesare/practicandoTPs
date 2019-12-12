#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "libros.h"
#include "inputElian.h"

#define CANTIDADAUTORES 10
#define CANTIDADLIBROS 10
#define CANTIDADSOCIOS 1000
#define CANTIDADPRESTAMOS 100


//REMEMBER //
//sacar hardcodes
// libros 612 no se muestran los prestamos de los socios dados de baja  , el lugar sigue ocupado igual , deberia dar de baja el prestamo?

int main()
{

    //Variables//
    STR_Autores autores[CANTIDADAUTORES];
    STR_Libros libros [CANTIDADLIBROS];
    STR_Socios socios[CANTIDADSOCIOS];
    STR_Prestamos prestamos [CANTIDADPRESTAMOS];
    char seleccion;

    //Inicializacion de prestamos y socios//

    iniciarSociosIsEmpty ( socios,CANTIDADSOCIOS, 1);// 1 Significa que NO hay un socio cargado
    inciarIncrementalIdSocios (socios, CANTIDADSOCIOS);  // pongo los id del 1 al -> CANTIDADSOCIOS de uno en uno

    iniciarPrestamosIsEmpty(prestamos,CANTIDADPRESTAMOS,1);// 1 Significa que NO hay un prestamo cargado
    iniciarIncrementalIdPrestamos(prestamos,CANTIDADPRESTAMOS);// pongo los id del 1 al -> CANTIDADPRESTAMOS de uno en uno

    //Hardcode//
    hardCodeAutores(autores);
    hardCodeLibros(libros);
    hardCodeSocios(socios);
    hardCodePrestamos(prestamos);

    //Menu//
    do
    {
        menu();

        //Switch//

        fflush(stdin);
        seleccion = getchar();
        seleccion = tolower(seleccion);

        switch(seleccion)
        {

        case '1':
            limpiar();
            altaSocio(socios,CANTIDADSOCIOS);
            f_i_continuar();
            break;

        case '2':
            limpiar();
            modificarSocio(socios,CANTIDADSOCIOS);
            f_i_continuar();
            break;

        case '3':
            limpiar();
            bajaSocio(socios,CANTIDADSOCIOS);
            f_i_continuar();
            break;

        case '4':
            limpiar();
            listarSocios (socios,CANTIDADSOCIOS);
            f_i_continuar();
            break;


        case '5':
            limpiar();
            listarLibros (autores,CANTIDADAUTORES,libros,CANTIDADLIBROS);
            f_i_continuar();
            break;

        case '6':
            limpiar();
            listarAutores(autores,CANTIDADAUTORES);
            f_i_continuar();
            break;

        case '7':
            limpiar();
            altaPrestamo(prestamos,libros,CANTIDADLIBROS,socios,CANTIDADSOCIOS,autores,CANTIDADAUTORES);
            f_i_continuar();
            break;


        //PARTE 2 _____________________________________________________________________________________________________________________ //

        case 'a':
            limpiar();
            listarTotalYPromedio(prestamos,CANTIDADPRESTAMOS);
            //listarPrestamos(prestamos,CANTIDADPRESTAMOS,socios,CANTIDADSOCIOS,libros,CANTIDADLIBROS);
            f_i_continuar();
            break;

        case 'b':
            limpiar();
            listarDiasPorDebajoPromedio(prestamos,CANTIDADPRESTAMOS);
            f_i_continuar();
            break;

        case 'c':
            limpiar();
            listarPrestamosDeUnLibro(prestamos,CANTIDADPRESTAMOS,socios,CANTIDADSOCIOS,libros,CANTIDADLIBROS,autores,CANTIDADAUTORES);
            f_i_continuar();
            break;

        case 'd':
            limpiar();
            listarPrestamosDeUnSocio(prestamos,CANTIDADPRESTAMOS,socios,CANTIDADSOCIOS,libros,CANTIDADLIBROS);
            f_i_continuar();
            break;

        case 'e':
            limpiar();
            listarLibrosMenosSolicitados(prestamos,CANTIDADPRESTAMOS,libros,CANTIDADLIBROS);
            f_i_continuar();
            break;

        case 'f':
            limpiar();
            listarSociosConMasPrestamos(prestamos,CANTIDADPRESTAMOS,socios,CANTIDADSOCIOS);
            f_i_continuar();
            break;

        case 'g':
            limpiar();
            listarLibrosPorFechaPrestamo (prestamos,CANTIDADPRESTAMOS,libros,CANTIDADLIBROS);
            f_i_continuar();
            break;

        case 'h':
            limpiar();
            listarSociosPorFechaPrestamo (prestamos,CANTIDADPRESTAMOS,socios,CANTIDADSOCIOS);
            f_i_continuar();
            break;

        case 'i':
            limpiar();
            listarLibrosBurbujeo(libros,CANTIDADLIBROS);
            f_i_continuar();
            break;

        case 'j':
            limpiar();
            listarSociosInsercion(socios,CANTIDADSOCIOS);
            f_i_continuar();
            break;

        case 'x':
            limpiar();
            break;

        default :
            limpiar();
            printf("**Opcion Invalida**\n");
            f_i_continuar();
            break;
        } //switch

    }
    while (seleccion != 'x');
    return 0;
}


