#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int main() {
    lli n, m;
    lli ans;
    cin >> n >> m;
    lli left = m - 2*n;
    if (left > 0) {
        ans = n + left/4;
    }
    else
        ans = m/2;

    cout << ans << endl;

}
