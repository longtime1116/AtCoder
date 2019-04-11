#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

int main (void)
{
    int     N, p, q;
    int     i, j, k, l, m, n, o;

    cin >> N;
    int     d[N][N];

    for ( i = 0; i < N; i++)
        for ( j = 0; j < N; j++ )
            cin >> d[i][j];

    cin >> q;

    int     max[N*N];
    memset(max, 0, sizeof(max));

    for ( i = 0; i < q; i++ )
    {   // 店員ごと
        cin >> p;
        for ( j = 1; j < p + 1; j++ )
        {
            for ( k = 0; k < j; k++ )
            {
                int     x, y;
                // 因数分解して計算する長方形を x * y で表す
                if ( j % (k + 1) != 0 )
                    continue;
                x = k + 1;
                y = j / x;
                if ( x > N )
                    x = N;
                if ( y > N )
                    y = N;
                for( l = 0; l < N - x + 1; l++ )
                {
                    for ( m = 0; m < N - y + 1; m++ )
                    {   // 長方形の計算
                        int temp = 0;
                        for ( n = l; n < l + x; n++ )
                        {
                            for (o = m; o < m + y; o++)
                            {
                                temp += d[n][o];
                                if ( temp > max[i] )
                                    max[i] = temp;
                            }
                        }
                    }
                }
            }
        }
    }

    for ( i = 0; i < q; i++ )
        cout << max[i] << endl;

    return 0;
}
