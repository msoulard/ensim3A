#include <stdio.h>
#include <stdlib.h>

int main()
{
    float val1 = 0;
    float val2 = 0;
    float val3 = 0;
    float min = 0;
    float max = 0;
    float moyenne = 0;

    printf("Donnez 3 nombres : ");
    scanf("%f %f %f", &val1, &val2, &val3);
    min = val1;
    max = val1;
    //Calcul de la moyenne
    moyenne = (val1 + val2 + val3)/3;
    //Trouver le minimum
    if(min > val2){
        min = val2;
    }
    if(min > val3){
        min = val3;
    }
    //Trouver le maximum
    if(max < val2){
        max = val2;
    }
    if(max < val3){
        max = val3;
    }

    printf("Le minimum est %f\n Le maximum est %f\n La moyenne est %f\n", min, max, moyenne);

    return 0;
}
