#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main (void)
{
    int     r, c, k;
    int     i, j;
    int     x,y;
    int     ans = 0;

    cin >> r >> c >> k;
    char    s[r];

    for (i = 0; i < r; i++)
        cin >> s[i];

    for ( x = k; x < r-k+1; x++ )
        for (y = k; y < r-k+1; y++)
        {
            bool result = true;
            for (i = 0; i < r+1; i++)
                for (j = 0; j < c+1; j++)
                    if ( abs(i - x) + abs(j - y) <= k-1 )
                        if ( s[i][j] != '×' )
                            result = false;
            if ( result == true )
                ans++;
        }

    cout << ans << endl;

    cout << s[1][1] << endl;
    

    return 0;
}
