#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 5

void inserisci_matrice(int matrice[N][M]);
void scambia_righe(int matrice[N][M]);
void stampa(int matrice[N][M]);
int main()
{
    int ma[N][M];
    inserisci_matrice(ma);
    scambia_righe(ma);
    stampa(ma);
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

void stampa(int matrice[N][M]){
    int i,j;
    for(i=0;i<N;i++){
        printf("\n");
        for(j=0;j<M;j++){
            printf("\t%d",matrice[i][j]);
        }
    }
}
void scambia_righe(int matrice[N][M]){
    int i,j,tempo;
    for(i=0;i<N;i+=2){
        for(j=0;j<M;j++){
            tempo=matrice[i][j];
            matrice[i][j]=matrice[i+1][j];
            matrice[i+1][j]=tempo;
        }
    }
}
