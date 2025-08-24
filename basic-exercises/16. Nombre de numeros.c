/*
Escriba un número por extenso aceptando números de hasta 9 dígitos, 
usando métodos 
*/

#include <stdio.h>
#include <stdlib.h>

void ingrese_numero(int *numero)
{
    printf("Ingrese un numero: ");
    scanf("%d",numero);
}

void numero_1_9(int numero)
{
    switch (numero)
    {
    case 1:
        printf("uno");
        break;
    case 2:
        printf("dos");
        break;
    case 3:
        printf("tres");
        break;
    case 4:
        printf("cuatro");
        break;
    case 5:
        printf("cinco");
        break;
    case 6:
        printf("seis");
        break;
    case 7:
        printf("siete");
        break;
    case 8:
        printf("ocho");
        break;
    case 9:
        printf("nueve");
        break;
    }
}

void numero_10_99(int numero)
{
    int decimal=numero/10, unidad=numero%10;

    switch (decimal)
    {
    case 0:
        numero_1_9(numero);
        break;
    case 1:
        switch (unidad)
        {
        case 0:
            printf("diez");
            break;
        case 1:
            printf("once");
            break;
        case 2:
            printf("doce");
            break;
        case 3:
            printf("trece");
            break;
        case 4:
            printf("catorce");
            break;
        case 5:
            printf("quince");
            break;
        }
        if(unidad>5)
        {
            printf("dieci");
            numero_1_9(unidad);
        }
        break;
    case 2:
        if(unidad==0)
        {
            printf("veinte");
            break;
        }
        else
        {
            printf("veinti");
            numero_1_9(unidad);
            break;
        }
    case 3:
        if(unidad==0)
        {
            printf("treinta");
            break;
        }
        else
        {
            printf("treinta y ");
            numero_1_9(unidad);
            break;
        }
    case 4:
        if(unidad==0)
        {
            printf("cuarenta");
            break;
        }
        else
        {
            printf("cuarenta y ");
            numero_1_9(unidad);
            break;
        }
        
    case 5:
        if(unidad==0)
        {
            printf("cincuenta");
            break;
        }
        else
        {
            printf("cincuenta y ");
            numero_1_9(unidad);
            break;
        }
        
    case 6:
        if(unidad==0)
        {
            printf("sesenta");
            break;
        }
        else
        {
            printf("sesenta y ");
            numero_1_9(unidad);
            break;
        }
        
        
    case 7:
        if(unidad==0)
        {
            printf("setenta");
            break;
        }
        else
        {
            printf("setenta y ");
            numero_1_9(unidad);
            break;
        }
        
    case 8:
        if(unidad==0)
        {
            printf("ochenta");
            break;
        }
        else
        {
            printf("ochenta y ");
            numero_1_9(unidad);
            break;
        }
        
    case 9:
        if(unidad==0)
        {
            printf("noventa");
            break;
        }
        else
        {
            printf("noventa y ");
            numero_1_9(unidad);
            break;
        }
    }
    
}

void numero_100_999(int numero)
{
    int centena=numero/100, decena=numero%100, unidad= numero%10;
    switch (centena)
    {
    case 0:
        numero_10_99(decena);
        break;

    case 1:
        if(decena==0 && unidad==0)
        {
            printf("cien");
            break;
        }
        else
        {
            printf("ciento ");
            numero_10_99(decena);
        }
        break;
    case 2: case 3: case 4: case 6: case 8:
        numero_1_9(centena);
        printf("cientos");
        numero_10_99(decena);
        break;

    case 7:
        printf("setecientos");
        numero_10_99(decena);
        break;
    case 9:
        printf("novecientos");
        numero_10_99(decena);
        break;
    case 5:
        printf("quinientos");
        numero_10_99(decena);
        break;
    }
}


void numero_1k_999k(int numero)
{
    int mil=numero/1000, centena=numero%1000;

    if(mil==1)
    {
        printf("mil ");
        numero_100_999(centena);
    }
    else if(mil>1 && mil<10)
    {
        numero_1_9(mil);
        printf("mil ");
        numero_100_999(centena);
    }
    else if(mil>=10 && mil<=99)
    {
        numero_10_99(mil);
        printf("mil ");
        numero_100_999(centena);
    }
    else if(mil>=100 && mil<=999)
    {
        numero_100_999(mil);
        printf("mil ");
        numero_100_999(centena);
    }
}

void numero_1mll_999mll(int numero)
{
    int millon=numero/1000000, mil=numero%1000000;

    if(millon==1)
    {
        printf("millon ");
        numero_1k_999k(mil);
    }
    else if(millon>1 && millon<10)
    {
        numero_1_9(millon);
        printf("millones ");
        numero_1k_999k(mil);
    }
    else if(millon>=10 && millon<=99)
    {
        numero_10_99(millon);
        printf("millones ");
        numero_100_999(mil);
    }
    else if(millon>=100 && millon<=999)
    {
        numero_100_999(millon);
        printf("millones ");
        numero_100_999(mil);
    }
}


int main()
{
    int numero=0;

    ingrese_numero(&numero); 

    printf("\nEl numero %d se escribe: ",numero);
    if(numero == 0) {
        printf("cero");
    }
    else if(numero>0 && numero<=9)
    {
        numero_1_9(numero);
    }
        
    else if(numero>=10 && numero<=99)
    {
        numero_10_99(numero);
    }
    else if(numero>=100 && numero<=999)
    {
        numero_100_999(numero); 
    }
    else if(numero>=1000 && numero<=999999)
    {
        numero_1k_999k(numero);
    }
    else if(numero>=1000000 && numero<=999999999)
    {
        numero_1mll_999mll(numero);
    }

    printf("\n\n");
    system("pause"); //Mantiene la consola abierta en Windows
    return 0; //Indica que el programa finalizó correctamente

}