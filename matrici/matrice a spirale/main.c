#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrice[8][8];
    int num=64,i,j,k,n=8,m=8;
    for(i=0;i<5;i++){
        for(j=0;j<m;j++){
            matrice[n][j]=num;
            num--;
        }
        for(j=0;j<n;j++){
            matrice[j][m]=num;
            num--;
        }
        for(k=m-1;k>=0;k--){
            matrice[n][k]=num;
            num--;
        }
        for(k=m-1;k>=0;k--){
            matrice[k][m]=num;
            num--;
        }
        n--;
        k--;
    }
    for(i=0;i<8;i++){
        printf("\n");
        for(j=0;j<8;j++){
            printf("\t%d",matrice[i][j]);
        }
    }
    return 0;
}
