#include <stdio.h>
#include <stdlib.h>

int main()
{
    int somma=0,prod=10;
    int n;

    do
    {
        printf("inserisci un numero: ");
        scanf("%d", &n);

        switch(n)
        {
        case 2:
            somma=somma+n;
            break;
        case 3:
            prod=prod*n;
        case 4:
            somma=somma+10;
            break;
        case 5:
            prod=somma*2;
            break;
        default:
            prod=prod*3;
            break;

        }
    }
    while(n>0);
    printf("%d  %d", somma, prod);


    return 0;
}
