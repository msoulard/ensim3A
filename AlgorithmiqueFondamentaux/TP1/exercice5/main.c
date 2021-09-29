#include <stdio.h>
#include <stdlib.h>

int estPremier(int n){
    int b;
    int i;
    int r;

    b = n/2;
    i = 2;
    r = 1;

    while(i <= b && r != 0){
        r = n%i;
        i++;
    }
    if(r != 0){
        r = 1;
    }
    else{
        r = 0;
    }

    return r;
}
int main()
{
    int n = 2;
    int tab[10];
    int i = 0;

    do{
        if(estPremier(n) == 1){
            tab[i] = n;
            i++;
        }
        n++;
    }while(i < 10);
    printf("Les 10 premiers nombres premiers sont : ");
    for(i = 0 ; i < 10 ; i++){
        printf("%d ; ", tab[i]);
    }

    return 0;
}
