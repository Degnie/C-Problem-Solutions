/*Calcule el retorno de una inversión financiera mes a mes, sin usar la fórmula 
de interés compuesto. El usuario debe informar cuánto invertirá cada mes y 
cuál será la tasa de interés mensual. El programa debe mostrar el saldo tras un 
año y preguntar si desea calcular el siguiente año. 
Ejemplo: Inversión mensual = R$100,00, tasa de interés = 1% mensual. 
Salida: Saldo tras 1 año: 1280.9328043328942 
¿Desea procesar un año más? (S/N) */

#include <stdio.h>
#include <stdbool.h>

int main()
{
    float capital, interes ;
    char continuar;
    float capital_agregado;
    int anhos=0;

    // Validación capital
    printf("Ingrese el capital (en soles): ");
    while (scanf("%f", &capital) != 1 || capital <= 0) 
    {
        printf("Error: ingrese un numero mayor que 0.\n");
        while (getchar() != '\n'); // limpiamos buffer
        printf("Ingrese el capital (en soles): ");
    }

    // Validación interes
    printf("Ingrese el porcentaje de interes mensual: ");
    while (scanf("%f", &interes) != 1 || interes <= 0) 
    {
        printf("Error: ingrese un numero mayor que 0.\n");
        while (getchar() != '\n'); 
        printf("Ingrese el porcentaje de interes mensual: ");
    }

    capital_agregado = capital;

    do
    {
        anhos++;
        for(int i=0; i<12; i++)
        {
            capital = capital * (1 + interes/100);

            if(i < 11)        //Se agrega dinero luego del primer deposito
            {
                capital = capital + capital_agregado;
            }
        }

        printf("\nEl saldo tras el %d° año es: %.2f soles\n", anhos, capital);

        printf("\nDesea procesar un año mas? (S/N) \n");
        scanf(" %c",&continuar); //Dejamos un espacio para que no agarre el salto de linea

        if(continuar!='N' &&  continuar!='n')
        {
            continue;
        }
        else
        {
            printf("\nGracias por usar el aplicativo.\n\n");
            break;
        }
    } while (true);

    system("pause");
    return 0;
}