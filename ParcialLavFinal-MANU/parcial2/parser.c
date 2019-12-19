#include <stdio.h>
#include <stdlib.h>
#include "stdlib.h"

#include "parser.h"
#include "LinkedList.h"
#include "computer.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_ComputerFromText(FILE* pFile, LinkedList* pArrayLinkedComputer)
{
    int result = 0;
    //char buffer[4][200];
    char id[30];
    char descripcion[200];
    char precio[30];
    char idTipo[30];

    int cant;

    eComputer* pc = NULL;

    if(pFile != NULL && pArrayLinkedComputer != NULL)
    {


        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, descripcion, precio,idTipo);

        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, descripcion, precio,idTipo);

            if(cant == 4)
            {
                pc = newComputer_Parametros(id, descripcion, precio,idTipo,"");

                if(pc != NULL)
                {
                    ll_add(pArrayLinkedComputer,pc );
                    result = 1;
                }
            }
            else
            {
                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    result = 0;
                    break;
                }
            }
        }
    }
    return result;
}

