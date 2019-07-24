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

// output
#define cout1(x)         cout << #x << ": " << x << endl;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

lli dp[301][301]; // k 個分用意しなくても上書きしてけば良いので、dp[i][j]のみ用意
#define INF (LLONG_MAX / 3);


int main() {
    lli N, M, R;
    cin3(N, M, R);
    lli r[8];
    ncin1(R, r);
    REP(i, 0, M) {
        lli from, to, cost;
        cin >> from >> to >> cost;
        dp[from][to] = dp[to][from] = cost;
    }

    // 初期化
    REPE(i, 1, N) {
        REPE(j, 1, N) {
            if (dp[i][j])
                continue;
            if (i == j)
                continue;
            dp[i][j] = INF;
        }
    }

    REPE(k, 1, N) {
        REPE(i, 1, N) {
            REPE(j, 1, N) {
                dp[j][i] = dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    lli ans = LLONG_MAX;
    sort(r, r+R);
    do {
        lli total = 0;
        REP(i, 0, R-1) {
            total += dp[r[i]][r[i+1]];
        }
        ans = min(ans, total);

    } while (next_permutation(r, r+R));
    cout << ans << endl;
    // dump
    //cout << endl;
    //REPE(i, 1, N) {
    //    REPE(j, 1, N) {
    //        cout << i << "-" << j << ": " << dp[i][j] << endl;
    //    }
    //    cout << endl;
    //}
}



