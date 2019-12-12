#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED





#endif // INFORMES_H_INCLUDED


int menuInformes();



void vuelosPilotoSeleccionado(eVuelo vuelos[], int tamVue, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDest);

void pilotosDestinoSeleccionado (eVuelo vuelos[], int tamVue, ePiloto pilotos[], int tamPil, eDestino destinos[], int tamDest);

void recaudacionPilotoSeleccionado(ePiloto piloto [], int tamPil, eVuelo vuelo [], int tamVue, eDestino destino [], int tamD);

void destinoMasElegido(eDestino destinos[], int tamDes, eVuelo vuelos[], int tamVuelo);///MANU

int cantidadDestinos(int idDestino, eVuelo vuelos[], int tamVuelo);///MANU
