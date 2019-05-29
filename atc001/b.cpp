#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

lli parent[200001];
lli depth[200001];


void init() {
    REP(i, 0, 200001) {
        parent[i] = i;
        depth[i] = 1;
    }
}

lli find(lli a) {
    if (parent[a] == a)
        return a;

    return parent[a] = find(parent[a]);
}

void unite(lli a, lli b) {
    lli a_root = find(a);
    lli b_root = find(b);

    if (a_root == b_root)
        return;

    if (depth[a_root] < depth[b_root]) {
        parent[a_root] = b_root;
    }
    else {
        parent[b_root] = a_root;
        if (depth[a_root] == depth[b_root])
            depth[a_root]++;
    }
}

string is_same_str(lli a, lli b) {
    if (find(a) == find(b))
        return "Yes";
    else
        return "No";
}

int main() {
    lli n, q;
    cin >> n >> q;
    lli p, a, b;

    init();
    REP(i, 0, q) {
        cin >> p >> a >> b;
        if (p == 1) {
            cout << is_same_str(a, b) << endl;
        }
        else {
            unite(a, b);
        }
    }
}
