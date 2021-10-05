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

int main()
{
    printf("Hello world!\n");
    return 0;
}
