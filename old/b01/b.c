#include <stdio.h>

int main (void)
{
    int     m;

    scanf("%d", &m);
    if ( m < 100 )
    {
        printf("00\n");
        return 0;
    }
    else if ( m <= 900 )
    {
        printf("0%d\n", m / 100);
        return 0;
    }
    else if ( m <= 5000 )
    {
        printf("%d\n", m / 100);
        return 0;
    }
    else if ( m <= 30000 )
    {
        printf("%d\n", m / 1000 + 50);
    }
    else if ( m <= 70000 )
    {
        printf("%d\n", (m / 1000 - 30) / 5 + 80 );
        return 0;
    }
    else
        printf("89\n");
    return 0;
}
