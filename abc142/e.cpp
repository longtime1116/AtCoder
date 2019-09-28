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



// dp[i][j] := i個目までの鍵で、状態jを叶える最小のコスト
//            状態jとは、x桁目はx個目の宝箱を開けられるか？というやつ
lli dp[1001][4096];

int main() {
    lli n,m;
    cin2(n,m);
    lli a[m], b[m];
    vector<lli> c[m];
    REP(i,0,m) {
        cin >> a[i] >> b[i];
        REP(j,0,b[i]) {
            lli cx;
            cin >> cx;
            c[i].push_back(cx);
        }
    }
    int inf = 10000000;
    REP(i,0,1001) {
        REP(j,0,4096) {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    REP(item,0,m) {
        // この item がもたらす効果を bit で表す
        lli item_bit = 0;
        REP(i,0,b[item]) {
            item_bit |= (1<<(c[item][i]-1));
        }
        //cout1(item_bit);

        // この bit をすべての状態に or 演算していく
        REPE(i,0,(1<<(n))-1) {
            dp[item+1][i] = min(dp[item+1][i], dp[item][i]);
            dp[item+1][i|item_bit] = min({
                    dp[item+1][i|item_bit],
                    dp[item][i|item_bit],
                    dp[item][i] + a[item]
                    });
            //cout1(i);
            //cout3(item+1, (i|item_bit), dp[item+1][i|item_bit]);
        }

    }
    if (dp[m][(1<<n)-1] == inf)
        cout << -1 << endl;
    else
        cout << dp[m][(1<<n)-1] << endl;
}
