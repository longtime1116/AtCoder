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
    lli h[n];
    ncin1(n, h);

    if (n == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    else if (n == 2) {
        if (h[0] - h[1] >= 2) {
            cout << "No" << endl;
        }
        else
            cout << "Yes" << endl;
        return 0;
    }
    REPE(i, 1, n-2) {
        lli prev = h[i-1];
        lli cur = h[i];
        lli next = h[i+1];
        if (prev < cur) {
            h[i] -= 1;
            cur -= 1;
        }
        if (cur  > next) {
            //cout1(i);
            //cout1(prev);
            //cout1(cur);
            //cout1(next);
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
