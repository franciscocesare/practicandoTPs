#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "funcionesGenerales.h"
#include "utn.h"

/** \brief Menu inicial ABM
 *
 * \param
 * \param
 * \return retorna entero para el swicht.
 *
 */

int menu(){
    int opcion;
    opcion=getIn("\n\tElija opcion:\n\n 1.- ALTA \n 2.- MODIFICAR\n 3.- BAJA\n 4.- INFORMAR \n 0.- SALIR\n\n Su opcion: ");
    return opcion;
}

/** \brief recorre array buscando lugar libre.
 *
 * \param empleado es el Array de Estrucura que recibe
 * \param cant ES el largo
 * \return retorna -1 si no encontro lugar libre, si encontro retorna i, el indice libre.
 *
 */

int searchLugar(Employee empleado[], int cant){
    int i;
    for (i=0;i<cant;i++){
            if(empleado[i].isEmpty==0){
            return  i;
            }
    }
    return -1;
}

/** \brief Menu para modificar empleados
 *
 * \param
 * \param
 * \return devuelve entero con la opcions elegida.
 *
 */

int menuModificar(){
int a;
a=getIn("\n¿Que dato desea modificar?\n\t\tIngrese:\n\t1.- Apellido\n\t2.-Nombre\n\t3.- Salario\n\t4.-Sector\n Elija opcion a modificar: ");
return a;
}
/** \brief
 *
 * \param
 * \param auxLegajo Recibe el legajo a comparar para q no se repita.
 * \return Devuelve True si no encontro a nadie.
 *
 */
int searchFirstOcurrencia(Employee empleado [], int CANT, int aux){
int i;
    for (i=0;i<CANT;i++){
        if(aux==empleado[i].legajo){
            return 0;
        }
    }
return 1;
}

