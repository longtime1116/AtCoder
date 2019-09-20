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


// dp[i][j] := sのi文字目までとtのj文字目までの状態での最長部分列長
lli dp[3001][3001];

int main() {
    string s, t;
    cin2(s, t);
    lli slen = s.length();
    lli tlen = t.length();

    s = "#" + s;
    t = "." + t;
    lli ans = 0;
    REPE(i,1,slen) {
        REPE(j,1,tlen) {
            if (s[i] == t[j]) {
                //dp[i][j] = max(dp[i-1][j-1], dp[i][j-1]) + 1;
                dp[i][j] = dp[i-1][j-1] + 1;
                //cout << "if" << endl;
                //cout2(i,j);
                //cout1(dp[i][j])
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                //dp[i][j] = dp[i][j-1];
                //dp[i][j] = dp[i-1][j-1];
                //cout << "else" << endl;
                //cout2(i,j);
                //cout1(dp[i][j])
            }
        }
    }
    //REP(i,0,slen) {
    //    REP(j,0,tlen) {
    //        cout2(i,j);
    //        cout1(dp[i][j]);
    //    }
    //}
    cout << dp[slen][tlen] << endl;
}


//abracadabra
//avadakedavra
//
//111111111111
//111111111111
//111111111122
//112222222222
//
//
