#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

lli dp[100002];

int main() {
    lli n, k;
    cin >> n >> k;
    lli h[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    dp[1] = 0;
    dp[2] = abs(h[2]-h[1]);
    for (lli i = 3; i <= n; i++) {
        lli cost = LLONG_MAX;
        for (int j=1; j <= k; j++) {
            if (i-j <= 0)
                continue;
            cost = min(cost, dp[i-j]+abs(h[i-j]-h[i]));
        }
        dp[i] = cost;
    }
    cout << dp[n] << endl;
}
