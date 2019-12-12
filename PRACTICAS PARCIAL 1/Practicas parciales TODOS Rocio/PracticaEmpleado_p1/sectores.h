#ifndef SECTORES_H_INCLUDED
#define SECTORES_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[51];

}eSector;

#endif // SECTORES_H_INCLUDED

void harcodearSectores(eSector vec[],int tam);
void mostrarSector(eSector vec);
void mostrarSectores(eSector vec[],int tam);
void obtenerNomSec(eSector vec[], int tam, int id, char dondeAsignar[]);
