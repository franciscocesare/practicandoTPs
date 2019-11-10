#include <stdio.h>
#include <stdlib.h>

/* Por teclado se ingresa el valor hora de un empleado. Posteriormente se ingresa el nombre del empleado, la
antigüedad y la cantidad de horas trabajadas en el mes. Se pide calcular el importe a cobrar teniendo en
cuenta que el total resulta de multiplicar el valor hora por la cantidad de horas trabajadas, hay que sumarle
la cantidad de años trabajados multiplicados por $30, y al total de todas esas operaciones restarle el 13% en
concepto de descuentos. Imprimir el recibo correspondiente con el nombre, la antigüedad, el valor hora, el
total a cobrar en bruto, el total de descuentos y el valor neto a cobrar */

int main()
{

    int valorHora;
    int antiguedad;
    int cantHoras;
    int bruto;
    float descuento;
    float precioHoras;
    char nombre[20];

    printf("ingrese valor por ahora: ");
    scanf("%d",&valorHora);

    printf("ingrese nombre de empleado: ");
    fflush(stdin);
    gets(nombre);

    printf("ingrese antiguedad: ");
    scanf("%d",&antiguedad);

    printf("ingrese horas trabajadas: ");
    scanf("%d",&cantHoras);

    precioHoras=valorHora*cantHoras;
    precioHoras=(30*antiguedad)+precioHoras;
    bruto=precioHoras;
    descuento=(float)(13*precioHoras)/100;
    precioHoras=(float)precioHoras-descuento;

    printf("\nempleado   valor hora   antiguedad   horas trabajadas   bruto   descuento  neto\n");
    printf(" ----        ------       ------       ------------      ---     ------     ---");
    printf("\n%s           $%d         %danos          %dhs           $%d      $ %.2f    $%.2f \n\n",nombre,valorHora,antiguedad,cantHoras,bruto,descuento,precioHoras);



    return 0;
}
