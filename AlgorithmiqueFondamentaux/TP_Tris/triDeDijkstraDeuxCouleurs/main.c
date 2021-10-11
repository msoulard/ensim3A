#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void triDijkstraDeux(int *tab, int n){
    int i = 0;
    int j = n-1;
    int tempo;

    do{
        switch(tab[i]){
            case 0 :
                i++;
                break;
            case 1 :
                tempo = tab[i];
                if(tab[j] == 0){
                    tab[i] = tab[j];
                    tab[j] = tempo;
                    j--;
                    i++;
                }
                else{
                    j--;
                }
                break;
        }
    }while(i <= j);
}

int main()
{
    int *tab;
    int n;
    int i = 0;
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
    fichier = fopen("H:\\Home\\Documents\\AlgorithmiqueFondamentaux\\TP_Tris\\dijkstraDeux.txt", "r+");
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
    triDijkstraDeux(tab, n);
    printf("\nVoici les valeurs du tableau trie :\n\t");
    for(int i = 0 ; i < n ; i++){
        printf("%d ", tab[i]);
    }
    free(tab);

    return 0;
}
