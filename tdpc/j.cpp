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



double dp[1<<18];

int main() {
    lli n;
    cin1(n);
    lli x[n];
    // x[i] は 1〜16 の値をとるとする
    REP(i,0,n) {
        cin >> x[i];
        x[i]++;
    }
    sort(x, x+n);
    // x
    // 1,3,7,8,9,10
    // 入力自体は、0,2,6,7,8,9

    lli state = 0;
    lli cur = 0;
    REP(i,0,18) {
        state <<= 1;
        if (cur != n && x[cur] == i) {
            state |= 1;
            cur++;
        }
    }

    // 2 0 2 => 010100000000000000 / state: 81920
    //cout << bitset<18>(state) << endl;
    //cout1(state);

    // E[11010] = (E[01010] + E[10010] + E[11010]) / 3 + 1
    // E[11010] = (E[01010] + E[10010] + 3) / 2
    // ↑をよく見ると、左辺は右辺の構成要素よりも必ず大きい値になっている。
    // つまり、値の小さいものから順にやっていけばE[state]が求まりそう
    // 別の言い方をすると、dp が DAG になるのでmaskを0から上げていくことで更新していける

    lli inf = 1<<19;
    REPE(i,1,(1<<18)-1) {
        if ((state & i) != i)
            continue;
        //cout1(i);
        dp[i] = inf;
        REPE(j,1,16) {
            int pat = (i>>(j-1)) & 7;
            //cout1(pat);
            double f1 = dp[i^(1<<(j-1))];
            double f2 = dp[i^(1<<j)];
            double f3 = dp[i^(1<<(j+1))];
            double x = inf;
            if (pat == 0)
                continue;
            else if (pat == 1) {
                 x = (1 + f1/3)*3;
            }
            else if (pat == 2) {
                 x = (1 + f2/3)*3;
            }
            else if (pat == 4) {
                 x = (1 + f3/3)*3;
            }
            else if (pat == 3) {
                 x = (1 + (f1+f2)/3)*1.5;
            }
            else if (pat == 5) {
                 x = (1 + (f1+f3)/3)*1.5;
            }
            else if (pat == 6) {
                 x = (1 + (f2+f3)/3)*1.5;
            }
            else {
                x = 1 + (f1+f2+f3)/3;
            }
            //cout1(dp[i]);
            //cout1(x);
            dp[i] = min(dp[i], x);
        }
    }
    cout <<setprecision(10) << dp[state] << endl;
}
