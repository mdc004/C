#include <stdio.h>
#include <stdlib.h>

void inserisci_matrice(int n, int m, int matrice[100][100]);
int cerca_x(int n, int m, int matrice[100][100]);
int main(){
    int n,m,ma[100][100],y=0;
    printf("inserire il numero di righe: ");
    scanf("%d",&n);
    printf("inserire il numero di colonne: ");
    scanf("%d",&m);
    inserisci_matrice(n,m,ma);
    y=cerca_x(n,m,ma);
    printf("il numero di volte che il numero compare nella matrice sono %d volte",y);
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

int cerca_x(int n, int m, int matrice[100][100]){
    int i,j,cont=0,x;
    printf("inserire il numero da cercare: ");
    scanf("%d",&x);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(x==matrice[i][j])cont++;
    return cont;
}
