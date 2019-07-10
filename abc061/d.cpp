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

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

struct edge {
    lli from;
    lli to;
    lli cost;
};
vector<edge> edges;


lli d[1001]; // 各頂点の始点からの距離
bool is_negative[1001]; // 各頂点の始点からの距離
lli V;       // 頂点の数
lli E;       // 辺の数
lli r;       // 始点の番号

bool calc_shortest_path(lli start) {
    REPE(i, 0, V) {
        d[i] = LLONG_MAX;
    }
    d[start] = 0;

    lli loop_count = 0;
    bool updated;
    // O(V*E)
    while (true) {
        // V-1 回に収まっていなかったら、負の閉路がある
        // なぜなら、1 ループごとに少なくとも 1 つの最短経路が求まるから
        // V 個の頂点のうち、1 つは始点なので、V-1 個の最短経路が求まれば良い。
        updated = false;
        REP(i, 0, (lli)edges.size()) {
            edge e = edges[i];
            if (d[e.from] == LLONG_MAX)
                continue;
            if (d[e.from] + e.cost < d[e.to]) {
                d[e.to] = d[e.from] + e.cost;
                updated = true;
                if (loop_count >= V)
                    is_negative[e.to] = true;
            }
        }

        // 負の閉路があったとして、ゴールの V が実際に負の閉路の影響を受けているかを気にしている。
        // 負の閉路が見つかってからさらに V 回ループすれば、その負の閉路の影響を受ける全ての辺をマークできる
        if (loop_count == 2*V) {
            if (is_negative[V])
                return false;
            else
                return true;
        }

        loop_count++;
        if (!updated)
            break;
    }
    return true;
}
int main() {
    cin2(V, E);
    r = 1;
    REP(i, 0, E) {
        lli a, b, c;
        cin3(a, b, c);
        edge e = {a, b, -c};
        edges.push_back(e);
    }

    if (calc_shortest_path(1)) {
        cout << -d[V] << endl;
    }
    else {
        cout << "inf" << endl;
    }

}
