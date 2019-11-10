#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include "carrera.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
    int idCarrera;
    int isEmpty;
} eAlumno;

#endif // ALUMNO_H_INCLUDED

void mostrarAlumno(eAlumno x,eCarrera vec[],int tamC);
void mostrarAlumnos(eAlumno vec[], int tam,eCarrera carrera[],int tamC);
int ordenarAlumnos(eAlumno vec[], int tam);
void inicializarAlumnos(eAlumno vec[], int tam);
int buscarLibre(eAlumno vec[], int tam);
int buscarAlumno(int legajo, eAlumno vec[], int tam);
int altaAlumno(eAlumno vec[], int tam, int legajo, eCarrera vecC[], int tamC);
eAlumno newAlumno(int leg,char nombre[],int edad, char sexo, int nota1, int nota2, eFecha f, int carrera);
int bajaAlumno(eAlumno vec[], int tam, eCarrera vecC[], int tamC);
int ModificarAlumno(eAlumno vec[], int tam, eCarrera vecC[], int tamC);
int hardcodearAlumnos( eAlumno vec[],int tam,int cant);
