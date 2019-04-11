#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
#define MAX1        (100)
#define MAX2        (100)

#define REP(i, n)   for(i = 0; i < n; i++)

int     n, m;
double  ans = 0;


double expectation(
    int     divisor_num)
{
    if ( divisor_num % 2 == 0 )
        return 0.5;
    else
        return (((double)divisor_num + 1) / 2) / (double)divisor_num;
}

int main (void)
{
    int     i, j;
    cin >> n;
    int     C[n];

    REP(i, n) {
        cin >> C[i];
    }

    REP(i, n) {
        int divisor_num = 0;
        REP(j, n) {
            if (C[i] % C[j] == 0)
                divisor_num++;
        }
        ans += expectation(divisor_num);
    }
    printf("%0.20lf\n", ans);

    return 0;
}
