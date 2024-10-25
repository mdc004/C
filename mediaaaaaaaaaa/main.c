#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 24, sum = 0;
    for(int i = 1; i < 25; i++)sum += i;
    float average = sum/count;
    printf("\n%f\n", average);
}
