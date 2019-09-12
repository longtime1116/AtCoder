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

#define coutp(p)         cout << #p << ":" <<  " (" << p.first << ", " << p.second << ")" << endl;

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;

lli calc_dist(lli cur, lli s_l, lli s_r, lli t_l, lli t_r) {

    return min({
            max(cur-s_l, cur-t_l),
            (cur-t_l)*2 + (s_r-cur),
            (cur-t_l) + (s_r-cur)*2,
            (cur-s_l)*2 + (t_r-cur),
            (cur-s_l) + (t_r-cur)*2,
            max(s_r-cur, t_r-cur)
            });

}
int main() {
    lli a, b, q;
    cin3(a,b,q);
    lli s[a+2];
    REPE(i, 1, a) {
        cin >> s[i];
    }
    s[0] = -LLONG_MAX/10;
    s[a+1] = LLONG_MAX/10;
    lli t[b+2];
    REPE(i, 1, b) {
        cin >> t[i];
    }
    t[0] = -LLONG_MAX/10;
    t[b+1] = LLONG_MAX/10;
    lli x[q];
    ncin1(q, x);
    lli y[q];
    REP(i,0,q) {
        y[i] = x[i];
    }

    map<lli, lli> m;

    sort(s, s+a);
    sort(t, t+b);
    sort(y, y+q);

    lli s_cur = 0;
    lli t_cur = 0;
    REP(i, 0, q) {
        while (s[s_cur+1] <= y[i]) {
            s_cur++;
        }
        while (t[t_cur+1] <= y[i]) {
            t_cur++;
        }
        lli s_l = s[s_cur];
        lli s_r = s[s_cur + 1];
        lli t_l = t[t_cur];
        lli t_r = t[t_cur + 1];
        m[y[i]] = calc_dist(y[i], s_l, s_r, t_l, t_r);
    }
    REP(i, 0, q) {
        cout << m[x[i]] << endl;
    }
}
