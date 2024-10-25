#include<stdio.h>
#include<stdlib.h>
int main()
{
    float voto;
    printf("Inserire il voto: ");
    scanf("%f", &voto);

    if (voto>7)
        {
        printf("Buono");
        }
    else {
        if (voto>=6)
        {
           printf("Discreto");
        }
        else
        {
         printf("Insufficiente");
        }
    }




    /*
    if (numero1<numero2)
    {
        printf("%.3f %.3f", numero2, numero1);
    }
    else
    {
        printf("%.3f %.3f\n", numero1, numero2);
    }
    system("pause");
    */
}
