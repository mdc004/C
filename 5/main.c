#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,conta;
    printf("Per terminare inserire un numero dispari");
    do {
        printf("Inserire un numero");
        scanf("%d",&n);
        conta++
    }
    while(n%2==0);
    conta--;
    printf("sono stati inseriti %d numeri pari", n);
}
