/* Elaborar un programa que permita que los valores de los 
coeficientes a, b, c; se comporten así: B debe ir de 1 hasta 7. 
C debe ir de 7 a 1. A debe tomar cada vez que la diferencia de B – C. 
Y, que imprima para cada juego de valores de a, b, c; si tiene raíz 
única, raíces complejas o raíces reales.
*/
#include <stdio.h>
#include <stdlib.h>


void hallar_racies(int a, int b, int c)
{
    int discriminante;
    discriminante= b*b -4*a*c;

    if(discriminante >0)
    {
        printf("Raices reales y diferentes.\n");
    }
    else if(discriminante==0)
    {

        printf("Raices reales e iguales\n");
    }
    else
    {
        printf("Raices complejas\n");
    }
}

int main()
{
    int a,b,c;

    printf("  Ecuacion de segundo grado  |        Tipo de raices\n");
    printf("-----------------------------------------------------------\n");
    for(int b=1; b<=7; b++)
    {
        for(int c=7; c>=1; c--)
        {
            a=b-c;

            if(a==0)
            {
                printf("  %2dX^2   + %2dX   + %2d       |  ",a,b,c);
                printf("No es una ecuacion de segundo grado.\n");
            }

            else
            {
                printf("  %2dX^2   + %2dX   + %2d       |  ",a,b,c);
                hallar_racies(a,b,c); 
            }
        }
    }
    printf("\n");
    system("pause");
    return 0;
}
