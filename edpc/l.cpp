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

// dp[i][j] := i個目からj個目までが残っている状態での X-Y
lli dp[3001][3001];
int main() {
    lli n;
    cin1(n);
    lli a[n+2] = {0};
    REP(i,0,n) {
        cin >> a[i+1];
    }

    REPE(i,1,n) {
        if ((n-1) % 2 == 0)
            dp[i][i] = a[i];
        else
            dp[i][i] = -a[i];
    }
    REP(i,1,n) {
        REPE(j,1,n-i) {
            // dp[j][j+i] を求める
            if((n-(i+1)) % 2 == 1) {
                dp[j][j+i] = min(dp[j+1][j+i] - a[j], dp[j][j+i-1] - a[j+i]);
            }
            else {
                dp[j][j+i] = max(dp[j+1][j+i] + a[j], dp[j][j+i-1] + a[j+i]);
            }
        }

    }
    //REPE(i,0,n) {
    //    REPE(j,0,n) {
    //        cout3(i, j, dp[i][j]);
    //    }
    //}
    cout << dp[1][n] << endl;
}
