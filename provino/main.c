#include <stdio.h>
#include <stdlib.h>

int inizializzazione(int *n, int *array[1000]);
int stampa(int *n, int *array[1000]);
int main(){
    int a=0,vettore[a];
    printf("\ninserire la quantita' di elementi dell'array: ");
    scanf("%d", &a);
    vettore[a]=inizializzazione(&a, &vettore[a]);
    stampa(&a, &vettore[a]);
    system("pause");
    return 0;
}
int inizializzazione(int *n, int *array[1000]){
    int i, num;
    for (i=0; i<n; i++){
        printf("Inserire un numero: ");
        scanf("%d", &num);
        array[i]=num;
    }
}
int stampa(int *n, int *array[1000]){
    int j;
    for (j=0; j<n;j++)printf("\nelemento %d: %d", j,array[j]);
}
