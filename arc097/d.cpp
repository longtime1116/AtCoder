#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

lli parent[100001]; // parent[i]: i が含まれる木の根の番号
lli depth[100001];  // depth[i] : i は自身が含まれる木のどれくらいの深さにいるか(最低1)
                 //            ただし、根の depth のみが参照される



void init(lli n) {
    REPE(i, 1, n) {
        parent[i] = i;
        depth[i] = 1;
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
    }
    else {
        parent[y_root] = x_root;
        if (depth[x_root] == depth[y_root])
            depth[x_root]++;
    }
}

bool same(lli x, lli y) {
    return find(x) == find(y);
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);

    int p[n+1];
    REP(i, 0, n) {
        cin >> p[i+1];
    }
    REP(i, 0, m) {
        int x, y;
        cin >> x >> y;
        unite(x, y);
    }

    // p[i] は、p[i]番目になりたい。
    // p[i]はi番目だということがわかっている。
    // iの根とp[i]の根が同じであれば、p[i]はp[i]番目になれる。
    lli ans = 0;
    REPE(i, 1, n) {
        //cout << "i   : " << i << endl;
        //cout << "p[i]: " << p[i] << endl;
        //cout << "find(i): " << find(i) << endl;
        //cout << "find(p[i]): " << find(p[i]) << endl;

        if (same(p[i], i)) {
            ans++;
        }
    }
    cout << ans << endl;
}
