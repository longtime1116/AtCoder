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
        // dp[i][j]: i 個目まで使える条件のもと重さの総和を j にするときの最大の価値
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
        // dp[i][j]: i 個目まで使える条件のもと価値の総和を j にするときの最小の重さ
        REP(i, 2) {
            REP(j, 200001) {
                if (j == 0 )
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1000000001;
            }
        }
        bool pos = false;
        for(int i=0;i<N;i++){
            for(lli j=0;j<200001;j++) {
                if (j-v[i]>=0)
                    dp[!pos][j] = min(dp[pos][j], (dp[pos][j-v[i]] + w[i]));
                else
                    dp[!pos][j] = dp[pos][j];

                if (dp[!pos][j] <= W)
                    ans = max(ans, j);
            }
            pos = !pos;
        }
    }
    else {
        // N <= 30 の条件のみなので、dp はきつい

    }

    cout << ans << endl;
}
