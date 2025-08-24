#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char numero_usuario[100];
    int longitud;

    do
    {
        bool valido=true;
        printf("Ingrese el numero: ");
        scanf("%s",numero_usuario);
        longitud=strlen(numero_usuario);
        for(int i=0; i<longitud; i++)
        {
            if(!isdigit(numero_usuario[i]) && numero_usuario[i]!='.' && !(i==0 && numero_usuario[i]=='-'))
            {
                valido=false;
                break;
            }
        }
        int contador_puntos=0;
        int n=longitud;           // *Usamos una variable, asi podemos modificar la longitud dentro del bucle
        for(int j=0; j<n; j++)
        {
            if(numero_usuario[j]=='.')
            {
                longitud=longitud-1;
                contador_puntos++;
            }

            if(contador_puntos>1)
            {
                break;
            }
        }
        if(!valido || contador_puntos>1)
        {
            printf("\nERROR, El valor ingresado es incorrecto,vuelva a intentarlo.\n");
            continue;
        }
    break;
    } while (true);
    
    if(numero_usuario[0]=='-')
    {
        longitud=longitud-1;
    }
    printf("\nLa cantidad de digitos del numero %s es: %d\n",numero_usuario,longitud);

    printf("\n");
    system("pause");
    return 0;

}