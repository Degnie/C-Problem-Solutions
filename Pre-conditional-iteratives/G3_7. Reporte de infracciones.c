/*El departamento de Policía y tránsito de la ciudad de Hermosillo, 
tiene los datos de las infracciones levantadas por sobrepasar los 
limites de velocidad establecidos. El departamento dividió a la 
ciudad en tres zonas, para cada una de las cuales desea obtener 
datos estadísticos que muestran las infracciones levantadas por 
el motivo indicado en el párrafo anterior. Por cada infracción se 
tiene los siguientes datos:

Número de placa (registro) del vehículo.
Zona en la que fue la infracción (1,2,3).
Límite de velocidad en kilómetros por hora.
Velocidad a la que iba el vehículo en kilómetros por hora.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TARIFA 3.0

typedef struct {
    char placa[20];   // La placa puede tener letras y/o numeros
    int zona;
    int limite;
    int velocidad;
    float multa;
} Infraccion;

void reporte(Infraccion infracciones[], int n) {
    int totalZona[4] = {0};        
    float montoZona[4] = {0};

    printf("INFRACCIONES A LOS LIMITES DE VELOCIDAD\n\n");
    printf("  VEHICULO\t REG.\t   VELOCIDAD\t    MULTA\n");

    for(int i=0; i<n; i++) {
        printf("%9s\t%3d\t%9d\t%9.2f\n",
            infracciones[i].placa,
            infracciones[i].zona,
            infracciones[i].velocidad,
            infracciones[i].multa);

        totalZona[infracciones[i].zona]++;
        montoZona[infracciones[i].zona] += infracciones[i].multa;
    }

    printf("\n");

    for(int z=1; z<=3; z++) {
        printf("ZONA %d :\tTOTAL DE INFRACCIONES : %d\n", z, totalZona[z]);
        printf("\tMONTO RECAUDADO EN MULTAS : %.2f\n\n", montoZona[z]);
    }
}

int main() {
    int n;
    Infraccion infracciones[100];

    printf("Ingrese el numero de infracciones: ");
    scanf("%d", &n);
    getchar(); // limpiar buffer

    for(int i=0; i<n; i++) {
        printf("\nInfraccion %d\n", i+1);

        // Placa
        printf("Numero de placa (puede ser letras y/o numeros): ");
        fgets(infracciones[i].placa, 20, stdin);
        infracciones[i].placa[strcspn(infracciones[i].placa, "\n")] = '\0'; // quitar salto

        // Zona (solo 1-3)
        do {
            printf("Zona (1-3): ");
            scanf("%d", &infracciones[i].zona);
            if(infracciones[i].zona < 1 || infracciones[i].zona > 3) {
                printf("⚠ Zona invalida. Debe ser 1, 2 o 3.\n");
            }
        } while(infracciones[i].zona < 1 || infracciones[i].zona > 3);

        // Limite de velocidad (positivo)
        do {
            printf("Limite de velocidad: ");
            scanf("%d", &infracciones[i].limite);
            if(infracciones[i].limite <= 0) {
                printf("⚠ El limite debe ser un numero positivo.\n");
            }
        } while(infracciones[i].limite <= 0);

        // Velocidad registrada (positiva y mayor al limite)
        do {
            printf("Velocidad registrada: ");
            scanf("%d", &infracciones[i].velocidad);
            if(infracciones[i].velocidad <= 0) {
                printf("⚠ La velocidad debe ser positiva.\n");
            } else if(infracciones[i].velocidad <= infracciones[i].limite) {
                printf("⚠ La velocidad debe ser mayor al limite (%d).\n", infracciones[i].limite);
            }
        } while(infracciones[i].velocidad <= 0 || infracciones[i].velocidad <= infracciones[i].limite);

        // Calculamos la multa
        int exceso = infracciones[i].velocidad - infracciones[i].limite;
        infracciones[i].multa = exceso * TARIFA;

        getchar(); // limpiar buffer antes de pedir la siguiente placa
    }

    printf("\n\n");
    reporte(infracciones, n);

    system("pause");
    return 0;
}
