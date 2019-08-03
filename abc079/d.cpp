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

lli dp[11][11]; // k 個分用意しなくても上書きしてけば良いので、dp[i][j]のみ用意
#define INF (LLONG_MAX / 3);

int main() {
    lli h, w;
    cin2(h, w);
    REP(i, 0, 10) {
        REP(j, 0, 10) {
            lli c;
            cin >> c;
            dp[i][j] = c;
        }
    }
    // 初期化
    REPE(i, 0, 9) {
        REPE(j, 0, 9) {
            if (dp[i][j])
                continue;
            if (i == j)
                continue;
            dp[i][j] = INF;
        }
    }
    REPE(k, 0, 9) {
        REPE(i, 0, 9) {
            REPE(j, 0, 9) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    lli ans = 0;
    lli a[h][w];
    REP(i, 0, h) {
        REP(j, 0, w) {
            cin >> a[i][j];
            if (a[i][j] == -1)
                continue;
            ans +=  dp[a[i][j]][1];
        }
    }
    cout << ans << endl;
}
