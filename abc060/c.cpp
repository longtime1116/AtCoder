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
    lli n, T;
    cin2(n, T);
    lli t[n+1];
    ncin1(n, t);
    t[n] = t[n-1] + T;

    lli ans = 0;
    //lli start_time = 0;
    //bool flowing = false;
    //REP(i, 0, n) {
    //    lli cur = t[i];
    //    lli finish_time = t[i] + T;
    //    lli next = t[i+1];
    //    if (!flowing) {
    //        flowing = true;
    //        start_time = cur;
    //    }
    //    if (next >=  finish_time) {
    //        ans += finish_time - start_time;
    //        flowing = false;
    //    }
    //}


    REP(i, 0, n) {
        ans += min(t[i+1]-t[i], T);
    }

    cout << ans << endl;

}
