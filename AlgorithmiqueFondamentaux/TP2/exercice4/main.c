#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c, d;
    float xMin, xMax;
    float y;
    float xI, yI;

    printf("Donnez 4 coefficients d'une fonction : ");
    scanf("%f %f %f %f", &a, &b, &c, &d);
    printf("Donnez les bornes de la fontion : ");
    scanf("%f %f", &xMin, &xMax);

    printf("La fonction est de la forme :\n\tf(x)=%.2f*x*x*x+%.2f*x*x+%.2f*x+%.2f\n", a, b, c, d);
    printf("Les images de x par rapport a la fonction pour x allant de %.2f a %.2f :\n", xMin, xMax);
    for(int i = xMin ; i <= xMax ; i++){
        y = a*i*i*i+b*i*i+c*i+d;
        printf("\t%d -> %.2f\n", i, y);
    }

    xI = (-b)/(3*a);
    yI = a*xI*xI*xI+b*xI*xI+c*xI+d;
    printf("Les coordonnees du point d'inflexion sont (%.2f;%.2f)", xI, yI);

    return 0;
}
