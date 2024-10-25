#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n1,n2,somma;
    printf("Inserire un numero: ");
    scanf("%d",&n1);
    printf("Inserire un numero: ");
    scanf("%d",&n2);
    somma=n1+n2;
    if(somma<INT_MIN)printf("Errore: si è vericato un overow nella somma degli interi inseriti");
    else if(somma>INT_MAX)printf("Errore: si è vericato un overow nella somma degli interi inseriti");
    else printf("La somma dei numeri e' %d",somma);
    return 0;
}
