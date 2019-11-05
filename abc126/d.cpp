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
typedef vector<lli> vlli;

struct edge {
    lli to;
    lli w;
};

vector<edge> G[100001];
lli done[100001]; // 0は未訪問、1 で奇数、2で偶数


void rec(lli cur) {
    REP(i,0,G[cur].size()) {
        edge e = G[cur][i];
        if (e.w % 2 == 0) {
            if (done[e.to] != 0)
                continue;
            done[e.to] = done[cur];
            rec(e.to);
        }
        else {
            if (done[e.to] != 0)
                continue;
            done[e.to] = done[cur] + 1;
            rec(e.to);
        }
    }
    return;
}
int main() {
    lli n;
    cin1(n);
    REP(i,0,n-1) {
        lli u, v, w;
        cin >> u >> v >> w;
        if (w % 2 == 0)
            w = 2;
        else
            w = 1;
        edge e1 = {v, w};
        edge e2 = {u, w};
        G[u].push_back(e1);
        G[v].push_back(e2);
    }

    done[1] = 1;
    rec(1);
    REPE(i,1,n) {
        cout << done[i] % 2 << endl;
    }
}
