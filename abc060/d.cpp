#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

// input
#define cin1(x)             cin >> x
#define cin2(x, y)          cin >> x >> y
#define cin3(x, y, z)       cin >> x >> y >> z
#define ncin1(n, x)         REP(i, 0, n) {cin1(x[i]);}
#define ncin2(n, x, y)      REP(i, 0, n) {cin2(x[i], y[i]);}
#define ncin3(n, x, y, z)   REP(i, 0, n) {cin3(x[i], y[i], z[i]);}

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

lli dp[101][101][301]; // dp[i][j][k]: i 個目まで使える状態で、j 個使って重さ k を満たす最大の価値

int main() {
    lli n, W;
    cin2(n, W);
    lli w[n], v[n];
    REP(i, 0, n) {
        cin >> w[i] >> v[i];
    }
    lli w0 = w[0];
    REP(i, 0, n) {
        w[i] -= w0;
    }

    REPE(i, 1, n) {
        REPE(j, 1, i) {
            REPE(k, 0, 3*n) {
                if (k-w[i-1] < 0) {
                    dp[i][j][k] = dp[i-1][j][k];
                }
                else {
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-1][k-w[i-1]] + v[i-1]);
                }
                //cout << "dp[" << i << "][" << j << "][" << k << "]: " << dp[i][j][k]  << endl;
            }
        }
    }
    lli ans = 0;
    REPE(j, 1, n) {
        REPE(k, 0, 3*n) {
            if (j*w0 + k > W)
                continue;
            //cout << "dp[" << n << "][" << j << "][" << k << "]: " << dp[n][j][k]  << endl;
            ans = max(ans, dp[n][j][k]);
        }
    }

    cout << ans << endl;
}
