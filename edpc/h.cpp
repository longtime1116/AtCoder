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

// dp[i][j] := i行j列目に到達するときの経路の総数 % mod
lli dp[1002][1002];
lli mod = 1e9+7;


inline lli add(lli x, lli y) {
    return (x + y) % mod;
}

int main() {
    lli h,w;
    cin2(h,w);
    char a[h+2][w+2];
    REPE(i,1,h) {
        REPE(j,1,w) {
            cin >> a[i][j];
        }
    }
    dp[h+1][w] = 1;
    a[h+1][w] = '.';
    a[h][w+1] = '#';
    REPE_R(i,h,1) {
        REPE_R(j,w,1) {
            if (a[i][j] != '.')
                continue;
            if (a[i+1][j] == '.')
                dp[i][j] = add(dp[i][j], dp[i+1][j]);
            if (a[i][j+1] == '.')
                dp[i][j] = add(dp[i][j], dp[i][j+1]);
        }
    }
    //REPE(i,1,h) {
    //    REPE(j,1,w) {
    //        cout << dp[i][j];
    //    }
    //    cout << endl;
    //}
    cout << dp[1][1]<<endl;
}
