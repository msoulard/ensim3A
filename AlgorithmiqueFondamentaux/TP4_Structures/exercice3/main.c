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

int diag1(matrice *mat){
    int somme = 0;

    for(int i = 0 ; i < (mat->nbLignes) ; i++){
        somme = somme + (mat->val[i][i]);
    }
    printf("\nsomme diagonale 1 : %d", somme);

    return somme;
}

int diag2(matrice *mat){
    int somme = 0;
    int i = 0;
    int j = (mat->nbColonnes-1);

    while(i < (mat->nbLignes) && j >= 0){
        somme = somme + (mat->val[i][j]);
        i++;
        j--;
    }
    printf("\nsomme diagonale 2 : %d", somme);

    return somme;
}

int sommeLigne(matrice *mat, int ligne){
    int somme = 0;

    for(int i = 0 ; i < (mat->nbColonnes) ; i++){
        somme = somme + (mat->val[ligne][i]);
    }
    printf("\nsomme ligne %d : %d", ligne, somme);

    return somme;
}

int sommeColonne(matrice *mat, int colonne){
    int somme = 0;

    for(int i = 0 ; i < (mat->nbLignes) ; i++){
        somme = somme + mat->val[i][colonne];
    }
    printf("\nsomme colonne %d : %d", colonne, somme);

    return somme;
}

int estMagique(matrice *mat){
    int verif = 1;
    int sommeDiag1 = diag1(mat);
    int sommeDiag2 = diag2(mat);
    int tabSommeLigne[100];
    int tabSommeColonne[100];

    if(sommeDiag1 == sommeDiag2){
        for(int i = 0 ; i < (mat->nbLignes) ; i++){
            tabSommeLigne[i] = sommeLigne(mat, i);
            tabSommeColonne[i] = sommeColonne(mat, i);
            if(sommeDiag1 != tabSommeLigne[i] || sommeDiag2 != tabSommeColonne[i]){
                verif = 0;
            }
        }
    }
    else{
        verif = 0;
    }


    return verif;
}

int main()
{
    int n;
    matrice* mat;

    printf("Donnez la taille de la matrice (nombre de lignes = nombre de colonnes) : ");
    scanf("%d", &n);

    mat = creerMatrice(n, n);
    lireMatrice(mat);
    afficherMatrice(mat);
    if(estMagique(mat) == 1){
        printf("\nLa matrice carree est magique !!");
    }
    else{
        printf("\nLa matrice carree n'est pas magique...");
    }

    return 0;
}
