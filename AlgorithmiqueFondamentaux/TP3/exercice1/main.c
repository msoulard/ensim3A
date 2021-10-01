#include <stdio.h>
#include <stdlib.h>

#define MAX 150

int main()
{
    int tab[MAX];
    int max;
    int somme;
    int i;

    printf("Donnez des nombres entiers positifs puis un negatif pour la fin : ");
    //scanf("%d", &tab[0]);
    i = 0;
    do{
        scanf("%d", &tab[i]);
        i++;
    }while(tab[i-1] >= 0 && i < MAX);
    i = 0;
    somme = 0;
    max = tab[0];
    while(tab[i] >= 0 && i < MAX){
        somme = somme + tab[i];
        if(max < tab[i]){
            max = tab[i];
        }
        i++;
    }
    printf("La valeur maximale est %d\nLa somme des valeurs vaut %d", max, somme);

    return 0;
}
