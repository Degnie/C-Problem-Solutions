/* Elaborar un programa que emita el reporte de un aumento de sueldos 
siguientes
Cálculo del nuevo sueldo es:
Si tipo empleado es 1 se incrementa el 5%
Si tipo empleado es 2 se incrementa el 7%
Si tipo empleado es 3 se incrementa el 10%
Si tipo empleado es 4 se incrementa el 14%
Si tipo empleado es 5 se incrementa el 18%
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100   // Máximo número de empleados

// Estructura para almacenar datos de cada empleado
typedef struct {
    char nombre[50];
    float sueldoAnterior;
    float sueldoActual;
    int tipo;
} Empleado;

float calcularIncremento(int tipo) {
    switch (tipo) {
        case 1: return 0.05;  // 5%
        case 2: return 0.07;  // 7%
        case 3: return 0.10;  // 10%
        case 4: return 0.14;  // 14%
        case 5: return 0.18;  // 18%
        default: return 0.0;  // Tipo inválido
    }
}

// Verificar que el nombre solo tenga letras y espacios
int validarNombre(char *nombre) {
    for (int i = 0; nombre[i] != '\0'; i++) {
        if (!isalpha(nombre[i]) && nombre[i] != ' ') {
            return 0; // inválido
        }
    }
    return 1; // válido
}

int main() {
    int n, i;
    Empleado empleados[MAX];
    float totalAnterior = 0, totalActual = 0;

    printf("Ingrese el numero de empleados: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEmpleado %d\n", i+1);

        // Nombre
        do {
            printf("Nombre: ");
            getchar(); // limpiar buffer
            fgets(empleados[i].nombre, 50, stdin);

            // Eliminar salto de línea de fgets
            for (int j = 0; empleados[i].nombre[j]; j++) {
                if (empleados[i].nombre[j] == '\n') {
                    empleados[i].nombre[j] = '\0';
                    break;
                }
            }

            if (!validarNombre(empleados[i].nombre)) {
                printf("Error: El nombre solo puede contener letras y espacios.\n");
            }
        } while (!validarNombre(empleados[i].nombre));

        // Sueldo anterior
        do {
            printf("Sueldo anterior: ");
            if (scanf("%f", &empleados[i].sueldoAnterior) != 1 || empleados[i].sueldoAnterior <= 0) {
                printf("Error: Ingrese un sueldo valido (numerico y mayor que 0).\n");
                while(getchar() != '\n'); // limpiar buffer
            } else break;
        } while (1);

        // Tipo de empleado
        do {
            printf("Tipo empleado (1-5): ");
            if (scanf("%d", &empleados[i].tipo) != 1 || empleados[i].tipo < 1 || empleados[i].tipo > 5) {
                printf("Error: Ingrese un tipo valido (1 a 5).\n");
                while(getchar() != '\n'); // limpiar buffer
            } else break;
        } while (1);

        // Calcular nuevo sueldo
        float inc = calcularIncremento(empleados[i].tipo);
        empleados[i].sueldoActual = empleados[i].sueldoAnterior * (1 + inc);

        totalAnterior += empleados[i].sueldoAnterior;
        totalActual   += empleados[i].sueldoActual;
    }

    // Reporte
    printf("\n\nAUMENTOS DE SUELDOS\n\n");
    printf("%-20s %15s %15s\n", "NOMBRE", "SUELDO ANT.", "SUELDO ACT.");
    printf("-------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-20s %15.2f %15.2f\n", 
            empleados[i].nombre, empleados[i].sueldoAnterior, empleados[i].sueldoActual);
    }

    printf("-------------------------------------------------------------\n");
    printf("%-20s %15.2f %15.2f\n", "TOTAL", totalAnterior, totalActual);

    printf("\n");
    system("pause");
    return 0;
}

