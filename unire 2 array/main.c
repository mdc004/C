#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[10]={1,3,4,5,22,33,66,88,94,99}, y[10]={11,32,34,37,38,55,67,85,92,98}, k=0,j=0, i=0, ar[20];
    while(i<20){
        if(x[j]>y[k]){
            ar[i]=y[k];
            k++;
        }
        else{
           ar[i]=x[j];
           j++;
        }
        i++;
    }
    for(i=0; i<20; i++)
    printf("%d\n", ar[i]);
    return 0;
}
