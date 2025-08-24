/*Calcule la raíz cuadrada aproximada de un número entero informado por el 
usuario, respetando un error máximo también informado. No utilice funciones 
predefinidas*/

#include <stdio.h>
#include <stdlib.h>

float valor_absoluto(float a)
{
    return (a >= 0) ? a : -a;
}

int main()
{
    float numero_usuario;
    float aproximacion;
    float error_maximo;

    printf("Ingrese el numero: ");
    // Validamos que el usuario realmente ingrese un número
    if(scanf("%f", &numero_usuario) != 1)
    {
        printf("Error: debe ingresar un numero valido (no se permiten caracteres).\n");
        return 1;
    }

    // Validación: no se permiten negativos
    if(numero_usuario < 0)
    {
        printf("Error: no se puede calcular la raiz cuadrada de un numero negativo.\n");
        return 1;
    }

    printf("Ingrese el error maximo permitido: ");
    if(scanf("%f", &error_maximo) != 1)
    {
        printf("Error: debe ingresar un numero valido para el error maximo.\n");
        return 1;
    }

    aproximacion = numero_usuario / 2;

    for(int i = 0; i < 200; i++)
    {
        aproximacion = (aproximacion + numero_usuario / aproximacion) / 2;

        if(valor_absoluto(numero_usuario - (aproximacion * aproximacion)) <= error_maximo)
        {
            break;
        }
    }

    printf("\n\nLa raiz aproximada de %.2f es: %f\n\n", numero_usuario, aproximacion);

    system("pause");
    return 0;
}