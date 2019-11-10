#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "funcionesGenerales.h"
#include "utn.h"

/**
 * \brief Solicita un numero al usuario y lo devuelve
 * \param mensaje, es el mensaje q mostrar como instruccion al usuario
 * \return El numero ingresado por el usuario
 * Devuelve un entero
 */
int getIn ( char mensaje[]) {
    int aux;
    printf("%s",mensaje);
    scanf("%d",&aux);
    return aux;
    }
/**
 * \brief Solicita un numero al usuario y lo devuelve
 * \param mensaje, es el mensaje q mostrar como instruccion al usuario
 * \return El numero ingresado por el usuario
 * devuelve un float
 */
float getFloat (char mensaje[]){
    float aux;
    printf("%s",mensaje);
    scanf("%f",&aux);
    return aux;
}
/**
 * \brief Solicita un caracter al usuario y lo devuelve
 * \param mensaje, es el mensaje q mostrar como instruccion al usuario
 * \return El numero ingresado por el usuario
 * devuelve un char
 */
char getChar(char mensaje[]){
    char aux;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}

/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}
/** \brief Verifica si el valor es numerico;
 *
 * \param str Recibe un array con la cadena q va a analizar.
 * \return 1 si es numerico, 0 si no lo es.
 *
 */

int esNumerico (char str []){
    int i=0;
    while (str[i]!='\0'){
        if(str[i]<'0' || str[i]>'9'){
        return 0;
        }
        i++;
    }
    return 1;
}
/** \brief Verifica si el valor es Letras
 *
 * \param str Recibe un array con la cadena q va a analizar.
 * \return 1 si es letras, 0 si no lo es.
 *
 */

int esLetras (char str[]){
int i=0;
    while (str[i]!='\0'){
        if((str[i]!=' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z')) // Chequea por la negativa para return 0
            {
        return 0;
        }
        i++;
    }
    return 1;
}
/** \brief Verifica si es alfa numerico
 *
 * \param str Recibe un array con la cadena q va a analizar.
 * \return 1 si es alfa numerico, 0 si no lo es.
 *
 */

int esAlfaNumerico (char str[]) {
    int i=0;
    while (str[i]!='\0'){
        if((str[i]<'0' || str[i]>'9')&& (str[i]!=' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z')) // Chequea por la negativa para return 0
            {
        return 0;
        }
        i++;
    }
    return 1;
}
/** \brief Verifica si es un conjunto numerico telefonico
 *
 * \param str Recibe un array con la cadena q va a analizar.
 * \return 1 si es correcto, 0 si no lo es.
 * Permite un solo guion
 */
int esTelefono (char str[]){
    int i=0;
    int contGuion=0;
    while (str[i]!='\0'){
        if((str[i]<'0' || str[i]>'9')&& (str[i]!=' ') && (str[i]!='-')) // Chequea por la negativa para return 0
            {
        return 0;
        }
        if (str[i]=='-'){
            contGuion++;
        }
        i++;
    }
    if (contGuion==1)
        return 1;

    return 0;
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/** \brief chequea el largo del array.
 *
 * \param str es el array
 * \param i, recibe el largo q debe tener.
 * \return  1 si esta ok, 0 i esta excedido.
 *
 */

int checkLenght(char str[], int i){
if (strlen(str)>i){
    return 0;
}
return 1;
}

int limitadorInt(float valor, int lowLimit, int highLimit){
if( valor < lowLimit || valor > highLimit )
    {
        printf("Error. No respeta los limites");
        return 0;
    }
return 1;
}


