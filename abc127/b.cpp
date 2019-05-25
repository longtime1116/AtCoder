#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(int i=init;i<n;i++)
#define REPE(i,init, n) for(int i=init;i<=n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int main() {
    int r, d, x2000;
    cin >> r >> d >> x2000;
    lli ans = x2000;
    REP(i, 0, 10) {
        ans = r * ans - d;
        cout << ans << endl;
    }
}
