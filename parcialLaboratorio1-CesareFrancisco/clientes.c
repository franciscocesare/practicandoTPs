
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "clientes.h"

///faltaria ordenar clientes

int menuClientes()
{
    int opcion;

    system("cls");
    printf("****** ABM Clientes *******\n\n");
    printf("1-Alta Cliente\n");
    printf("2-Baja Cliente\n");
    printf("3-Modificar Cliente \n");
    printf("4-Listar Clientes\n");
    printf("5-Volver al menu anterior\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

/** \brief completa el array con valores hardcodeados
* \param array clientes
* \param size int Tamaño del array
* \param  cantidad de elementos a cargar
* \return inicia la estructura con valores precargados, cont=cuantos se cargaron
*
*/
int hardcodearClientes( eCliente vec[], int tam, int cantidad)
{
    int cont = 0;

    eCliente aux[]=
    {
        {1000,   "JUAN", "GARAY", 'M', "1160313333", "Av San Juan 284",100,0},
        {1001,   "ROBERTO", "LARALALA", 'M', "1150315433","Eva Peron 1221", 100,0},
        {1002,   "ROMINA", "LESCANO", 'F', "1167413333","Las Piedras 1445", 101,0},
        {1003,   "PABLO", "PEREZ", 'M', "1140313953","Tucuman 1145", 104,0},
        {1004,   "JIMENA", "GUTIERREZ", 'F', "1174314125","Mejico 2252", 105,0},
        {1005,   "NORMA", "ARIAS", 'F', "1161314569", "Santa Fe 3500",107,0},
        {1006,   "LUIS", "ARRIETA", 'M', "1165213458", "Av Medrano 2105",103,0},
        {1007,   "SILVIA", "LUGUERCIO", 'F', "1152313336", "Av San Juan 865",108,0},
        {1008,   "ANIBAL", "MONTE", 'M', "1160357896", "Libertad 65",102,0},
        {1009,   "DANIELA", "ERGO", 'F', "1121513612", "Av BraSil 444",101,0}

    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vec[i] = aux[i];
            cont++;
        }
    }

    return cont;
}

void harcodearlocalidad(eLocalidad vec[], int tamLoc)
{


    eLocalidad localidades[]=
    {
        {100, "Capital Federal"},
        {101, "Lanus"},
        {102, "Longchamps"},
        {103, "Avellaneda"},
        {104, "Gerli"},
        {105, "Liverpool"},
        {106, "Washington"},
        {107, "Londres"},
        {108, "Calzada"},
        {109, "Turdera"},
        {110, "Quilmes"},



    };

    for(int i=0; i<tamLoc; i++)
    {
        vec[i]=localidades[i];
    }
}

/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array clientes
* \param size int Tamaño del array
* \param Id cliente para buscar
* \return int Return indice donde se encuentra
*
*/

int buscarCliente(int idCliente, eCliente vec[], int tam)
{
    int index = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].idCliente == idCliente && vec[i].isEmpty == 0)
        {
            index = i;
            break;
        }

    }
    return index;
}


/** \brief Busca el primer lugar vacio en un array
* \param array cliente
* \param size int Tamaño del array
* \param
* \return posicion del array donde se encuentra el valor buscado, el indice vacio
*
*/
int findFree(eCliente vec[], int tam)
{
    int index = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            index = i;
            break;
        }
    }
    return index;
}

/** \brief  para indicar que el array esta vacio pone en todas las posiciones,
el isEmpty en 1, vacio
* \param array cliente
* \param size int tamnio del array
* \return funcion VOID, todas las posiciones inicializadas
*
*/
void inicializarClientes(eCliente vec[], int tam)///inicia el array, pone todas las posicciones en 1. VACIO
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array cliente
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return(1) si se agrega un nuevo elemento exitosamente
*
*/

