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

    lli x = n;
    lli keta =0;
    while (x != 0) {
        x = x / 10;
        keta++;
    }
    lli ans = 0;
    for (lli i = keta; i >= 1; i--) {
        if (i % 2 == 1) {
            if (i == keta) {
                ans += n - pow(10, (i-1)) + 1;
                //cout << "1added: " << n - 10*(i-1) + 1 << endl;
            }
            else {
                ans += 9*pow(10, i-1);

                //cout << "2added: " << 9*i << endl;
            }

        }
    }
    cout << ans<<endl;
}