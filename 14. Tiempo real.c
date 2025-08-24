/*Lea del usuario un tiempo en segundos y muéstrelo en horas, minutos y segundos. 
Utilice cinco métodos: lectura de datos, escritura, obtención de horas, minutos y segundos.
*/

#include <stdio.h>
#include <stdlib.h>

void ingresar_datos(int *segundos_totales)
{
    int resultado;
    do
    {
        printf("Ingrese los segundos totales (solo numeros positivos): ");
        resultado = scanf("%d", segundos_totales);

        // limpiar buffer en caso de caracteres inválidos
        while(getchar() != '\n');

        if (resultado != 1 || *segundos_totales < 0)
        {
            printf("Entrada invalida. Solo se permiten numeros enteros positivos.\n\n");
        }

    } while (resultado != 1 || *segundos_totales < 0);
}

void horas_finales(int *segundos_totales, int *horas)
{
    *horas = *segundos_totales / 3600;
}

void minutos_finales(int *segundos_totales, int *minutos)
{
    *segundos_totales = *segundos_totales % 3600;
    *minutos = *segundos_totales / 60;
}

void segundos_fianles(int *segundos_totales, int *segundos)
{
    *segundos = *segundos_totales % 60;
}

void mostrar_tiempo(int horas, int minutos, int segundos)
{
    printf("\n\nEl tiempo ingresado es: %d HR : %d MIN : %d SEG\n\n", horas, minutos, segundos);
}

int main()
{
    int segundos_totalaes = 0, horas, minutos, segundos;

    ingresar_datos(&segundos_totalaes);
    horas_finales(&segundos_totalaes, &horas);
    minutos_finales(&segundos_totalaes, &minutos);
    segundos_fianles(&segundos_totalaes, &segundos);
    mostrar_tiempo(horas, minutos, segundos);

    system("pause");
    return 0;
}