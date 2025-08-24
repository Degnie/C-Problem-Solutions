/* Cree dos vectores de 50 posiciones con valores enteros aleatorios, ordene cada uno individualmente 
y combínalos en un nuevo vector de 100 posiciones ya ordenado.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void llenado_vector(int v[],int n,int max, int min) 
{
    for(int i=0;i<n;i++)
    {
        v[i]=(rand()%(max-min+1) +min);
    }
}
void imprimir_vector(int v[],int n) 
{
    printf("\n\n");
    for(int i=0; i<n;i++)
    {
        printf(" %d",v[i]);
    }
    printf("\n\n");
}

void ordenar_vector(int v[],int n) 
{
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<n-1;j++) 
        {
            if(v[j]>v[j+1]) 
            {
                int intermedio=v[j];
                v[j]=v[j+1];
                v[j+1]=intermedio;
            }

        }
    }
}

void unir_vectores(int v1[],int v2[], int v3[],int tamanho_separado,int tamanho_junto)
{
    for(int i=0;i<tamanho_junto;i++) //for con el tamaño maximo
    {
        if(i<tamanho_separado) // Para llenar con el primer vector
        { 
            v1[i]= v2[i];
        }
        else
        {
            v1[i]=v3[i-tamanho_separado]; // i- tamaño_separado nos dara un valor valido
        }                                 // Para el vector v3
    }
}

int main()
{
    srand(time(0));
    int vector_1[50]={0}, vector_2[50]={0};
    int vector_combinado[100]={0};
    int maximo,minimo;
    int validacion;

    printf("Ingrese el rango de valores al azar: \n");

    // No se permite ningun caracter en el minimo
    do 
    {
        printf("\nMinimo: ");
        validacion = scanf("%d", &minimo);

        // limpiar buffer en caso de error
        if(validacion != 1) 
        {
            printf("Error: Solo se permiten numeros enteros.\n");
            while(getchar()!='\n'); // limpia entrada
        }
    } while(validacion != 1);

    // No se permite ningun caracter en el maximo
    do 
    {
        printf("\nMaximo: ");
        validacion = scanf("%d", &maximo);

        if(validacion != 1) 
        {
            printf("Error: Solo se permiten numeros enteros.\n");
            while(getchar()!='\n');
        }
    } while(validacion != 1);

    // El 'minimo' siempre debe ser menor al 'maximo'
    if(minimo >= maximo) 
    {
        printf("\nError: El minimo no puede ser mayor ni igual al maximo.\n");
        return 1;
    }

    llenado_vector(vector_1,50,maximo,minimo);
    llenado_vector(vector_2,50,maximo,minimo);

    ordenar_vector(vector_2,50);
    ordenar_vector(vector_1,50);
    printf("\nLos vectores ordenados de forma ascendente son: \n");
    imprimir_vector(vector_1,50);
    imprimir_vector(vector_2,50);

    unir_vectores(vector_combinado,vector_1,vector_2,50,100);
    ordenar_vector(vector_combinado,100);
    printf("\nEl vector total ordenado de forma ascendente es: \n");
    imprimir_vector(vector_combinado,100);

    system("\npause");
    return 0;
}
