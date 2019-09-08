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
#define cout2(x, y)      cout << #x << ": " << x << ", " << #y << ": " << y << endl;
#define cout3(x, y, z)   cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl;;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

#define coutp(p)         cout << #p << ":" <<  " (" << p.first << ", " << p.second << ")" << endl;

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;

#define mod (1000000007)


// dp[i][c3][c2][c1] := i 個の文字までで3,2,1個前がそれぞれc3,c2,c1となっているものの個数
lli dp[101][4][4][4];


int main() {
    lli n;
    cin1(n);

    // 0: A
    // 1: C
    // 2: G
    // 3: T
    // 初期化
    REP(c2, 0, 4) {
        REP(c1, 0, 4) {
            REP(c0, 0, 4) {
                if ( (c2 == 0 && c1 == 2 && c0 == 1) || // AGC
                     (c2 == 0 && c1 == 1 && c0 == 2) || // ACG
                     (c2 == 2 && c1 == 0 && c0 == 1) )  // GAC
                    continue;
                dp[3][c2][c1][c0] = 1;
            }
        }
    }

    REPE(i, 4, n) {
        REP(c3, 0, 4) {
            REP(c2, 0, 4) {
                REP(c1, 0, 4) {
                    REP(c0, 0, 4) {
                        // AGC
                        if ( (c2 == 0 && c1 == 2 && c0 == 1) || // AGC
                             (c2 == 0 && c1 == 1 && c0 == 2) || // ACG
                             (c2 == 2 && c1 == 0 && c0 == 1) || // GAC
                             (c3 == 0 && c1 == 2 && c0 == 1) || // A*GC
                             (c3 == 0 && c2 == 2 && c0 == 1))   // AG*C
                            continue;
                        dp[i][c2][c1][c0] = (dp[i][c2][c1][c0] + dp[i-1][c3][c2][c1]) % mod;
                    }
                }
            }
        }
    }

    lli ans = 0;
    REP(c2, 0, 4) {
        REP(c1, 0, 4) {
            REP(c0, 0, 4) {
                ans = (ans + dp[n][c2][c1][c0]) % mod;
            }
        }
    }
    cout << ans << endl;


}
