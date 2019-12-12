#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char apellido[51];
	char nombre[51];
	char sexo;
	float salario;
	eFecha fechaIngreso;
	int idSector;
	int isEmpty;
}eEmpleado;

#endif // EMPLEADOS_H_INCLUDED
#include "sectores.h"

void inicializarEmpleados(eEmpleado vec[], int tam);
int buscarLibreEmp(eEmpleado vec[],int tam);
int harcodearEmp(eEmpleado vec[],int tam,int cant);
void mostrarEmpleado(eEmpleado vec, eSector sec[], int tam);
void mostrarEmpleados(eEmpleado emp[], int tamE, eSector sec[], int tamS);
void ordenarEmp(eEmpleado emp[], int tam);
int altaEmp(eEmpleado emp[], int tamE, eSector sec[], int tamS, int id);
int buscarEmpId(eEmpleado emp[], int tam, int id);
void bajaEmp(eEmpleado emp[], int tamE, eSector sec[], int tamS);
void modificarEmp(eEmpleado emp[], int tamE, eSector sec[], int tamS);
void obtenerNomEmp(eEmpleado emp[], int tam, int id, char dondeAsignar[]);
