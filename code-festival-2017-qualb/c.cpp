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
    vector<lli> edges;
};
vertex vertexes[100001];


int main() {
    lli n, m;
    cin >> n >> m;
    REP(i, 0, m) {
        lli a, b;
        cin >> a >> b;
        (vertexes[a].edges).push_back(b);
    }

    REP(i, 0, 100001) {
        vector<lli> edges = vertexes[i].edges;
        if (edges.size() == 0)
            continue;
        REP(j, 0, edges.size()) {
            cout << i << " -> " << edges[j] << endl;
        }
    }
    cout << "hoge" << endl;
}
