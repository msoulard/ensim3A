#include <stdio.h>
#include <stdlib.h>

void triInsertion(int *tab, int n, int *tabTrie){
    //int *tabTrie = (int*)malloc(sizeof(int)*n);
    int j = 0;
    int index = 0;

    tabTrie[1] = tab[1];
    for(int i = 0 ; i < n ; i++){
            //printf("bonjour");
        while(tab[i] < tabTrie[j] && j <= index){
            printf("%d ",tab[i]);
            printf("%d ", tabTrie[j]);
            j++;
        }
        for(int k = index ; k <= j ; k--){
            tabTrie[k] = tabTrie[k-1];
        }
        tabTrie[j] = tab[i];
        index ++;
        for(int h = 0 ; h < n ; h++){
            printf("%d ", tabTrie[h]);
        }
    }
    //return tabTrie;
}
int main()
{
    int *tab;
    int *tabTrie;
    int n;

    printf("Donnez le nombre de valeurs a trier : ");
    scanf("%d", &n);
    tab = (int*)malloc(sizeof(int)*n);
    for(int i = 0 ; i < n ; i++){
        printf("\nDonnez la valeur %d du tableau : ", i);
        scanf("%d", &tab[i]);
    }
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
