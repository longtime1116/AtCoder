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
    REP(i, 0, G[target].size()) {
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
    lli n, m;
    cin >> n >> m;
    REP(i, 0, m) {
        lli a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 s と t の距離が奇数のときは必ず辺が張られる。
    // 二部グラフの場合は、二色に塗り分けたとして、別の色としか紐付かない
    // ので、その掛け合わせ分の線が引ける
    // 二部グラフでない場合はかならず任意の頂点を結ぶ奇数長パスを導けるので、
    // 任意の頂点を結べる
    if (is_bipartite(1, 1)) {
        lli black = 0, white = 0;
        REPE(i, 1, n) {
            if (colors[i] == 1)
                black++;
            else
                white++;
        }
        cout << black * white - m  << endl;
    }
    else {
        cout << n * (n-1) / 2 - m << endl;
    }
}
