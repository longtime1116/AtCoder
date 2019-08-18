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

// 大きい順にpop
class CompareDist
{
public:
    bool operator()(P n1, P n2) {
        return n1.second<=n2.second;
    }
};

int main() {
    lli n;
    cin1(n);
    lli a[n];
    lli b[n];
    ncin1(n, a);
    ncin1(n, b);


    priority_queue< P, vector<P>, CompareDist > que;

    REP(i, 0, n) {
        if (a[i] != b[i])
            que.push(P(i, b[i]));
    }

    lli ans = 0;
    while (true) {
        P p = que.top();
        lli cur = p.first;
        lli prev = (cur + n - 1) % n;
        lli next = (cur + n + 1) % n;

        lli x = b[cur];
        lli y = b[prev] + b[next];
        lli count = (x - a[cur]) / y;
        if (count == 0)
            break;
        x -= y * count;

        b[cur] = x;
        que.pop();
        if (x != a[cur]) {
            que.push(P(cur, b[cur]));
        }

        ans+=count;
        //cout1(ans);
    }

    REP(i, 0, n) {
        if (a[i] != b[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
