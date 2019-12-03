#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,from, to) for(lli i=from;i<to;i++)
#define REPE(i,from, to) for(lli i=from;i<=to;i++)
#define REP_R(i,from, to) for(lli i=from;i>to;i--)
#define REPE_R(i,from, to) for(lli i=from;i>=to;i--)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

// input
#define cin1(x)             cin >> x
#define cin2(x, y)          cin >> x >> y
#define cin3(x, y, z)       cin >> x >> y >> z
#define ncin1(n, x)         REP(i, 0, n) { cin1(x[i]); }
#define ncin2(n, x, y)      REP(i, 0, n) { cin2(x[i], y[i]); }
#define ncin3(n, x, y, z)   REP(i, 0, n) { cin3(x[i], y[i], z[i]); }
#define ncinp(n, p)         REP(i, 0, n) { lli p1,p2; cin >> p1 >> p2; p[i] = P(p1, p2); }
#define ncin1_1(n, x)       REPE(i, 1, n) { cin1(x[i]); }
#define ncin2_1(n, x, y)    REPE(i, 1, n) { cin2(x[i], y[i]); }
#define ncin3_1(n, x, y, z) REPE(i, 1, n) { cin3(x[i], y[i], z[i]); }
#define ncinp_1(n, p)       REPE(i, 1, n) { lli p1,p2; cin >> p1 >> p2; p[i] = P(p1, p2); }

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
typedef vector<lli> vlli;

int main() {
    lli n,m;
    cin2(n,m);
    lli a[n];
    ncin1(n,a);

    a[0] %= m;
    // FIXME: m は 10^9 以下の制約なので、これだとメモリ確保しすぎになる。
    // vec.push_back(make_pair(0, [1,3,4])) みたいな感じにすれば、たかだかn個になる。
    map<lli, vlli> loc;
    vlli v = {0};
    loc[a[0]] = v;
    loc[a[0]].push_back(0);
    REP(i,1,n) {
        a[i] = (a[i-1] + a[i]) % m;
        vlli v;
        if (loc[a[i]].size() == 0) {
            loc[a[i]] = v;
        }
        loc[a[i]].push_back(i);
    }
    lli cur = 0;
    lli ans = 0;
    REP(i,0,n) {
        if (loc[cur].size() == 0)
            continue;
        auto it = lower_bound(loc[cur].begin(), loc[cur].end(), i);
        if (it == loc[cur].end())
            continue;
        ans += loc[cur].size() - ((it - loc[cur].begin()));
        cout3(i, cur,loc[cur].size() - ((it - loc[cur].begin())-1));
        cout1(it - loc[cur].begin());
        cout1(loc[cur].size());

        lli x = (m + cur - a[i]) % m;
        cur = m-x;
    }
    cout << ans << endl;


}
