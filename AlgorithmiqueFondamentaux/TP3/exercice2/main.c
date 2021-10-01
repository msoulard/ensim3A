#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float *tabNotes;
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
    }
    variance = variance / nbEleves;
    ecartType = sqrt(variance);

    printf("La moyenne est de %f\n", moyenne);
    printf("La variance est de %f\n", variance);
    printf("L'ecart type est de %f\n", ecartType);
    printf("%d eleves ont eu au moins %f", nbSup, moyenne);

    return 0;
}
