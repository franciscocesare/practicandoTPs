#ifndef ALMUERZOS_H_INCLUDED
#define ALMUERZOS_H_INCLUDED
#include "empleados.h"

typedef struct
{
    int id;
    int idMenu;
    int idEmp;
    eFecha fechaAlmuerzo;
    int isEmpty;

}eAlmuerzo;


#endif // ALMUERZOS_H_INCLUDED

void inicializarAlmuerzos(eAlmuerzo alm[], int tam);
int buscarLibreAlm(eAlmuerzo alm[], int tam);
int harcodearAlmuerzos(eAlmuerzo alm[], int tam, int cant);
void mostrarAlmuerzo(eAlmuerzo alm, eMenu menu[], int tamM, eEmpleado emp[], int tamE);
void mostrarAlmuerzos(eAlmuerzo alm[],int tamA, eMenu menu[], int tamM, eEmpleado emp[], int tamE);
