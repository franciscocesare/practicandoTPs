#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "Dominio.h"

/** \brief Valida el valor de la ID y lo carga en estructura.
 *
 * \param recibe puntero de estructura Employee.
 * \param Toma el valor ID ingresado por el usuario.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eCachorro_setId(eCachorro* listaCachorro,int id)
{
    int result=0;
    if(listaCachorro!=NULL && id >0)
    {
        listaCachorro->id_cachorro = id;
        result=1;
    }

    return result;
}

/** \brief Toma valor de ID de una estructura Employee.
 *
 * \param recibe puntero de estructura Employee.
 * \param puntero a entero y que guardara el valor del ID.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eCachorro_getId(eCachorro* listaCachorro,int* id)
{
    int result=0;

    if(listaCachorro!=NULL && id!=NULL)
    {
        *id = listaCachorro->id_cachorro;
        result = 1;
    }

    return result;
}

/** \brief Valida la cadena y lo carga en estructura.
 *
 * \param Recibe puntero de estructura Employee.
 * \param Recibe cadena de caracteres.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eCachorro_setNombre(eCachorro* listaCachorro, char* nombre)
{
    int result=0;
    if( listaCachorro != NULL && nombre != NULL && strlen(nombre) >= 20 )
    {
        strcpy(listaCachorro->nombre, nombre);
        result = 1;
    }
    return result;
}


/** \brief Toma la cadena de una estructura Employee.
 *
 * \param Recibe puntero de estructura Employee.
 * \param Puntero a char donde guardara la cadena de la estructura.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eCachorro_getnombre(eCachorro* listaCachorro,char* nombre)
{

    int result=0;
    if( listaCachorro != NULL && nombre != NULL)
    {
        strcpy( nombre,listaCachorro->nombre);
        result = 1;
    }
    return result;
}

/** \brief Valida el valor de las horas y lo carga en estructura.
 *
 * \param Recibe puntero de estructura Employee.
 * \param Toma el valor Horas ingresado por el usuario.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eCachorro_getDias(eCachorro* listaCachorro,int* dias)
{

    int result=0;
    if( listaCachorro != NULL && dias > 0)
    {
        *dias = listaCachorro->dias;
        result = 1;
    }
    return result;
}


/** \brief Toma valor de Horas de una estructura Employee.
 *
 * \param recibe puntero de estructura Employee.
 * \param Puntero a entero y que guardara el valor de variable HorasTrabajadas.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eCachorro_setDias(eCachorro* listaCachorro,int dias)
{

    int result=0;

    if(listaCachorro!=NULL && dias>0)
    {
        listaCachorro->dias = dias;
        result = 1;
    }
    return result;
}

/** \brief Valida la cadena y lo carga en estructura.
 *
 * \param Recibe puntero de estructura Employee.
 * \param Recibe cadena de caracteres.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eCachorro_setRaza(eCachorro* listaCachorro, char* raza)
{
    int result=0;
    if( listaCachorro != NULL && raza!= NULL && strlen(raza) <= 20 )
    {
        strcpy(listaCachorro->raza, raza);
        result = 1;
    }
    return result;
}


/** \brief Toma la cadena de una estructura Employee.
 *
 * \param Recibe puntero de estructura Employee.
 * \param Puntero a char donde guardara la cadena de la estructura.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eCachorro_getRaza(eCachorro* listaCachorro,char* raza)
{

    int result=0;
    if( listaCachorro != NULL && raza != NULL)
    {
        strcpy( raza,listaCachorro->raza);
        result = 1;
    }
    return result;
}

/** \brief Valida el valor sueldo y lo carga en estructura
 *
 * \param Recibe puntero de estructura Employee
 * \param Toma el valor Sueldo ingresado por el usuario
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eCachorro_setGenero(eCachorro* listaCachorro,char* genero)
{

    int result=0;
    if(listaCachorro!=NULL  )
    {
        listaCachorro->genero = *genero;
        result=1;
    }

    return result;
}

/** \brief Toma valor de Sueldo de una estructura Employee.
 *
 * \param recibe puntero de estructura Employee.
 * \param Puntero a entero y que guardara el valor del sueldo.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eCachorro_getGenero(eCachorro* listaCachorro,char* genero)
{

    int result=0;

    if(listaCachorro!=NULL && genero != NULL)
    {
        *genero=listaCachorro->genero;
        ///*genero = listaCachorro->genero;
        result = 1;
    }
    return result;
}

///aca agrego la de reservado igual a genero

int eCachorro_setReservado(eCachorro* listaCachorro,char* reservado)
{

    int result=0;
    if(listaCachorro!=NULL  )
    {
        strcpy(listaCachorro->reservado, reservado);
        ///listaCachorro->reservado = *reservado;
        result=1;
    }

    return result;
}

/** \brief Toma valor de Sueldo de una estructura Employee.
 *
 * \param recibe puntero de estructura Employee.
 * \param Puntero a entero y que guardara el valor del sueldo.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eCachorro_getReservado(eCachorro* listaCachorro,char* reservado)
{

    int result=0;

    if(listaCachorro!=NULL && reservado != NULL)
    {
       strcpy(reservado, listaCachorro->reservado);
       /// *reservado = listaCachorro->reservado;
        result = 1;
    }
    return result;
}

/** \brief Crea espacio en memoria y crea una nueva estructura del tipo Employee
 *
 * \return Devuelve la nueva estructura creada con los campos inicializados
 */
