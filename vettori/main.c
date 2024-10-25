#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,n;
   printf("Inserire la quantita' di numeri da inserire: ");
    scanf("%d", &n);
    int prova[n];
    for (i=1;i<=n;i++)
    {
        printf("Inserire un numero: ");
        scanf("%d", &prova[i]);
    }
    for (i=1;i<=n;i++)printf("%d\n", prova[i]);
}
