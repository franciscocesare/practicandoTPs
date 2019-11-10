#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int id;
    char Apellido[31];
    char nombre[31];
    char sexo;
    char telefono[16];
    char mail[31];
    eFecha asociado;
    int isEmpty;

} eSocio;

#endif // SOCIOS_H_INCLUDED

int hardCodeSocios (eSocio lista[],int tam, int cant);
void iniciarlizarSocios(eSocio vec[], int tam);
int buscarLibreSocio(eSocio vec[], int tam);
void mostrarSocio(eSocio socio);
void mostrarSocios(eSocio vec[],int tam);
void ordenarSocios(eSocio vec[], int tam);
int buscarSocioId(eSocio vec[], int tam, int codigo);
void bajaSocio(eSocio vec[], int tam);
int altaSocio(eSocio vec[],int tam,int codigo);
int menuModificacion();
void modificarSocio(eSocio vec[],int tam);
void obtenerNomSocio(eSocio vec[],int tam, int id, char dondeAsignar[]);



