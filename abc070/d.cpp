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
lli d[100001];
lli n;
lli prev_v[100001]; // 経路復元用

void dijkstra(lli start) {
    REPE(i, 1, n) {
        d[i] = LLONG_MAX;
    }
    d[start] = 0;
    prev_v[start] = start;

    // first がその時点での最短経路のコスト、second が頂点の番号
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, start));

    while (!que.empty()) {
        P p = que.top();
        que.pop();

        lli cur_v = p.second;
        // もっと短い経路が既に登録されていたら、このpopしたやつは無視してよい
        if (d[cur_v] < p.first) {
            continue;
        }
        // cur_v の辺を周って、更新しつつ queue に push していく
        REP(i, 0, (lli)G[cur_v].size()) {
            edge e = G[cur_v][i];
            if (d[e.to] > d[cur_v] + e.cost) {
                d[e.to] = d[cur_v] + e.cost;
                que.push(P(d[e.to], e.to));
                prev_v[e.to] = cur_v;
            }
        }
    }
}

int main() {
    cin1(n);
    REP(i, 0, n-1) {
        lli a, b, c;
        cin >> a >> b >> c;
        edge e1 = {b, c};
        edge e2 = {a, c};
        G[a].push_back(e1);
        G[b].push_back(e2);
    }
    lli q, k;
    cin2(q, k);
    lli x[q], y[q];
    ncin2(q, x, y);

    dijkstra(k);
    REP(i, 0, q) {
        cout << d[x[i]] + d[y[i]] << endl;
    }



}
