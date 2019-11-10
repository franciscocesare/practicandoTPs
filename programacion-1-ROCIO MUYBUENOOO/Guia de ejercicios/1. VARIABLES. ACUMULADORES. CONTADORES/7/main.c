#include <stdio.h>
#include <stdlib.h>

// Diseñar un programa que calcule la longitud de la circunferencia y el área del círculo de radio dado

int main()
{
    int radio;
    float area;
    float longitud;
    const float pi = 3.14;

    printf("ingrese radio de circulo: ");
    scanf("%d",&radio);

    area = (float) pi*radio*radio;
    longitud=(float) 2*pi*radio;

    printf("\nel area es de %.2f \nla longitud es de %.2f\n\n",area,longitud);
    return 0;
}
