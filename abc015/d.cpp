#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;


lli dp[51][10001][51];

int main() {
    int w, n, k;
    cin >> w >> n >> k;
    int a[n+1], b[n+1];
    REP(i, n) {
        cin >> a[i+1] >> b[i+1];
    }

    // dp[i][j][k]: i個目までのスクショを使ったときに、width 合計 j で枚数 k という制約のもとでの最大価値
    lli ans = 0;
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < w+1; j++) {
            for(int l = 0; l < k+1; l++) {
                dp[i][j][l] = 0;
            }
        }
    }
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < w+1; j++) {
            for(int l = 1; l < k+1; l++) {
                if (j-a[i]<0) {
                    dp[i][j][l] = dp[i-1][j][l];
                    continue;
                }
                dp[i][j][l] = max(dp[i-1][j][l], dp[i-1][j-a[i]][l-1]+b[i]);
                ans = max(ans, dp[i][j][l]);
                // cout << "ans: " << ans << endl;
                // cout << "i, j, l: " << i << ", " << j << "," << l << endl;
            }
        }
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < w+1; j++) {
            for(int l = 1; l < k+1; l++) {
                //cout << "i: "  << i;
                //cout << ", j: "<< j;
                //cout << ", l: "<< l << endl;
                //cout << "dp: " << dp[i][j][l] << endl;

            }
            //cout << endl;
        }
        //cout << endl;
        //cout << endl;
    }
    cout << ans << endl;
}
