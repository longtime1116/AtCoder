#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
using namespace std;
#define MAX1        (100)
#define MAX2        (100)

#define MP          make_pair

#define REP(i, n)   for(i = 0; i < n; i++)

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
typedef long long ll;



int     W, H, N;
int     X[30], Y[30];
map<ppp, ll> m;

int dfs(int i, int j, int k, int l)
{
    int I;
    ppp p = MP(MP(i, j), MP(k, l));
    // 既にこの領域の最適解が存在したらそれを返す
    if ( m.find(p) != m.end() )
        return m[p];

    // 最適解の算出
    ll ans = 0;
    REP(I, N) {
        if ( !(X[I] >= i && Y[I] >= j && X[I] <= k && Y[I] <= l) )
            continue;
        ll x = (k - i + 1) + (l - j + 1) - 1;

        x += dfs(i, Y[I] + 1, X[I] - 1, l);     // 左上領域
        x += dfs(i, j, X[I] - 1, Y[I] - 1);     // 左下領域
        x += dfs(X[I] + 1, Y[I] + 1, k, l);     // 右上領域
        x += dfs(X[I] + 1, j, k, Y[I] - 1);     // 右下領域
        ans = max(ans, x);
    }

    return m[p] = ans;
}






int main (void)
{
    int     i, j;
    cin >> W >> H;
    cin >> N;

    REP(i, N) {
        cin >> X[i] >> Y[i];
    }
    cout << dfs(1, 1, W, H) << endl;


    return 0;
}
