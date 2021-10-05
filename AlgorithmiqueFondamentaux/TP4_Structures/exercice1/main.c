#include <stdio.h>
#include <stdlib.h>

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

void sommeMatrices(matrice *mA, matrice *mB, matrice **mC){
    if(mA->nbLignes == mB->nbLignes && mA->nbColonnes == mB->nbColonnes){
        *mC = creerMatrice(mA->nbLignes, mB->nbColonnes);
        for(int i = 0 ; i < (*mC)->nbLignes ; i++){
            for(int j = 0 ; j < (*mC)->nbColonnes ; j++){
                (*mC)->val[i][j] = mA->val[i][j] + mB->val[i][j];
            }
        }
    }
    else{
        printf("L'addition des deux matrices n'est pas possible");
    }
}

void transposerMatrice(matrice **m){
    int tempo;
    if((*m)->nbLignes == (*m)->nbColonnes){
        for(int i = 0 ; i < (*m)->nbLignes ; i++){
            for(int j = 0 ; j < i ; j++){
                tempo = (*m)->val[j][i];
                (*m)->val[j][i] = (*m)->val[i][j];
                (*m)->val[i][j] = tempo;
            }
        }
    }
    else{
        printf("La transposée de la matrice n'est pas possible");
    }

}

int estTransposee(matrice *mA, matrice *mB){
    int verif = 0;

    if(mA->nbLignes == mB->nbLignes && mA->nbColonnes == mB->nbColonnes){
        for(int i = 0 ; i < mA->nbLignes ; i++){
            for(int j = 0 ; j < mA->nbColonnes ; j++){
                if(mA->val[i][j] == mB->val[j][i]){
                    verif = 1;
                }
                else{
                    verif = 0;
                }
            }
        }
    }
    else{
        printf("La transposée de la matrice n'est pas possible");
    }

    return verif;
}

int main()
{
    int nbLA, nbCA, nbLB, nbCB;
    //int tailleInt = sizeof(int);
    //int tailleIntE = sizeof(int*);
    matrice *matA, *matB, *matC;

    //printf("%d %d", tailleInt, tailleIntE);
    //Première matrice
    printf("Donnez le nombre de lignes et de colonnes de la matrice A : ");
    scanf("%d %d", &nbLA, &nbCA);
    matA = creerMatrice(nbLA, nbCA);
    lireMatrice(matA);
    afficherMatrice(matA);
    //Deuxième matrice
    printf("Donnez le nombre de lignes et de colonnes de la matrice B : ");
    scanf("%d %d", &nbLB, &nbCB);
    matB = creerMatrice(nbLB, nbCB);
    lireMatrice(matB);
    afficherMatrice(matB);/*
    //Somme des deux matrices A et B dans la matrice C
    printf("\nLa somme des deux matrices A et B donnent la matrice suivante :\n");
    sommeMatrices(matA, matB, &matC);
    afficherMatrice(matC);

    //Transposée de la matrice A
    printf("\nLa transposee de la matrice A vaut :\n");
    transposerMatrice(&matA);
    afficherMatrice(matA);*/

    //Vérification que la matrice B est la transposée de la matrice A
    if(estTransposee(matA,matB) == 1){
        printf("\nLa matrice B est la transposee de la matrice A");
    }
    else{
        printf("\nLa matrice B n'est pas la transposee de la matrice A");
    }

    return 0;
}
