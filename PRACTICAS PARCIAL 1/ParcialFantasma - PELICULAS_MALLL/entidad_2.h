#ifndef ENTIDAD_2_H_INCLUDED
#define ENTIDAD_2_H_INCLUDED


typedef struct
{
    int idGenero;
    char nombreGenero[20];

} eGenero;

typedef struct
{
    int idActor;
    char nombreActor[50];
    char paisActor[20];

} eActores;


#endif // ENTIDAD_2_H_INCLUDED

void hardcodearGeneros(eGenero vec[], int tam);

void mostrarGenero(eGenero gen);

void mostrarGeneros(eGenero vec[], int tam);

void hardcodearActores(eActores vec[], int tam);

void mostrarActor(eActores act);

void mostrarActores(eActores vec[], int tam);

void obtenerGenero(eGenero vec[], int tam, int id, char dondeAsigar[]);

void obtenerNombreActor(eActores vec[], int tam, int id, char dondeAsigar[]);
