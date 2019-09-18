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


// dp[i][j]: i文字目からの文字とj文字目からの文字の最長の重なり
lli dp[5001][5001];

int main() {
    lli n;
    string s;
    cin1(n);
    cin1(s);
    REPE(i,0,n-2) {
        if (s[n-1] == s[i]) {
            dp[n-1][i] = 1;
        }
    }
    for (lli i = n-2; i >= 0; i--) {
        for (lli j = i-1; j >= 0; j--) {
            if (s[i] == s[j]) {
                dp[i][j] = min(i - j, dp[i+1][j+1] + 1);

            }
        }
    }
    lli ans = 0;
    for (lli i = n-2; i >= 0; i--) {
        for (lli j = i-1; j >= 0; j--) {
            //cout2(i,j);
            //cout1(dp[i][j]);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}
