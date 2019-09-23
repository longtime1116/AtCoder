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

// dp[i] := i が親のとき、その木の最長有効パスの長さ。子のとき、そこまでの最長有効パスの長さ
lli dp[100001];
vector<lli> G[100001];
lli counts[100001];

int main() {
    lli n, m;
    cin2(n, m);
    REP(i,0,m) {
        lli x, y;
        cin >> x >> y;
        G[x].push_back(y);
        counts[y]++;
    }
    queue<P> que;
    REPE(i,1,n) {
        if (counts[i] == 0)
            que.push(P(i, 0));
    }
    lli ans = 0;
    while (!que.empty()) {
        lli node, len;
        tie(node, len) = que.front();
        que.pop();
        if (dp[node] != 0 && dp[node] >= len)
            continue;
        dp[node] = len;
        ans = max(ans, dp[node]);
        REP(i,0,G[node].size()) {
            lli next = G[node][i];
            counts[next]--;
            if (counts[next] == 0)
                que.push(P(next, len+1));
        }
    }
    cout << ans << endl;
}
