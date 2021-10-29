#ifndef JEUNIM_H_INCLUDED
#define JEUNIM_H_INCLUDED


void recupererPseudoJoueurs(char _joueur1[], char _joueur2[]);
void afficherRectangleJeu(int _tabBatonnets[2][20]);
void initialiserTableauBatonnets(int _tabBatonnets[2][20]);
void jouerJeuDeNim();
int verifierPossibiliteCoups(int _tabBatonnets[2][20], char _lettreBatonnet, int _nbBatonnets);
void supprimerBatonnetsPris(int _tabBatonnets[2][20], int _nbSupprimes, int _positionBatonnets);


#endif // JEUNIM_H_INCLUDED
