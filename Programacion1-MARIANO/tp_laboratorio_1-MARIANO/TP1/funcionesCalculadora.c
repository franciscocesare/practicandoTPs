/** \brief funcion operacion suma
 * \param recibe int de las variables numeroA y numeroB
 * \return devuelve el resultado de la operacion
 */

int add(int a, int b ){
    int cuenta;
    cuenta=a+b;
    return cuenta;
}
/** \brief funcion operacion resta
 * \param recibe int de las variables numeroA y numeroB
 * \return devuelve el resultado de la operacion
 */
int substract(int a, int b){
int cuenta;
cuenta = a-b;
return cuenta;
}
/** \brief funcion operacion multiplicacion
 * \param recibe int de las variables numeroA y numeroB
 * \return devuelve el resultado de la operacion
 */
int multiply(int a,  int b){
int cuenta;
cuenta=a*b;
return cuenta;
}
/** \brief funcion operacion Division
 * \param recibe float de las variables numeroA y numeroB
 * \return devuelve float con el resultado de la operacion
 */
float divide( float a, float b) {
float cuenta;
cuenta=a/b;
return cuenta;
}
/** \brief funcion operacion Factorial
 * \param recibe int de las variables numeroA y numeroB
 * \return devuelve el resultado de la operacion
 */
int factorize(int a)
{
    int resp=1;
    int i;
    for (i=1; i<=a; i++){
    resp = resp*i;
    }
return (resp);
}
