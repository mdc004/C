#include <stdio.h>
#include <stdlib.h>

void iniziallizzazione(int *n, int array[1000]);
int max(int array[1000], int n);

int main()
{   int q=0, vettore[1000], mag;
    iniziallizzazione(&q,vettore);
    mag=max(vettore,q);
    printf("L'elemento maggiore dell'array e' %d", mag);
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
int max(int array[1000], int n){
    int i, maggiore;
    maggiore=array[0];
        for (i=0;i<n;i++){
            if (array[i]>maggiore)maggiore=array[i];
        }
    return maggiore;
}
