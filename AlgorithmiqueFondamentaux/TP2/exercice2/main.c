#include <stdio.h>
#include <stdlib.h>

int main()
{
    int xMin, xMax;
    float y;

    printf("Donnez une valeur entiere minimale de x : ");
    scanf("%d", &xMin);
    printf("Donnez une valeur entiere maximale de x : ");
    scanf("%d", &xMax);

    printf("Les valeurs de x par rapport a la fonction sont :\n");
    for(int i = xMin ; i <= xMax ; i++){
        y = 4*i*i+2*i-5;
        printf("%d -> %.2f\n", i, y);
    }

    return 0;
}
