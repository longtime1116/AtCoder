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

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

int main() {
    lli n;
    cin1(n);
    lli a[n*3];
    ncin1(n*3, a);


    lli l_que_total = 0;
    lli r_que_total = 0;
    priority_queue<lli, vector<lli>, greater<lli>> l_que;
    priority_queue<lli> r_que;
    REP(i, 0, n) {
        l_que.push(a[i]);
        l_que_total += a[i];
        r_que.push(a[n*3-1-i]);
        r_que_total += a[n*3-1-i];
    }

    lli l_que_totals[3*n];
    lli r_que_totals[3*n];
    l_que_totals[n-1] = l_que_total;
    r_que_totals[2*n] = r_que_total;
    REP(i, n, n*2) {
        l_que_total += a[i];
        l_que.push(a[i]);
        l_que_total -= l_que.top();
        l_que.pop();
        l_que_totals[i] = l_que_total;
    }
    for (lli i = 2*n-1; i >=n; i--) {
        r_que_total += a[i];
        r_que.push(a[i]);
        r_que_total -= r_que.top();
        r_que.pop();
        r_que_totals[i] = r_que_total;
    }
    lli ans = -LLONG_MAX;
    REPE(i, n-1, n*2-1) {
        ans = max(ans, l_que_totals[i] - r_que_totals[i+1]);
    }
    cout << ans << endl;
}
