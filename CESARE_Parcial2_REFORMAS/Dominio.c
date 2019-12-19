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
int eComputer_setId(eComputer* listaComputer,int id)
{
    int result=0;
    if(listaComputer!=NULL && id >0)
    {
        listaComputer->id = id;
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

/** \brief Valida la cadena y lo carga en estructura.
 *
 * \param Recibe puntero de estructura Employee.
 * \param Recibe cadena de caracteres.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int eComputer_setDescripcion(eComputer* listaComputer, char* descripcion)
{
    int result=0;
    if( listaComputer != NULL && descripcion != NULL && strlen(descripcion) <= 150 )
    {
        strcpy(listaComputer->descripcion, descripcion);
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
int eComputer_getDescripcion(eComputer* listaComputer,char* descripcion)
{

    int result=0;
    if( listaComputer != NULL && descripcion != NULL)
    {
        strcpy( descripcion,listaComputer->descripcion);
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
int eComputer_getPrecio(eComputer* listaComputer,float* precio) ///precio
{

    int result=0;
    if( listaComputer != NULL && precio!=NULL)
    {
        *precio = listaComputer->precio;
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
int eComputer_setPrecio(eComputer* listaComputer,float precio)
{

    int result=0;

    if(listaComputer!=NULL)///va el precio!=NULL?
    {
        listaComputer->precio = precio;
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
int eComputer_setIdTipo(eComputer* listaComputer,int idTipo)
{
    int result=0;
    if(listaComputer!=NULL && idTipo >0)
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
/** \brief Valida el valor sueldo y lo carga en estructura
 *
 * \param Recibe puntero de estructura Employee
 * \param Toma el valor Sueldo ingresado por el usuario
 * \return Retorna 0 (cero) o 1 (uno).
 */


int eComputer_setOferta(eComputer* listaComputer,char* oferta)
{

    int result=0;
    if(listaComputer!=NULL  )
    {
        strcpy(listaComputer->oferta, oferta);
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
int eComputer_getOferta(eComputer* listaComputer,char* oferta)
{

    int result=0;

    if(listaComputer!=NULL && oferta != NULL)
    {
        strcpy(oferta, listaComputer->oferta);
        result = 1;
    }
    return result;
}

/** \brief Crea espacio en memoria y crea una nueva estructura del tipo Employee
 *
 * \return Devuelve la nueva estructura creada con los campos inicializados
 */
/*eCachorro* newCachorro()
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
}*/
eComputer* newComputer()
{
    eComputer* nuevo = (eComputer*) malloc(sizeof(eComputer));///nuevo->para los Int Float, strcpy para los string
    if(nuevo != NULL)
    {
        nuevo->id= 0;
        strcpy(nuevo->descripcion, "");
        nuevo->precio = 0; ///precio float
        nuevo->idTipo=0;///idTipo int
        strcpy(nuevo->oferta, "");///Oferta char

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

 eComputer* newComputer_Parametros(char* id, char* descripcion, char* precio, char* idTipo, char* oferta)
{
    eComputer* nuevo = newComputer();
    if( nuevo != NULL)
    {
        if (id!=NULL && descripcion!=NULL && precio!=NULL &&  idTipo!=NULL && oferta != NULL)
        {
            eComputer_setId(nuevo,atoi(id));
            eComputer_setDescripcion(nuevo, descripcion);
            eComputer_setPrecio(nuevo, atof(precio));  ///siempre en el New algo van los setters
            eComputer_setIdTipo(nuevo,atoi(idTipo));
            eComputer_setDescripcion(nuevo, descripcion);
            eComputer_setOferta(nuevo, oferta);
        }
        else
        {
            free(nuevo);
        }
    }
    return nuevo;
}
/*eCachorro* newCachorro_Parametros(char* id,char* nombre,char* dias, char* raza, char* reservado,char* genero)
{
    eCachorro* nuevo = newCachorro();
    if( nuevo != NULL)
    {
        if (id!=NULL && nombre!=NULL && dias!=NULL &&  raza!=NULL && reservado != NULL && genero!=NULL)
        {
            eCachorro_setId(nuevo,atoi(id));
            eCachorro_setNombre(nuevo, nombre);
            eCachorro_setDias(nuevo, atoi(dias));
            eCachorro_setRaza(nuevo, raza);
            eCachorro_setReservado(nuevo, reservado);
            eCachorro_setGenero(nuevo, genero);
        }
        else
        {
            free(nuevo);
        }
    }
    return nuevo;
}*/





/** \brief Muestra en pantalla, los datos de la linkedList
 *
 * \param Recibe LinkedList*
 */
/*void showCachorro(eCachorro* nuevo)
{
    if (nuevo!= NULL)
    {
        printf("%4d   %10s  %5d   %10s   %10s   %5c\n",nuevo->id_cachorro, nuevo->nombre, nuevo->dias, nuevo->raza, nuevo->reservado, nuevo->genero);
    }
}*/

void showComputer(eComputer* compu)
{
    char descTipo [30]; ///para poner el tipo en vez de Id Tipo
    if(compu!=NULL)
    {
        cargarDescripcion(compu, descTipo);
        printf("%2d %10.2f  %12s  %-103s %12s\n",compu->id,compu->precio,descTipo, compu->descripcion,compu->oferta);
    }
}

/** \brief Muestra los datos de un empleado
 *
 * \param Recibe un puntero a Employee
 */

///void showDominios(LinkedList* pArrayLinkedDominio)
/*void showCachorros(LinkedList* pArrayLinkedCachorro)
{
    int tam;

    printf(" ID     NOMBRE       DIAS       RAZA        RESERVADO   GENERO\n");
    printf("-----------------------------------------------------\n");

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
}*/
void showComputers(LinkedList* pArrayLinkedComputers)
{
    int tam;
system("cls");
    printf(" ID   PRECIO         TIPO           DESCRIPCION                                                                                         OFERTA\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");

    if(ll_len(pArrayLinkedComputers) == 0)
    {
        printf("NO HAY COMPUTADORAS QUE MOSTRAR\n\n");
    }

    if(pArrayLinkedComputers != NULL)
    {
        tam = ll_len(pArrayLinkedComputers);
        for(int i=0; i<tam; i++)
        {
            showComputer((eComputer*) ll_get(pArrayLinkedComputers, i));
        }
    }
}

int cargarDescripcion(void* lista, char* desc)
{
    int todoOk = 0;
    int idTipo;

    if(lista != NULL && desc != NULL){
        if(eComputer_getIdTipo(lista, &idTipo)){
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


int sortComputers (void* desktop, void* laptop)///(void* Employee1, void* Employee2)
{

        int retorno;
        int idTipoDesktop;
        int idTipoLaptop;

        eComputer* auxComputer1 = (eComputer*) desktop;
        eComputer* auxComputer2 = (eComputer*) laptop;

        eComputer_getIdTipo(auxComputer1, &idTipoDesktop);
        eComputer_getIdTipo(auxComputer2, &idTipoLaptop);

       if (idTipoDesktop > idTipoLaptop)
        {
            retorno = 1;
        }
     else if (idTipoDesktop < idTipoLaptop)

        {
            retorno=-1;
        }
        else{
            retorno =0;
        }

    return retorno;
}



int filter_desktop(void* aux) ///la funcion que despues es pasada como pFUNC a ll_filter con filtro de CARACTERES
{
    int todoOk = 0;
    int idTipo;

    ///eCachorro* cachorro45 =NULL;
    if(aux != NULL)
    {

        aux = (eComputer*)aux;
        eComputer_getIdTipo(aux, &idTipo);
        if (idTipo==2)
            todoOk=1;
    }
    return todoOk;
}

int setearOferta(void* element)
{
    int result = 0;
    eComputer* compu = NULL;

    if( element != NULL){
        compu = (eComputer*)element;
        if( compu->idTipo == 2){
            strcpy(compu->oferta, "SIN DATOS");
        }
        else if(compu->idTipo == 1   && compu->precio > 20000 ){
            strcpy(compu->oferta, "50% DESCUENTO");
        }
        result = 1;
    }
    return result;
}

/// PARA FILTER
/*int filter_45dias(void* aux) ///la funcion que despues es pasada como pFUNC a ll_filter filtro de INT
{
    int todoOk = 0;
    int dias;

    if(aux != NULL)
    {
        aux = (eCachorro*)aux;
        eCachorro_getDias(aux,&dias);
        if (dias>45)
            todoOk=1;
    }
    return todoOk;
}*/


///FILTER SIN LOS CACHORROS QUE SON MACHOS
/*int filter_machos(void* aux) ///la funcion que despues es pasada como pFUNC a ll_filter con filtro de UN CARACTER
{
    int todoOk = 0;
    char genero;
    if(aux != NULL)  ///me falla machos
    {
        aux = (eCachorro*)aux;
        eCachorro_getGenero(aux,&genero);///el & va porque es un carcater no una cadena

        if (genero !='M')
            todoOk=1;
    }
    return todoOk;
}*/


/*int filter_callejeros(void* aux) ///la funcion que despues es pasada como pFUNC a ll_filter con filtro de CARACTERES
{
    int todoOk = 0;
    char raza [20];

    ///eCachorro* cachorro45 =NULL;
    if(aux != NULL)
    {

        aux = (eCachorro*)aux;
        eCachorro_getRaza(aux,raza);
        if (strcmpi(raza,"Callejero")==0)
            todoOk=1;
    }
    return todoOk;
}*/

///FILTER DE RESERVADO COMO EJEMPLO

/*int filter_reservado(void* aux) ///la funcion que despues es pasada como pFUNC a ll_filter con filtro de CARACTERES
{
    int todoOk = 0;
    char reservado [20];

    if(aux != NULL)
    {

        aux = (eCachorro*)aux;
        eCachorro_getReservado(aux,reservado);
        if (strcmpi(reservado,"SI")==0)
            todoOk=1;
    }
    return todoOk;
}*/

///FILTER DE RO
/*int employee_filterUnder45(void* aux)
{
    int returnAux = 0;

    if(aux != NULL)
    {
        int age;
        aux = (mascota*)aux;

        employee_getAge(aux, &age);

        if(age > 45)
            returnAux = 1;
    }

    return returnAux;
}
*/
