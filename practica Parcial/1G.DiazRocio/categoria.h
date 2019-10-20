#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[51];
}eCategoria;

#endif // CATEGORIA_H_INCLUDED

void harcodearCategoria(eCategoria vec[], int tam);
void mostrarCategoria(eCategoria vec);
void mostrarCategorias(eCategoria vec[], int tam);
void obtenerNomCat(eCategoria vec[], int tam, int id, char dondeAsignar[]);

