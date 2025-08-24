/* Elabore un programa que lea un valor N y que imprima un triángulo 
de asteriscos, como se muestra a continuación, si el valor leído 
es 5 imprimir:*/

#include <stdio.h>
#include <stdlib.h>

void ingrese_altura(int *n)
{
    printf("ingrese la altura del triangulo: ");
    scanf("%d",n);
}

void triangulo_rectangulo_isosceles(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i;j++)
        {
            printf("*") ;
        }
        printf("\n") ;
    }
}

void triangulo_equilatero(int n)
{
    for(int i=0; i<n;i++)
    {
        for (int j=n-1; j>i;j--)
        {
            printf(" ") ;
        }
        for(int j=0;j<=i;j++)
        {
            printf("* ") ;
        }
        printf("\n") ;
    }
}

void triangulos_juntos(int n)
{
    for(int i =0; i<n; i++)
    {
        for(int j=0; j<=i;j++)
        {
            printf("*");
        }
        for(int k=n-1; k>i;k--)
        {
            printf(" ");
        }
        for(int z=n-1; z>i;z--)
        {
            printf(" ");
        }
        for (int p=0; p<=i;p++)
        {
            printf("*");
        }
        printf("\n") ;
    }
}

int main()
{
    int altura_triangulo ;

    ingrese_altura(&altura_triangulo) ;
    printf("\n") ;

    triangulo_rectangulo_isosceles(altura_triangulo) ;
    printf("\n") ;

    triangulo_equilatero(altura_triangulo) ;
    printf("\n") ;

    triangulos_juntos(altura_triangulo) ;   
    printf("\n") ;
    
    system("pause") ;
    return 0 ;


}