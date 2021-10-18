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
    int tabBatonnets[2][20];
    initialiserTableauBatonnets(tabBatonnets);
    afficherRectangleJeu(tabBatonnets);

    return 0;
}
