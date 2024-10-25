#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    char c=CHAR_MAX;
    int i;
    printf("Inserire un numero: ");
    scanf("%d",&i);
    printf("Il in interi %d\n",i);
    printf("Il in char %c\n",i);
    printf("Il in u %u\n",i);
    return 0;
}
