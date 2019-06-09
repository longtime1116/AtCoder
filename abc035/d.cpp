#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

struct edge {
    lli to;
    lli cost;
};

vector<edge> G_go[100001];
lli d_go[100001];

vector<edge> G_come[100001];
lli d_come[100001];
lli n;

void dijkstra_go(lli start) {
    REPE(i, 1, n) {
        d_go[i] = LLONG_MAX;
    }
    d_go[start] = 0;

    // first が最短経路、second が頂点の番号
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, start));

    while (!que.empty()) {
        P p = que.top();
        que.pop();

        lli cur_v = p.second;
        // もっと短い経路が既に登録されていたら、このpopしたやつは無視してよい
        if (d_go[cur_v] < p.first) {
            continue;
        }
        // cur_v の辺を周って、更新しつつ queue に push していく
        REP(i, 0, (lli)G_go[cur_v].size()) {
            edge e = G_go[cur_v][i];
            if (d_go[e.to] > d_go[cur_v] + e.cost) {
                d_go[e.to] = d_go[cur_v] + e.cost;
                que.push(P(d_go[e.to], e.to));
            }
        }
    }
}

void dijkstra_come(lli start) {
    REPE(i, 1, n) {
        d_come[i] = LLONG_MAX;
    }
    d_come[start] = 0;

    // first が最短経路、second が頂点の番号
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, start));

    while (!que.empty()) {
        P p = que.top();
        que.pop();

        lli cur_v = p.second;
        // もっと短い経路が既に登録されていたら、このpopしたやつは無視してよい
        if (d_come[cur_v] < p.first) {
            continue;
        }
        // cur_v の辺を周って、更新しつつ queue に push していく
        REP(i, 0, (lli)G_come[cur_v].size()) {
            edge e = G_come[cur_v][i];
            if (d_come[e.to] > d_come[cur_v] + e.cost) {
                d_come[e.to] = d_come[cur_v] + e.cost;
                que.push(P(d_come[e.to], e.to));
            }
        }
    }
}

int main() {
    lli m, t;
    cin >> n >> m >> t;
    lli A[n+1];
    REP(i, 0, n) {
        lli a;
        cin >> a;
        A[i+1] = a;
    }
    REP(i, 0, m) {
        lli a, b, c;
        cin >> a >> b >> c;
        edge e_go = {b, c};
        G_go[a].push_back(e_go);
        edge e_come = {a, c};
        G_come[b].push_back(e_come);
    }

    dijkstra_go(1);
    dijkstra_come(1);
    lli ans = 0;
    REPE(i, 1, n) {
        //cout << "d_go[" << i << "]: " << d_go[i] << endl;
        //cout << "d_come[" << i << "]: " << d_come[i] << endl;
        if (d_go[i] == LLONG_MAX || d_come[i] == LLONG_MAX)
            continue;
        if (t - d_go[i] - d_come[i] < 0)
            continue;

        ans = max(ans, (t - d_go[i] - d_come[i]) * A[i]);
    }
    cout << ans << endl;
}
