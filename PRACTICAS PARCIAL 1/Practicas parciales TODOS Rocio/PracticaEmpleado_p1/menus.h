#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[51];
    float importe;

}eMenu;

#endif // MENUS_H_INCLUDED

void harcodearMenus(eMenu vec[], int tam);
void mostrarMenu(eMenu vec);
void mostrarMenus(eMenu vec[], int tam);
void obtenerNomMenu(eMenu vec[], int tam, int id, char dondeAsignar[]);
