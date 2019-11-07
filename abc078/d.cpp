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
typedef vector<lli> vlli;

int main() {
    lli n,z,w;
    cin3(n,z,w);
    lli a[n];
    ncin1(n,a);

    lli b[n];
    lli cur = 0;
    REPE_R(i,n-1,0) {
        cur = max(cur, a[i]);
        b[i] = cur;
    }
    //REP(i,0,n) { cout2(i, b[i]); }

    vlli c;
    c.push_back(b[0]);
    cur = b[0];
    REP(i,1,n) {
        if (cur == b[i])
            continue;
        cur = b[i];
        c.push_back(cur);
    }
    //REP(i,0,c.size()) { cout2(i,c[i]); }

    vlli d;
    REP(i,0,c.size()-1) {
        d.push_back(c[i]-c[i+1]);
    }
    //REP(i,0,d.size()) { cout2(i,d[i]); }



}
// 7 100 100 10 3000 100 2000 10 100 30
// とする。Xがその時点で持っているものをx、Yはyとする
// まず、右から走査して
// 3000 3000 2000 2000 100 100 30
// 圧縮して
// 3000 2000 100 30
// 差の配列
// 1000 1900 70 30-y
//
// 先行は、左から走査して一番でかいものをとる。
//
// これは違いそう。1900を取ってもどうせその後上書きされたら意味がない。結局のところ最後のあたりの勝負になるのではないか？
