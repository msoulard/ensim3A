#include <stdio.h>
#include <stdlib.h>

int main()
{
    char adr[]="Bonjour";
    int i;

    for(int i = 0 ; i < 3 ; i++){
        printf("%c",adr[i]);
    }
    printf("\n");
    i = 0;
    while(adr[i]){
        putchar(adr[i++]);
    }
    printf("\n");

    return 0;
}
