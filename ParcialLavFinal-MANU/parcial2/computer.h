#include "LinkedList.h"

#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED

typedef struct{
    int id;
    char descripcion[120];
    float precio;
    int idTipo;
    char oferta[30];
}eComputer;

int eComputer_getId(eComputer* listaComputer,int* id);
int eComputer_setId(eComputer* listaComputer,int id);
int eComputer_getDescipcion(eComputer* listaComputer,char* descripcion);
int eComputer_setDescipcion(eComputer* listaComputer, char* descripcion);
int eComputer_getPrecio(eComputer* listaComputer,float* precio);
int eComputer_setPrecio(eComputer* listaComputer,float precio);
int eComputer_getIdTipo(eComputer* listaComputer,int* idTipo);
int eComputer_setIdTipo(eComputer* listaComputer,int idTipo);
int eComputer_getOferta(eComputer* listaComputer,char* oferta);
int eComputer_setOferta(eComputer* listaComputer, char* oferta);
int orderIdTipo(void* comp1, void* comp2);

int setearOferta(void* e);
int filtrarDesktop(void* e);
int cargarDesc(void* e, char* desc);

void showComputer(eComputer* pc);
void showComputers(LinkedList* pArrayLinkedComputer);
eComputer* newComputer();
eComputer* newComputer_Parametros(char* id,char* descripcion,char* precio,char* idTipo, char* oferta);




#endif // COMPUTER_H_INCLUDED
