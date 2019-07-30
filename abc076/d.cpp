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

int main() {
    lli n;
    cin1(n);
    lli t[n+2], v[n+2];
    REPE(i, 1, n) {
        cin >> t[i];
    }
    REPE(i, 1, n) {
        cin >> v[i];
    }
    t[0] = 0;
    v[0] = v[n+1] = 0;
    t[n+1] = LLONG_MAX; // 使わない
    double ans = 0;
    REPE(i, 1, n) {
        if (v[i] < v[i+1]) {
            if (v[i-1] + t[i] < v[i]) {
                double h = v[i-1] + t[i];
                ans += (v[i-1] + h) * t[i] / 2.0;
            }
            else {
                ans += t[i] * v[i];
                // 加速するなら、その分を引く
                ans -= (v[i]-v[i-1]) * (v[i]-v[i-1]) / 2.0;

            }
        }
        else {
            //cout << "a" << endl;
            if (t[i] < (v[i]-v[i-1]+v[i]-v[i+1])) {
                //cout << "b" << endl;
                double x;
                x = (t[i] - v[i-1]) / 2.0;

                double h = v[i-1] + x;
                ans += (v[i-1]+h) * x / 2.0;
                ans += h * (t[i]-x) / 2.0;
            }
            else {
                //cout << "c" << endl;
                ans += t[i] * v[i];
                // 加速するなら、その分を引く
                if (v[i-1] < v[i])
                    ans -= (v[i]-v[i-1]) * (v[i]-v[i-1]) / 2.0;
                // 減速するなら、その分を引く
                // TODO: これ、入力例3のときにおかしそう
                if (v[i+1] < v[i])
                    ans -= (v[i]-v[i+1]) * (v[i]-v[i+1]) / 2.0;
            }
        }
    }
    cout << fixed <<  ans << endl;
}
