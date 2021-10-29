#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include "jeuNim.h"
#include "conio.h"

#define NBLIGNES 12
#define NBCOLONNES 43
#define TAILLEPSEUDO 50

//Fonction permettant de récupérer le pseudo des joueurs
void recupererPseudoJoueurs(char _joueur1[], char _joueur2[])
{
    system("cls");
    printf("\nDonnez les pseudos des joueurs : ");
    printf("\n\tPseudo joueur 1 : ");
    fflush(stdin);
    gets(_joueur1);
    printf("\tPseudo joueur 2 : ");
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

//Fonction permettant de supprimer les bâtonnets pris
void supprimerBatonnetsPris(int _tabBatonnets[2][20], int _nbSupprimes, int _positionBatonnets){
    /*for(int i = 0 ; i < 2 ; i++){
        printf("\n");
        for(int j = 0 ; j < 20 ; j++){
            printf("%d ", _tabBatonnets[i][j]);
        }
    }
    printf("\n");*/
    for(int i = 0 ; i < _nbSupprimes ; i++){
        _tabBatonnets[0][_positionBatonnets + i] = 0;
        //printf("%d",_tabBatonnets[0][_positionBatonnets + i]);
    }
    /*printf("\n");
    for(int i = 0 ; i < 2 ; i++){
        printf("\n");
        for(int j = 0 ; j < 20 ; j++){
            printf("%d ", _tabBatonnets[i][j]);
        }
    }*/
}

//Fonction permattant de vérifier la possibilité du coups
int verifierPossibiliteCoups(int _tabBatonnets[2][20], char _lettreBatonnet, int _nbBatonnets){
    int possibilite = 0;
    int positionBatonnet;
    for(int i = 0 ; i < 20 ; i++){
        if(_tabBatonnets[1][i] == (int)_lettreBatonnet){
            positionBatonnet = i;
        }
    }
    for(int i = 0 ; i < _nbBatonnets ; i++){
        if(_tabBatonnets[0][positionBatonnet + i] == 1){
            possibilite = 1;
        }
        else{
            possibilite = 0;
        }
    }
    if(possibilite == 1){
        supprimerBatonnetsPris(_tabBatonnets, _nbBatonnets, positionBatonnet);
    }

    return possibilite;
}

//Fonction permettant de jouer au jeu de Nim
void jouerJeuDeNim(){
    int tabBatonnets[2][20];
    char joueur1[TAILLEPSEUDO];
    char joueur2[TAILLEPSEUDO];
    char lettreBatonnet;
    int nbBatonnets = 20;
    int nbCoups = 0;
    int nbSupprimes = 0;
    int possibilite;
    FILE *fichier;
    time_t date;

    //Récupération de la date
    time(&date);
    //Ouverture ou création du fichier positionnement à la fin du fichier
    fichier = fopen("jeuDeNim.txt", "a+");
    //si problème à l'ouverture
    if(fichier == NULL){
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    //sinon écriture dans le fichier
    else{
        //écriture de la date dans le fichier
        fprintf(fichier, "\n%s", ctime(&date));
        //printf("%s", ctime(&date));
        //récupération et écriture des pseudos des joueurs
        recupererPseudoJoueurs(joueur1, joueur2);
        fprintf(fichier, "\npseudo du joueur 1 : %s", joueur1);
        fprintf(fichier, "\npseudo du joueur 2 : %s", joueur2);
        //initialisation des bâtonnets
        initialiserTableauBatonnets(tabBatonnets[2][20]);
        //début du jeu
        fprintf(fichier, "\n\t\tDébut du jeu de Nim");
        do{
            //joueur 1 joue
            if(nbCoups%2 == 0){
                possibilite = 0;
                do{
                    //effacer l'écran précédent
                    system("cls");
                    //afficher l'écran de jeu
                    afficherRectangleJeu(tabBatonnets[2][20]);
                    printf("\n%s a vous de jouer :", joueur1);
                    printf("\nCombien de batonnets a supprimer ? ");
                    fflush(stdin);
                    scanf("%d", &nbSupprimes);
                    printf("A partir de quel batonnet (lettre) ? ");
                    fflush(stdin);
                    scanf("%c", &lettreBatonnet);
                    possibilite = verifierPossibiliteCoups(tabBatonnets[2][20], lettreBatonnet, nbSupprimes);
                    //printf("\npossibilite = %d", possibilite);
                }while(possibilite != 1);
                //écriture du coup du joueur dans le fichier
                fprintf(fichier, "\n%s a supprime %d batonnets a partir de la lettre %c", joueur1, nbSupprimes, lettreBatonnet);
                nbBatonnets = nbBatonnets - nbSupprimes;
                nbCoups++;
            }
            //joueur 2 joue
            else{
                possibilite = 0;
                do{
                    system("cls");
                    afficherRectangleJeu(tabBatonnets[2][20]);
                    printf("\n%s a vous de jouer :", joueur2);
                    printf("\nCombien de batonnets a supprimer ? ");
                    fflush(stdin);
                    scanf("%d", &nbSupprimes);
                    printf("A partir de quel batonnet (lettre) ? ");
                    fflush(stdin);
                    scanf("%c", &lettreBatonnet);
                    possibilite = verifierPossibiliteCoups(tabBatonnets[2][20], lettreBatonnet, nbSupprimes);
                }while(possibilite != 1);
                //écriture du coup du joueur dans le fichier
                fprintf(fichier, "\n%s a supprime %d batonnets a partir de la lettre %c", joueur2, nbSupprimes, lettreBatonnet);
                nbBatonnets = nbBatonnets - nbSupprimes;
                nbCoups++;
            }
        }while(nbBatonnets > 0);
        //joueur 2 perdu
        if(nbCoups%2 == 0){
            textcolor(12);
            printf("\n%s a perdu", joueur2);
            textcolor(10);
            printf("\n%s a gagne", joueur1);
            textcolor(15);
            printf("\n");
            //écriture du résultat de la partie dans le fichier
            fprintf(fichier, "\n%s a gagne mais %s a malheureusement perdu", joueur1, joueur2);
        }
        //joueur 1 perdu
        else{
            textcolor(12);
            printf("\n%s a perdu", joueur1);
            textcolor(10);
            printf("\n%s a gagne", joueur2);
            textcolor(15);
            printf("\n");
            //écriture du résultat de la partie dans le fichier
            fprintf(fichier, "\n%s a gagne mais %s a malheureusement perdu", joueur2, joueur1);
        }
    }
    //ecriture de la fin de la partie
    fprintf(fichier, "\n\t\tLa partie est terminee\n");
    //fermeture du fichier
    fclose(fichier);
}
