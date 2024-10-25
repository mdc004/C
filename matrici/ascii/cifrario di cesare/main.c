#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crypt(char s[80],int key[21]);
void decrypt(char s[80],int key[21]);
int main()
{
    int key,choice;
    char stringa[80];
    printf("Inserire la stringa senza spazi: ");
    scanf("%s",&stringa);
    printf("Inserire la chiave di cifratura: ");
    scanf("%d",&key);
    printf("Premi\n 1. per cifrare la stringa\n 2. per decifrare la stringa\n\tscelta: ");
    scanf("%d",&choice);
    switch (choice){
        case 1: crypt(stringa,key);
        break;
        case 2: decrypt(stringa,key);
        break;
    }
    printf("\n\t%s\n",stringa);
    return 0;
}
void crypt(char s[80],int key[21]){
    int i,c;
    for (i=0;i<strlen(s);i++){
        c=(int)s[i];
        c+=key;
        s[i]=(char)c;
    }
}

void decrypt(char s[80],int key[21]){
    int i,c;
    for (i=0;i<strlen(s);i++){
        c=(int)s[i];
        c-=key;
        s[i]=(char)c;
    }
}
