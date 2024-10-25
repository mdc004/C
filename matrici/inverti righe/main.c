#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 7

void inserisci_matrice(int matrice[N][M]);
void inverti_righe(int matrice[N][M]);
void stampa(int matrice[N][M]);
int main()
{
    int ma[N][M];
    inserisci_matrice(ma);
    inverti_righe(ma);
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

void inverti_righe(int matrice[N][M]){
    int j,temp;
        for(j=0;j<N;j+=2){
            for(j=0;j<M;j++){
                temp=matrice[0][j];
                matrice[0][j]=matrice[1][j];
                matrice[1][j]=temp;
            }
        }
}
