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

vector<lli> G[100001];
lli d_a[100001];
bool done_a[100001];
void rec_a(lli cur, lli distance) {
    d_a[cur] = distance;
    done_a[cur] = true;
    distance++;

    REP(i, 0, G[cur].size()) {
        if (done_a[G[cur][i]])
            continue;
        rec_a(G[cur][i], distance);
    }
    return;
}
lli d_b[100001];
bool done_b[100001];
void rec_b(lli cur, lli distance) {
    d_b[cur] = distance;
    done_b[cur] = true;
    distance++;

    REP(i, 0, G[cur].size()) {
        if (done_b[G[cur][i]])
            continue;
        rec_b(G[cur][i], distance);
    }
    return;
}

int main() {
    lli n;
    cin1(n);
    REP(i, 0, n-1) {
        lli a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rec_a(1, 0);
    rec_b(n, 0);

    // 1 からの距離を記録した d_a と、N からの距離を記録した d_b を構築する。
    // 同距離にあるものは、先行の Fennec が取得できる。
    // ので、|Fennec に近いもの + 同距離にあるもの| > |Snuke に近いもの| ならば Fennec の勝ち
    lli a_cnt = 0;
    lli b_cnt = 0;
    lli same_cnt = 0;
    REPE(i, 1, n) {
        if (d_a[i] < d_b[i]) {
            a_cnt++;
        }
        else if (d_a[i] > d_b[i]) {
            b_cnt++;
        }
        else {
            same_cnt++;
        }
    }
    if (a_cnt + same_cnt > b_cnt)
        cout << "Fennec" << endl;
    else
        cout << "Snuke" << endl;


}
