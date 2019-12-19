#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "stdlib.h"

#include "LinkedList.h"
#include "parser.h"
#include "Dominio.h"
#include "validaciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 int controller_loadFromText(char* path , LinkedList* pArrayLinkedComputers)
{
     FILE* pFile = NULL;
    int result=0;

    if(path != NULL && pArrayLinkedComputers != NULL){
        pFile= fopen(path,"r");
        if(pFile==NULL)
        {
            result=0;
        }
        else
        {
          result = parser_ComputersFromText(pFile, pArrayLinkedComputers);
        }
    }
    fclose(pFile);

    return result;
}
/*int controller_loadFromText(char* path , LinkedList* pArrayLinkedCachorros)
{
     FILE* pFile = NULL;
    int result=0;

    if(path != NULL && pArrayLinkedCachorros != NULL){
        pFile= fopen(path,"r");
        if(pFile==NULL)
        {
            result=0;
        }
        else
        {
          result = parser_CachorroFromText(pFile, pArrayLinkedCachorros);
        }
    }
    fclose(pFile);

    return result;
}*/

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_loadFromBinary(char* path , LinkedList* pArrayLinkedDominio)
{
    FILE* pFile = NULL;
    int result=0;

    if(path != NULL && pArrayLinkedDominio != NULL){
        pFile = fopen(path,"rb");
        if(pFile==NULL)
        {
            result=0;
        }
        else
        {
          result = parser_DominioFromBinary(pFile, pArrayLinkedDominio);
        }
    }
    fclose(pFile);

    return result;
}
*/

int controller_map(LinkedList* pList)
{
    int todoOk = 0;

    system("cls");

    if(pList != NULL)
    {

      pList=ll_map(pList,setearOferta);
      todoOk=1;

    }
    return todoOk;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */

int controller_sort(LinkedList* pList)
{
    int todoOk = 0;

    system("cls");

    if(pList != NULL)
    {

       ll_sort(pList,sortComputers,1);

    }
    system("pause");
    return todoOk;
}




/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
///int controller_saveAsText(char* path , LinkedList* pArrayLinkedDominio)
int controller_saveAsText(char* path , LinkedList* pArrayLinkedComputers)
{
    FILE* pFile = NULL;
    eComputer* auxComputer = NULL;///la inicio en NULL para arrancar
    int size=ll_len(pArrayLinkedComputers);///defino el tamaño igual al array
    int result=-1;

    int id;
    char descripcion[120];
    float precio;
    int idTipo;
    char oferta[30];

    if(pArrayLinkedComputers!=NULL && path!=NULL)
    {
        if(size>0)
        {
            pFile=fopen(path,"w");///abrimos el archivo para escrbirlo

            if(pFile!=NULL)
            {
                 for(int i=0;i<size;i++)
                {
                    auxComputer=(eComputer*)ll_get(pArrayLinkedComputers,i);///obtiene el array en tal indice
                    eComputer_getId(auxComputer,&id);
                    eComputer_getDescripcion(auxComputer,descripcion);
                    eComputer_getPrecio(auxComputer,&precio);
                    eComputer_getIdTipo(auxComputer,&idTipo);
                    eComputer_getOferta(auxComputer,oferta);

                    fprintf(pFile,"%d,%s,%f,%d,%s\n",id,descripcion,precio,idTipo,oferta);
                }
                fclose(pFile);
                result=1;
            }
            else{
                result=0;
            }
        }
    }

    return result;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_saveAsBinary(char* path , LinkedList* pArrayLinkedDominio)
{
    FILE* pFile = NULL;
    eDominio* auxDom = NULL;
    int size = ll_len(pArrayLinkedDominio);
    int result = -1;

    if(pArrayLinkedDominio!=NULL && path!=NULL)
    {
        if(size>0)
        {
            pFile=fopen(path,"wb");

            if(pFile!=NULL)
            {
                for(int i=0; i<size;i++)
                {
                    auxDom=ll_get(pArrayLinkedDominio,i);
                    if(auxDom!=NULL)
                    {
                        fwrite(auxDom,sizeof(eDominio),1,pFile);
                    }
                }
            result=1;
            fclose(pFile);
            }
            else{
            result=0;
            }
        }
    }
    else{
        result=0;
    }

    return result;
}

*/

