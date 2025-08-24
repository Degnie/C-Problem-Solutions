/*Calcule la distancia entre dos puntos en un espacio de 3 dimensiones. */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double ai,aj,ak,bi,bj,bk;
    double distancia;


    printf("Ingrese el valor de la primera posicion i,j, k : \n");
    scanf("%lf %lf %lf",&ai,&aj,&ak);

    printf("\nIngrese el valor de la segunda posicion: \n");
    printf("i: ");
    scanf("%lf",&bi);
    printf("j: ");
    scanf("%lf",&bj);
    printf("k: ");
    scanf("%lf",&bk);

    /**
     * !La distancia saldra en DOUBLE
     */

    distancia= sqrt(pow(ai-bi,2)+pow(aj-bj,2)+pow(ak-bk,2));

    printf("\nLa distancia entre el punto A y B es: %.2lf\n",distancia);

    printf("\n");
    system("pause");
    return 0;
}