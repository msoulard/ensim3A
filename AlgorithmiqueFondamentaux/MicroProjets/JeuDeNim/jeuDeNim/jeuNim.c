#include <stdio.h>
#include <stdlib.h>
#include "jeuNim.h"
#include "conio.h"

#define NBLIGNES 12
#define NBCOLONNES 43

//Fonction permettant de récupérer le pseudo des joueurs
void recupererPseudoJoueurs(char _joueur1[], char _joueur2[])
{
    printf("\nDonnez les pseudos des joueurs : ");
    printf("\n\tPseudo joueur 1 : ");
    gets(_joueur1);
    printf("\n\tPseudo joueur 2 : ");
    gets(_joueur2);
}

//Fonction permettant d'afficher le rectangle du jeu
void afficherRectangleJeu(int _tabBatonnets[2][20]){
    int k = 1;
    int numBatonnet = 0;
    for(int i = 1 ; i <= NBLIGNES ; i++){
        printf("\t");
        numBatonnet = 0;
        for(int j = 1 ; j <= NBCOLONNES ; j++){
            if(i == 1 || i == NBLIGNES){
                printf("=");
            }
            else{
                if(j == 1 || j == NBCOLONNES){
                    printf("|");
                }
                else{
                    if(j%2 == 0){
                        printf(" ");
                    }
                    else{
                        if(_tabBatonnets[0][numBatonnet] == 1){
                            printf("%c", 219);
                            numBatonnet++;
                        }
                        else{
                            printf(" ");
                            numBatonnet++;
                        }
                    }
                }
            }
        }
        printf("\n");
    }
    numBatonnet = 0;
    printf("\t ");
    do{
        if(k%2 == 0){
            k++;
            printf(" ");
        }
        else{
            if(k != 1){
                printf("%c", _tabBatonnets[1][numBatonnet]);
                numBatonnet++;
            }
            k++;
        }
    }while(k < 43 && numBatonnet < 20);
}

//Fonction permettant d'initialiser le tableau des bâtonnets
void initialiserTableauBatonnets(int _tabBatonnets[2][20]){
    for(int i = 0 ; i < 20 ; i++){
        _tabBatonnets[0][i] = 1;
        _tabBatonnets[1][i] = 65 + i;
    }
}
