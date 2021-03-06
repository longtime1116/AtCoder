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

// dp[k][i][j]: k 個目までを中間地点として使って良いとしたときの、iとjの最短距離
//              たどり着けないときはINF、i==jならば0が入る
//              kを0から|V|まで回せば、全ての点を中間地点として使う場合の全点間最短距離が
//              算出されていることになる
lli dp[301][301]; // k 個分用意しなくても上書きしてけば良いので、dp[i][j]のみ用意
lli dp2[301][301]; // 最短経路が l 以下になっている場合に1の辺を貼るグラフ

#define INF (LLONG_MAX / 3)

int main() {
    lli n,m,l;
    cin3(n,m,l);
    lli a[m],b[m],c[m];
    ncin3(m,a,b,c);
    lli q;
    cin1(q);
    lli s[q];
    lli t[q];
    ncin2(q,s,t);

    REP(i, 0, m) {
        if (c[i] <= l)
            dp[a[i]][b[i]] = dp[b[i]][a[i]] = c[i];
    }
    // 初期化
    REPE(i, 1, n) {
        REPE(j, 1, n) {
            if (dp[i][j])
                continue;
            if (i == j)
                continue;
            dp[i][j] = INF;
            dp2[i][j] = INF;
        }
    }

    REPE(k, 1, n) {
        REPE(i, 1, n) {
            REPE(j, 1, n) {
                dp[j][i] = dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    REPE(i,1,n) {
        REPE(j,i+1,n) {
            if (dp[i][j] <= l) {
                dp2[j][i] = dp2[i][j] = 1;
            }
            //cout3(i,j,dp[i][j]);
        }
    }
    REPE(k, 1, n) {
        REPE(i, 1, n) {
            REPE(j, 1, n) {
                dp2[j][i] = dp2[i][j] = min(dp2[i][j], dp2[i][k]+dp2[k][j]);
            }
        }
    }
    REP(i,0,q) {
        if (dp[s[i]][t[i]] == INF)
            cout << -1 << endl;
        else
            cout << dp2[s[i]][t[i]]-1 << endl;
    }

}
