#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 5

void inserisci_matrice(int matrice[N][M]);
void stampa(int matrice[N][M]);
int diagonale(int matrice[N][M]);
int main()
{
    int ma[N][M],y;
    inserisci_matrice(ma);
    stampa(ma);
    y=diagonale(ma);
    printf("\n%d",y);
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

int diagonale(int matrice[N][M]){
    int i,j=5;
    for(i=0;i<N;i++){
        if(matrice[i][j]!=matrice[i+1][j-1])printf("\nno");
        j--;
    }
    return 1;

}
