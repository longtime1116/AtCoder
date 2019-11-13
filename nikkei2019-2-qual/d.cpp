#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,from, to) for(lli i=from;i<to;i++)
#define REPE(i,from, to) for(lli i=from;i<=to;i++)
#define REP_R(i,from, to) for(lli i=from;i>to;i--)
#define REPE_R(i,from, to) for(lli i=from;i>=to;i--)
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
#define cout2(x, y)      cout << #x << ": " << x << ", " << #y << ": " << y << endl;
#define cout3(x, y, z)   cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl;;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

#define coutp(p)         cout << #p << ":" <<  " (" << p.first << ", " << p.second << ")" << endl;

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;
typedef vector<lli> vlli;

struct edge {
    lli to;
    lli cost;
};

bool exist[100001]; // exist[i] := i から i-1 の辺が存在しているか？
vector<edge> G[100001];
lli d[100001];
lli n,m;

void dijkstra(lli start) {
    REPE(i, 1, n) {
        d[i] = LLONG_MAX;
    }
    d[start] = 0;

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
            }
        }
    }
}

int main() {
    cin2(n,m);
    lli l[m], r[m], c[m];
    ncin3(m,l,r,c);
    REP(i,0,m) {
        // l => r の辺
        edge e1 = {r[i], c[i]};
        G[l[i]].push_back(e1);
        // r => lとrの間の辺
        REPE_R(j,r[i],l[i]+2) {
            // j から j-1 へ
            if (exist[j])
                continue;
            edge e = {j-1, 0};
            G[j].push_back(e);
            exist[j] = true;

        }
    }
    dijkstra(1);
    if (d[n] == LLONG_MAX)
        cout << -1 << endl;
    else
        cout << d[n] << endl;
}
