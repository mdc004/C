#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,min;
    printf("Per terminare inserire un numero negativo\n");
    do{
        printf("Inserire un numero \n");
        scanf("%d",&n);
        if(n>0 && n<min)
            min=n;
    }
   while(n>0);
   printf("il numero piu' piccolo e': %d",min);
    return 0;
}
