#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=1,i,somma=0,conta=0;
    do{
        /**printf("Inserire un numero ");
        scanf("%d",&n);**/
        n++;
        somma=0;
        for(i=1;i<n;i++)
        {
            if(n%i==0)somma+=i;
        }
        if(somma==n)
        {
          conta++;
          printf("%d e' un numero perfetto\n", n);
        }
    }
    while(conta<5);
    return 0;
}
