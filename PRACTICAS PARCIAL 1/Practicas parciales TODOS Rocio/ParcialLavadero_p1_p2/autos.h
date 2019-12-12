#include "autos.h"

typedef struct
{
    int idMarca;
    char nombreMarca[20];
} eMarca;

typedef struct
{
    int idColor;
    char nombreColor[20];
} eColor;

typedef struct
{
    int idAuto;
    char patente[8];
    int idMarca;
    int idColor;
    int anioAuto;
    char nombre[20];
    char sexo;
    int ocupado;

} eAuto;

typedef struct
{
    int idServicio;
    char nombreServicio[25];
    int precio;

} eServicio;


int menuABM();
int menuModificacionAuto();

void inicializarAuto(eAuto vec[], int tam);
int buscarLibre(eAuto vec[], int tam);
int buscarAutoPorPatente(eAuto vec[],int tam, char patente[]);

void ordenarAutos(eAuto vec[], int tam);
void mostrarAuto(eAuto vecAuto, eColor vecColor[], int tamColor, eMarca vecMarca[], int tamMarca);
void mostrarAutos(eAuto vecAuto[],int tamAuto, eColor vecColor[], int tamColor, eMarca vecMarca[], int tamMarca);

void mostrarMarca(eMarca lista);
void mostrarMarcas(eMarca lista[], int tam);
int obtenerMarcas(eMarca vecMarca[], int tamMarca, int idMarca, char dondeAsinar[]);
int buscarMarcaPorId(eMarca vec[], int tam, int idMarca);

void mostrarColor(eColor lista);
void mostrarColores(eColor lista[], int tam);
int obtenerColores(eColor vecColor[], int tamColor, int idColor, char dondeAsignar[]);
int buscarColorPorId(eColor vec[], int tam, int idColor);

void altaAuto(eAuto vecAuto[],int tamAuto, eColor vecColor[], int tamColor, eMarca vecMarca[], int tamMarca);
void modificarAuto(eAuto vecAuto[],int tamAuto, eColor vecColor[], int tamColor, eMarca vecMarca[], int tamMarca);
void bajaAuto(eAuto vecAuto[],int tamAuto, eColor vecColor[], int tamColor, eMarca vecMarca[], int tamMarca);
