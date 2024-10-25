#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 5

void inserisci_matrice(int matrice[N][M]);
float media_righe_pari(int matrice[N][M]);
int main()
{
    int ma[N][M];
    float average;
    inserisci_matrice(ma);
    average=media_righe_pari(ma);
    printf("la media delle righe pari e': %f", average);
    return 0;
}

void inserisci_matrice(int matrice[N][M]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("inserire l'elemento in riga %d e colonna %d: ",i,j);
            scanf("%d", &matrice[i][j]);
        }
    }
}

float media_righe_pari(int matrice[N][M]){
    int i,j,somma,cont=0;
    float media;
    for(i=0;i<N;i+=2){
        for(j=0;j<M;j++){
            somma+=matrice[i][j];
            cont++;
        }
    }
    media=somma/cont;
    return media;
}
