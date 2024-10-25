#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i,p;
    p=0;
    printf("Inserire il primo numero ");
    scanf("%d", &a);
    printf("Inserire il secondo numero ");
    scanf("%d", &b);
    for(i=0;i<b;i++)
    {
        p+=a;
        printf("%d\n", p);
    }
    return 0;

}
minggv
gdb