eCachorro* newCachorro()
{
    eCachorro* nuevo = (eCachorro*) malloc(sizeof(eCachorro));
    if(nuevo != NULL)
    {
        nuevo->id_cachorro = 0;
        strcpy(nuevo->nombre, "");
        nuevo->dias = 0;
        strcpy(nuevo->raza, "");
        strcpy(nuevo->reservado, "");
        nuevo->genero=' ';

    }
    return nuevo;
}


/** \brief Crea una nueva estructura de tipo Employee* y se cargan los campos con los parametros recibidos
 *
 * \param  Recibe cadena con los datos de la Id
 * \param  Recibe cadena de caracteres con los datos de Nombre
 * \param  Recibe cadena con el valor de las Horas trabajadas
 * \param  Recibe cadena con el valor del Sueldo
 *
 * \return Retorna la estructura Employee* con los datos cargados en sus campos
 */
eCachorro* newCachorro_Parametros(char* id,char* nombre,char* dias, char* raza , char* reservado,char* genero)
{
    eCachorro* nuevo = newCachorro();
    if( nuevo != NULL)
    {
        ///if(id!=NULL && dominio!=NULL && anio!=NULL && tipo!=NULL)
        if (id!=NULL && nombre!=NULL && dias!=NULL &&  raza!=NULL && reservado != NULL && genero!=NULL)
        {
         if( !eCachorro_setId(nuevo,atoi(id))
            || !eCachorro_setNombre(nuevo, nombre)
            || !eCachorro_setDias(nuevo, atoi(dias))
            || !eCachorro_setRaza(nuevo, raza)
            || !eCachorro_setReservado(nuevo, reservado)
            || !eCachorro_setGenero(nuevo, genero))

            {
                free(nuevo);
                nuevo = NULL;
            }
        }
    }

    return nuevo;
}


/** \brief Muestra en pantalla, los datos de la linkedList
 *
 * \param Recibe LinkedList*
 */
void showCachorro(eCachorro* nuevo)
{
    if (nuevo!= NULL)
    {
        printf("%4d   %10s  %5d   %10s   %10s   %5c\n",nuevo->id_cachorro, nuevo->nombre, nuevo->dias, nuevo->raza, nuevo->reservado, nuevo->genero);
    }
}
/*void showDominio(eCachorro* dominios)
{
    if(dominios!=NULL)
    {
        printf("%4d  %10s  %5d    %5c\n",dominios->id,dominios->dominio,dominios->anio,dominios->tipo);
    }
}
*/
/** \brief Muestra los datos de un empleado
 *
 * \param Recibe un puntero a Employee
 */

///void showDominios(LinkedList* pArrayLinkedDominio)
void showCachorros(LinkedList* pArrayLinkedCachorro)
{
    int tam;

    printf(" ID     NOMBRE   DIAS   RAZA  RESERVADO   GENERO\n");
    printf("------------------------------------\n");

    if(ll_len(pArrayLinkedCachorro) == 0)
    {
        printf("NO HAY CACHORROS QUE MOSTRAR\n\n");
    }

    if(pArrayLinkedCachorro != NULL)
    {
        tam = ll_len(pArrayLinkedCachorro);
        for(int i=0; i<tam; i++)
        {
            showCachorro((eCachorro*) ll_get(pArrayLinkedCachorro, i));
        }
    }
}

//  PARA MAP
/*int setearTipo(eCachorro* dom)
{
    int result = 0;

    if(dom != NULL)
    {

        if( *(dom->dominio) >= 65 && *(dom->dominio) <= 90  )
        {
            dom->tipo = 'A';
        }
        else
        {
            dom->tipo = 'M';
        }
        result = 1;
    }
    return result;
}

void* seteaTipo(eCachorro* dom)///la funcion que despues es pasada como pFUNC a ll_map
{

    if(dom != NULL)
    {
        if( *(dom->dominio) >= 65 && *(dom->dominio) <= 90  )///EL * ANTES DEL () ES PARA ACCEDER AL CONTENIDO
        {
            dom->tipo = 'A';
        }
        else
        {
            dom->tipo = 'M';
        }
    }

}

/// COPIA POR EJEMPLO PARA MODIFICAR PATENTE
/*
void* seteaTipo(eDominio* dom)///la funcion que despues es pasada como pFUNC a ll_map
{

    if(dom != NULL)
    {
        if(dom->anio >= 2016){
            strcpy(*(dom->dominio), "PEPE")
        }
    }

}
*/
/// PARA FILTER

/*int filterTipo(void* e) ///la funcion que despues es pasada como pFUNC a ll_filter
{
    int todoOk = 0;
    eCachorro* dom =NULL;
    if(e != NULL)
    {
        dom = (eCachorro*)e;
        if(dom->tipo != 'M')
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

*/
