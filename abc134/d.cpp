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
lli status[200001];

int main() {
    lli n;
    cin1(n);
    lli a[n];
    REPE(i, 1, n) {
        cin >> a[i];
    }
    // 素因数 key が value 個ある、を表す map


    for (lli i = n; i >=1; i--) {
        if (a[n] == 0) {

        }
        map<lli, lli> fac;
        lli num = i;
        for(lli i = 2; i*i<=num; i++) {
            while (num % i == 0) {
                fac[i]++;
                num /= i;
                t[i*fac[i]]++;
            }
        }
        if (num != 1) {
            fac[num] = 1;
            t[num] = 0;
        }
    }
    lli num = 0;
    REPE(i, 1, n) {
        if (t[i] == 1)
            num++;
    }
    cout << num << endl;
    if (num == 0)
        return 0;
    REPE(i, 1, n) {
        if (t[i] == 1)
            cout << i << " ";
    }
    cout << endl;
}
