#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

lli dp[100002];

int main() {
    lli n;
    cin >> n;
    lli h[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    dp[1] = 0;
    dp[2] = abs(h[2]-h[1]);
    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i-1]+abs(h[i-1]-h[i]), dp[i-2]+abs(h[i-2]-h[i]));
    }
    cout << dp[n] << endl;
}
