#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main (void)
{
    int     r, c, k;
    int     i, j;
    int     x,y;
    int     ans = 0;

    cin >> r >> c >> k;
    char    s[r][c];

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            cin >> s[i][j];

    for ( x = k - 1; x < r-k+1; x++ )
    {
        for (y = k - 1; y < c-k+1; y++)
        {
            bool result = true;
            for (i = x - k + 1; i < x + k; i++)
            {
                for (j = y - k + 1; j < y + k; j++)
                {
                    int ab = abs(i - x) + abs(j - y);
                    if ( ab <= k-1 )
                    {
                        if ( s[i][j] == 'x' )
                        {
                            result = false;
                            goto OUT;
                        }
                        if ( ab == k-1 && j >= y )
                        {
                            cout << "asdf" << endl;
                            break;
                        }
                    }
                }
            }
OUT:
            if ( result == true )
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
