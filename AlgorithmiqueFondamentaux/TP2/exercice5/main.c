#include <stdio.h>
#include <stdlib.h>

int main()
{
    int val, somme;
    somme = 0;

    printf("Donnez un entier inferieur a 10000 : ");
    scanf("%d", &val);

    for(int i = 1 ; i < val ; i++){
        if(val%i == 0){
            somme = somme + i;
        }
    }
    if(somme == val){
        printf("Le nombre %d est un nombre parfait", val);
    }
    else{
        printf("Le nombre %d n'est pas un nombre parfait", val);
    }

    return 0;
}
