#include <stdio.h>
#include <stdlib.h>

void procedura();
int main(){procedura();}
void procedura()
{
    char c, voc[6]={'a','e','i','o','u'},nome[20],nome2[20];
    FILE *pt, *pt2;
    printf("Inserire il nome del file da copiare: ");
    scanf("%s", nome);
    printf("\nInserire il nome del file in cui copiare: ");
    scanf("%s", nome2);
    pt=fopen("%s","r");
    pt2=fopen("%s","w");
    if((pt==NULL)||(pt2==NULL))printf("\nNon e' stato possible aprire il file\n");
    while(!feof(pt)){
        int cont=0;
        c=fgetc(pt);
        for(int i=0; i<5; i++){
            if(voc[i]==c){
                cont++;
                break;
            }
        }
        if(cont==0)fprintf(pt2,"%c",c);
    }
    fclose(pt);
    fclose(pt2);
}
