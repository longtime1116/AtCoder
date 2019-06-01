#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

lli parent1[200001]; // parent[i]: i が含まれる木の根の番号
lli depth1[200001];  // depth[i] : i は自身が含まれる木のどれくらいの深さにいるか(最低1)
                    //            ただし、根の depth のみが参照される
lli parent2[200001]; // parent[i]: i が含まれる木の根の番号
lli depth2[200001];  // depth[i] : i は自身が含まれる木のどれくらいの深さにいるか(最低1)

void init() {
    REPE(i, 1, 200000) {
        parent1[i] = i;
        depth1[i] = 1;
        parent2[i] = i;
        depth2[i] = 1;
    }
}

lli find1(lli x) {
    if (parent1[x] == x)
        return x;
    else
        return parent1[x] = find1(parent1[x]);
}

void unite1(lli x, lli y) {
    lli x_root = find1(x);
    lli y_root = find1(y);
    if (x_root == y_root)
        return;

    if (depth1[x_root] < depth1[y_root]) {
        parent1[x_root] = y_root;
    }
    else {
        parent1[y_root] = x_root;
        if (depth1[x_root] == depth1[y_root])
            depth1[x_root]++;
    }
}

bool same1(lli x, lli y) {
    return find1(x) == find1(y);
}

lli find2(lli x) {
    if (parent2[x] == x)
        return x;
    else
        return parent2[x] = find2(parent2[x]);
}

void unite2(lli x, lli y) {
    lli x_root = find2(x);
    lli y_root = find2(y);
    if (x_root == y_root)
        return;

    if (depth2[x_root] < depth2[y_root]) {
        parent2[x_root] = y_root;
    }
    else {
        parent2[y_root] = x_root;
        if (depth2[x_root] == depth2[y_root])
            depth2[x_root]++;
    }
}

bool same2(lli x, lli y) {
    return find2(x) == find2(y);
}

int main() {
    init();


    lli n, k, l;
    cin >> n >> k >> l;
    REP(i, 0, k) {
        lli p, q;
        cin >> p >> q;
        unite1(p, q);
    }
    REP(i, 0, l) {
        lli r, s;
        cin >> r >> s;
        unite2(r, s);
    }

    // 頂点をまわり、それぞれの頂点の unit1 と unite2 の根のpairを保存。
    // 根のpairが同じならば unite1 も unite2 も同じということで、どっちの経路でも繋がれる
    map<P, lli> m;
    REPE(i, 1, n) {
        P p = P(find1(i), find2(i));
        auto it = m.find(p);
        lli val = 1;
        if (it != m.end()) {
            val = it->second + 1;
            m.erase(p);
        }
        m.insert(make_pair(P(find1(i), find2(i)), val));
    }
    REPE(i, 1, n) {
        P p = P(find1(i), find2(i));
        auto it = m.find(p);
        //cout << it->first.first << endl;
        cout << it->second << endl;
    }
}
