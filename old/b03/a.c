#include <stdio.h>
int main (void)
{
    int a, b=0;
    int i;
    scanf ("%d", &a);

    for ( i = 0; i < a; i++ )
    {
        b += i+1;
    }
    b = b * 10000 / a;
    printf("%d\n", b);

    return 0;
}
