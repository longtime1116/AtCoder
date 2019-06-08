#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

struct vertex {
    set<lli> edges;
};
vertex vertexes[100001];
lli n, m;

set<lli> used;


lli rec(lli origin, lli num, lli lest) {

    if (lest == 0) {
        auto o_edges = vertexes[origin].edges;
        auto it = o_edges.find(num);
        if (it != o_edges.end())
            return 0;

        auto n_edges = vertexes[num].edges;
        auto it2 = n_edges.find(origin);
        if (it2 != n_edges.end())
            return 0;
        vertexes[origin].edges.insert(num);
        vertexes[num].edges.insert(origin);
        //cout << "fuga" << endl;
        //cout << origin << endl;
        //cout << num << endl;
        //cout << "hoge" << endl;
        //REPIT(it3, edges) {
        //    cout << "origin" << " -> " << *it3 << endl;
        //}
        //REP(i, 0, n) {
        //    auto edges = vertexes[i].edges;
        //    if (edges.size() == 0)
        //        continue;
        //    REPIT(it2, edges) {
        //        cout << i << " -> " << *it2 << endl;
        //    }
        //}
        return 1;
    }
    auto edges = vertexes[num].edges;
    lli ans = 0;
    REPIT(it, edges) {
        if (used.find(*it) != used.end())
            continue;
        used.insert(*it);
        ans += rec(origin, *it, lest-1);
        used.erase(*it);
    }
    return ans;
}

int main() {
    cin >> n >> m;
    REP(i, 0, m) {
        lli a, b;
        cin >> a >> b;
        (vertexes[a].edges).insert(b);
        (vertexes[b].edges).insert(a);
    }

    lli ans = 0;
    for(lli i = n; i > 0; i--) {
        used.insert(i);
        ans += rec(i, i, 3);
        used.erase(i);
    }
    //REP(i, 0, n) {
    //    auto edges = vertexes[i].edges;
    //    if (edges.size() == 0)
    //        continue;
    //    REPIT(it, edges) {
    //        cout << i << " -> " << *it << endl;
    //    }
    //}
    cout << ans << endl;
}
