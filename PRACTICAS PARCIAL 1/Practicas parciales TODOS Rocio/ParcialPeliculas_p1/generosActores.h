#ifndef GENEROSACTORES_H_INCLUDED
#define GENEROSACTORES_H_INCLUDED


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

#endif // GENEROSACTORES_H_INCLUDED


//FUNCIONES ACTORES
void mostrarActor(eActores vec);
void mostrarActores(eActores vec[], int tam);
void nombreActor(eActores vec[], int tam,int id,char* dondeAsignar);
int validarActor(eActores vec[],int tam);

//FUNCIONES GENEROS
void mostrarGenero(eGenero vec);
void mostrarGeneros(eGenero vec[], int tam);
int validarGenero(eGenero vec[], int tam);
void nombreGenero(eGenero vec[], int tam,int id,char* dondeAsignar);

