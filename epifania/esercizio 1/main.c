#include <stdio.h>
#include <stdlib.h>

void iniziallizzazione(int *n, int array[1000]);
int main()
{   int q=0,vettore[1000];
    iniziallizzazione(&q,vettore);
    return 0;
}
void iniziallizzazione(int *n, int array[1000]){
    int i;
    printf("Inserire la quantita' di elementi dell'array: ");
    scanf("%d",&(*n));
    for (i=0;i<*n;i++){
        printf("\nInserire un numero: ");
        scanf("%d",&array[i]);
    }
}
