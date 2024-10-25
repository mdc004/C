#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[20], voc[5]={'a','e','i','o','u'},c;
    int cont=0,i;
    FILE *ptr;
    printf("Inserisci il nome del file: ");
    gets(nome);
    ptr=fopen(nome,"r");

    if (ptr==NULL){
      printf("impossibile aprire il file!!!");
      exit(1);
    }
    c=fgetc(ptr);
    while(c!=EOF){
        for(i=0;i<5;i++)
            if(c==voc[i])cont++;
        c=fgetc(ptr);
    }
    printf("\nLe vocali presenti nel file sono %d", cont);

    fclose(ptr);
}
