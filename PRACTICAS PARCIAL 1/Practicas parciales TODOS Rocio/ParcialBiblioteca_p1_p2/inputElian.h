#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

/*Funciones para obtener valores*/
/**\brief Solicita un número entero al usuario y lo asigna a la variable enviada
 * \param var_dondeAsignar es donde se guarda el valor
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirInt (int * var_dondeAsignar, char mensaje[]);

/**\brief Solicita un número entero al usuario , valida que este dentro de 2 parametros y lo asigna a la variable enviada
 * \param var_dondeAsignar es donde se guarda el valor
 * \param min Es el numero minimo que el usuario puede ingresar
 * \param max Es el numero maximo que el usuario puede ingresar
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirIntEntre(int * var_dondeAsignar, int min, int max, char mensaje[]);

/**\brief Solicita un número tipo flotante al usuario y lo asigna a la variable enviada
 * \param var_dondeAsignar es donde se guarda el valor
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirFloat (float * var_dondeAsignar, char mensaje[]);

/**\brief Solicita un caracter al usuario y lo asigna a la variable enviada
 * \param var_dondeAsignar es donde se guarda el valor
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirChar (char * var_dondeAsignar, char mensaje[]);

/**\brief Solicita un string al usuario , elimina saltos de linea , y lo asigna a la variable enviada
 * \param mensaje Es el mensaje a ser mostrado
 * \param var_dondeAsignar es donde se guarda el valor
 * \return void
 */
void f_i_PedirString(char var_dondeAsignar[], int longitudMaxString, char mensaje[]);

/*Funciones para obtener datos especificos*/
/** \brief Solicita un texto al usuario , valida que sea solo letras y espacios, vuelve la primer letra Mayuscula y el resto minuscula despues de cada espacio
 * elimina saltos de linea
 * \param var_dondeAsignar es donde se guarda el valor
 * \param longitudMaxString es la cantidad maxima de caracteres que puede ingresar el usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirNombre(char var_dondeAsignar[],int longitudMaxString, char mensaje[]);
/** \brief Solicita un texto al usuario , valida que sea solo numeros,elimina saltos de linea
 * \param var_dondeAsignar es donde se guarda el valor
 * \param longitudMaxString es la cantidad maxima de caracteres que puede ingresar el usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirStringSoloNumeros(char var_dondeAsignar[],int longitudMaxString,char mensaje[]);
/** \brief Solicita un texto al usuario , valida que sea solo letras,elimina saltos de linea
 * \param var_dondeAsignar es donde se guarda el valor
 * \param longitudMaxString es la cantidad maxima de caracteres que puede ingresar el usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirStringSoloLetras(char var_dondeAsignar[],int longitudMaxString,char mensaje[]);
/** \brief Solicita un texto al usuario , valida que sea solo numeros y un '.' como maximo
 * \param var_dondeAsignar es donde se guarda el valor
 * \param longitudMaxString es la cantidad maxima de caracteres que puede ingresar el usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirStringSoloFloat(char var_dondeAsignar[],int longitudMaxString,char mensaje[]);
/** \brief Solicita un texto al usuario , valida que sea solo numeros , letras o espacios , elimina saltos de linea
 * \param var_dondeAsignar es donde se guarda el valor
 * \param longitudMaxString es la cantidad maxima de caracteres que puede ingresar el usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirStringAlfaNumerico(char var_dondeAsignar[],int longitudMaxString,char mensaje[]);
/** \brief Pide un string de formato patente AAA 123 y valida que se ingrese un dato valido.
 * \param var_dondeAsignar es donde se guarda el valor
 * \param longitudMaxString es la cantidad maxima de caracteres que puede ingresar el usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirPatenteVieja(char var_DondeAsignar[], char mensaje[]);
/** \brief Solicita un texto al usuario , valida que sea de formato e-mail, maximo UN punto y UN arroba ,permite numeros y "_"
 * elimina saltos de linea
 * \param var_dondeAsignar es donde se guarda el valor
 * \param longitudMaxString es la cantidad maxima de caracteres que puede ingresar el usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirEmail (char var_dondeAsignar [], int longitudMaxString, char mensaje [] );
/** \brief Solicita un texto al usuario , valida que sea de formato Teleforno,de 8 a (longitudMaxString) caracteres maximos,solo permite numeros
 * elimina saltos de linea
 * \param var_dondeAsignar es donde se guarda el valor
 * \param longitudMaxString es la cantidad maxima de caracteres que puede ingresar el usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirTelefono (char var_dondeAsignar[], int longitudMaxString, char mensaje[]);
/** \brief Solicita un caracter al usuario , valida que sea solo pueda ingresar 'F' o 'M' , arregla las mayusculas automaticamente
 * \param var_dondeAsignar es donde se guarda el valor
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirSexo(char * var_dondeAsignar, char mensaje[]);
/** \brief Solicita un entero al usuario , valida que sea entre 0 y 99
 * \param var_dondeAsignar es donde se guarda el valor
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirEdad (int * var_dondeAsignar,char mensaje[]);
/** \brief Solicita una fecha al usuario , valida dia mes y anyo
 * \param laFecha es donde se guarda el valor
 * \param diaEnQue Es el mensaje a ser mostrado para el dia
  * \param mesEnQue Es el mensaje a ser mostrado para el mes
   * \param anyoEnQue Es el mensaje a ser mostrado para el anyo
 * \return void
 */
