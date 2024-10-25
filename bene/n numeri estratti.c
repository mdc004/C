#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x,max;
    srand(time(NULL));
    printf("la quantita' di numeri da estrarre: ");
    scanf("%d",&max);
    for (x=1; x<=max; x+=1)
    {
        n=(rand()%6)+1;
        printf("\n%d", n);
    }



    return 0;

}
