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


// cur 桁目を決める(i>=0)
lli rec(lli n, lli &ans, lli cur, lli val, bool ok_3, bool ok_5, bool ok_7) {
    if (ok_3 && ok_5 && ok_7) {
        //cout3(ans, cur, val);
        ans++;
    }
    lli next;
    // cur 桁目が3
    next = val + 3*pow(10, cur);
    if (next > n) {
        return ans;
    }
    rec(n, ans, cur+1, next, true, ok_5, ok_7);

    // cur 桁目が5
    next = val + 5*pow(10, cur);
    if (next > n) {
        return ans;
    }
    rec(n, ans, cur+1, next, ok_3, true, ok_7);

    // cur 桁目が7
    next = val + 7*pow(10, cur);
    if (next > n) {
        return ans;
    }
    rec(n, ans, cur+1, next, ok_3, ok_5, true);
    return ans;
}

int main() {
    lli n;
    cin1(n);
    lli ans = 0;

    cout << rec(n, ans, 0, 0, false, false, false) << endl;
}
