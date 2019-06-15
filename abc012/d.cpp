#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

lli dp[301][301];
#define INF (LLONG_MAX / 3);

int main() {
    lli n, m;
    cin >> n >> m;
    REP(i, 0, m) {
        lli from, to, cost;
        cin >> from >> to >> cost;
        dp[from][to] = dp[to][from] = cost;
    }

    // 初期化
    REPE(i, 1, n) {
        REPE(j, 1, n) {
            if (dp[i][j])
                continue;
            if (i == j)
                continue;
            dp[i][j] = INF;
        }
    }

    REPE(k, 1, n) {
        REPE(i, 1, n) {
            REPE(j, 1, n) {
                dp[j][i] = dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    // dump
    // cout << endl;
    // REPE(i, 1, n) {
    //     REPE(j, 1, n) {
    //         cout << i << "-" << j << ": " << dp[i][j] << endl;
    //     }
    //     cout << endl;
    // }

    lli ans = INF;
    REPE(i, 1, n) {
        lli rep = 0;
        REPE(j, 1, n) {
            rep = max(rep, dp[i][j]);
        }
        ans = min(ans, rep);
    }
    cout << ans << endl;
}
