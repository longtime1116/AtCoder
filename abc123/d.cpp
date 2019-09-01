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
#define cout2(x, y)      cout << #x << ": " << x << ", " << #y << ": " << y << endl;
#define cout3(x, y, z)   cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl;;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;

int main() {
    lli x, y, z, k;
    cin >> x >> y >> z >> k;
    lli a[x];
    lli b[y];
    lli c[z];
    ncin1(x, a);
    ncin1(y, b);
    ncin1(z, c);

    priority_queue<lli> que;
    REP(i, 0, x) {
        REP(j, 0, y) {
            que.push(a[i] + b[j]);
        }
    }

    sort_r(c, c+z);
    priority_queue<lli> que2;
    REP(i, 0, min(k, x*y)) {
        lli x = que.top();
        que.pop();
        REP(j, 0, z) {
            que2.push(x+c[j]);
        }
    }
    REP(i, 0, k) {
        lli x = que2.top();
        cout << x << endl;
        que2.pop();
    }
}
