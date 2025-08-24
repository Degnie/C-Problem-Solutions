/*Construya la tabla de multiplicación de números del 1 al 10 (ej.: 1 x 1 = 1, 1 x 2 = 
2, etc.). */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int numero;

    do
    {
        printf("Ingrese un numero: ");
        scanf("%d",&numero);

        if(numero<=0)
        {
            printf("\nError en la eleccion del numero, vuelva a intentarlo.\n");
            continue;
        }
        break;
    } while (true);
    
    printf("Tabla de multiplicar\n");
    for(int i=0; i<10;i++)
    {
        printf("\n\n   Tabla del %d\n",i+1);
        printf("---------------------\n");

        for(int j=0; j<numero; j++)
        {
            printf("\n  %3d x %3d = %5d",i+1,j+1,(i+1)*(j+1));
        }

    }
    
    printf("\n\n");
    system("pause");
    return 0;

}