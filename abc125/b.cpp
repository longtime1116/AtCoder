#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int main() {
    int n;
    cin >> n;
    int v[n];
    int c[n];
    REP(i, n) {
        cin >> v[i];
    }
    REP(i, n) {
        cin >> c[i];
    }
    int ans = 0;

    REP(i, n) {
        if (v[i] - c[i] > 0)
            ans += v[i] - c[i];
    }

    cout << ans << endl;
}
