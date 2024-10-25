#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void crea_file_random();
void aggiungi_numeri();
int main(){
    crea_file_random();
    aggiungi_numeri();
    return 0;
}

void crea_file_random(){
    int i;
    FILE *ptr;
    ptr=fopen("random.txt","w");
    if (ptr==NULL){
        printf("\nNon e' stato possibile aprire il file!\n");
        exit(1);
    }
    srand(time(NULL));
    for (i=0;i<20;i++){
        fprintf(ptr,"%d \n",(rand()%31)-11);
    }
    fclose(ptr);
}

void aggiungi_numeri(){
    int i, q;
    FILE *ptr;
    ptr=fopen("random.txt","a");
    if (ptr==NULL){
        printf("\nNon e' stato possibile aprire il file!\n");
        exit(1);
    }
    printf("\nInserire la quantita' di numeri in piu' da aggiungere: ");
    scanf("%d",&q);

    for (i=0;i<q;i+=2){
        fprintf(ptr,"%d\n",i);
    }
    fclose(ptr);
}
