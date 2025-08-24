/* Elaborar un programa para calcular la cantidad que se tendría 
ahorrada después de 10 años, si se deposita mil nuevos soles 
mensuales a una tasa de interés mensual de 3%, capitalizable 
cada mes, es decir, que al capital se le agregan los intereses .
*/

#include <stdio.h>
#include <stdlib.h>



void cantidad_ahorrado(float *ahorrado)
{
    float capital=0;
    for(int i=1; i<=120; i++)
    {
        int mensual=1000;
        capital=mensual+capital;
        capital=capital*(1+0.03);
    }
    *ahorrado=capital;
}

void imprimir_resultado(float ahorrado)
{
    printf("Cantidad ahorrada despues de 10 años: %.2f soles \n",ahorrado);
}

int main()
{
    float ahorrado;

    printf("Inversion mensual: 1000 soles \n");
    printf("Tasa de interes mensual: 3%% \n\n");
    cantidad_ahorrado(&ahorrado);
    imprimir_resultado(ahorrado);

    printf("\n");
    system("pause");
    return 0;
}