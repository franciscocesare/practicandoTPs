#include "computer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "stdlib.h"


///////////////////////////////////////////////////// SETERS Y GETTERS
/** \brief Toma valor de ID de una estructura.
 *
 * \param recibe puntero de estructura.
 * \param puntero a entero y que guardara el valor del ID.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eComputer_getId(eComputer* listaComputer,int* id)
{
    int result=0;

    if(listaComputer!=NULL && id!=NULL)
    {
        *id = listaComputer->id;
        result = 1;
    }
    return result;
}

/** \brief Valida el valor de la ID y lo carga en estructura.
 *
 * \param recibe puntero de estructura.
 * \param Toma el valor ID ingresado por el usuario.
 * \return Retorna 0 (cero) o 1 (uno).
 */

int eComputer_setId(eComputer* listaComputer,int id)
{
    int result=0;
    if(listaComputer!=NULL && id > 0)
    {
        listaComputer->id = id;
        result=1;
    }

    return result;
}



/** \brief Toma la cadena de una estructura Employee.
 *
 * \param Recibe puntero de estructura Employee.
 * \param Puntero a char donde guardara la cadena de la estructura.
 * \return Retorna 0 (cero) o 1 (uno).
 */

int eComputer_getDescipcion(eComputer* listaComputer,char* descripcion)
{

    int result=0;
    if( listaComputer != NULL && descripcion != NULL)
    {
        strcpy( descripcion,listaComputer->descripcion);
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

int eComputer_setDescipcion(eComputer* listaComputer, char* descripcion)
{
    int result=0;
    if( listaComputer != NULL && descripcion != NULL )
    {
        strcpy(listaComputer->descripcion, descripcion);
        result = 1;
    }
    return result;
}

/** \brief Toma valor de ID de una estructura.
 *
 * \param recibe puntero de estructura.
 * \param puntero a entero y que guardara el valor del ID.
 * \return Retorna 0 (cero) o 1 (uno).
 */

int eComputer_getPrecio(eComputer* listaComputer,float* precio)
{
    int result=0;

    if(listaComputer!=NULL && precio!=NULL)
    {
        *precio = listaComputer->precio;
        result = 1;
    }
    return result;
}

/** \brief Valida el valor de la ID y lo carga en estructura.
 *
 * \param recibe puntero de estructura.
 * \param Toma el valor ID ingresado por el usuario.
 * \return Retorna 0 (cero) o 1 (uno).
 */

int eComputer_setPrecio(eComputer* listaComputer,float precio)
{
    int result=0;
    if(listaComputer!=NULL )
    {
        listaComputer->precio = precio;
        result=1;
    }

    return result;
}

/** \brief Toma valor de ID de una estructura.
 *
 * \param recibe puntero de estructura.
 * \param puntero a entero y que guardara el valor del ID.
 * \return Retorna 0 (cero) o 1 (uno).
 */

int eComputer_getIdTipo(eComputer* listaComputer,int* idTipo)
{
    int result=0;

    if(listaComputer!=NULL && idTipo!=NULL)
    {
        *idTipo = listaComputer->idTipo;
        result = 1;
    }
    return result;
}

/** \brief Valida el valor de la ID y lo carga en estructura.
 *
 * \param recibe puntero de estructura.
 * \param Toma el valor ID ingresado por el usuario.
 * \return Retorna 0 (cero) o 1 (uno).
 */

int eComputer_setIdTipo(eComputer* listaComputer,int idTipo)
{
    int result=0;
    if(listaComputer!=NULL )
    {
        listaComputer->idTipo = idTipo;
        result=1;
    }

    return result;
}



/** \brief Toma la cadena de una estructura Employee.
 *
 * \param Recibe puntero de estructura Employee.
 * \param Puntero a char donde guardara la cadena de la estructura.
 * \return Retorna 0 (cero) o 1 (uno).
 */

int eComputer_getOferta(eComputer* listaComputer,char* oferta)
{

    int result=0;
    if( listaComputer != NULL && oferta != NULL)
    {
        strcpy( oferta,listaComputer->oferta);
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

int eComputer_setOferta(eComputer* listaComputer, char* oferta)
{
    int result=0;
    if( listaComputer != NULL && oferta != NULL )
    {
        strcpy(listaComputer->oferta, oferta);
        result = 1;
    }
    return result;
}


///////////////////////////////////////////////// NEWS

/** \brief Crea espacio en memoria y crea una nueva estructura del tipo Employee
 *
 * \return Devuelve la nueva estructura creada con los campos inicializados
 */

eComputer* newComputer()
{
    eComputer* nuevo = (eComputer*) malloc(sizeof(eComputer));
    if(nuevo != NULL){
        nuevo->id = 0;
        strcpy(nuevo->descripcion, "");
        nuevo->precio = 0;
        nuevo->idTipo = 0;
        strcpy(nuevo->oferta, "");
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

eComputer* newComputer_Parametros(char* id,char* descripcion,char* precio,char* idTipo, char* oferta)
{
    eComputer* nuevo = newComputer();
    if( nuevo != NULL)
    {
        if(id!=NULL && descripcion!=NULL && precio!=NULL && idTipo!=NULL && oferta!=NULL)
        {
            if(    !eComputer_setId(nuevo, atoi(id))
                || !eComputer_setDescipcion(nuevo,descripcion)
                || !eComputer_setPrecio(nuevo,atof(precio))
                || !eComputer_setIdTipo(nuevo,atoi(idTipo))
                || !eComputer_setOferta(nuevo,oferta))
            {
            free(nuevo);
            nuevo = NULL;
            }
        }
    }

    return nuevo;
}



///////////////////////////////////////////////////// SHOWS

/** \brief Muestra en pantalla, los datos de la linkedList
 *
 * \param Recibe LinkedList*
 */

void showComputer(eComputer* pc)
{
    char desc[30];
    if(pc!=NULL){
        cargarDesc(pc, desc);
       printf("%4d  %103s  %10.2f  %10s %10s \n",pc->id, pc->descripcion, pc->precio, desc, pc->oferta);
    }
}


/** \brief Muestra los datos de un empleado
 *
 * \param Recibe un puntero a Employee
 */

void showComputers(LinkedList* pArrayLinkedComputer)
{
    int tam;

    printf(" ID                                                                            DESCRIPCION                        PRECIO      ID_TIPO      OFERTA    \n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");

    if(ll_len(pArrayLinkedComputer) == 0){
            printf("NO HAY COMPUTADORAS QUE MOSTRAR\n\n");
    }


    if(pArrayLinkedComputer != NULL){
        tam = ll_len(pArrayLinkedComputer);
        for(int i=0; i<tam; i++){
            showComputer((eComputer*) ll_get(pArrayLinkedComputer, i));
        }
    }
}

int cargarDesc(void* e, char* desc)
{
    int todoOk = 0;
    int idTipo;


    if(e != NULL && desc != NULL){

        if(eComputer_getIdTipo(e, &idTipo)){
            if(idTipo == 1){
                strcpy(desc, "DESKTOP");
            }else if(idTipo == 2){
                strcpy(desc, "LAPTOP");
            }
            todoOk=1;
        }
    }
    return todoOk;
}


/////////////////////////////////////////////////// PARA MAP
int orderIdTipo(void* comp1, void* comp2)
{
    int result=0;
    eComputer* p1 = NULL;
    eComputer* p2 = NULL;

    if(comp1 != NULL && comp2 != NULL)
    {
        p1=(eComputer*) comp1;
        p2=(eComputer*) comp2;

        if(p1->idTipo > p2->idTipo)
            result = 1;
        else if(p1->idTipo < p2->idTipo)
            result=-1;
        else
            result=0;
    }
    return result;
}


int setearOferta(void* e)
{
    int result = 0;
    eComputer* comp = NULL;

    if( e != NULL){
        comp = (eComputer*)e;
        if( comp->idTipo == 2){
            strcpy(comp->oferta, "SIN DATOS");
        }
        else if(comp->idTipo == 1   && comp->precio > 20000 ){
            strcpy(comp->oferta, "50% DESCUENTO");
        }
        result = 1;
    }
    return result;
}


/////////////////////////////////////////// PARA FILTER



int filtrarDesktop(void* e)
{
    int todoOk = 0;
    int idTipo;

    if(e != NULL){

        if(eComputer_getIdTipo(e, &idTipo)){
            if(idTipo == 1){
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

