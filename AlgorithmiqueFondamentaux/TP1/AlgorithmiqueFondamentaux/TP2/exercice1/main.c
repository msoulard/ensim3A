#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    float y;
     printf("Donnez une valeur de x : ");
     scanf("%d", &x);
     y = 4*x*x+2*x-5;
     printf("4x%dx%d+2x%d-5=%.2f", x, x, x, y);

    return 0;
}
