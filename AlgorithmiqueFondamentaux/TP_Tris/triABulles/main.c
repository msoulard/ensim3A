#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void triBulles(int *tab, int n){
    int max = tab[0];
    int index = 0;
    int j;

    for(int i = 0 ; i < n ; i++){
        j = i;
        max = tab[i];
        do{
            if(max < tab[j]){
                max = tab[j];
                index = j;
            }
            j++;
        }while(j < n);
        tab[index] = tab[i];
        tab[i] = max;
    }
}
int main()
{
    int *tab;
    int n;
    int i;
    int val;
    char retour;
    FILE* fichier;

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
    triBulles(tab, n);
    printf("\nVoici les valeurs du tableau trie :\n\t");
    for(int i = 0 ; i < n ; i++){
        printf("%d ", tab[i]);
    }
    free(tab);

    return 0;
}
