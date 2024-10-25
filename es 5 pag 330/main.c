#include <stdio.h>
#include <stdlib.h>

void converti(int intero, char stringa[6]);
int main()
{
    int n;
    char numero[6];
    do{
        printf("Inserire un numero compreso fra zero e diecimila: ");
        scanf("%d",&n);
    }
    while((n<0)||(n>10000));
    converti(n,numero);
    printf("Il numero nella stringa sara': %s", numero);
    return 0;
}
void converti(int intero, char stringa[6]){
        sprintf(stringa,"%d",intero);
}
