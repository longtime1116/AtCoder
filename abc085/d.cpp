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
    lli n, h;
    cin2(n, h);
    lli a[n], b[n];
    ncin2(n, a, b);


    lli a_max = 0;
    lli a_max_b = LLONG_MAX;
    lli a_max_i;
    REP(i, 0, n) {
        if (a_max < a[i] || (a_max == a[i] && a_max_b > b[i])) {
            a_max = max(a_max, a[i]);
            a_max_b = b[i];
            a_max_i = i;
        }
    }
    priority_queue<lli> que;
    priority_queue<lli> que2;
    REP(i, 0, n) {
        if (i == a_max_i)
            continue;
        else if (a_max < b[i]) {
            que.push(b[i]);
            que2.push(b[i]);
        }
    }

    lli ans1 = 0;
    lli damage = 0;

    // a_max_b を使うケース
    damage += a_max_b;
    ans1++;
    while (!que.empty()){
        lli x = que.top();
        que.pop();
        damage += x;
        ans1++;
        if (damage >= h)
            break;
    }
    if (damage < h) {
        ans1 += ((h+a_max-1) - damage) / a_max;
    }

    lli ans2 = 0;
    damage = 0;
    // a_max_b を使わないケース
    while (!que2.empty()){
        lli x = que2.top();
        que2.pop();
        damage += x;
        ans2++;
        if (damage >= h)
            break;
    }
    if (damage < h) {
        ans2 += ((h+a_max-1) - damage) / a_max;
    }

    cout << min(ans1, ans2) << endl;
}