int altaCliente(eCliente vec[], int tam, int idCliente, eLocalidad loc[], int tamLoc)
{

    int todoOk = 0;
    int index;
    char name[51];
    char lastName[51];
    char sexo;
    char telefono [20];
    char direccion[51];
    char localidad [51];
    int idLocalidad;

    system("cls");

    printf("*****Alta Cliente*****\n\n");

    index = findFree(vec, tam); ///a ver si hay lugar libre, lo guarda en index 1 si hay, -1 sino

    if( index == -1)
    {
        printf("\nEl Sistema Esta Completo\n\n");
        system("pause");
    }
    else
    {
        vec[index].idCliente = idCliente;
        getStringAlpha(51, "Ingrese el Nombre: ", name);
        getStringAlpha(51, "Ingrese el Apellido: ", lastName);
        pedirSexo(&sexo,"Ingrese sexo F/M: ");
        getStringAlphaNum(51, "Ingrese el domicilio: ", direccion);
        mostrarLocalidades(loc, tamLoc);
        getIntRange(&idLocalidad, 100,110, "Ingrese el Id de la localidad");
        obtenerLocalidad(loc, tamLoc, loc.idLocalidad,localidad);
        ///obtenerNomCliente(lista,tamC,vec.idCliente,nomCliente);
        getTelefono("Ingrese el Telefono sin espacios ni guiones: \n", "\nError telefono invalido\n",8,20,0, 9,2,telefono);
        vec[index] = newCliente(idCliente, name, lastName, sexo, direccion,localidad, telefono);
        todoOk = 1;
        printf("\nSe ha realizado el alta del cliente\n\n");
        system("pause");

    }
    return todoOk;
}

eCliente newCliente(

    int idCliente,
    char name[],
    char lastName[],
    char sexo,
    char direccion[],
    char localidad[],
    char telefono[])
{

    eCliente cliente;
    cliente.idCliente = idCliente;
    strcpy( cliente.nombre, name);
    strcpy( cliente.apellido, lastName);
    strcpy( cliente.direccion, direccion);
    strcpy( cliente.telefono, telefono);
    cliente.sexo = sexo;
    cliente.isEmpty = 0;

    return cliente;
}

/** \brief Borra un elemento del array por ID
* \param array Cliente
* \param size int Tamaño del array
* \return int Return 1 si se elimina el elemento exitosamente
*
*/
int borrarCliente(eCliente vec[], int tam, eLocalidad loc[], int tamLoc)
{
    int todoOk = 0;
    int id;
    int index;
    char confirma;
    printf("***** Baja Cliente *****\n\n");

    mostrarClientes(vec, tam, loc, tamLoc);

    printf("Ingrese id: ");
    scanf("%d", &id);

    index = buscarCliente(id, vec, tam);
    if( index == -1)
    {
        printf("No existe un cliente con ese ID\n\n");

    }
    else
    {

        mostrarCliente(vec[index],loc[index]);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[index].isEmpty = 1;
            todoOk = 1;
            printf("Baja de cliente exitosa!\n");
        }
        else
        {
            printf("\nNo se realizo la baja correspondiente\n ");
        }
    }

    return todoOk;
}

