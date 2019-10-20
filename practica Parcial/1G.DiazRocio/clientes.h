#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    char domicilio[51];
    int isEmpty;

}eCliente;

#endif // CLIENTES_H_INCLUDED

int harcodearClientes(eCliente vec[], int tam, int cant);
void inicializarClientes(eCliente vec[], int tam);
int buscarLibreCliente(eCliente vec[],int tam);
void mostrarCliente(eCliente vec);
void mostrarClientes(eCliente vec[], int tam);
int buscarClienteId(eCliente vec[], int tam, int id);
int altaCliente(eCliente vec[], int tam,int id);
void bajaCliente(eCliente vec[], int tam);
void ordenarCliente(eCliente vec[], int tam);
int menuModificacion();
void modificarCliente(eCliente vec[], int tam);
void obtenerNomCliente(eCliente vec[], int tam, int id, char dondeAsigar[]);
