#include <stdio.h>
#include <stdlib.h>

void majEnMin(char chaine[]){
    int i = 0 ;
    while(chaine[i] != '\0'){
        if(chaine[i] <= 90 && chaine[i] >= 65){
            chaine[i] = chaine[i] + 32;
        }
        i++;
    }
}
int main()
{
    char chaine[100];

    printf("Donnez une chaine de caracteres : ");
    gets(chaine);
    majEnMin(chaine);
    printf("\nLa chaine de caracteres apres transformation : %s", chaine);

    return 0;
}
