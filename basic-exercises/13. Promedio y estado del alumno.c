/* Haga un método que calcule el promedio de un alumno y otro que indique el estado del alumno: 
Nota superior a 6 → Aprobado 
Nota entre 4 y 6 → Verificación Suplementaria 
Nota inferior a 4 → Reprobado */

#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>  // Para validar caracteres

// Función para limpiar buffer de entrada
void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void llenar_notas(float v[], int n)
{
    printf("\n\nIngrese las notas (valores entre 0 y 10)\n\n");
    
    for (int i = 0; i < n; i++)
    {
        float nota;
        int valido = 0;

        do {
            printf("Nota %d: ", i + 1);

            if (scanf("%f", &nota) != 1) {
                printf("Entrada inválida. Solo se permiten números.\n");
                limpiar_buffer();
            } 
            else if (nota < 0 || nota > 10) {
                printf("La nota debe estar entre 0 y 10.\n");
                limpiar_buffer();
            }
            else {
                valido = 1;
                v[i] = nota;
            }
        } while (!valido);
    }
}

void promedio_alumnos(float v[], int n, float *promedio)
{
    float suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += v[i];
    }

    *promedio = suma / n;
    printf("\nEl promedio es: %.2f", *promedio);
}

void estado_alumnos(float promedio)
{
    if (promedio > 6)
    {
        printf("Aprobado");
    }
    else if (promedio >= 4 && promedio <= 6)
    {
        printf("Verificacion suplementaria");
    }
    else
    {
        printf("Reprobado");
    }
    printf("\n\n");
}

int main()
{
    float notas[100] = {0}; 
    int cantidad_notas;
    float promedio = 0;
    int valido = 0;

    // Validacion de cantidad de notas
    do {
        printf("Ingrese la cantidad de notas (1-100): ");
        if (scanf("%d", &cantidad_notas) != 1) {
            printf("Entrada inválida. Solo se permiten números.\n");
            limpiar_buffer();
        }
        else if (cantidad_notas <= 0 || cantidad_notas > 100) {
            printf("La cantidad debe estar entre 1 y 100.\n");
            limpiar_buffer();
        }
        else {
            valido = 1;
        }
    } while (!valido);

    // Funciones:
    llenar_notas(notas, cantidad_notas);
    promedio_alumnos(notas, cantidad_notas, &promedio);
    printf("\n\nEl estado del alumno es: ");
    estado_alumnos(promedio);

    system("pause"); 
    return 0;
}
