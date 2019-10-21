#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct{
    int idCliente;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    char domicilio[51];
    int isEmpty;
}eCliente;


int altaCliente(eCliente clientes[], int tamCli, int idCliente);
int isEmptyCliente(eCliente clientes[], int tamCli);
int inicializarClientes(eCliente clientes[], int tamCli);
eCliente newCliente(int idCliente, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[]);
void ordenarClientes(eCliente cli[], int tamCli);
void mostrarClientes(eCliente clientes[], int tamCli);
void mostrarCliente(eCliente cliente);
int hardcodearClientes( eCliente clientes[], int tamCli, int cantidad);
int bajaCliente(eCliente clientes[], int tamCli);
int buscarIdCliente(eCliente clientes[], int tamCli, int idCliente);
int modificarCliente(eCliente clientes[], int tamCli);
int cargarDescCliente(int idCliente, eCliente clientess[], int tamCli, char desc[]);
int subMenu();
#endif // CLIENTE_H_INCLUDED
