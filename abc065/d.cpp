#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef pair<lli, P> PP;

struct edge {
    lli to;
    lli cost;
};

vector<edge> G[100001];
bool used[100001];

lli prim() {
    lli total = 0;
    priority_queue< P, vector<P>, greater<P> > xque;

    // 事前に最初の node の辺のみ入れておく
    used[1] = true;
    lli cur_v = 1;
    REP(i, 0, (lli)G[cur_v].size()) {
        edge e = G[cur_v][i];
        if (!used[e.to])
            xque.push(P(e.cost, e.to));
    }

    // O(ElogV) なのか・・・？
    while (true) {
        // 次に使われる辺を選ぶ
        edge next = {LLONG_MAX, LLONG_MAX};
        while (!xque.empty()) {
            P p = xque.top();
            xque.pop();
            if (!used[p.second]) {
                next.cost = p.first;
                next.to = p.second;
                total += next.cost;
                used[next.to] = true;
                break;
            }
        }
        if (next.cost == LLONG_MAX)
            break;

        // next が使われた辺なので、新たに next.to から張られる辺を登録
        cur_v = next.to;
        REP(i, 0, (lli)G[cur_v].size()) {
            edge e = G[cur_v][i];
            if (!used[e.to])
                xque.push(P(e.cost, e.to));
        }
    }

    return total;
}


int main() {
    lli n;
    cin >> n;
    // v_xi[i]: i 番目のpair。first が x 座標で、second が何個目か
    vector<PP> v_x;
    vector<PP> v_y;
    REP(i, 0, n) {
        lli x;
        lli y;
        cin >> x >> y;
        v_x.push_back(PP(x, P(y, i+1)));
        v_y.push_back(PP(y, P(x, i+1)));
    }
    // ソートして前後の辺のみをグラフに登録することができ、prim 法に持ち込める
    sort(v_x.begin(), v_x.end());
    sort(v_y.begin(), v_y.end());

    REP(i, 0, n-1) {
        lli x_diff, y_diff;
        // x 軸方向で辺登録
        x_diff = v_x[i+1].first - v_x[i].first;
        y_diff = abs(v_x[i+1].second.first - v_x[i].second.first);
        edge e1_x = {v_x[i+1].second.second, min(x_diff, y_diff)};
        edge e2_x = {v_x[i].second.second, min(x_diff, y_diff)};
        G[v_x[i].second.second].push_back(e1_x);
        G[v_x[i+1].second.second].push_back(e2_x);

        // y 軸方向で辺登録
        y_diff = v_y[i+1].first - v_y[i].first;
        x_diff = abs(v_y[i+1].second.first - v_y[i].second.first);
        edge e1_y = {v_y[i+1].second.second, min(x_diff, y_diff)};
        edge e2_y = {v_y[i].second.second, min(x_diff, y_diff)};
        G[v_y[i].second.second].push_back(e1_y);
        G[v_y[i+1].second.second].push_back(e2_y);
    }

    lli ans = prim();
    cout << ans << endl;


}
