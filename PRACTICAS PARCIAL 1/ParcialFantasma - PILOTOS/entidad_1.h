#ifndef ENTIDAD_1_H_INCLUDED
#define ENTIDAD_1_H_INCLUDED

typedef struct
{
    int idPiloto;
    char nombre[51];

}ePiloto;


#endif // ENTIDAD_1_H_INCLUDED

void harcodearPilotos(ePiloto piloto[], int tamPil);

void mostrarPiloto(ePiloto vecPil);

void mostrarPilotos(ePiloto vecPil[], int tamPil);

int buscarPilotoId(ePiloto vecPil[], int tamPil, int id);

void ordenarPilotos(ePiloto vecPil[], int tamPil);

void obtenerNomPiloto(ePiloto vecPil[], int tamPil, int id, char dondeAsigar[]);
