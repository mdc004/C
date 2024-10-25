#include <stdio.h>
#include <stdlib.h>

void copia();
int main()
{
    copia();
    return 0;
}
void copia(){
    FILE *ptr, *ptr2;
    char nome1[20], nome2[20];
    printf("Inserisci il nome del file da cui copiare: ");
    gets(nome1);
    printf("Inserisci il nome del file su cui copiare: ");
    gets(nome2);
    ptr=fopen(nome1,"r");
    ptr2=fopen(nome2, "w");
    if((ptr==NULL)||(ptr2==NULL)){
        printf("ERRORE");
        exit(1);
    }
    while(!feof(ptr)){
        char c=fgetc(ptr);
        if (feof(ptr)) break;
        if((c!='a')&&(c!='e')&&(c!='i')&&(c!='o')&&(c!='u')){
            fprintf(ptr2,"%c",c);
        }
    }
    fclose(ptr);
    fclose(ptr2);
}
