#include <stdio.h>
#include <stdlib.h>

int main()
{
    int somma=0, conta=0, n;
    float

    printf("Per terminare inserire un numero negativo\n");
    do{
        printf("\ninserire un numero: ");
        scanf("%d", &n);
        somma+=n;
        conta++;
        media=somma/conta;
        printf("La media dei numeri inseriti e' pari a %d", media);
    }
    while(n>0);
    return 0;
}
