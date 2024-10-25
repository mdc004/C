#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int base,altezza;
    float area, perimetro, latob;
    base = 10;
    altezza = 5;
    latob = sqrt(pow (base/2 ,2)+pow (altezza ,2));
    perimetro = latob*2+base;
    area = (base*altezza)/2;
    printf("L'area e': %f\n", area);
    printf("Il perimetro e': %f\n", perimetro);
    system("pause");
}
