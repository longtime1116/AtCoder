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
    lli n;
    cin1(n);
    lli a[n];
    lli max_val = -LLONG_MAX;
    lli min_val = LLONG_MAX;
    lli max_i, min_i;
    REP(i,0,n) {
        cin >> a[i];
        if (max_val < a[i]) {
            max_val = max(max_val, a[i]);
            max_i = i;
        }
        if (min_val > a[i]) {
            min_val = min(min_val, a[i]);
            min_i = i;
        }
    }
    vector<P> ans;
    if (abs(max_val) > abs(min_val)) {
        // 正に変えていく
        REP(i,0,n) {
            a[i] += max_val;
            ans.push_back(P(max_i+1, i+1));
        }
        // 左から順に、足しこんでいく
        REP(i,1,n) {
            a[i] += a[i-1];
            ans.push_back(P(i, i+1));
        }
    }
    else {
        REP(i,0,n) {
            a[i] += min_val;
            ans.push_back(P(min_i+1, i+1));
        }
        // 右から順に、足しこんでいく
        REPE_R(i,n-2,0) {
            a[i] += a[i+1];
            ans.push_back(P(i+2, i+1));
        }
    }
    cout << ans.size() << endl;
    REP(i,0,ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}


// 1 8 2 3 1
// 1 8 10 3 1
// 1 8 10 13 1
// 1 8 10 13 14
//
// 2 1 3 2 1
// 2 3 3 2 1
// 2 3 6 2 1
// 2 3 6 8 1
// 2 3 6 8 9
//
//
// 絶対値が一番大きいのは正 => 正にする(高々n-1回)
// -2 5 -1
// 3 5 -1
// 3 5 4
// 3 5 9
//
//
//
// -50 -1 -100 5 -200
// -50 -1 -100 -195 -200
// -546 -496 -495 -395 -200
// まず正負をそろえ、次に正なら左から、負なら右からやっていく
