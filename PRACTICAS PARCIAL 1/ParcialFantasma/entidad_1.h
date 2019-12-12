#ifndef ENTIDAD_1_H_INCLUDED
#define ENTIDAD_1_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    int edad;
    int isEmpty;
    char nombre[20];
    char sexo;
    eFecha fecha;

} STRUCT_NAME;

#endif // ENTIDAD_1_H_INCLUDED


void hardcodearDATOS(eENTIDAD_1 vecDATO[], int tam); ///SI NO TIENE CAMPO ISEMPTY

int hardcodearDATOS_INT(eENTIDAD_1 vec[], int tam, int cant);///SI TIENE CAMPO ISEMPTY

void inicializarEstructura(STRUCT_NAME vec[], int tam);///INICIALIZAR LA ESTRUC QUE TIENE CAMPO ISEMPTY PARA PONERLOS EN 1, INAACTIVOS

int buscarLibre(STRUCT_NAME vec[], int tam); ///SE VA A USAR CUANDO DEMOS UN ALTA

void mostrarDATO(STRUCT_NAME dato); ///NOMOBRE DE LA ESTRUCTURA Y DE UN DATO. si van mas estruct voy a tener que obtener los datos de cada una

///void mostrarVuelo(eVuelo vecVue, eDestino destino[], int tamD, ePiloto piloto[], int tamPil); SI ES UN MOSTRAR CON OBTENER

///void obtenerNomPiloto(ePiloto vecPil[], int tamPil, int id, char dondeAsigar[]);

void mostrarDatos(STRUCT_NAME vec[], int tam);

int altaDATO(eVuelo vuelo[], int tamV,ePiloto piloto[], int tamPil, eDestino destino[], int tamD, int idVuelo);

void bajaDATO(eVuelo vecVue[], int tamVue, eDestino vecDest [], int tamD, ePiloto pil [], int tamPil);

int modificarDATO(eVuelo vec[], int tam, eDestino dest[], int tamD, ePiloto pil[], int tamP) ///ACA VAN LAS ESTRUC QUE INFLUYEN EN LA MODIFICACION,A VACES ES UNA SOLA

int buscarPersonaPOR_ID(int VALOR_A_BUSCAR, STRUCT_NAME vec[], int tam);
