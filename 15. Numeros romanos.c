/* Lea un número decimal (hasta 3 dígitos) y muestre su equivalente en números romanos. Use métodos para convertir cada dígito.
Pistas: 1=I, 5=V, 10=X, 50=L, 100=C, 500=D, 1000=M.*/

#include <stdio.h>
#include <stdlib.h>

void ingresar_numero(int *numero)
{
    int resultado;
    do
    {
        printf("Ingrese el numero (1-999): ");
        resultado = scanf("%d", numero);

        // Limpiamos el buffer
        while(getchar()!='\n');

        if (resultado != 1 || *numero < 1 || *numero > 999)
        {
            printf("Entrada invalida. Solo numeros entre 1 y 999.\n\n");
            *numero = 0; // para repetir
        }
    } while (*numero == 0);
}


void numero_romano_1_9(int numero)
{
    switch (numero)
    {
    case 0:
        printf("");
        break;
    case 1:
        printf("I");
        break;
    case 2:
        printf("II");
        break;
    case 3:
        printf("III");
        break;
    case 4:
        printf("IV");
        break;
    case 5:
        printf("V");
        break;
    case 6:
        printf("VI");
        break;
    case 7:
        printf("VII");
        break;
    case 8:
        printf("VIII");
        break;
    case 9:
        printf("IX");
        break;
    }
}

void numero_romano_10_99(int numero)
{
    int decena= numero/10, unidad=numero%10;
    switch (decena)
    {
    case 0:
        printf("");
        numero_romano_1_9(unidad);
        break;
    case 1:
        printf("X");
        numero_romano_1_9(unidad);
        break;
    case 2:
        printf("XX");
        numero_romano_1_9(unidad);
        break;
    case 3:
        printf("XXX");
        numero_romano_1_9(unidad);
        break;
    case 4:
        printf("XL");
        numero_romano_1_9(unidad);
        break;
    case 5:
        printf("L");
        numero_romano_1_9(unidad);
        break;
    case 6:
        printf("LX");
        numero_romano_1_9(unidad);
        break;
    case 7:
        printf("LXX");
        numero_romano_1_9(unidad);
        break;
    case 8:
        printf("LXXX");
        numero_romano_1_9(unidad);
        break;
    case 9:
        printf("XC");
        numero_romano_1_9(unidad);
        break;
    }
}

void numero_romano_100_999(int numero)
{
    int centena=numero/100, decena=numero%100;

    switch (centena)
    {
    case 1:
        printf("C");
        numero_romano_10_99(decena);
        break;
    case 2:
        printf("CC");
        numero_romano_10_99(decena);
        break;
    case 3:
        printf("CCC");
        numero_romano_10_99(decena);
        break;
    case 4:
        printf("CD");
        numero_romano_10_99(decena);
        break;
    case 5:
        printf("D");
        numero_romano_10_99(decena);
        break;
    case 6:
        printf("DC");
        numero_romano_10_99(decena);
        break;
    case 7:
        printf("DCC");
        numero_romano_10_99(decena);
        break;
    case 8:
        printf("DCCC");
        numero_romano_10_99(decena);
        break;
    case 9:
        printf("CM");
        numero_romano_10_99(decena);
        break;
    }
}

int main()
{
    int numero=0;

    ingresar_numero(&numero);

    printf("\n\nEl numero %d en romano es: ",numero);
    if(numero<10)
    {
        numero_romano_1_9(numero);
    }
    else if(numero>=10 && numero<100)
    {
        numero_romano_10_99(numero);

    }
    else if(numero>=100 &&numero<1000)
    {
        numero_romano_100_999(numero);

    }

    printf("\n\n");
    system("pause");
    return 0;
}