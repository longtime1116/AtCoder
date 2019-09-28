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

// dp[i] := i のときの期待値
//          ただし、iは状態をbitで表す整数
//double dp[2^17];



int state[18];
// dp[i][j][k] := 前後含む3マスに何個ボールがあるのか、i,j,kをそれぞれ1,2,3個として、そのときの期待値
double dp[18][18][18];

int main() {
    lli n;
    cin1(n);
    lli x[n];
    // x[i] は 1〜16 の値をとるとする
    REP(i,0,n) {
        cin >> x[i];
        x[i]++;
    }
    //sort(x, x+n);
    // x
    // 1,3,7,8,9,10
    // 入力自体は、0,2,6,7,8,9

    REP(i,0,n) {
        state[x[i]-1]++;
        state[x[i]]++;
        state[x[i]+1]++;
    }
    queue<int> que1;
    queue<int> que2;
    queue<int> que3;
    REP(i,0,18) {
        cout2(i, state[i]);
        if (state[i] == 1)
            que1.push(i);
        else if (state[i] == 2)
            que2.push(i);
        else if (state[i] == 3)
            que3.push(i);
    }
    double ans = 0;
    cout << ans << endl;
}
