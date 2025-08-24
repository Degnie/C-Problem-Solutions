/* Elaborar un programa que permita leer un número N par; y, 
calcule e imprima la suma de los números pares del 2 hasta el número 
leído. Si el número leído es menor a 2 debe imprimir un mensaje de 
error.*/

#include <stdio.h>
#include <stdlib.h>


void sumar_pares(int n, int *suma)
{
    for(int i=2; i<=n; i+=2) // i+=2 es equivalente a i=i+2 
    {
        *suma+= i; 
    }
}

void imprimir_reultados(int n, int suma)
{
    printf("La suma de pares hasta %d es: %d\n",n,suma);
}


int es_valido(int n) // Verifica que el numero sea par y mayor a 2
{
    if(n <= 2) 
    {
        printf("Error: el numero debe ser mayor a 2.\n");
        return 0;
    }
    if(n % 2 != 0) 
    {
        printf("Error: el numero debe ser par.\n");
        return 0;
    }
    return 1;
}

int leer_numero_seguro(int *n)
{
    char c;
    if(scanf("%d", n) != 1) // Verifica que realmente se lea un entero
    {
        printf("Error: solo se permiten numeros positivos.\n");
        while((c = getchar()) != '\n' && c != EOF); // limpia el buffer
        return 0;
    }
    if(*n <= 0) // Evita negativos o cero
    {
        printf("Error: solo se permiten numeros positivos.\n");
        return 0;
    }
    return 1;
}

int main()
{
    int numero, suma=0;

    // Usamos un ciclo para forzar entrada válida
    do {
        printf("Ingrese un numero par mayor a 2: ");
    } while(!leer_numero_seguro(&numero) || !es_valido(numero));

    sumar_pares(numero,&suma);
    printf("\n");
    imprimir_reultados(numero,suma);
    printf("\n");

    system("pause");
    return 0;
}
