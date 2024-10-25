#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max, min, i;
    printf("Inserire un numero ");
    scanf("%d", &max);
    printf("\nInserire un secondo numero numero ");
    scanf("%d", &min);
    if(min>max)
            {
            i=max;
            max=min;
            min=i;
            }
    do {
        max=max-min;
        printf("La differenza dei due numeri e' %d\n",max);
    }
    while(max>=3);
    return 0;
}
