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


lli t[200001];

int main() {
    lli n;
    cin1(n);
    lli a[n+1];
    REPE(i, 1, n) {
        cin >> a[i];
    }

    for (lli i = n; i >= 1; i--) {

        lli x = i / n;
        lli count = 0;
        for (lli j = i+i; j <= n; j += i) {
            count += t[j];
        }
        if (a[i] == 1) {
            if (count % 2 == 0)
                t[i] = 1;
        }
        else {
            if (count % 2 == 1)
                t[i] = 1;
        }
    }
    lli ans = 0;
    REPE(i, 1, n) {
        if (t[i] > 0)
            ans++;
    }
    cout << ans << endl;
    if (ans == 0)
        return 0;

    REPE(i, 1, n) {
        if (t[i] > 0)
            cout << i << " ";
    }
    cout << endl;
}


