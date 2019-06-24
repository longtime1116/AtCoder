#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

int main() {
    lli n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    lli x[n];
    lli y[n];
    REP(i, 0, n) {
        lli xi, yi;
        cin >> xi >> yi;
        x[i] = xi;
        y[i] = yi;
    }
    map<P, lli> m;
    REP(i, 0, n) {
        REP(j, 0, n) {
            if (i == j)
                continue;
            // この(p, q)の組み合わせでのコストを出す。
            lli p = x[j] - x[i];
            lli q = y[j] - y[i];

            m[P(p, q)]++;
        }
    }

    lli ans = 0;
    REPIT(it, m) {
        ans = max(ans, it->second);
    }
    cout << n - ans << endl;
}
