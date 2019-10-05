#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,from, to) for(lli i=from;i<to;i++)
#define REPE(i,from, to) for(lli i=from;i<=to;i++)
#define REP_R(i,from, to) for(lli i=from;i>to;i--)
#define REPE_R(i,from, to) for(lli i=from;i>=to;i--)
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

// dp[i][j] := i人目までで j 個残っているときの通り数の累積和
// dp[1][0] = min(a[1], 1)          # 0
// dp[1][1] = min(a[1], 2)          # 0
// dp[1][2] = min(a[1], 3)          # 0
// dp[1][3] = min(a[1], 4)          # 1
// dp[1][4] = min(a[1], 5)          # 2
//
// dp[2][0] = dp[1][2] - dp[1][-1]  # 0
// dp[2][1] = dp[1][3] - dp[1][0]   # 0
// dp[2][2] = dp[1][4] - dp[1][1]   # 2
// dp[2][3] = dp[1][4] - dp[1][2]   # 2
// dp[2][4] = dp[1][4] - dp[1][3]   # 1
//
// dp[3][0] = dp[2][3]              # 2
// dp[3][1] = dp[2][4] - dp[2][0]   # 1
// dp[3][2] = dp[2][4] - dp[2][1]   # 1
// dp[3][3] = dp[2][4] - dp[2][2]   # -1
// dp[3][4] = dp[2][4] - dp[2][3]   # -1
unsigned long long int dp[101][100001];
int main() {
    lli n, k;
    cin2(n, k);
    lli a[n+1] = {0};
    REP(i,0,n) {
        cin >> a[i+1];
    }

    REPE(j,0,k) {
        if (j >= k - a[1]) {
            if (j == 0)
                dp[1][j] = 1;
            else
                dp[1][j] = dp[1][j-1] + 1;
        }
        //cout1(dp[1][j]);
    }
    REPE(i,2,n) {
        REPE(j,0,k) {
            if (j == 0) {
                dp[i][j] = dp[i-1][min(j+a[i], k)];
            }
            else {
                dp[i][j] = (dp[i][j-1] + ((dp[i-1][min(j+a[i],k)]+1000000007 - dp[i-1][j-1]) % 1000000007)) % 1000000007;
            }
            //cout3(i,j,dp[i][j])
        }
    }
    cout << dp[n][0] << endl;
}
