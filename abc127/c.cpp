#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(int i=init;i<n;i++)
#define REPE(i,init, n) for(int i=init;i<=n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int main() {
    lli n, m;
    cin >> n >> m;
    lli small = 0;
    lli large = 100001;
    REP(i, 0, m) {
        lli l, r;
        cin >> l >> r;
        small = max(small, l);
        large = min(large, r);
    }
    if (large - small + 1 <= 0)
        cout << 0 << endl;
    else
        cout << large - small + 1 << endl;
}
