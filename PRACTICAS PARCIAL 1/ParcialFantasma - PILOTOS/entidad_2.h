#ifndef ENTIDAD_2_H_INCLUDED
#define ENTIDAD_2_H_INCLUDED

typedef struct
{
    int iDdestino;
    char descripcion[30];
    float importe;

}eDestino;

#endif // ENTIDAD_2_H_INCLUDED

void harcodearDestino(eDestino vecDes[], int tamD);

void mostrarDestino (eDestino destino);

void mostrarDestinos (eDestino destino [], int tamD);

void obtenerNomDestino (eDestino vecDes[], int tamD, int idDestino, char dondeAsignar[]);
