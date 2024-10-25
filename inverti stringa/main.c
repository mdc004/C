#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverti_stringa(char stringa[30]);
int main()
{
    char parola[30], x;
    printf("Inserire la frase da invertire: ");
    scanf("%s", parola);
    inverti_stringa(parola);
    printf("\n La stringa invertita e': %s",parola);
    return 0;
}

void inverti_stringa(char stringa[30]){
    int i;
    char temp;
    for(i=0;i<strlen(stringa)/2;i++){
        temp=stringa[i];
        stringa[i]=stringa[(strlen(stringa)-1)-i];
        stringa[(strlen(stringa)-1)-i]=temp;
    }
}
