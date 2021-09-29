#include <stdio.h>
#include <stdlib.h>

void afficherLigne(int nbEtoiles){
    for(int i = 1 ; i<= nbEtoiles ; i++){
        printf("*");
    }
}

void afficherRectangle(int nbEtoiles, int nbLignes){
    for(int ligne = 1 ; ligne <= nbLignes ; ligne++){
        printf("\t");
        if(ligne == 1 || ligne == nbLignes){
            afficherLigne(nbEtoiles);
        }
        else{
            for(int colonne = 1 ; colonne <= nbEtoiles ; colonne++){
                if(colonne == 1 || colonne == nbEtoiles){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
int main()
{
    int nbEtoiles;
    int nbLignes;

    printf("Donnez le nombres d'etoiles et le nombre de lignes: ");
    scanf("%d %d", &nbEtoiles, &nbLignes);
    afficherRectangle(nbEtoiles, nbLignes);

    return 0;
}
