#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void crea_file_primi();
int primi(int i);
int main(){
    crea_file_primi();
    return 0;
}

void crea_file_primi(){
    int i,q,j;
    FILE *ptr;
    ptr=fopen("primi.txt","w");
    if (ptr==NULL){
        printf("\nNon e' stato possibile aprire il file!\n");
        exit(1);
    }
    printf("\nInserire la quantita' di numeri: ");
    scanf("%d",&q);
    for (j=0;j<q;i++){
        if(primi(i)==1){
                fprintf(ptr,"%d \n",i);
                j++;
        }
    }
    fclose(ptr);
}
int primi(int i){
    int div=1;
	int conta=0;

	while(conta<3 && div<=i/2)
	{
		if(i%div==0)
			conta=conta+1;
		div=div+1;
	}
	if (conta==1)return 1;
	else return 0;
}
