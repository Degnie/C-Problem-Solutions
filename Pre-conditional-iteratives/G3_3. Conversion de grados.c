/*Elaborar un programa que permita leer el valor inicial y el valor 
final en grados Fahrenheit ; e imprima una tabla con equivalencias 
en grados Centígrados, desde el valor inicial hasta el valor final 
de 1 en 1
*/

#include <stdio.h>
#include <stdlib.h>

#define FAHRENHEIT 32

void ingrese_dato(int *grados_inicial, int *grados_final)
{
    int result;

    // Leer valor inicial validando caracteres y rango
    do {
        printf("Ingrese el valor inicial en grados Fahrenheit (>= -459): ");
        result = scanf("%d", grados_inicial);

        if (result != 1) { 
            printf("Error: Solo se permiten numeros (ej: -100, 50).\n");
            while(getchar()!='\n'); // limpiar buffer
            continue;
        }

        if (*grados_inicial < -459) {
            printf("Error: El valor inicial no puede ser menor que -459.\n");
        }

    } while (result != 1 || *grados_inicial < -459);

    // Leer valor final validando caracteres y que sea mayor al inicial
    do {
        printf("Ingrese el valor final en grados Fahrenheit (mayor que %d): ", *grados_inicial);
        result = scanf("%d", grados_final);

        if (result != 1) { 
            printf("Error: Solo se permiten numeros.\n");
            while(getchar()!='\n'); // limpiar buffer
            continue;
        }

        if (*grados_final <= *grados_inicial) {
            printf("Error: El valor final debe ser mayor que el valor inicial (%d).\n", *grados_inicial);
        }

    } while (result != 1 || *grados_final <= *grados_inicial);
}

float convertir_a_centigrados(int grados_fahrenheit)
{
    float grados_centigrados;
    grados_centigrados = (grados_fahrenheit - FAHRENHEIT) * (5.0/9);
    return grados_centigrados;
}

void imprimir_tabla(int grado_inicial, int grado_final)
{
    printf("\n\n   Fahrenheit     |   Centigrados\n");
    printf("-------------------------------------\n");
    for(int i = grado_inicial; i <= grado_final; i++)
    {
        printf("%7d           |   %7.2f\n", i, convertir_a_centigrados(i));
    }
}

int main()
{
    int grados_inicial, grados_final;

    ingrese_dato(&grados_inicial,&grados_final);
    imprimir_tabla(grados_inicial,grados_final);

    printf("\n");
    system("pause");
    return 0;
}


