#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base, altezza, area;
    printf("calcolo area rettangolo:");
    printf("inserire la base: ");
    scanf("%d",&base);
    printf("inserire l'altezza: ");
    scanf("%d ",&altezza);
    area=base*altezza;
    printf("l'area del rettangolo e': %d \n", area);
    system("pause");

}



