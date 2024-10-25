#include <stdio.h>
#include <stdlib.h>

int inizializzazione(int n, int *array[1000]);
int contapari(int n, int *conta, int *array[1000]);
int main(void){
    int q,contap=0, vettore[1000];
    printf("\ninserire la quantita' di elementi dell'array: ");
    scanf("%d", &q);
    vettore[1000]=inizializzazione(q, &vettore[1000]);
    contapari(q, &contap, &vettore[1000]);
    system("pause");
    return 0;
}
int inizializzazione(int n, int *array[1000]){
    int i, num;
    for (i=0; i<n; i++){
        printf("Inserire un numero: ");
        scanf("%d", &num);
        array[i]=num;
    }
}
int contapari(int n, int *conta, int *array[1000]){
    int j;
    for (j=0; j<n;j++){
        if(*array[j]%2==0){
            conta++;
        }
    }
    printf("\ngli elementi pari dell'array sono: %d\n", *conta);
}
