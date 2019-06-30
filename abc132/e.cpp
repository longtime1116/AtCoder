#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, pair<lli, lli>> P;

vector<lli> G[100001]; // G[i]: node i から張られる辺の向き先が配列になっている
lli d[100001][3];
lli n;

void dijkstra(lli start) {
    REPE(i, 1, n) {
        REP(j, 0, 3) {
            d[i][j] = LLONG_MAX;
        }
    }
    d[start][0] = 0;

    // first がその時点での最短経路のコスト、second が頂点の番号とindex
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, make_pair(start, 0)));

    while (!que.empty()) {
        P p = que.top();
        que.pop();

        lli cur_v = p.second.first;
        lli cur_index = p.second.second;
        lli next_index = (cur_index + 1) % 3;
        // もっと短い経路が既に登録されていたら、このpopしたやつは無視してよい
        if (d[cur_v][cur_index] < p.first) {
            continue;
        }
        // cur_v の辺を周って、更新しつつ queue に push していく
        REP(i, 0, (lli)G[cur_v].size()) {
            lli to = G[cur_v][i];
            if (d[to][next_index] > d[cur_v][cur_index] + 1) {
                d[to][next_index] = d[cur_v][cur_index] + 1;
                que.push(P(d[to][next_index], make_pair(to, next_index)));
            }
        }
    }
}

int main() {
    lli m;
    cin >> n >> m;
    REP(i, 0, m) {
        lli u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    lli s, t;
    cin >> s >> t;

    dijkstra(s);
    if (d[t][0] == LLONG_MAX)
        cout << -1 << endl;
    else
        cout << d[t][0]/3 << endl;
}

