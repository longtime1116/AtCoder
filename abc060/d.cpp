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

lli dp[101][101][401]; // dp[i][j][k]: i 個目まで使える状態で、j 個使って重さ k を満たす最大の価値

int main() {
    lli n, W;
    cin2(n, W);
    lli w[n], v[n];
    REP(i, 0, n) {
        cin >> w[i] >> v[i];
    }
    lli w_diff = w[0] - 1;
    REP(i, 0, n) {
        w[i] -= w_diff;
    }
    cout << "hoge" << endl;

    lli ans = 0;
    REPE(use_count, 1, n) {
        lli cur_w = W - w_diff*use_count;
        if (cur_w < 0)
            break;
        REPE(i, 1, n) {
            REPE(j, 1, use_count) {
                REPE(k, 0, 400) {
                    if (k-w[i-1] < 0) {
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                    else {
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-1][k-w[i-1]] + v[i-1]);
                    }
                    cout << "dp[" << i << "][" << j << "][" << k << "]: " << dp[i][j][k]  << endl;
                }
            }
        }
        // 評価
        REPE(i, 0, n) {
            REPE(j, 0, n) {
                REP(k, 0, 401) {
                    ans = max(ans, dp[i][j][k]);
                    dp[i][j][k] = 0;
                }
            }
        }
    }
//dp[3][3][3]: 4
//dp[3][3][4]: 4
//dp[3][3][5]: 4
//dp[3][3][6]: 4
//dp[3][3][7]: 14
//dp[3][3][8]: 14
//dp[3][3][9]: 14
//dp[3][3][10]: 18
//dp[3][3][11]: 18
//dp[3][3][12]: 18

    //REPE(i, 1, n) {
    //    REPE(j, 1, i) {
    //        REPE(k, 0, 10) {
    //            cout << "dp[" << i << "][" << j << "][" << k << "]: " << dp[i][j][k]  << endl;
    //        }
    //    }
    //}

    cout << ans << endl;
}


//4 6
//2 1
//3 4
//4 10
//3 4
//
//
//
//5 => 5
//6 => 11
//5 => 5
//9 => 15
//
//4 6
//1 1
//2 4
//3 10
//2 4
//
//3 => 5
//4 => 11
//3 => 5
//6 => 15
//
//
//
//
