#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "funcionesGenerales.h"
#include "utn.h"


/** \brief lleva los estados a 0 para indicar q esta vacio
 *
 * \param Employee empleado[] recibe el array de estructura de empleados
 * \param valor recibe el valor, 0 cero, para indicar q esta libre
 * \return
 *
 */
int initEmployees(Employee empleado[],int largo, int valor){
    int i;
    for (i=0;i<largo;i++){
                empleado[i].isEmpty=valor;
    }
return 0;
}


/** \brief Realiza la toma de datos para el Alta de empleado
 *
 * \param empleado REcibe Array de estructura
 * \param CANT el largo del array
 * \param i es el indice donde realiza la carga.
 * \return retorna -1 si falla algo, 1 si la carga es completa.
 * OJO, quedò al reves, isEmpty es 1 True si No esta vacio!!!!!
 */

int addEmployee(Employee empleado[], int CANT, int i,int idIncremental){
char aux[51], auxSalary[5];
float auxSalaryFloat;
char auxSector[10];
int auxSectorInt;
int lenght=51;
    if(!empleado[i].isEmpty){
        empleado[i].id=idIncremental+100;
        if(!getStringLetras("\nIngrese Apellido: ",aux)){
        printf("\nError. Ingrese solo letras");
        return -1;
        }
        if(!checkLenght(aux, lenght)){
            printf("Se ha excedido en el largo de caracteres.");
            return -1;
        }
        aux[0]=toupper(aux[0]);
        strcpy(empleado[i].lastName,aux);

        if(!getStringLetras("\nIngrese Nombre: ",aux)){
        printf("\nError. Ingrese solo letras");
        return -1;
        }
        if(!checkLenght(aux, lenght)){
            printf("Se ha excedido en el largo de caracteres.");
            return -1;
        }
        aux[0]=toupper(aux[0]);
        strcpy(empleado[i].name, aux);

        if(!getStringNumerosFlotantes("\nIngrese Salario (Solo numeros entre 1000 y 50000): ", auxSalary)){
        printf("Error. Ingrese solo numeros.");
        return -1;
        }
        auxSalaryFloat=atoi(auxSalary);
        if(!limitadorInt(auxSalaryFloat,1000,50000)){
            return -1;
        }
        empleado[i].salary=auxSalaryFloat;

        if(!getStringNumeros("\nIngrese Sector (Solo sectores 1 al 5): ",auxSector)){
        printf("Error. Ingrese solo numeros");
        return -1;
        }
        auxSectorInt=atoi(auxSector);
        if ((auxSectorInt<1) || (auxSectorInt>5)){
                printf("Error. Sector incorrecto.");
            return -1;
        }
        empleado[i].sector=auxSectorInt;

        empleado[i].isEmpty=1;
        return 1;
        }else {
            printf("Hay un Error");
            return -1;
        }
return -1;
}

/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
*
* \param empleado Es el array a analizar
* \param CANT int largo del array
* \param i int RECIBE el indice del array
* \return RETORNA el Id encontrado, o 0 si fallo algo.
*
*/

int findEmployeeById(Employee empleado[], int CANT,int auxID){
    int i;
    for (i=0;i<CANT;i++){
        if(auxID==empleado[i].id && empleado[i].isEmpty==1){
                    system("cls");
                    printf("\n Se ha encontrado la siguiente persona:");
                    printf("\n\t%d\t\t -%s\t\t   -   %s\t\t   -   %.2f\t\t   -  %d",empleado[i].id, empleado[i].name, empleado[i].lastName, empleado[i].salary,empleado[i].sector);
        return i;
        }
    }
    return -1;
}
/** \brief MOdificacion de datos de alta realizada previamente.
 *
* \param empleado Es el array a analizar
* \param CANT int largo del array
* \param i int RECIBE el indice del array
 * \return
 *
 */

