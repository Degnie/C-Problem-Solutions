/*Para cada producto informado (nombre, precio y cantidad), escriba el nombre 
del producto comprado y el valor total a pagar, considerando que se ofrecen 
descuentos según el número de unidades compradas: 
○ Hasta 10 unidades: valor total 
○ De 11 a 20 unidades: 10% de descuento 
○ De 21 a 50 unidades: 20% de descuento 
○ Más de 50 unidades: 25% de descuento.*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    char nombre_producto[20]="";
    float precio_producto,precio_final;
    int cantidad_producto;

    printf("Ingrese el nombre del producto que desea comprar: ");
    scanf("%s",nombre_producto);  //No es necesario el & porque ya es un vector

    do
    {
        printf("Ingrese el precio del producto: ");
        scanf("%f",&precio_producto);

        if(precio_producto<=0)
        {
        printf("Error con el precio, vuelva a intentarlo.\n");
        continue;
        }

        do
        {
            printf("Ingrese la cantidad de %s que desea comprar: ",nombre_producto);
            scanf("%d",&cantidad_producto);

            if(cantidad_producto<=0)
            {
            printf("Error en la cantidad de productos, vuelva a intentarlo.\n");
            continue;
            }
            break;
        } while (true);
        
        break;
    } while (true);
    
    
    /*
    ○ Hasta 10 unidades: valor total 
    ○ De 11 a 20 unidades: 10% de descuento 
    ○ De 21 a 50 unidades: 20% de descuento 
    ○ Más de 50 unidades: 25% de descuento.*/

    precio_final=precio_producto*cantidad_producto;

    if(cantidad_producto<=10)
    {
        printf("\nEl monto a pagar es: %.2f",precio_final);
    }

    else if(cantidad_producto>10 && cantidad_producto<=20)
    {
        printf("\nUsted tiene un descuento del 10%%\n");
        printf("El monto a pagar es: %.2f\n", precio_final*0.9);
    }

    else if(cantidad_producto>20 && cantidad_producto<=50)
    {
        printf("\nUsted tiene un descuento del 20%%\n");
        printf("El monto a pagar es: %.2f\n",precio_final*0.8);
    }

    else
    {
        printf("\nUsted tiene un descuento del 25%%\n");
        printf("El monto a pagar es: %.2f\n",precio_final*0.75);
    }

    printf("\n");
    system("pause");
    return 0;
}