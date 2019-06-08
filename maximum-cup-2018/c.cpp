#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

vector<lli> G[100001];
lli colors[100001];

lli is_bipartite(lli target, lli color) {
    colors[target] = color;
    REP(i, 0, (lli)G[target].size()) {
        lli next = G[target][i];
        if (colors[next] == -color) {
            // 別の色で既に塗られている。それが塗られたときは二部グラフだったはずで、
            // ここで target を塗ったとしても矛盾するわけではないのでスキップ
            continue;
        }
        else if (colors[next] == color) {
            // 同一色で既に塗られているのでアウト
            return false;
        }
        else if (!is_bipartite(next, -color)) {
            // まだ塗られていないので、next 以降にゆだねている
            return false;
        }
    }
    return true;
}


int main() {
    lli n;
    cin >> n;
    REPE(i, 1, n) {
        lli a;
        cin >> a;
        G[i].push_back(a);
        G[a].push_back(i);
    }
    bool all_bipartite = true;
    REPE(i, 1, n) {
        if (colors[i] != 0)
            continue;
        if (!is_bipartite(i, 1))
            all_bipartite = false;
    }
    if (all_bipartite) {
        lli black = 0, white = 0;
        REPE(i, 1, n) {
            if (colors[i] == 1)
                black++;
            else
                white++;
        }
        cout << max(black, white) << endl;
    }
    else {
        cout << -1 << endl;
    }
}