int modifyEmployee(Employee empleado[], int CANT){

    char aux[50];
    float auxSalaryFloat;
    int auxSectorInt;
    int opcionModify;
    int i;
    int id;
    int lenght=51;

    if(!getStringNumeros("\nIngrese ID del empleado a modificar : ",aux)){
        printf("Error. Ingrese solo numeros");
        return -1;
    }

    id=atoi(aux);
    for(i=0;i<CANT;i++){
        if(id==empleado[i].id && empleado[i].isEmpty==1){
            opcionModify=menuModificar();
            switch(opcionModify){
            case 1:
                    getStringLetras("\nVa a modificar apellido. Ingrese nuevo Apellido: ",aux);
                    if(!checkLenght(aux, lenght)){
                    printf("Se ha excedido en el largo de caracteres.");
                    break;
                    }
                    aux[0]=toupper(aux[0]);
                    strcpy(empleado[i].lastName,aux);
                    break;
            case 2:
                    getStringLetras("\nVa a modificar nombre. Ingrese nuevo Nombre :",aux);
                    if(!checkLenght(aux, lenght)){
                    printf("Se ha excedido en el largo de caracteres.");
                    break;
                    }
                    aux[0]=toupper(aux[0]);
                    strcpy(empleado[i].name, aux);
                    break;
            case 3:
                    getStringNumerosFlotantes("\nVa a modificar Salario. Ingrese nuevo salario: ",aux);
                    auxSalaryFloat=atoi(aux);
                    if(!limitadorInt(auxSalaryFloat,1000,50000)){
                    break;
                    }
                    empleado[i].salary=auxSalaryFloat;
                    break;
            case 4:
                    getStringNumeros("\nIngrese nuevo sector: ",aux);
                    auxSectorInt=atoi(aux);
                    empleado[i].sector=auxSectorInt;
                    break;
            }
        }
     }
//printf("No se ha encontrado el Id del empleado a modificar. Intente nuevamente");
return -1;
}
/** \brief Remove a Employee by Id
*
* \param empleado Es el array a analizar
* \param CANT int largo del array
* \param i int RECIBE el indice del array
* \return int Return 1 si esta ok. 0 si fallo.
*
*/

int removeEmployee(Employee empleado[], int CANT, int i){
    char answer;// Pregunta para eliminar
    do{
    answer=tolower(getChar("\n\nProcede a eliminar? S/N "));
        if (answer=='s'){
            empleado[i].isEmpty=0;
            printf("El empleado %d ha sido eliminado.",empleado[i].id);
            return 1;
        }else if(answer=='n'){
            printf("\n No se ha eliminado.");
        }
    }while(!((answer=='s' || answer=='n')));
    return 0;
}
/** \brief Sort the elements in the array of employees
*
* \param list Employee
* \param len int
* \param
* \return
*
*/
void sortEmployee(Employee empleado[],int arrayLenght)
{
    Employee Aux;
    int i,j;

    for(i=0; i < arrayLenght - 1; i++)
    {
        if(empleado[i].isEmpty == 0)
        {
            continue;
        }
        for(j=i+1; j < arrayLenght; j++)
        {
            if(empleado[j].isEmpty == 0)
            {
                continue;
            }
            if(strcmp(empleado[j].lastName,empleado[i].lastName)<0)
            {
                Aux = empleado[j];
                empleado[j] = empleado[i];
                empleado[i] = Aux;
            }
            else if(strcmp(empleado[j].lastName,empleado[i].lastName) == 0)
            {
                if(empleado[i].sector > empleado[j].sector)
                {
                    Aux = empleado[j];
                    empleado[j] = empleado[i];
                    empleado[i] = Aux;
                }
            }
        }
    }
}
/** \brief Muestra por pantalla los empledos vigentes
 *
 * \param empleado Array
 * \param CANT int de largo
 * \return Retorna 1 por las dudad !? :)
 *
 */

int printEmployees(Employee empleado[], int CANT){
    int i;
    system("cls");
        printf("\n\t\t-------  Listado de personal  -------\n");
        printf("\n\tId Empleado\t\t Apellido\tNombre\t\t\tSalario\t\tSector");

        for (i=0;i<CANT;i++){
            if(empleado[i].isEmpty){
                printf("\n\t%10d\t %-15s\t %-10s\t\t %.2f\t %d\t",empleado[i].id,empleado[i].lastName,empleado[i].name,empleado[i].salary,empleado[i].sector);
            }
        }
        printf("\n");
return 1;
}
/** \brief suma todos los salarios
 *
 * \param Array de empleados
 * \param CANT largo array
 * \return float con la suma
 *
 */

float sumaSalary(Employee empleado[], int CANT){
int i;
float acumuladorSalario=0;
for(i=0;i<CANT; i++){
    if(empleado[i].isEmpty){
            acumuladorSalario=acumuladorSalario+empleado[i].salary;
            }
}
return acumuladorSalario;
}
/** \brief Contador de empleados activos
 *
 * \param
 * \param
 * \return int de cantidad
 *
 */

int contadorEmployees(Employee empleado[], int CANT){
int i;
int contador=0;
for(i=0;i<CANT; i++){
    if(empleado[i].isEmpty){
            contador++;
            }
}
return contador;
}
/** \brief
 *
 * \param empleado Array estuctura
 * \param largo array
* \param int de promedio salario
 * \param int contador empleados activos
 * \return int
 *
 */

int contadorArribaPromedio(Employee empleado[], int CANT, int promedioSalario, int contador){
int i;
int j=0;
for (i=0;i<CANT;i++){
            if(!empleado[i].isEmpty){
                    continue;
            }
            if(empleado[i].salary>promedioSalario){
                j++;
            }
        }
        return j;
}
