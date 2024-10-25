#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aggiungi(char s[80]);
int main()
{
    char stringa[80];
    printf("Inserire la stringa: ");
    fflush(stdin);
    gets(stringa);
    aggiungi(stringa);
    printf("La stringa finale sara': %s", stringa);
    return 0;
}

void aggiungi(char s[80]){
    int i,x;
    for(i=strlen(s);i>=0;i--){
        s[i+3]=s[i];

    }
    x=strlen(s);
    for(i=0;i<3;i++){
        s[i]='*';
        s[i+x]='*';
    }
}
