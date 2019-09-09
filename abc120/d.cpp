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

lli parent[100001]; // parent[i]: i が含まれる木の根の番号
lli depth[100001];  // depth[i] : i は自身が含まれる木のどれくらいの深さにいるか(最低1) ただし、根の depth のみが参照される
lli counts[100001];

void init(lli n) {
    REPE(i, 1, n) {
        parent[i] = i;
        depth[i] = 1;
        counts[i] = 1;
    }
}

lli find(lli x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void unite(lli x, lli y) {
    lli x_root = find(x);
    lli y_root = find(y);
    if (x_root == y_root)
        return;

    if (depth[x_root] < depth[y_root]) {
        parent[x_root] = y_root;
        counts[y_root] += counts[x_root];
        counts[x_root] = 0;
    }
    else {
        parent[y_root] = x_root;
        counts[x_root] += counts[y_root];
        counts[y_root] = 0;
        if (depth[x_root] == depth[y_root])
            depth[x_root]++;
    }
}

bool same(lli x, lli y) {
    return find(x) == find(y);
}


int main() {
    lli n, m;
    cin2(n, m);
    lli a[m];
    lli b[m];
    ncin2(m, a, b);

    init(n);
    lli ans[m] = {0};
    for (lli i = m-1; i >= 0; i--) {
        lli a_root = find(a[i]);
        lli b_root = find(b[i]);
        if (a_root == b_root) {
            ans[i] = 0;
            continue;
        }
        ans[i] = counts[a_root] * counts[b_root];
        unite(a[i], b[i]);
    }
    lli x = 0;
    REP(i, 0, m) {
        x += ans[i];
        cout << x << endl;
    }
}
