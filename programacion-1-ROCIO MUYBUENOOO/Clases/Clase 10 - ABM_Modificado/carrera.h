#ifndef CARRERA_H_INCLUDED
#define CARRERA_H_INCLUDED

typedef struct
{
    int idCarrera;
    char descripcion[20];
} eCarrera;

#endif // CARRERA_H_INCLUDED

void mostrarCarrera(eCarrera datos);
void mostrarCarreras(eCarrera vec[], int tamC);
int obtenerNomCarrera(eCarrera vec[], int tamC, int id, char dondeAsinar[]);
int menuInformes();
void informes(eAlumno vec[], int tamA, eCarrera vecC[], int tamC);
