#include <stdio.h>
#include <stdlib.h>
#define N 4
#define M 5

void inserisci_matrice(int matrice[N][M]);
void massimo_per_riga(int matrice[N][M]);
int main()
{
    int ma[N][M];
    inserisci_matrice(ma);
    massimo_per_riga(ma);
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

void massimo_per_riga(int matrice[N][M]){
    int i,j,max;
    for(i=0;i<N;i++){
        max=matrice[i][0];
        for(j=0;j<M;j++)if(matrice[i][j]>max)max=matrice[i][j];
        printf("\nIl maggiore della riga %d e' %d",i,max);
    }
}
