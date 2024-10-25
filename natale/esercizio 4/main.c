#include <stdio.h>
#include <stdlib.h>

void iniziallizzazione(int *n, int array[1000]);
float calcmedia(int array[1000], int n);
int main()
{   int q=0, vettore[1000];
    float m;
    iniziallizzazione(&q,vettore);
    m=calcmedia(vettore,q);
    printf("\nLa media degli elementi dell'array e' pari a: %.2f", m);
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
float calcmedia(int array[1000], int n){
    int j;
    float media, somma=0;
    for (j=0;j<n;j++){
            somma+=array[j];
    }
    media=somma/n;
    return media;
}
