#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    FILE *pt, *pt2;
    pt=fopen("parola.txt","r");

    if (pt==NULL){
      printf("\nNon e' stato possibile aprire il file\n");
      exit(1);
    }

    c=fgetc(pt);
    while(!feof(pt)){
        fputc(c,pt2);
        c=fgetc(pt);
    }

    fclose(pt);
    fclose(pt2);
}
