#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono [51];
    char domicilio[21];
    int isEmpty;
}eClientes;


#endif // CLIENTE_H_INCLUDED

int initClientes(eClientes listaC[], int tamC);
int altaCliente(eClientes listaC[], int tamC, int id);
int buscarLibre(eClientes listaC[], int tamC);
int addCliente(eClientes cliente[], int id, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[]);
void listarClientes(eClientes clientes[], int tamC);
void listarCliente(eClientes clientes);
void ordenarClientes(eClientes clientes[], int tamC);
int buscarClientePorId(eClientes list[], int tam, int codigo);
void modificarCliente(eClientes clientes[], int tamC);
int bajaCliente(eClientes vec[], int tamC);
