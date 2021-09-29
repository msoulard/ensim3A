#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int parite(int val){
    int pair = 0;
    int resultat;

    resultat = val%2;
    if(resultat == 0){
        pair = 1;
    }
    else{
        pair = 0;
    }
    return pair;
}
int main()
{
    int val;

    printf("Donnez un nombre entier : ");
    scanf("%d", &val);
    if(parite(val) == 1){
        printf("Le nombre %d est pair", val);
    }
    else{
        printf("Le nombre %d est impair", val);
    }

    return 0;
}
