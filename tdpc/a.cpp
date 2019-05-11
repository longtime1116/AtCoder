#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;


// i 問目までで j 得点になるかどうか
bool dp[101][10001];
int main() {
    int n;
    cin >> n;
    int p[n+1];
    p[0] = 0;
    REP(i, n) {
        cin >> p[i+1];
    }
    for(int i=0;i<n+1;i++) {
        dp[i][0] = true;
    }

    lli ans = 1;
    for(int i=1;i<n+1;i++) {
        for (int j=1; j < n*100+1; j++) {
            if (dp[i-1][j])
                dp[i][j] =  true;
            if (j-p[i] >= 0 && dp[i-1][j-p[i]]) {
                dp[i][j] =  true;
            }

            if (i==n && dp[i][j]) {
                ans++;
            }
        }
    }


    cout << ans << endl;
}
