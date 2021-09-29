#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    int b;
    int i;
    int r;

    printf("Saisir un nombre : ");
    scanf("%d", &n);

    b = n/2;
    i = 2;
    r = 1;

    while(i <= b && r != 0){
        r = n%i;
        i++;
    }
    if(r != 0){
        printf("Le nombre %d est premier", n);
    }
    else{
        printf("Le nombre %d n'est pas premier", n);
    }

    return 0;
}
