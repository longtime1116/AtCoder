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
    lli a1[n];
    lli a2[n];
    ncin1(n, a1);
    ncin1(n, a2);

    lli total[n] = {0};

    REP(i, 0, n) {
        // i 列目を足す
        REP(j, 0, n) {
            // j 列目で下に落ちているやつ
            if (i < j) {
                total[j] += a1[i];
            }
            else if (i == j) {
                total[j] += a1[i] + a2[i];
            }
            else {
                total[j] += a2[i];
            }
        }
    }

    lli ans = 0;
    REP(i,0,n) {
        ans = max(ans, total[i]);
    }
    cout << ans << endl;
}

// a,b,cで12分
