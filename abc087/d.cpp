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

struct edge {
    lli to;
    lli cost;
};

vector<edge> G[100001];
lli x[100001];

#define INF (-LLONG_MAX)

bool rec(lli num, lli cur_x) {
    REP(i, 0, G[num].size()) {
        if (x[G[num][i].to] != INF) {
            if (x[G[num][i].to] != cur_x + G[num][i].cost) {
                return false;
            }
            continue;
        }
        x[G[num][i].to] = cur_x + G[num][i].cost;
        if (!rec(G[num][i].to, x[G[num][i].to]))
            return false;
    }
    return true;
}

int main() {
    lli n,m;
    cin2(n, m);

    set<lli> s;
    lli l[m];
    lli r[m];
    lli d[m];
    ncin3(m, l, r, d);
    if (m == 0)
        goto YES;

    REP(i, 0, m) {
        G[l[i]].push_back({r[i], d[i]});
        s.insert(l[i]);
        s.insert(r[i]);
    }
    REP(i, 0, m) {
        s.erase(r[i]);
    }
    if (s.size() == 0)
        goto NO;

    // n 人目の位置
    REP(i, 0, 100001) {
        x[i] = INF;
    }

    REPIT(it, s) {
        if (x[*it] != INF)
            continue;

        x[*it] = 0;
        if (!rec(*it, 0))
            goto NO;
    }

YES:
    cout << "Yes" << endl;
    return 0;

NO:
    cout << "No" << endl;
}
