#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
#define MAX1        (100)
#define MAX2        (100)

#define REP(i, n)   for(i = 0; i < n; i++)

int     w, n, k;
int     dp[51][10001][51];
int     screen[51][10001];


int main (void)
{
    int     i, j, l = 0, m=0;
    cin >> w >> n >> k;
    int     a[n+1];
    int     b[n+1];


    REP(i, n) {
        cin >> a[i] >> b[i];
    }

    memset(dp, 0, sizeof(dp));

    REP(i, n) {
        REP(j, w+1) {
            if (j < a[i]) {
                l = screen[i][j];
                dp[i+1][j][l] = dp[i][j][l];
                screen[i+1][j] = l;
            }
            else {
                int temp;
                l = screen[i][j];
                m = screen[i][j-a[i]];
                temp = max(dp[i][j][l], dp[i][j - a[i]][m] + b[i]);
                if ( temp != dp[i][j][l] && m <= k ) {
                    screen[i+1][j] = m + 1;
                }
                else {
                    screen[i+1][j] = l;
                }
                dp[i+1][j][screen[i+1][j]] = temp;
            }
        }
    }

    int     max1 = -1;
    for (l = k; l >= 0; l--) {
        REP(i, n+1) {
            REP(j, w+1) {
                max1 = max(max1, dp[i][j][l]);
            }
        }
    }
    cout << max1 << endl;

    return 0;
}
