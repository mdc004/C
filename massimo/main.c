#include <stdio.h>
#include <stdlib.h>

int main()
{
    int q,i,n,max;
    printf("Iserire la quantita' di numeri da inserire");
    scanf("%d", &q);

    for (i=1;i<q; i++)
        {
        printf("inserire un numero");
        scanf("%d", &n);
        if(n<max)max=n;
        }
    printf("%d e' il maggiore", max);
}
