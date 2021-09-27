#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a;
    float b;
    float c;
    float delta;
    float x1;
    float x2;

    printf("Donnez les coefficients d'une equation du second degre :\n a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    printf("c = ");
    scanf("%f", &c);

    //Calcul du discriminant
    delta = (b*b)-(4*a*c);
    //Différents cas de discriminant
    if(delta == 0){
        x1= -b/2*a;
        printf("Le discriminant vaut 0 donc il y a une unique racine : x = %f", x1);
    }
    if(delta < 0){
        printf("Le discriminant est negatif donc il n'y a pas de racine reelle");
    }

    if(delta > 0){
        x1 = -b-sqrt(delta)/2*a;
        x2 = -b+sqrt(delta)/2*a;
        printf("Le discriminant est positif donc il y a deux racines reelles : x1 = %f et x2 = %f", x1, x2);
    }

    return 0;
}
