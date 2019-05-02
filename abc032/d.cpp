#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

lli dp[2][200001];

int main() {
    lli N, W;
    cin >> N >> W;
    lli v[N];
    lli w[N];
    lli max_v = 0;
    lli max_w = 0;
    lli ans = 0;
    REP(i, N) {
        cin >> v[i] >> w[i];
        max_v = max(max_v, v[i]);
        max_w = max(max_w, w[i]);
    }
    if (max_w <= 1000) {
        // w が 1 <= w <= 1000 を満たすときは、重さの総和は MAX 200000 なので、dp でいける
        // dp[i][j]: i 個目まで使える条件のもと 重さの総和を j 以下に抑えるときの最大の価値
        bool pos = false;
        for(int i=0;i<N;i++){
            REP(j, W+1) {
                if (j-w[i]>=0)
                    dp[!pos][j] = max(dp[pos][j], (dp[pos][j-w[i]] + v[i]));
                else
                    dp[!pos][j] = dp[pos][j];
            }
            pos = !pos;
        }
        ans = dp[pos][W];
    }
    else if (max_v <= 1000) {
        // v が 1 <= v <= 1000 を満たすときは、価値の総和は 200000 なので、dp でいける
    }
    else {
        // N <= 30 の条件のみなので、dp はきつい

    }

    cout << ans << endl;
}
