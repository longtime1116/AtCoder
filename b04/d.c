#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int count(
    int     n)
{
    if ( n % 2 != 0 )
        return ( n*n - 1 ) / 4;
    else
        return n * n / 4;
}

int main (void)
{
    int     r, g, b;
    int     ans = 0;

    cin >> r >> g >> b;
    ans += count(r);
    ans += count(g);
    ans += count(b);

    cout << ans << endl;

    return 0;
}
