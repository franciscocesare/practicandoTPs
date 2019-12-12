#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int idCliente;
    char nombre[51];
    char apellido[51]; ///validar
    char sexo;
    char telefono[21];
    char direccion[51];
    int idLocalidad;
    int isEmpty;

} eCliente;

typedef struct
{
    int idLocalidad;
    char nombreLocalidad [51];

}eLocalidad;

#endif // CLIENTES_H_INCLUDED

int menuClientes();
int hardcodearClientes( eCliente[], int tam, int cantidad);
void inicializarClientes(eCliente vec[], int tam);
int findFree(eCliente vec[], int tam);
int altaCliente(eCliente vec[], int tam, int idCliente, eLocalidad loc[], int tamLoc);
eCliente newCliente(int idCliente,char name[],char lastName[],char sexo,char direccion[],char localidad[],char telefono[]);
int buscarCliente(int id, eCliente vec[], int tam);
void mostrarClientes(eCliente vec[], int tam, eLocalidad loc[],int tamLoc);
//void mostrarCliente(eCliente x, eLocalidad loc);
void mostrarCliente(eCliente x, eLocalidad loc[], int tamLoc);

int borrarCliente(eCliente vec[], int tam, eLocalidad loc[], int tamLoc);
int modificarCliente(eCliente vec[], int tam, eLocalidad loc[], int tamLoc);
void obtenerNomCliente(eCliente vec[], int tam, int id, char dondeAsigar[]);///modificar eso en la funcion de donde asignar
void ordenarCliente(eCliente vec[], int tam);

void harcodearlocalidad(eLocalidad vec[], int tamLoc);
void mostrarLocalidades(eLocalidad loc[], int tamLoc);
void obtenerLocalidad(eLocalidad vec[], int tamLoc, int id, char dondeAsignar[]);
