#include <stdio.h>
#include <stdlib.h>
#include "jeuNim.h"

int main()
{
    //test de la fonction pour récupérer les pseudos des joueurs
    /*char joueur1[50];
    char joueur2[50];
    recupererPseudoJoueurs(joueur1, joueur2);
    printf("\njoueur 1 : %s\njoueur 2 : %s", joueur1, joueur2);*/

    //test de la fonction pour afficher le rectangle de jeu
    //afficherRectangleJeu();

    //test de l'affichage du jeu lors de l'initialisation
    /*int tabBatonnets[2][20];
    initialiserTableauBatonnets(tabBatonnets);
    afficherRectangleJeu(tabBatonnets);*/

    //Menu et boucle de jeu
    char choix;
    do{
        printf("\nChoisissez une option : ");
        printf("\n\tN - Jeu de Nim");
        printf("\n\tQ - Quitter");
        printf("\nVotre choix : ");
        fflush(stdin);
        scanf("%c", &choix);
        if(choix == 'N' || choix == 'n'){
            jouerJeuDeNim();
        }
    }while(choix != 'Q' && choix != 'q');

    return 0;
}
