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
    lli b[n];
    lli c[n];
    ncin1(n,a);
    ncin1(n,b);
    ncin1(n,c);

    sort(a, a+n);
    sort(b, b+n);
    sort(c, c+n);

    lli b_c[n];
    // まずbをすべて走査し、それぞれの値についてcが何個使えるかを計算する。O(nlogn)
    // そこから累積和の配列の形にできる
    // あとは、aのそれぞれについて二分探索でbのどの部分に当てはまるか見て、累積和のところからO(1)でとってくる(O(nlogn))
    REP(i,0,n) {
        auto it = upper_bound(c, c+n, b[i]);
        b_c[i] = n-(it-c);
        //cout2(i, b_c[i]);
    }
    lli b_c_sum[n] = {0};
    b_c_sum[n-1] = b_c[n-1];
    REPE_R(i,n-2,0) {
        b_c_sum[i] = b_c_sum[i+1] + b_c[i];
    }
    REP(i,0,n) {
        //cout2(i, b_c_sum[i]);
    }

    lli ans = 0;
    REP(i,0,n) {
        auto it = upper_bound(b, b+n, a[i]);
        if (it == b+n)
            continue;
        ans += b_c_sum[it-b];
        //cout2(i, b_c[i]);
    }
    cout << ans << endl;
}
