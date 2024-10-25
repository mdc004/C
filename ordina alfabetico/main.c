#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordina(char s[30]);
int main()
{
    char stringa[30];
    printf("Inserire la stringa: ");
    scanf("%s", stringa);
    ordina(stringa);
    printf("Stringa ordinata in ordina alfabetico: %s", stringa);
}

void ordina(char s[30]){
    int i, j, temp;
    for(i=0;i<strlen(s)-1;i++){
      for(j=strlen(s)-1;j>i;j--){
                  if (s[j]<s[j-1]){
                    temp=s[j];
                    s[j]=s[j-1];
                    s[j-1]=temp;
                  }
        }
    }
}
