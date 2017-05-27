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
    int     i, j, l, m;
    int     x,y;
    int     ans = 0;
    int     ab;

    cin >> r >> c >> k;
    char    s[r][c];
    char    xx[r][c];

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            cin >> s[i][j];

    // 必要な部分のみ'o'クリア
    for ( i = k - 1; i < r - k + 1; i++ )
        for ( j = k - 1; j < c - k + 1; j++ )
            xx[i][j] = 'o';

    for ( i = 0; i < r; i++ ) {
        for ( j = 0; j < c; j++ ) {
            if ( s[i][j] == 'x' ) {
                for ( l = k - 1; l < r - k + 1; l++ ) {
                    for ( m = k - 1; m < c - k + 1; m++ ) {
                        ab = abs(l - i) + abs(m - j);
                        if ( ab <= k-1 )
                            xx[l][m] = 'x';
                        else {
                            // 各種スキップ
                            if ( j < m )
                                break;
                            if ( abs(j - m) > (k-1) )
                                m += abs(j-m) - k;
                        }
                    }
                }
            }
        }
    }

    for ( x = k - 1; x < r - k + 1; x++ ) {
        for ( y = k - 1; y < c - k + 1; y++ ) {
            if ( xx[x][y] == 'o' )
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
