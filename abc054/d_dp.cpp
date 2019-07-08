#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,init, n)          for(lli i=init;i<n;i++)
#define REPE(i,init, n)         for(lli i=init;i<=n;i++)
#define REPIT(it,container)     for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container)   for(auto it = container.rbegin(); it != container.rend(); it++)

#define cin1(x)             cin >> x
#define cin2(x, y)          cin >> x >> y
#define cin3(x, y, z)       cin >> x >> y >> z
#define ncin1(n, x)         REP(i, 0, n) {cin1(x[i]);}
#define ncin2(n, x, y)      REP(i, 0, n) {cin2(x[i], y[i]);}
#define ncin3(n, x, y, z)   REP(i, 0, n) {cin3(x[i], y[i], z[i]);}

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

// dp[i][ag][bg]: i 個目までを使えるときに、ag, bg を実現する最小コスト
lli dp[41][401][401];
lli inf = 100000;

int main() {
    lli n, ma, mb;
    cin3(n, ma, mb);
    lli a[n];
    lli b[n];
    lli c[n];
    ncin3(n, a, b, c);

    REPE(i, 0, 40) {
        REP(ag, 0, 401) {
            REP(bg, 0, 401) {
                dp[i][ag][bg] = inf;
            }
        }
    }
    dp[0][0][0] = 0;

    REPE(i, 1, n) {
        REP(ag, 0, 401) {
            REP(bg, 0, 401) {
                if (ag - a[i-1] < 0 || bg - b[i-1] < 0) {
                    dp[i][ag][bg] = dp[i-1][ag][bg];
                }
                else {
                    dp[i][ag][bg] = min(dp[i-1][ag][bg], dp[i-1][ag-a[i-1]][bg-b[i-1]] + c[i-1]);
                }
            }
        }
    }

    // dump
    // REPE(i, 1, n) {
    //     REP(ag, 1, 401) {
    //         REP(bg, 1, 401) {
    //             if (dp[i][ag][bg] == inf)
    //                 continue;
    //             cout << "dp[" << i << "][" << ag << "][" << bg << "]: " << dp[i][ag][bg] << endl;
    //         }
    //     }
    // }
    lli ans = inf;
    REP(ag, 1, 401) {
        REP(bg, 1, 401) {
            if (bg*ma == ag*mb) {
                ans = min(ans, dp[n][ag][bg]);
            }

        }
    }
    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
