#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* pFile=NULL;

    if(pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            if(parser_EmployeeFromText(pFile , pArrayListEmployee))
            {
                fclose(pFile);
                todoOk = 1;
            }
        }
    }

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* pFile=NULL;

    if(pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");

        if(pFile != NULL)
        {
            if(parser_EmployeeFromBinary(pFile , pArrayListEmployee))
            {
                fclose(pFile);
                todoOk = 1;
            }
        }
    }

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int repetido=0;//flag para validar Id duplicado
    char id[20];
    char nombre[128];
    char horasTrabajadas[20];
    char sueldo[20];
    Employee* auxEmployee;
    system("cls");
    printf("**ALTA DE EMPLEADO**\n");

    if(pArrayListEmployee != NULL)
    {//obetenemos el id
        do{
            repetido=0;
            if(getNumber(id,"Ingrese Id: ", "ERROR. Numero invalido, reingrese Id: "))
            {
                if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
                {
                    for (int i=0; i<ll_len(pArrayListEmployee); i++)
                    {
                        auxEmployee = ll_get(pArrayListEmployee, i);

                        if(auxEmployee != NULL)
                        {
                            if(auxEmployee->id==atoi(id))
                            {
                                repetido=1;
                                printf("\nNumero de Id existente.\n");
                            }
                        }
                    }
                }
            }
        }while(repetido);
        //obtenemos el nombre

        getString(nombre,"Ingrese el nombre: ", "ERROR. Nombre invalido, reingrese el nombre: ");
        getNumber(horasTrabajadas,"Ingrese las horas trabajadas: ", "ERROR. Numero invalido, reingrese las horas trabajadas: ");
        getNumber(sueldo,"Ingrese el sueldo: ", "ERROR. Numero invalido, reingrese el sueldo: ");

        auxEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

        if(auxEmployee != NULL)
        {
            if(ll_add(pArrayListEmployee,auxEmployee) == 0)
            {
                todoOk = 1;
            }
        }
    }

    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    char nombre[128];
    char horasTrabajadas[20];
    char sueldo[20];

    char seguir='s';
    Employee* modEmployee=NULL;//empleado a modificar

    int option;

    system("cls");
    controller_ListEmployee(pArrayListEmployee);
    printf("\n***MODIFICAR EMPLEADO***\n");


    do{
        printf("\n1- Nombre.");
        printf("\n2- Horas trabajadas.");
        printf("\n3- Sueldo.");
        printf("\n5- Salir");
        printf("\n\nQue desea modificar? Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &option);
        modEmployee = (Employee*) menuModificar(pArrayListEmployee, option);

        switch(option){

        case 1:
            getString(nombre,"Ingrese el nombre: ", "ERROR. Nombre invalido, reingrese el nombre: ");
            employee_setNombre( modEmployee, nombre);
            todoOk=1;
            break;

        case 2:
            getNumber(horasTrabajadas,"Ingrese las horas trabajadas: ", "ERROR. Numero invalido, reingrese las horas trabajadas: ");
            employee_setHorasTrabajadas(modEmployee, atoi(horasTrabajadas));
            todoOk=1;
            break;

        case 3:
            getNumber(sueldo,"Ingrese el sueldo: ", "ERROR. Numero invalido, reingrese el sueldo: ");
            employee_setSueldo(modEmployee, atoi(sueldo));
            todoOk=1;
            break;

        case 5:
            printf("\nDesea modificar algun otro dato?");
            fflush(stdin);
            scanf("%c", &seguir);
            break;

        default:
            printf("\nOPCION INVALIDA\n");
            break;

        }
     printf("\nDesea seguir modificando datos? (s-n): ");
     fflush(stdin);
     scanf("%c", &seguir);

    }while(seguir=='s');


    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    char id[20];
    int i;
    int tam=ll_len(pArrayListEmployee);
    char encontro='n';
    Employee* auxEmployee;
    system("cls");

    controller_ListEmployee(pArrayListEmployee);

    printf("\n***ELIMINAR EMPLEADO***\n");
    getNumber(id,"Ingrese Id: ", "ERROR. Numero invalido, reingrese Id: ");

    auxEmployee = (Employee*)employee_FindById(pArrayListEmployee, atoi(id));

    while(encontro!='s')
    {
        if(auxEmployee==NULL)
        {
            printf("\nNo se encontro el empleado.");
            getNumber(id,"Ingrese Id: ", "ERROR. Numero invalido, reingrese Id: ");
            auxEmployee =(Employee*) employee_FindById(pArrayListEmployee, atoi(id));
        }
        else
        {
            printf("\nEl empleado a eliminar es correcto?(s-n): ");
            fflush(stdin);
            scanf("%c",&encontro);
            if(encontro!='s')
            auxEmployee=NULL;
        }
    }
    for(i=0; i<tam;i++)
    {
        auxEmployee=ll_get(pArrayListEmployee, i);
        if(auxEmployee->id == atoi(id))
            break;
    }

    ll_remove(pArrayListEmployee,i);
    employee_delete(auxEmployee);

    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* nEmployee;

    if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
    {
        printf("\n  ID          Nombre Horas  Sueldo \n");

        for (int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            nEmployee = ll_get(pArrayListEmployee, i);

            if(nEmployee != NULL)
            {
                printf ("%4d %15s  %4d  %6d\n", nEmployee->id, nEmployee->nombre, nEmployee->horasTrabajadas, nEmployee->sueldo);
            }
        }

        todoOk=1;
    }
    else
    {
        printf("\nNo hay empleados que mostrar.\n");
    }

    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int option;
    int criterio;

    system("cls");
    printf("***ORDERNAR EMPLEADOS***\n");
    printf("\n1-Id");
    printf("\n2-Nombre");
    printf("\n3-Horas trabajadas");
    printf("\n4-Sueldo");

    if(pArrayListEmployee != NULL)
    {

        printf("\nIngrese la opcion elegida: ");
        fflush(stdin);
        scanf("%d",&option);

        printf("\nIngrese Ingrese el criterio del orden, ASCENDENTE (1) DESCENDENTE (0): ");
        fflush(stdin);
        scanf("%d",&criterio);

        switch(option)
        {
        case 1:
            printf("\nOrdenando lista de empleados, aguarde un momento\n");
            ll_sort(pArrayListEmployee, ordenarEmpleadosId, criterio);
            todoOk=1;
            break;

        case 2:
            printf("\nOrdenando lista de empleados, aguarde un momento\n");
            ll_sort(pArrayListEmployee, ordenarEmpleadosNombre, criterio);
            todoOk=1;
            break;

        case 3:
            printf("\nOrdenando lista de empleados, aguarde un momento\n");
            ll_sort(pArrayListEmployee, ordenarEmpleadosHoras, criterio);
            todoOk=1;
            break;

        case 4:
            printf("\nOrdenando lista de empleados, aguarde un momento\n");
            ll_sort(pArrayListEmployee, ordenarEmpleadosSueldo, criterio);
            todoOk=1;
            break;

        default:
            printf("\nOPCION INVALIDA.\n");
        }

    }
    printf("\nSe ordeno correctamente.\n");
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int tam = ll_len(pArrayListEmployee);
    Employee* auxEmployee;
    FILE* pFile=NULL;


    if( pArrayListEmployee != NULL && tam > 0 && path != NULL)
    {
        pFile = fopen(path, "w");
        if( pFile == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            system("pause");
            return todoOk;
        }
        fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
        for(int i=0; i < tam; i++)
        {
            auxEmployee=ll_get(pArrayListEmployee, i);
            fprintf(pFile, "%d,%s,%d,%d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
        }
        fclose(pFile);
        todoOk = 1;
    }


    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int tam;
    Employee* auxEmpleado;
    FILE* pFile=NULL;


    if(path !=NULL && pArrayListEmployee != NULL)
    {
       tam=ll_len(pArrayListEmployee);
       pFile=fopen(path,"wb");

       if(pFile!=NULL && tam >0)
        {
            for(int i=0; i<tam ; i++)
            {
                auxEmpleado=ll_get(pArrayListEmployee,i);
                //fwrite(pE,sizeof(Employee),1,fp);

                fwrite( auxEmpleado,  sizeof(Employee), 1, pFile);

            }

            fclose(pFile);
            todoOk=1;
        }
        else
        {
            printf("\nNo se pudo abrir el archivo.");
        }

    }
    return todoOk;
}

