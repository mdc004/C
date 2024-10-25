#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 5

void massimo(int vettore[10]);
int main()
{
    int array[10],i;
    for(i=0;i<10;i++){
        printf("inserire elemento %d: ",i);
        scanf("%d", &array[i]);
    }
    massimo(array);
    return 0;
}
void massimo(int vettore[10]){
    int i,cont=0,max;
    max=vettore[0];
    for(i=0;i<10;i++){
        if(vettore[i]>max){
            cont=1;
            max=vettore[i];
        }
        else if(max==vettore[i])cont++;
    }
    printf("\nL'elemento massimo e' %d e compare %d volte", max,cont);
}
