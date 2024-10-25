#include <stdio.h>
#include <stdlib.h>
#define N 2 //righe
#define M 3 //colonne

void inserisci_matrice(int matrice[N][M]);
void stampa(int matrice[N][M]);
float media(int matrice[N][M]);
int main()
{
    int ma[N][M];
    float y;
    inserisci_matrice(ma);
    stampa(ma);
    y=media(ma);
    printf("\n%f\n",y);
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

float media(int matrice[N][M]){
    int i,j,somma,cont=0;
    float media;
    for(i=0;i<N;i++){
        for(j=0;j<M;j+=2){
            somma+=matrice[i][j];
            cont++;
        }
    }
    media=((float)(somma))/cont;
    return media;
}
