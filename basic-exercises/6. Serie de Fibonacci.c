/*Calcule la serie de Fibonacci para un número entero no negativo informado 
por el usuario. 
Ejemplo: si el usuario ingresa el número 9, el resultado sería: 0, 1, 1, 2, 3, 5, 8, 
13, 21, 34. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // ! <- para usar booleanos

int main()
{
    int numero_usuario;

    printf("Ingrese un numero: ");
    if (scanf("%d",&numero_usuario) != 1) {   // !<- valida si la entrada fue un número
        printf("\nError: Debe ingresar un numero entero.\n\n");
        return 1; // ! terminamos el programa con error
    }

    if (numero_usuario < 0) {   // ! <- valida si es negativo
        printf("\nError: No se permiten numeros negativos.\n\n");
        return 1;
    }

    int a,b,c; 
    a=0;
    b=1;
    printf("\n\nLos %d primeros valores de fibonacci son: \n\n",numero_usuario + 1 );
    for(int i=0;i<=numero_usuario;i++)
    { //algoritmode fibonacci
        printf("%d   ",a);  // TODO: a porque deseo que empiece a mostrar desde 0
        c=a+b;
        a=b;
        b=c;

        
    }
    printf("\n\n");
    system("pause");
    return 0;
}