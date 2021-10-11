#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tailleChaine(char chaine[]){
    int i = 0;
    int taille = 0;

    while(chaine[i] != '\0'){
        taille = taille + 1;
        i++;
    }
    return taille;
}

int main()
{
    char chaine[100];

    printf("Donnez une chaine de caracteres : ");
    gets(chaine);
    printf("\nLa longueur de la chaine est de %d", tailleChaine(chaine));

    return 0;
}
