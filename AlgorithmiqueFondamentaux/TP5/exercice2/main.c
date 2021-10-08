#include <stdio.h>
#include <stdlib.h>

int main()
{
    char adr[]="Bonjour";
    int i = 0;

    while(adr[i]){
        printf("%d\n",adr[i++]);
    }
    printf("\n");

    return 0;
}
