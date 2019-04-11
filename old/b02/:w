#include <algorithm>
#include <stdio.h>
#include <string.h>
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



int     N, M, ans, g[11][11];

map<ppp, ll> m;



int dfs(
    vector<int> v,
    int         k)
{
    if ( k == N ) {
        // v に入っている node 同士が完全に知り合いかどうかをチェック
        ans = max(ans, size(v));
    }
    else {
        dfs(v, k+1)
        v.push_back(k);
        dfs(v, k+1);
        v.pop_back(k);
    }
    return ans;
}

int main (void)
{
    vector<int> v;
    int i, x, y;
    cin >> N >> M;
    REP(i, M) {
        cin >> x >> y;
        x--;
        y--;
        g[x][y] = g[y][x] = 1;
    }

    cout << dfs(v, 0) << endl;

    return 0;
}
