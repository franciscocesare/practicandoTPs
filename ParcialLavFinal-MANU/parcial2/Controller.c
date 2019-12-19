#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "stdlib.h"

#include "LinkedList.h"
#include "parser.h"
#include "biblioteca.h"
#include "computer.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayLinkedComputer)
{
     FILE* pFile = NULL;
    int result=0;

    if(path != NULL && pArrayLinkedComputer != NULL){
        pFile= fopen(path,"r");
        if(pFile==NULL)
        {
            result=0;
        }
        else
        {
          result = parser_ComputerFromText(pFile, pArrayLinkedComputer);
        }
    }
    fclose(pFile);

    return result;
}


///////////////////////////////////////////// ORDENAR


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortComputer(LinkedList* pArrayLinkedComputer)
{
    int todoOk = 0;
    if(pArrayLinkedComputer != NULL){

        ll_sort(pArrayLinkedComputer,orderIdTipo,1);
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayLinkedComputer)
{
    FILE* pFile = NULL;
    eComputer* auxComputer = NULL;
    int size=ll_len(pArrayLinkedComputer);
    int result=-1;

    int id;
    char descripcion[120];
    float precio;
    int itTipo;
    char oferta[30];


    if(pArrayLinkedComputer!=NULL && path!=NULL)
    {
        if(size>0)
        {
            pFile=fopen(path,"w");

            if(pFile!=NULL)
            {
                 for(int i=0;i<size;i++)
                {
                    auxComputer=(eComputer*)ll_get(pArrayLinkedComputer,i);
                    eComputer_getId(auxComputer, &id);
                    eComputer_getDescipcion(auxComputer,descripcion);
                    eComputer_getPrecio(auxComputer,&precio);
                    eComputer_getIdTipo(auxComputer,&itTipo);
                    eComputer_getOferta(auxComputer,oferta);

                    fprintf(pFile,"%d,%s,%f,%d,%s\n",id,descripcion,precio,itTipo,oferta);
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



