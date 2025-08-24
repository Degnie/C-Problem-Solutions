/* Elaborar un programa que imprima la secante, cosecante y tangente 
de X; para valores de X desde –1 hasta 1 con intervalos de 0.1. 
Debe imprimir una tabla:	
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void imprimir_tabla_funciones_trigonometricas()
{
    printf("       Valor     |         Secante        |     Cosecante      |      Tangente\n");
    printf("-----------------------------------------------------------------------------------\n");
    for(float i=-1.0; i<=1.01; i+=0.1) //se usa 1.01 para incluir el 1.0 porque el float no es exacto
    {
        if(i>=-0.001 && i<=0.001) // evitar division entre 0, considerando que el float no es exacto
        {
        
            printf(" %10.2f      |    %10.2f          |         ND         |   %10.2f\n",i,1/cos(i),tan(i));
        }
        else
        {
            printf(" %10.2f      |    %10.2f          |  %10.2f        |   %10.2f\n",i, 1/cos(i),1/sin(i),tan(i));
        }
    }
    printf("\n");

}

int main()
{
    imprimir_tabla_funciones_trigonometricas();

    system("pause");
    return 0;
}