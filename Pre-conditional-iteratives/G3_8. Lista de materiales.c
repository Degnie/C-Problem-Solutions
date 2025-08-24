/* Una compañía manufacturera fabrica el producto A. Para fabricar 
una unidad de dicho producto se requiere los siguientes materiales:

Material 1: 3 unidades
Material 2: 4 unidades
Material 3: 1 unidad
Material 4: 2 unidades
Material 5: 3 unidades
Material 6: 2 unidades

Se tiene como datos el costo de una unidad de cada uno de los seis 
materiales. Elaborar un programa que lea los costos de los 
materiales, luego que lea pedidos del producto A en cada pedido 
se tiene el dato cantidad de unidades del producto A; cuando termine 
de leer los pedidos, imprimir:

*/
#include <stdio.h>
#include <stdlib.h>

#define MATERIALES 6 // Número de materiales

int main() {
    int requeridos[MATERIALES] = {3, 4, 1, 2, 3, 2}; // unidades necesarias para producir el producto A
    float costoUnitario[MATERIALES];
    int cantidadMaterial[MATERIALES] = {0};
    float costoEstimado[MATERIALES] = {0};
    int cantidadProductos, totalProductos = 0;
    float costoTotal = 0;

    // Leer costo unitario de materiales
    printf("Ingrese el costo por unidad de los 6 materiales (solo positivos):\n");
    for(int i = 0; i < MATERIALES; i++) {
        do {
            printf("Costo material %d: ", i+1);
            scanf("%f", &costoUnitario[i]);
            if(costoUnitario[i] <= 0) {
                printf("Error: el costo debe ser un número positivo.\n");
            }
        } while(costoUnitario[i] <= 0);
    }

    // Leer pedidos
    printf("\nIngrese pedidos del producto A (0 para terminar):\n");
    do {
        do {
            printf("Cantidad de productos A: ");
            scanf("%d", &cantidadProductos);
            if(cantidadProductos < 0) {
                printf("Error: la cantidad no puede ser negativa.\n");
            }
        } while(cantidadProductos < 0);

        if(cantidadProductos > 0) {
            totalProductos += cantidadProductos;
        }
    } while(cantidadProductos != 0); // Usamos el 0 para terminar

    // Calcular requerimientos y costos
    for(int i = 0; i < MATERIALES; i++) {
        cantidadMaterial[i] = requeridos[i] * totalProductos;
        costoEstimado[i] = cantidadMaterial[i] * costoUnitario[i];
        costoTotal += costoEstimado[i];
    }

    // Reporte
    printf("\n\nLISTADO DE MATERIALES REQUERIDOS\n\n");
    printf("MATERIAL\tCANTIDAD\tCOSTO ESTIMADO\n");
    printf("-------------------------------------------------\n");
    for(int i = 0; i < MATERIALES; i++) {
        printf("%3d\t\t%8d\t\t%10.2f\n", i+1, cantidadMaterial[i], costoEstimado[i]);
    }
    printf("-------------------------------------------------\n");
    printf("COSTO TOTAL\t\t\t\t%10.2f\n", costoTotal);

    printf("\n");
    system("pause");
    return 0;
}

