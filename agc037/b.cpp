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

#define MOD (998244353)


lli mul(lli a, lli b) {
    return a * b % MOD;
}

int main() {
    lli n;
    cin1(n);
    string s;
    cin1(s);

    lli ans = 1;

    lli r, b, g, rb, rg, bg;
    r = b = g = rb = rg = bg = 0;
    REP(i, 0, 3*n) {
        if (s[i] == 'R') {
            if (bg > 0) {
                ans = mul(ans, bg);
                bg--;
            }
            else if (b > 0) {
                ans = mul(ans, b);
                rb++;
                b--;
            }
            else if (g > 0) {
                ans = mul(ans, g);
                rg++;
                g--;
            }
            else {
                r++;
            }
        }
        else if (s[i] == 'B') {
            if (rg > 0) {
                ans = mul(ans, rg);
                rg--;
            }
            else if (r > 0) {
                ans = mul(ans, r);
                rb++;
                r--;
            }
            else if (g > 0) {
                ans = mul(ans, g);
                bg++;
                g--;
            }
            else {
                b++;
            }
        }

        else if (s[i] == 'G') {
            if (rb > 0) {
                ans = mul(ans, rb);
                rb--;
            }
            else if (r > 0) {
                ans = mul(ans, r);
                rg++;
                r--;
            }
            else if (b > 0) {
                ans = mul(ans, b);
                bg++;
                b--;
            }
            else {
                g++;
            }
        }
    }
    REPE(i, 1, n) {
        ans = mul(ans, i);
    }
    cout << ans << endl;
}
