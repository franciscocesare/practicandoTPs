#ifndef ENTIDAD_3_H_INCLUDED
#define ENTIDAD_3_H_INCLUDED

typedef struct
{
    int idJuego;
    char descripcion[20];
    float importe;
    int idCategoria;
} eJuego;

#endif // ENTIDAD_3_H_INCLUDED

void harcodearJuego(eJuego vec[], int tam);
void obtenerNomJuego(eJuego vec[], int tam, int id, char dondeAsignar[]);
void mostrarJuego(eJuego juegos, eCategoria categorias[], int tam);
void mostrarJuegos(eJuego juego[],int tamJ, eCategoria categoria[], int tamC);
