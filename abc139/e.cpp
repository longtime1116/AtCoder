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

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;

map <P, vector<P>> G;
map <P, lli> counts;

int main() {
    lli n;
    cin1(n);
    lli none_zero_count = 0;
    REPE(i, 1, n) {
        lli prev;
        REPE(j, 1, n-1) {
            lli x;
            cin >> x;
            if (j != 1) {
                lli a, b;
                a = min(i, prev);
                b = max(i, prev);
                lli c, d;
                c = min(i, x);
                d = max(i, x);

                G[P(a, b)].push_back(P(c, d));
                counts[P(c,d)]++;
                if (counts[P(c,d)] == 1)
                    none_zero_count++;
            }
            prev = x;
        }
    }

    lli ans = 0;
    queue<P> que;
    REPIT(it, G) {
        P  p = it->first;
        if (counts[p] == 0)
            que.push(p);
    }
    while (true) {
        ans++;
        lli num = que.size();
        REP(i, 0, num) {
            P p = que.front();
            que.pop();
            vector<P> pv = G[p];
            REP(j, 0, pv.size()) {
                counts[pv[j]]--;
                if (counts[pv[j]] == 0) {
                    none_zero_count--;
                    que.push(pv[j]);
                }
            }
        }
        if (que.empty())
            break;
    }
    if (none_zero_count != 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
