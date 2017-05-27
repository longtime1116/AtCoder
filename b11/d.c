#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
#define MAX1        (100)
#define MAX2        (100)

#define MP          make_pair

#define REP(i, n)   for(i = 0; i < n; i++)

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
typedef long long ll;


int     N;
ll      D, X, Y;
int     dp[61][61][61];

int dfs(
    int  nowN,
    int  nowX,
    int  nowY)
{
    int count = 0;
    if ( nowN == 0 && nowX == (int)X && nowY == (int)Y )
        return 1;
    if ( nowN == 0 )
        return 0;

    if ( dp[nowN+30][nowX+30][nowY+30] != 0 )
        return dp[nowN+30][nowX+30][nowY+30];

    // 4 方向に向かう
    count += dfs(nowN-1, nowX-1, nowY);
    count += dfs(nowN-1, nowX+1, nowY);
    count += dfs(nowN-1, nowX, nowY-1);
    count += dfs(nowN-1, nowX, nowY+1);

    dp[nowN+30][nowX+30][nowY+30] = count;

    return count;
}


int main (void)
{
    int     nowX = 0, nowY = 0;
    int     count;
    cin >> N >> D >> X >> Y;

    if ( X % D == 0 && Y % D == 0 ) {
        X /= D;
        Y /= D;

        count = dfs(N, nowX, nowY);
    }
    else {
        count = 0;
    }
    printf("%8f\n", (double)count / pow(4.0, N));


    return 0;
}
