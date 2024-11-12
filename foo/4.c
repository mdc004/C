#include <stdio.h>
#include <stdlib.h>
//ti dice se un numero è positivo o negativo//
int main()
{
    float numero;
    printf("inserire il numero: ");
    scanf("%f",&numero);
    if (numero==0)
    {
       printf("il numero inserito e' zero");
    }
    else
    {
        if (numero>0)
            {
            printf("il numero e' positivo");
            }

            else
                {
                printf("il numero e' negativo");
                }
    }
}
