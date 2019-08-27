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
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;


#define mod (1000000007)

int main() {
    lli n, k;
    cin2(n, k);
    lli a[n];
    ncin1(n, a);

    // 内部のやつを出す
    // i 個目
    lli ans1 = 0;
    REP(i, 0, n) {
        REP(j, i+1, n) {
            if (a[i] > a[j])
                ans1++;
            if (ans1 >= mod)
                ans1 = ans1 % mod;
        }
    }
    //cout1(ans1);

    lli ans2 = 0;
    // 次のやつとのやつを出す
    REP(i, 0, n) {
        REP(j, 0, n) {
            if (a[i] > a[j])
                ans2++;
            if (ans2 >= mod)
                ans2 = ans2 % mod;
        }
    }

    //cout1(ans2);
    lli x = (ans1 * k) % mod;
    lli y = (ans2 * ((k * (k-1) / 2) % mod)) % mod;
    //cout1(x);
    //cout1(y);
    cout << (x + y) % mod << endl;
}
