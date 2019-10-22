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


vlli G[51];

lli dfs(vector<P> &res, lli cur, lli &count, lli from, vlli &low, vlli &pre) {
    pre[cur] = count;
    low[cur] = pre[cur];
    count++;

    // low と pre が等しくないノードは、必ず閉路に含まれる。
    // その閉路には、1つだけ low と pre が等しいノードが含まれている(閉路代表と呼ぶ)
    // low と pre が等しい => 閉路を構成しないノード or 閉路代表
    REP(i,0,G[cur].size()) {
        lli to = G[cur][i];
        // 親に返るのを阻止
        if (from == to) {
            continue;
        }

        if (pre[to] == -1) {
            // 初訪問。次のnodeに行った場合の low を調べ、必要があれば更新
            low[cur] = min(low[cur], dfs(res, to, count, cur, low, pre));
            if (low[to] == pre[to]) {
                // to から先で完結しており、cur と to は同一グループ内に存在しない
                res.push_back(P(cur, to));
            }
        }
        else {
            // 閉路であることが確認された。
            low[cur] = min(low[cur], low[to]);
        }
    }

    return low[cur];
}

// n: number of nodes
void bridges(vector<P> &res, lli n) {
    vlli low(n+1, -1); // 最も小さい、到達時のカウンタ
    vlli pre(n+1, -1); // 走査されたときのカウンタ(pre-order)
    lli count = 1; // nodeを訪れるごとにインクリメントされていくカウンタ
    dfs(res, 1, count, -1, low, pre);
}

// n: number of nodes
lli closed_path_count(vector<P> &res, lli n) {
    vlli low(n+1, -1); // 最も小さい、到達時のカウンタ
    vlli pre(n+1, -1); // 走査されたときのカウンタ(pre-order)
    lli count = 1; // nodeを訪れるごとにインクリメントされていくカウンタ
    dfs(res, 1, count, -1, low, pre);

    //REP(i,0,res.size()) {
    //    coutp(res[i]);
    //}
    //REPE(i,1,n) {
    //    cout2(i,low[i]);
    //}
    sort(low.begin(), low.end());
    lli ret = 0;
    REP(i,0,res.size()) {
        auto it1 = lower_bound(low.begin(), low.end(), res[i].second);
        auto it2 = upper_bound(low.begin(), low.end(), res[i].second);

        if ((it2 - it1) > 1)
            ret++;
    }
    // 開始地点はresに含まれないので個別にチェック
    auto it1 = lower_bound(low.begin(), low.end(), 1);
    auto it2 = upper_bound(low.begin(), low.end(), 1);
    if ((it2 - it1) > 1)
        ret++;
    return ret;
}

int main() {
    lli n,m;
    cin2(n,m);
    REP(i,0,m) {
        lli a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<P> res;
    bridges(res, n);
    cout << res.size() << endl;
    //vector<P> res2;
    //cout << closed_path_count(res2,n) << endl;
}


// 入力例
// 8 9 1 2 2 3 3 4 4 1 5 6 6 7 7 8 8 5 2 5
//
// o-o o-o
// | | | |
// o-o-o-o
//
// 8 10 1 2 2 3 3 4 4 1 5 6 6 7 7 8 8 5 2 5 3 8
//
// o-o-o-o
// | | | |
// o-o-o-o
//
// 9 10 1 2 2 3 2 4 4 5 5 6 5 7 7 8 8 9 4 8 2 9
//
//   o-o-o
//   | | |
// o-o-o-o-o
//   |
//   o
//

// 参考: http://nupioca.hatenadiary.jp/entry/2013/11/03/200006
