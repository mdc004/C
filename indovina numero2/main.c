#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int num,n=(rand()%1000)+1,conta=10;
    while(conta>0)
        {
            printf("\nHai ancora %d tentativi\n", conta);
            printf("Inserisci un numero ");
            scanf("%d", &num);
            conta--;
                if(num>n)
                    printf("Inserisci un numero piu' piccolo\n");
                if(num<n)
                    printf("Inserisci un numero piu' grande\n");
                if(num==n)
                {
                    printf("\nBravo! Hai indovinato!\n");
                    conta=-1;
                }
        }
    if(conta!=-1)printf("\nPeccato hai perso!\nIl numero era %d\n",n);
    return 0;
}
