/*Ordene un vector de 100 números enteros generados aleatoriamente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>   //Necesario para usar el tiempo

int main()
{
    srand(time(0)); //Inicializamos la semilla con el tiempo actual

    int numero[100]={0};
    int max, min;

    printf("Ingrese los rangos de los numeros aleatorios: \n");
    printf("\nMinimo: ");
    scanf("%d",&min);
    printf("\nMaximo: ");
    scanf("%d",&max);

    for(int i=0; i<100; i++)
    {
        numero[i]= (rand()%(max-min+1)) +min;
    }

    // *Algoritmo para ordernar por burbuja
    for(int i=0; i<100;i++)      // *For para revisar numero por numero
    {
        for(int j=0;j<99;j++)   // *For para comparar numeros vecinos(uno menos q el total)
        {                       // *porque no existe el numero[100] como indice
            if(numero[j]>numero[j+1]) // *Condicionamos, si el segundo es mayor al primero 
            {
                int intermedio=numero[j]; //* Guardamos el valor del 1° en el intermedio
                numero[j]=numero[j+1];    //* Guardamos el valor del 2° en el 1° (q ya se habia guardado)
                numero[j+1]=intermedio;   //* Guardamos el valor del 1° en el 2°
            }

            // *Como no existe un else, si el 1° no es mayor al 2° entonces lo dejara igual
        }
    }

    printf("\nEl vector ordenado es: \n\n");
    for(int i=0;i<100;i++)
    {
        printf("%d ",numero[i]);
    }
    printf("\n\n");
    system("pause");
    return 0;
}