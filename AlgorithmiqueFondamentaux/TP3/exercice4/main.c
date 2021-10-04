#include <stdio.h>
#include <stdlib.h>

#define TAILLE 5

void rotationDroite(int tab[], int n){
    int tabD[n];

    for(int i = 0 ; i < n ; i++){
        if(i == n - 1){
            tabD[0] = tab[n-1];
            tabD[n-1] = tab[i-1];
        }
        else{
            tabD[i+1] = tab[i];
        }
    }

    printf("\nLe tableau apres rotation a droite : \n");
    for(int i = 0 ; i < n ; i++){
        printf("%d ", tabD[i]);
    }
}

void inversionTab(int tab[], int n){
    int tabI[n];
    int i, j;

    i = 0;
    j = n-1;

    do{
      tabI[j] = tab[i];
      i++;
      j--;
    }while(i < n || j >= 0);

    printf("\nLe tableau apres inversion : \n");
    for(int i = 0 ; i < n ; i++){
        printf("%d ", tabI[i]);
    }
}

int main()
{
    int tab[5] = {1, 2, 3, 4, 5};

    printf("Le tableau avant rotation a droite : \n");
    for(int i = 0 ; i < TAILLE ; i++){
        printf("%d ", tab[i]);
    }

    rotationDroite(tab, TAILLE);
    inversionTab(tab, TAILLE);

    return 0;
}
