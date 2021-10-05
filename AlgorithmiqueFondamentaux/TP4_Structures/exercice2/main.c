#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef struct{
    int ** val;
    int nbLignes;
    int nbColonnes;
}matrice;

matrice* creerMatrice(int _nbLignes, int _nbColonnes){
    matrice* m;
    m = (matrice*)malloc(sizeof(matrice)*1);
    m->nbLignes = _nbLignes;
    m->nbColonnes = _nbColonnes;
    m->val = (int**)malloc(sizeof(int*)*_nbLignes);
    for(int i = 0 ; i < m->nbLignes ; i++){
        m->val[i] = (int*)malloc(sizeof(int)*m->nbColonnes);
    }

    return m;
}

void lireMatrice(matrice* m){
    int x;
    printf("Donnez les valeurs de la matrice : ");
    for(int i = 0 ; i < m->nbLignes ; i++){
        for(int j = 0 ; j < m->nbColonnes ; j++){
            scanf("%d", &x);
            m->val[i][j] = x;
            fflush(stdin);
        }
    }
}

void afficherMatrice(matrice *m){
    for(int i = 0 ; i < m->nbLignes ; i++){
        printf("\t");
        for(int j = 0 ; j < m->nbColonnes ; j++){
            printf("%d ", m->val[i][j]);
        }
        printf("\n");
    }
}

void initEchiquier(matrice *m){
    for(int i = 0 ; i < m->nbLignes ; i++){
        for(int j = 0 ; j < m->nbColonnes ; j++){
            m->val[i][j] = 0;
        }
    }
}

int coordValides(int x, int y){
    int verif;

    if(x >= 1 && x <= N && y >= 1 && y <= N){
        verif = 1;
    }
    else{
        verif = 0;
    }

    return verif;
}

int main()
{
    int xTour, yTour;
    int xFou, yFou;
    int i,j;
    matrice *echiquier;

    //Initialisation du plateau de l'échiquier
    echiquier = creerMatrice(N, N);
    initEchiquier(echiquier);
    //Position de la tour
    /*printf("Donnez la position de la tour (x, y) : ");
    scanf("%d %d", &xTour, &yTour);
    if(coordValides(xTour, yTour) == 1){
        printf("\nLa tour est sur le plateau\n");
        for(int i = 0 ; i < N ; i++){
            echiquier->val[xTour-1][i] = 1;
            echiquier->val[i][yTour-1] = 1;
        }
        echiquier->val[xTour-1][yTour-1] = 2;
        afficherMatrice(echiquier);
    }
    else{
        printf("\nLa tour n'est pas sur le plateau");
    }*/

    //Position du fou
    printf("Donnez la position du fou (x, y) : ");
    scanf("%d %d", &xFou, &yFou);
    if(coordValides(xFou, yFou) == 1){
        printf("\nLe fou est sur le plateau\n");
        i = xFou-1;
        j = yFou-1;
        while(i < N && j < N){
            echiquier->val[i][j] = 1;
            i++;
            j++;
        }
        i = xFou-1;
        j = yFou-1;
        while(i >= 0 && j >= 0){
            echiquier->val[i][j] = 1;
            i--;
            j--;
        }
        i = xFou-1;
        j = yFou-1;
        while(i >= 0 && j < N){
            echiquier->val[i][j] = 1;
            i--;
            j++;
        }
        i = xFou-1;
        j = yFou-1;
        while(i < N && j >= 0){
            echiquier->val[i][j] = 1;
            i++;
            j--;
        }
        echiquier->val[xFou-1][yFou-1] = 1;
        afficherMatrice(echiquier);
    }
    else{
        printf("\nLe fou n'est pas sur le plateau");
    }

    return 0;
}
