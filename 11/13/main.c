#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, array[10],conta=0;
    for(i=0;i<10;i++)
    {
       printf("\nInserisci un numero ");
       scanf("%d", &array[i]);
    }
    printf("\nNumeri pari multipli di 3:");
    for(i=0;i<10;i++)
    {
       if((array[i]%3==0)&&(array[i]%2==0))
       {
        printf("\n%d",array[i]);
        conta++;
       }
    }
    printf("\nI numeri pari sono %d", conta);
    return 0;
}
