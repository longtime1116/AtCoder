#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

// i 回目までに j 回勝率が上昇する場合の最小の勝利数
lli dp[2001][2001];
// i 回目までに j 回勝率が上昇する場合の最小の勝利数のときの勝率


int main() {
    lli n, k;
    cin >> n >> k;
    lli a[n+1];
    lli total = 0;
    a[0] = 0;
    REP(i, n) {
        cin >> a[i+1];
        total += a[i+1];
        dp[i][i+1] = 2000*500000+1;
    }
    dp[1][1] = 1;
    if (total == k) {
        cout << 1 << endl;
        return 0;
    }
    lli done_game_count = 0;
    for(lli i=1;i<n+1;i++) {
        for(lli j=1;j<n+1;j++) {
            if (i == j && i == 1)
                break;
            if (i < j)
                break;
            lli w = dp[i-1][j-1] * a[i] / done_game_count + 1;
            // Q: なぜ w > a[i] のケースでも dp[i-1][j-1] + w を採用すべきなのだろうか
            // 解答が間違っているということはないのだろうか・・・
            if (w > a[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + w);
        }
        done_game_count += a[i];
    }
    //REP(i, n+1) {
    //    REP(j, n+1) {
    //        cout << dp[i][j] << ",";
    //    }
    //    cout << endl;
    //}
    lli ans=0;
    for(int i=n; i>=0; i--) {
        if (dp[n][i] <= k) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
