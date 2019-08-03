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
    double total = 0;
    REPE(i, 1, n) {
        cin >> t[i];
        total += t[i];
    }
    lli total_t[n+1] = {0};
    REPE(i, 1, n) {
        total_t[i] = t[i] + total_t[i-1];
    }
    REPE(i, 1, n) {
        cin >> v[i];
    }
    v[0] = v[n+1] = 0;
    t[n+1] = LLONG_MAX; // 使わない
    double ans = 0;
    double left, right;
    left = 0;
    REPE(i, 1, n){
        double th1, th2, th3;

        //cout << "i: " << i << endl;
        for (double cur = total_t[i-1]+0.5; cur <= total_t[i]; cur += 0.5) {
            th1 = v[i];
            th2 = th3 = LLONG_MAX;
            REPE(j, 1, n) {
                if (j <= i)
                    th2 = min(th2, v[j-1] + (cur - total_t[j-1]));
                if (j >= i)
                    th3 = min(th3, v[j+1] + (total_t[j] - cur));
            }

            right = min({th1, th2, th3});
            ans += (left + right) * 0.5 * 0.5;
            //cout << "  add: " << (left + right) * 0.5 * 0.5;
            //cout << "  (total: " << ans << ")";
            //cout << "  (right, left): " << right << ", " << left << endl;
            left = right;
        }
    }
    cout << fixed <<  ans << endl;
}
