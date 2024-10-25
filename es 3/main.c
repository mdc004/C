#include <stdio.h>
#include <stdlib.h>

int main()
{
    int crescente=0, decrescente=0,a,n,i,q;
    do{
        printf("Inserire una quantita' di numeri da inserire maggiore di 1 ");
        scanf("%d", &q);
    }
    while(q<=2);

    printf("Inserire un numero: ");
    scanf("%d", &a);

    for(i=1; i<q; i++)
    {
        printf("Inserire un numero: ");
        scanf("%d", &n);

        if(n>a)
        {
            crescente++;
        }
        else
            decrescente++;
        a=n;
    }
    if((crescente>0)&&(decrescente>0))printf("No crescente, no decrescente");
    else
    {
    if(crescente>decrescente) printf("La sequenza e' crescente");
    else printf("La sequenza e' decrescente");
    }
}

