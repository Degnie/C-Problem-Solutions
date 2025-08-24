/*Determine las raíces de una ecuación de 2º grado: ax² + bx + c = 0 (recordar 
que el discriminante Δ = b² – 4ac, y que la raíz r = (–b ± √Δ)/2a). */


#include <stdio.h>
#include <math.h>  
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    double a,b,c;
    double discriminante;

    do
    {
        printf("Ingrese el valor de a: \n");
        scanf("%lf",&a);

        if(a==0)
        {
            printf("ERROR, no es una ecuacion de segundo grado, vuelva a intentarlo\n");
            continue;
        }
        break;

    }while(true);
        
        printf("ingere el valor de b: \n");
        scanf("%lf",&b);
        printf("Ingrese el valor de c: \n");
        scanf("%lf",&c);

        discriminante= pow(b,2) -4*a*c;

        double x1, x2;
        if(discriminante == 0)
        {
            x1= -b/(2*a);

            printf("Las raices son iguales y valen: %lf\n",x1);

        }

        else if(discriminante>0)
        {
            x1= (-b + sqrt(discriminante))/(2*a) ;
            x2= (-b - sqrt(discriminante))/(2*a);

            printf("La raiz x1 es: %.2lf\n",x1);
            printf("La raiz x2 es: %.2lf\n",x2);
        
        }
        else
        {
            x1 = -b/(2*a);
            x2 = sqrt(-discriminante)/(2*a);

            printf("La raiz x1 es: %lf + %.2lf i\n",x1,x2);
            printf("La raiz x2 es: %lf - %.2lf i\n",x1,x2);

        }


    printf("\n");   
    system("pause");
    return 0;
}