#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void triInsertion(int *tab, int n, int *tabTrie){
    int tempo;
    int j;

    for (int i = 0 ; i < n ; i++) {
        tempo = tab[i];
        for (j = i ; j > 0 && tabTrie[j - 1] > tempo ; j--) {
            tabTrie[j] = tabTrie[j - 1];
        }
        tabTrie[j] = tempo;
    }
}
int main()
{
    int *tab;
    int *tabTrie;
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
    tabTrie = (int*)calloc(n, sizeof(int));
    triInsertion(tab, n, tabTrie);
    printf("\nVoici les valeurs du tableau trie :\n\t");
    for(int i = 0 ; i < n ; i++){
        printf("%d ", tabTrie[i]);
    }
    free(tab);
    free(tabTrie);

    return 0;
}
