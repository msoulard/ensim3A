#include <stdio.h>
#include <stdlib.h>

void afficherLigne(int nbEtoiles){
    for(int i = 1 ; i<= nbEtoiles ; i++){
        printf("*");
    }
}
int main()
{
    int nbEtoiles;

    printf("Donnez le nombres d'etoiles : ");
    scanf("%d", &nbEtoiles);
    afficherLigne(nbEtoiles);

    return 0;
}
