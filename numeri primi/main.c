#include <stdio.h>
#include <stdlib.h>

int ifprimo(int num);
int main()
{
    int x,n;
    printf("Inserire un numero: ");
    scanf("%d",&n);
    x=ifprimo(n);
    if(x==0)printf("\nIl numero non e' primo");
    else printf("\nIl numero e' primo");;
    return 0;
}
int ifprimo(int num){
    int ver,i;
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)ver=1;
        break;
    }
    if(ver==1)return 0;
    else return 1;
}
