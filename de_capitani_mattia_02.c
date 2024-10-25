#include <stdio.h>

int main()
{
    float importo, sconto;
    printf("Inserie l'importo della spesa: ");
    scanf("%f",&importo);

    if (importo>=80) {sconto=10;}
    else {
        if (importo>=65){sconto=7;}
        else {
            if (importo>=50) {sconto=6;}
            else {sconto=5;}
        }
    }
    sconto=sconto*importo/100;
    printf("Lo sconto e': %.2f \nL'importo e': %.2f", sconto, importo);
}
