#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void triSelectionMinimum(int *tab, int n){
    int tempo;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j <n ; j++){
            if(tab[i]<tab[j]){
                tempo = tab[i];
                tab[i] = tab[j];
                tab[j] = tempo;
            }
        }
    }
}

int main()
{
    int *tab;
    int n = 0;
    int i = 0;
    int val;
    FILE* fichier;
    char retour;

    /*printf("Donnez le nombre de valeurs a trier : ");
    scanf("%d", &n);
    tab = (int*)malloc(sizeof(int)*n);
    for(int i = 0 ; i < n ; i++){
        printf("\nDonnez la valeur %d du tableau : ", i);
        scanf("%d", &tab[i]);
    }*/

    //ouverture du fichier
    fichier = fopen("H:\\Home\\Documents\\AlgorithmiqueFondamentaux\\TP_Tris\\data.txt", "r+");
    //si problème à l'ouverture
    if(fichier == NULL){
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    //sinon lecture du fichier
    else{
        //récupérer la taille du tableau
        fseek(fichier, 0, SEEK_END);
        n = ftell(fichier) / 2 + 1;
        printf("\nn = %d\n", n);
        /*while (!feof(fichier)) {
            retour = fgetc(fichier);
            if (retour == EOF) {
                printf("%s\n", strerror(errno));
                exit(errno);
            }
            //printf("\nretour = %c ", retour);
            if(retour != ' '){
                n++;
                val = (int) retour - 48;
                printf("%d ", val);
            }
        }*/
        //allocation de la taille du tableau
        tab = (int*)malloc(sizeof(int)*n);
        //replacer le curseur au début du fichier
        rewind(fichier);
        //récupérer les valeurs du tableau
        while (i < n) {
            retour = fgetc(fichier);
            if (retour == EOF) {
                printf("%s\n", strerror(errno));
                exit(errno);
            }
            //printf("\nretour = %c ", retour);
            if(retour != ' '){
                val = (int) retour - 48;
                printf("%d ", val);
                tab[i] = val;
                i++;
            }
        }
    }
    //fermeture du fichier
    fclose(fichier);
    //tri du tableau
    triSelectionMinimum(tab, n);
    printf("\nVoici les valeurs du tableau trie :\n\t");
    for(int i = 0 ; i < n ; i++){
        printf("%d ", tab[i]);
    }
    free(tab);

    return 0;
}
