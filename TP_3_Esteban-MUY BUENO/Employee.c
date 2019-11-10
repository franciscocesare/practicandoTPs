#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validaciones.h"
#include "LinkedList.h"

Employee* employee_new()
{
    Employee* nuevo;
    nuevo = (Employee*) malloc(sizeof(Employee));
    if(nuevo != NULL)
    {
        nuevo->id=0;
        strcpy(nuevo->nombre, " ");
        nuevo->horasTrabajadas=0;
        nuevo->sueldo=0;
    }
    return nuevo;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nEmployee;
    nEmployee = employee_new();
    if(nEmployee != NULL)
    {
        if(esNumeroEntero(idStr) && esNumeroEntero(horasTrabajadasStr) && esNumeroEntero(sueldoStr))
        {
            if(employee_setId(nEmployee, atoi(idStr)) &&
               employee_setNombre(nEmployee, nombreStr) &&
               employee_setHorasTrabajadas(nEmployee, atoi(horasTrabajadasStr)) &&
               employee_setSueldo(nEmployee, atoi(sueldoStr))==0 )
            {
                free(nEmployee);
                nEmployee=NULL;
            }
        }
    }

    return nEmployee;
}

int employee_delete(Employee* this)
{
    int todoOk=0;

    if(this != NULL)
    {
        free(this);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setId(Employee* this,int id)
{
    int todoOk=0;

    if(this != NULL)
    {
        if(id >= 0)
        {
            this->id = id;
            todoOk = 1;
        }
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk=0;

    if(this != NULL && nombre != NULL && strlen(nombre) < 127)
    {
        strcpy(this->nombre, nombre);
        todoOk=1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;

    if(this != NULL)
    {
        if(horasTrabajadas >= 0)
        {
            this->horasTrabajadas = horasTrabajadas;
            todoOk = 1;
        }
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk=0;

    if(this != NULL && sueldo >=0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getId(Employee* this, int* id)
{
    int todoOk=0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk=1;
    }
    return todoOk;

}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk=0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk=1;
    }
    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk=0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk=0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk=1;
    }
    return todoOk;
}

Employee* employee_FindById(LinkedList* pArrayListEmployee, int id)
{
    Employee* auxEmployee=NULL;

     if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0 && id > 0)
     {
         for(int i=0; i<ll_len(pArrayListEmployee); i++)
         {
             auxEmployee = ll_get(pArrayListEmployee, i);
             if(auxEmployee->id == id && auxEmployee!=NULL)
             {
                 auxEmployee = ll_get(pArrayListEmployee, i);
                 printf("\n  ID          Nombre Horas  Sueldo \n");
                 printf ("%4d %15s  %4d  %6d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);

                 break;
             }else
             {
                 auxEmployee=NULL;
             }
         }
     }

    return auxEmployee;
}

int ordenarEmpleadosNombre(void* Employee1, void* Employee2)
{
        int retorno;
        Employee* auxEmployee1 = (Employee*) Employee1;
        Employee* auxEmployee2 = (Employee*) Employee2;

        if(strcmp(auxEmployee1->nombre, auxEmployee2->nombre)>0)
        {
            retorno = 1;
        }
        else if(strcmp(auxEmployee1->nombre, auxEmployee2->nombre)<0)
        {
            retorno=-1;
        }
        else{
            retorno =0;
        }

    return retorno;
}

int ordenarEmpleadosId (void* Employee1, void* Employee2)
{
   int retorno;
        Employee* auxEmployee1 = (Employee*) Employee1;
        Employee* auxEmployee2 = (Employee*) Employee2;

        if(auxEmployee1->id > auxEmployee2->id)
        {
            retorno = 1;
        }
        else if(auxEmployee1->id < auxEmployee2->id)
        {
            retorno=-1;
        }
        else{
            retorno =0;
        }

    return retorno;
}

int ordenarEmpleadosHoras (void* Employee1, void* Employee2)
{
   int retorno;
        Employee* auxEmployee1 = (Employee*) Employee1;
        Employee* auxEmployee2 = (Employee*) Employee2;

        if(auxEmployee1->horasTrabajadas> auxEmployee2->horasTrabajadas)
        {
            retorno = 1;
        }
        else if(auxEmployee1->horasTrabajadas< auxEmployee2->horasTrabajadas)
        {
            retorno=-1;
        }
        else{
            retorno =0;
        }

    return retorno;
}

int ordenarEmpleadosSueldo (void* Employee1, void* Employee2)
{
   int retorno;
        Employee* auxEmployee1 = (Employee*) Employee1;
        Employee* auxEmployee2 = (Employee*) Employee2;

        if(auxEmployee1->sueldo> auxEmployee2->sueldo)
        {
            retorno = 1;
        }
        else if(auxEmployee1->sueldo<auxEmployee2->sueldo)
        {
            retorno=-1;
        }
        else{
            retorno =0;
        }

    return retorno;
}


