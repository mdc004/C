#include <stdio.h>
#include <stdlib.h>

void inserisci_matrice(int n, int m, int matrice[100][100]);
void cambia_diagonale(int n, int m, int matrice[100][100]);
void stampa(int n, int m, int matrice[100][100]);
int main()
{
    int n,m,ma[100][100];
    printf("inserire il numero di righe: ");
    scanf("%d",&n);
    printf("inserire il numero di colonne: ");
    scanf("%d",&m);
    inserisci_matrice(n,m,ma);
    cambia_diagonale(n,m,ma);
    stampa(n,m,ma);

    return 0;
}

void inserisci_matrice(int n, int m, int matrice[100][100]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("inserire l'elemento in riga %d e colonna %d: ",i,j);
            scanf("%d", &matrice[i][j]);
        }
    }
}

void cambia_diagonale(int n, int m, int matrice[100][100]){
    int i;
    for(i=0;i<n;i++){
        matrice[i][i]=0;
    }
}

void stampa(int n, int m, int matrice[100][100]){
    int i,j;
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<m;j++){
            printf("\t%d",matrice[i][j]);

        }
    }
}