void pedirFecha (int *dia, int* mes, int *anyo,char diaEnQue[],char mesEnQue[],char anyoEnQue[]);
/** \brief Solicita al usuario y valida que solo se ingrese 'S' o 'N' , arregla mayusculas automaticamente
 * \param mensaje Es el mensaje a ser mostrado
 * \return 1 si el usuario ingreso 'S' , 0 si el usuario ingreso 'N'
 */
int f_i_SioNo(char mensaje[]);
/** \brief Pausa el programa y solicita al usuario que ingrese una tecla para continuar
 * \return void
 */
void f_i_continuar(void);

/*Funciones para otras funciones y general*/
/** \brief Limpia la pantalla
 * \return void
 */
void limpiar (void);
/** \brief Hace un sleep
 * \param ms son milisegundos a esperar
 * \return void
 */
void esperar (int ms);
/** \brief Cambia el color de la consola
 * \return void
 */
void noVeo(void);

/*Funciones de ordenamiento*/
/**\brief Recibe un array de enteros y iguala todos sus elementos a un valor que se le asigne
 * \param var_dondeAsignar es donde se guarda el valor
 * \param asignarleEsteNumero es el numero que se le asigna a todos los elementos del array
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array var_dondeAsignar
 * \return void
 */
void f_o_IniciarArrayInt (int var_dondeAsignar[],int asignarleEsteNumero,int cantidadElementos);
/**\brief Recibe un array de enteros y asigna valores a todos sus elementos de manera creciente de uno en uno (empezando desde 1)
 * \param var_dondeAsignar es donde se guarda el valor
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array var_dondeAsignar
 * \return void
 */
void f_o_IniciarArrayIntIncremental(int var_dondeAsignar[],int cantidadElementos);
/**\brief Recibe un array de enteros y devuelve el indice donde se encuentre la primera ocurrencia que se le asigne a la funcion
 * \param var_dondeAsignar es donde se busca el valor
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array var_dondeAsignar
 * \param indicadorPrimerOcurrencia es el numero que se busca dentro del array
 * \return el indice de la primer ocurrencia si se encuntra ,  -1 si no se encuentra .
 */
int f_o_BuscarIndicePrimerOcurrencia (int var_dondeAsignar[],int cantidadElementos,int indicadorPrimerOcurrencia);
/**\brief Recibe un array de enteros lo ordena de mayor a menor
 * \param var_dondeAsignar es el array a ordenar
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array var_dondeAsignar
 * \return void
 */
void f_o_OrdernarArrayMayorAMenor (int var_dondeAsignar[],int cantidadElementos);
/**\brief Recibe un array de enteros lo ordena de menor a mayor
 * \param var_dondeAsignar es el array a ordenar
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array var_dondeAsignar
 * \return void
 */
void f_o_OrdernarArrayMenorAMayor (int var_dondeAsignar[],int cantidadElementos);
/**\brief Recibe un array de strings y lo ordena alfabeticamente
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array var_dondeAsignar
 * \param longitudMaxString es la longitud maxima de los string de el array var_dondeAsignar
 * \param var_dondeAsignar es el array a ordenar
 * \return void
 */
void f_o_OrdenarArrayAlfabeticamente(int cantidadElementos,int longitudMaxString,
                                     char var_dondeAsignar[cantidadElementos][longitudMaxString]);
/**\brief Recibe un array de strings y deja cada palabra de cada elemento con la primera letra mayuscula y el resto minuscula
 * \param cantidadElementos es la cantidad maxima de elementos que tiene el array var_dondeAsignar
 * \param longitudMaxString es la longitud maxima de los string de el array var_dondeAsignar
 * \param var_dondeAsignar es el array a arreglar mayusculas
 * \return void
 */
void f_o_ArreglarCaps (int cantidadElementos,int longitudMaxString,
                       char var_dondeAsignar[cantidadElementos][longitudMaxString]);


