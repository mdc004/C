#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Inserire il numero: ");
    scanf("%d", &n);

    if (n%2!=0)
        {
        n--;
        }
    else
        {
        n-=2;
        }
    while (n>=0)
        {
        printf("%d\n", n);
        n-=2;
        }

}
