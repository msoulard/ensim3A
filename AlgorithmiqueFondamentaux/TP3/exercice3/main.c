#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float *tabNotes;
    int tab[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int j;
    int nbEleves, nbSup;
    float moyenne, variance, ecartType;

    printf("Combien de notes ? ");
    scanf("%d", &nbEleves);
    tabNotes = (double*)malloc(sizeof(double)*nbEleves);

    moyenne = 0;
    for(int i = 0 ; i < nbEleves ; i++){
        printf("Donnez la note de l'eleve %d : ", i+1);
        scanf("%f", &tabNotes[i]);
        moyenne = moyenne + tabNotes[i];
    }
    moyenne = moyenne / nbEleves;
    variance = 0;
    nbSup = 0;
    for(int i = 0 ; i < nbEleves ; i++){
        variance = variance + pow((tabNotes[i]-moyenne), 2);
        if(tabNotes[i] >= moyenne){
            nbSup = nbSup + 1;
        }
        switch ((int)tabNotes[i]) {
        case 0 : case 1 :
            tab[0] +=1;
            break;
        case 2  : case 3 :
            tab[1] +=1;
            break;
        case 4  : case 5 :
            tab[2] +=1;
            break;
        case 6  : case 7 :
            tab[3] +=1;
            break;
        case 8  : case 9 :
            tab[4] +=1;
            break;
        case 10  : case 11 :
            tab[5] +=1;
            break;
        case 12  : case 13 :
            tab[6] +=1;
            break;
        case 14  : case 15 :
            tab[7] +=1;
            break;
        case 16  : case 17 :
            tab[8] +=1;
            break;
        case 18  : case 19 :
            tab[9] +=1;
            break;
        case 20 :
            tab[10] +=1;
            break;
        }
    }
    variance = variance / nbEleves;
    ecartType = sqrt(variance);

    printf("La moyenne est de %f\n", moyenne);
    printf("La variance est de %f\n", variance);
    printf("L'ecart type est de %f\n", ecartType);
    printf("%d eleves ont eu au moins %f\n", nbSup, moyenne);

    printf("Affichage de l'histogramme des notes :\n");
    for(int i = 0 ; i < 11 ; i++){
        j = 1;
        printf("\t");
        while(tab[i] >= j){
            printf("#");
            j++;
        }
        printf("\n");
    }

    return 0;
}
