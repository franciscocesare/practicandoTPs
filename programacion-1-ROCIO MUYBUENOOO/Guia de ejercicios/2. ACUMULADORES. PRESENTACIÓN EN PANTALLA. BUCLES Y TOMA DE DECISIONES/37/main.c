#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Hacer un programa que simule el funcionamiento de un reloj digital y que permita ponerlo en hora

int main()
{
    for (int h=00; h<24; h++)
    {
        for (int m=00; m<60; m++)
        {
            for (int s=00; s<60; s++)
            {
                printf("%d:%d:%d\n",h,m,s);
               // Sleep(500);
            }
        }
    }

    return 0;
}
