#include <stdio.h>
#include <stdlib.h>

int f(int a, int b) {
    if(b == 0)
        return 0;
    if(b > 0)
        return f(a, b-1) + x;
    return f(a, b+1) - x;
}




int main()
{
    printf(f(1,2));
    return 0;
}
