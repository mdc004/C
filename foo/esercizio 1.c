#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,min;
    printf("Per terminare inserire un numero negativo");
    printf("\nInserire un numero ");
    scanf("%d",&min);
    do{
        printf("\nInserire un numero ");
        scanf("%d",&n);
        if(n<0);
        else if(n<min)min=n;
    }
   while(n>0);
   printf("il numero piu' piccolo e': %d",min);
}
