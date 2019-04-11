#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int int_cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main (void)
{
    int     N, K;
    int     i;
    double  takahashi = 0;

    scanf("%d %d", &N, &K);
    int     rate[N];

    for ( i = 0; i < N; i++ )
        cin >> rate[i];

    qsort(rate, N, sizeof(int), int_cmp);

    for ( i = N - K; i < N; i++)
        takahashi = (takahashi + rate[i]) / 2;

    printf("%lf\n", takahashi);

    return 0;
}

