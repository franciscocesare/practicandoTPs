#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL){
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
     Node* pNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
            pNode = this->pFirstNode;

        while(nodeIndex > 0){
                pNode = pNode->pNextNode;
                nodeIndex--;
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    Node* newNode = NULL;

    if(this != NULL && nodeIndex >= 0){
        newNode = (Node*) malloc(sizeof(Node));

        if(newNode != NULL){
            newNode->pElement = pElement;
            if(nodeIndex == 0){
                newNode->pNextNode = this->pFirstNode;
                this->pFirstNode = newNode;
            }
            else{
                newNode->pNextNode = getNode(this,(nodeIndex -1))->pNextNode;
                getNode(this, (nodeIndex -1))->pNextNode = newNode;
            }
            this->size++;
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

        if(this != NULL){
            returnAux = addNode(this, ll_len(this), pElement);
        }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;

    Node* auxNode = NULL;

        if(this != NULL && index >= 0 && index < ll_len(this)){
            auxNode =  getNode(this, index);

            if(auxNode != NULL){
                returnAux = auxNode->pElement;
            }
        }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
        Node* auxNode = NULL;
        if(this != NULL && index >= 0 && index < ll_len(this)){
            auxNode = getNode(this, index);
            if(auxNode != NULL){
                auxNode->pElement = ll_get(this, index);
                auxNode->pElement = pElement;
                returnAux = 0;
            }
        }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
        Node* auxNode = NULL;
        if(this != NULL && index >= 0 && index < ll_len(this)){
            auxNode = getNode(this, index);
            if(auxNode != NULL){
                if(index == 0){
                    this->pFirstNode = getNode(this, (index+1));
                    free(auxNode);
                }
                else{
                    (getNode(this, index -1))->pNextNode = auxNode->pNextNode;
                }
               this->size--;
               returnAux = 0;
            }
        }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

       int index;

        if(this != NULL){
            index = ll_len(this);
            while(index >= 0){
                ll_remove(this, (index));
                index--;
            }
            returnAux=0;
        }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
        if(this != NULL && ll_clear(this) == 0){
                 free(this);
                 returnAux = 0;
        }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tam;
        if(this != NULL){
            tam = ll_len(this);

                for(int i=0; i<tam; i++){

                    if(ll_get(this, i) == pElement){
                        returnAux = i;
                        break;
                    }
                }

        }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int tam;
        if(this != NULL){
            tam = ll_len(this);
            if(tam > 0){
                returnAux = 0;
            }
            else{
                returnAux = 1;
            }
        }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

        if(this != NULL && index >= 0 && index <= ll_len(this)){
            if(addNode(this, index, pElement) == 0 ){
                 returnAux = 0;
            }
        }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* pElement = NULL;
        if(this != NULL && index >= 0 && index < ll_len(this)){
            pElement =  ll_get(this, index);
            if(ll_remove(this, index) == 0){
                returnAux = pElement;
            }
        }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int esta;
        if(this != NULL){
            esta = ll_indexOf(this, pElement);
            if(esta != -1){
                returnAux = 1;
            }
            else{
                returnAux = 0;
            }
        }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int contador = 0;
    int tam;
    int tam2;
        if(this != NULL && this2 != NULL){
            tam = ll_len(this);
            tam2 = ll_len(this2);
            if(tam >= tam2){
                for(int i=0; i<tam; i++){
                        if( ll_contains(this, ll_get(this2, i)) == 1 ){
                            contador++;
                        }
                }
                if(tam2 == contador){
                    returnAux = 1;
                }
                else{
                    returnAux = 0;
                }
            }
            else{
                    returnAux = 0;
                }
        }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    Node* newNode = NULL;

        if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this) ){  // a que apunta el ultimo nexNode si to es el tama�o de la lista
            cloneArray = ll_newLinkedList();
            if(cloneArray != NULL){
                for(int i=from; i<to; i++){
                    newNode = getNode(this,i);
                    if(newNode != NULL){
                        ll_add(cloneArray,newNode->pElement);
                    }
                }
            }
        }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

        if(this != NULL){
           cloneArray = ll_subList(this, 0, ll_len(this));
        }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int tam;
    Node* auxNode = NULL;
    Node* auxNode1 = NULL;
    Node* auxNode2 = NULL;

        if(this != NULL && pFunc != NULL && (order == 0 || order == 1) ){
        tam = ll_len(this);

            for(int i=0; i<tam-1; i++){
                for(int j=i+1; j<tam; j++){
                auxNode1 = getNode(this,  i);
                auxNode2 = getNode(this , j);
                if(auxNode1 != NULL && auxNode2 != NULL){
                    if(order){
                        if( pFunc(auxNode1->pElement, auxNode2->pElement) ){
                            auxNode =  auxNode1->pElement;
                            auxNode1->pElement = auxNode2->pElement;
                            auxNode2->pElement = auxNode;
                        }
                    returnAux = 0;
                    }
                    else{
                        if( pFunc(auxNode1->pElement, auxNode2->pElement) == -1 ){
                            auxNode =  auxNode1->pElement;
                            auxNode1->pElement = auxNode2->pElement;
                            auxNode2->pElement = auxNode;
                        }
                    returnAux = 0;
                    }
                }

                }
            }
        }

    return returnAux;
}



////////////////////////////////////// MAP

LinkedList* ll_Map(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* mapList = NULL;
    Node* auxNode = NULL;
    int tam;

    if(this != NULL && pFunc != NULL){
        mapList = ll_newLinkedList();
        if(mapList != NULL){
            tam = ll_len(this);
            for(int i=0; i<tam; i++){
                auxNode = getNode(this, i);
                if(auxNode != NULL){
                    if( pFunc( auxNode->pElement) ){
                            ll_add(mapList, auxNode->pElement);
                    }
                }
            }
        }
    }

    return mapList;
}

////////////////// MAP 2
/*
LinkedList* ll_Maps(LinkedList* this, void*(*pFunc)(void*))
{
    LinkedList* mapList = NULL;
    void* auxElement = NULL;

    int tam;

    if(this != NULL && pFunc != NULL){
        mapList = ll_newLinkedList();
        if(mapList != NULL){
            tam = ll_len(this);
            for(int i=0; i<tam; i++){
                auxElement = ll_get(this, i);
                if(auxElement != NULL){
                    pFunc( auxElement);
                    ll_add(mapList, auxElement);
                }
            }
        }
    }

    return mapList;
}
*/



//////////////////////////////  FILTER

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* filterList = NULL;

    if(this != NULL && pFunc != NULL){
        filterList = ll_newLinkedList();
        if(filterList != NULL){
            for(int i=0; i<ll_len(this); i++){
                if( pFunc(ll_get(this, i)) ){
                    ll_add(filterList, ll_get(this, i));
                }
            }
        }
    }
    return filterList;
}
