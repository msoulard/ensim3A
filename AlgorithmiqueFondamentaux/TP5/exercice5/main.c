#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char chaine[100];
    int i = 0;
    int nbVoyelles = 0;

    printf("Donnez une chaine de caracteres : ");
    gets(chaine);
    while(chaine[i] != '\0'){
        switch(chaine[i]){
        case 'a' : case 'A' :
        case 'e' : case 'E' :
        case 'i' : case 'I' :
        case 'o' : case 'O' :
        case 'u' : case 'U' :
        case 'y' : case 'Y' :
            nbVoyelles = nbVoyelles + 1;
            break;
        }
        i++;
    }
    printf("\nDans la chaine de caracteres, il y a %d voyelles", nbVoyelles);

    return 0;
}