/** \brief Busca un elemento por ID y modifica sus campos
* \param array clientes
* \param size int Tamaño del array
* \return int Return 1 si se modifica el elemento exitosamente
*
*/
int modificarCliente(eCliente vec[], int tam, eLocalidad loc[], int tamLoc)
{

    int todoOk = 0;
    int id;
    int index;
    system("cls");
    printf("\n***** MODIFICAR DATOS DE CLIENTES *****\n\n");
    mostrarClientes(vec, tam, loc, tamLoc);

    printf("Ingrese id del cliente: ");
    scanf("%d", &id);
    int opcion;

    index = buscarCliente(id, vec, tam);

    if( index == -1)
    {
        printf("No existe un cliente con ese id\n\n");

    }
    else
    {
        printf(" ID     APELLIDO     NOMBRE  SEXO    DIRECCION  LOCALIDAD   TELEFONO\n\n");
        mostrarCliente(vec[index],loc[index]);

        printf("\n\n***QUE DESEA MODIFICAR DEL CLIENTE***\n\n");
        printf("1- Modificar nombre\n");
        printf("2- Modificar apellido\n");
        printf("3- Modificar domicilio\n");
        printf("4- Modificar telefono\n");
        printf("5- Salir\n\n");
        printf("Ingrese opcion: \n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:

            getStringAlpha(51, "Ingrese nuevo Nombre: ", vec[index].nombre);
            break;

        case 2:
            getStringAlpha(51, "Ingrese el Apellido: ", vec[index].apellido);
            break;

        case 3:
            getStringAlphaNum(51, "Ingrese el domicilio: ", vec[index].direccion);

            break;

        case 4:
            printf("Ingrese nuevo telefono: ");
            scanf("%s", vec[index].telefono);

            break;

        case 5:
            printf("Se ha cancelado la modificacion ");
            break;

        }
    }
    return todoOk;
}

/** \brief obtiene nombre de un cliente a traves del id
 *
 * \param estructura clientes
 * \param tamanio estructura clientes
 * \param id de la categoria a buscar
 * \param donde asignar nombre obtenido
 * \return VOID, nombre cargado
 *
 */
void obtenerNomCliente(eCliente vec[], int tam, int id, char dondeAsigar[])
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].idCliente == id)
        {
            strcpy(dondeAsigar,vec[i].apellido);
            strcat(dondeAsigar,", ");
            strcat(dondeAsigar,vec[i].nombre);
        }
    }
}

/** \brief Lista 1 elemento de un array
* \param 1 posicionarray clientes
* \return Void, imprime en pantalla el listado de mostrar cliente
*
*/
void mostrarCliente(eCliente x, eLocalidad loc)
{
    printf(" %d  %3s   %5s    %5c    %8s   %8s  %8s \n",
           x.idCliente,
           x.apellido,
           x.nombre,
           x.sexo,
           x.direccion,
           loc.nombreLocalidad,
           x.telefono);
}

/** \brief Lista los elementos de un array
* \param array clientes
* \param size int Tamaño del array
* \return Void, imprime en pantalla el listado de mostrar cliente
*
*/

void mostrarClientes(eCliente vec[], int tam, eLocalidad loc[], int tamLoc)
{

    int flag = 0;
    system("cls");

    printf(" ID   APELLIDO    NOMBRE    SEXO    DIRECCION  LOCALIDAD  TELEFONO  \n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarCliente(vec[i], loc[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay clientes que mostrar\n");
    }

    printf("\n\n");
}

/** \brief ordena el array de clientes de manera ascendente
 *
 * \param vector de clientes
 * \param tamnio del vector clientes
 * \param auxiliar para guardar el valor y no e pierda en el swapeo
 * \return
 *
 */

void ordenarCliente(eCliente vec[], int tam)
{
    eCliente aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmpi(vec[i].apellido,vec[j].apellido)>0)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
            else
            {
                if(strcmpi(vec[i].apellido,vec[j].apellido)==0 && strcmpi(vec[i].nombre,vec[j].nombre)>0)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }
    }
}

void mostrarLocalidades(eLocalidad loc[], int tamLoc)
{

    system("cls");
    printf(" ID    LOCALIDAD\n\n");

    for(int i=0 ; i<tamLoc; i++)
    {
       printf("\n%d , %s", loc[i].idLocalidad, loc[i].nombreLocalidad);
    }
}

void obtenerLocalidad(eLocalidad vec[], int tamLoc, int id, char dondeAsignar[])

{
    for(int i=0 ; i<tamLoc; i++)
    {
        if(vec[i].idLocalidad == id)
        {
            strcpy(dondeAsignar,vec[i].nombreLocalidad);
        }
    }
}
