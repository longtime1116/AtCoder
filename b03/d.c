#include <algorithm>                                                                                                                                           
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
#define MAX1        (100)
#define MAX2        (100)

#define MP          make_pair

#define REP(i, n)   for(int i = 0; i < n; i++)
#define DIVISOR (1000000007)

typedef long long ll;


ll comb(
    int     n,
    int     r)
{
    // nCr を返す。
    ll     tpas[n+1];
    ll     tmp[n+1];

    memset(tpas, 0, sizeof(tpas));
    memset(tmp, 0, sizeof(tmp));

    REP(i, n+1) {
        REP(j, i+1) {
            if ( j == 0 )
                tmp[j] = 1;
            else
                tmp[j] = (tpas[j-1] + tpas[j]) % DIVISOR;
        }
        REP(j, i+1) {
            tpas[j] = tmp[j];
        }
    }
    return tpas[r];
}

long long factorial_apart(
    long long   n,
    long long   r)
{
    long long   mult = 1;
    long long   i;
    for ( i = 0; i < r; i++ )
        mult *= n - i;

    return mult;
}

long long factorial(
    long long   n)
{
    long long   mult = 1;
    while ( n != 0 )
    {
        mult *= n;
        n--;
    }

    return mult;
}


long long combination(
    long long   n,
    long long   r)
{
    return factorial_apart(n, r) / factorial(r);
}


int main (void)
{
    long long   r, c, x, y, d, l;
    long long   aloc, com;
    long long   pattern;
    long long   smaller;

    cin >> r >> c;
    cin >> x >> y;
    cin >> d >> l;

    if (d < l)
        smaller = d;
    else
        smaller = l;

    aloc = ((r -x + 1) * (c - y + 1)) % DIVISOR;
//    com = (combination(d + l, smaller)) % DIVISOR;
    com = comb(d+l, smaller) * comb(x*y, d+l);
    pattern = (aloc * com) % DIVISOR;
        cout << pattern << endl;

    return 0;
}

