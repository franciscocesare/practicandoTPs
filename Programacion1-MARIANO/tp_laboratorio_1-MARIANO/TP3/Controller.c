#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile=fopen(path, "r");

    if(pFile==NULL){
        printf("Error");
        return -1;
    }else{
        parser_EmployeeFromText(pFile, pArrayListEmployee);
    }
    fclose(pFile);
    return 1;
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
    FILE* pFile=fopen(path, "rb");
    if (pFile==NULL){
        return -1;
    }else{
    parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }
    fclose(pFile);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee){

    //FALTAN VALIDACIONES
    Employee* eEmpleado;

    int aux=0;
    int aux_id;
    char aux_nombre[30];
    int aux_horasTrabajadas;
    int aux_sueldo;
    int i;

    if(pArrayListEmployee==NULL){
        printf("\nError");
    }else{
        aux_id=getIn("\n Ingrese numero de Id: ");
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            eEmpleado=ll_get(pArrayListEmployee,i);
            if(aux_id==eEmpleado->id){
                printf("\nERROR. Ese Id ya existe. Intente nuevamente\n");
                system("pause");
                return aux;
            }
        }

        eEmpleado=employee_new();
        aux=employee_setId(eEmpleado,aux_id);

        getString("\n Ingrese nombre: ", aux_nombre);
        aux=employee_setNombre(eEmpleado, aux_nombre);

        aux_horasTrabajadas=getIn("\n Ingrese horas trabajadas: ");
        aux=employee_setHorasTrabajadas(eEmpleado,aux_horasTrabajadas);

        aux_sueldo=getIn("\n Ingrese sueldo: ");
        aux=employee_setSueldo(eEmpleado,aux_sueldo);

        ll_add(pArrayListEmployee,eEmpleado);
        aux=1;
        }
return aux;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee){
    Employee* eEmpleado;
    int aux=0;
    int aux_id;
    char aux_nombre[30];
    int aux_horasTrabajadas;
    int aux_sueldo;
    int i;
    char answer;

    if(pArrayListEmployee==NULL){
        printf("\nError");
    }else{
        aux_id=getIn("\n Ingrese numero de Id a modificar: ");
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            eEmpleado=ll_get(pArrayListEmployee,i);
            if(aux_id==eEmpleado->id){
                printf("\nSe ha encontrado la siguiente informacion: \n ID \t nombre \t horas trabajadas \t Sueldo \n\n%d %10s %8d %6d\n",eEmpleado->id,eEmpleado->nombre,eEmpleado->horasTrabajadas,eEmpleado->sueldo);
                system("pause");

                answer=getChar("\nModifica nombre? s/n ");
                if(answer=='s' || answer=='S'){
                    getString("\n Ingrese nombre: ", aux_nombre);
                    aux=employee_setNombre(eEmpleado, aux_nombre);
                    answer=' ';
                }
                answer=getChar("\nModifica horas trabajadas? s/n");
                if(answer=='s' || answer=='S'){
                    aux_horasTrabajadas=getIn("\n Ingrese horas trabajadas: ");
                    aux=employee_setHorasTrabajadas(eEmpleado,aux_horasTrabajadas);
                    answer=' ';
                }
                answer=getChar("\nModifica sueldo? s/n");
                if(answer=='s' || answer=='S'){
                    aux_sueldo=getIn("\n Ingrese nuevo sueldo: ");
                    aux=employee_setSueldo(eEmpleado,aux_sueldo);
                }

                ll_set(pArrayListEmployee, i, eEmpleado);
                aux=1;

            }
        }
    }
return aux;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee){
    Employee* eEmpleado;

    int aux=0;
    int aux_id;
    int i;

    eEmpleado=employee_new();

    if(pArrayListEmployee==NULL){
        printf("\nError");
    }else{
        aux_id=getIn("\n Ingrese numero de Id: ");
        for(i=0;i<ll_len(pArrayListEmployee);i++){

            eEmpleado=ll_get(pArrayListEmployee,i);
            if(aux_id==eEmpleado->id){
                printf("\nSe ha encontrado la siguiente informacion:%d %s %d %d\n",eEmpleado->id,eEmpleado->nombre,eEmpleado->horasTrabajadas,eEmpleado->sueldo);
                system("pause");
                ll_remove(pArrayListEmployee,i);
                aux=1;
            }
        }
    }
    return aux;
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
    int largo, i;
    Employee* eEmpleado;
    eEmpleado=employee_new();

    if(pArrayListEmployee==NULL){
        printf("\nError");
    }else{
        largo=ll_len(pArrayListEmployee);
        printf("\n El largo es: %d",largo);
        printf("\n %5s %15s %5s %s ","Id","Nombre","Horas Trabajadas", "Sueldo");
        for (i=0;i<largo;i++){
            eEmpleado=ll_get(pArrayListEmployee, i);
            printf("\n %5d %-15s %5d %d",eEmpleado->id, eEmpleado->nombre,eEmpleado->horasTrabajadas, eEmpleado->sueldo);
        }
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *  Ordeno solo por nombre descendente.
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee){

int i,j;
int largo=ll_len(pArrayListEmployee);

Employee* eEmpleadoA=employee_new();
Employee* eEmpleadoB=employee_new();
Employee* eAux=employee_new();

for(i=0;i<largo-1;i++){
    for(j=i+1;j<largo;j++){
        eEmpleadoA=ll_get(pArrayListEmployee,i);
        eEmpleadoB=ll_get(pArrayListEmployee, j);

        if(strcmp(eEmpleadoA->nombre,eEmpleadoB->nombre)>0){
            *eAux=*eEmpleadoA;
            *eEmpleadoA=*eEmpleadoB;
            *eEmpleadoB=*eAux;
        }
    }
}

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){

    FILE* pFile=fopen(path, "w");
    Employee* eEmpleado;
    eEmpleado=employee_new();
    int i;
    int len=ll_len(pArrayListEmployee);
    int aux=0;
    if(pFile==NULL){
        printf("\n Hay un error");
    }else{
        for(i=0;i<len;i++){
            eEmpleado= (Employee*) ll_get(pArrayListEmployee, i);
            fprintf(pFile, "%d, %s, %d, %d\n", eEmpleado->id, eEmpleado->nombre, eEmpleado->horasTrabajadas, eEmpleado->sueldo);
            }
        aux=1;
        }

    fclose(pFile);
    return aux;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
    FILE* pFile=fopen(path, "wb");
    Employee* eEmpleado;
    eEmpleado=employee_new();
    int i;
    int len=ll_len(pArrayListEmployee);
    int aux=0;

    if(pFile==NULL){
        printf("\n Hay un error");
    }else{
        for(i=0;i<len;i++){
            eEmpleado= (Employee*) ll_get(pArrayListEmployee, i);
            fprintf(pFile, "%d, %s, %d, %d\n", eEmpleado->id, eEmpleado->nombre, eEmpleado->horasTrabajadas, eEmpleado->sueldo);
            }
        aux=1;
        }

    fclose(pFile);
    return aux;
}


