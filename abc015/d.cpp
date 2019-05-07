#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;


int dp_n[51][5001];
lli dp_w[51][5001];

int main() {
    int w, n, k;
    cin >> w >> n >> k;
    int a[n+1], b[n+1];
    REP(i, n) {
        cin >> a[i+1] >> b[i+1];
    }

    // dp_w[i][j]: i個目までのスクショを使ったときに、価値jを実現するときのwidth合計
    // dp_n[i][j]: i個目までのスクショを使ったときに、価値jを実現するための最小のスクショ枚数
    lli ans = 0;
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < k*100+1; j++) {
            if (!(i == 0 || j == 0))
                dp_w[i][j] = LLONG_MAX;
        }
    }
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < k*100+1; j++) {
            if (j - b[i] < 0 )
                continue;
            if (dp_n[i-1][j-b[i]] >= k)
                continue;

            if (dp_w[i-1][j-b[i]] + a[i] > w)
                continue;

            dp_w[i][j] = min(dp_w[i-1][j], dp_w[i-1][j-b[i]]+a[i]);
            if (dp_w[i][j] != dp_w[i-1][j])
                dp_n[i][j] = dp_n[i-1][j-b[i]] + 1;

            if (dp_w[i][j] != LLONG_MAX)
                ans = max(ans, (lli)j);
            //if (dp_w[i-1][j] >= dp_w[i-1][j-b[i]]+a[i]) {
            //    //cout << "if" << endl;
            //    dp_w[i][j] = dp_w[i-1][j];
            //    dp_n[i][j] = dp_n[i-1][j];
            //}
            //else if (dp_w[i-1][j-b[i]] + a[i] <= w && dp_n[i-1][j-b[i]] + 1 <= k){
            //    //cout << "else" << endl;
            //    dp_w[i][j] = dp_w[i-1][j-b[i]] + a[i];
            //    dp_n[i][j] = dp_n[i-1][j-b[i]] + 1;

            //    if (dp_w[i][j] != LLONG_MAX)
            //        ans = max(ans, (lli)j);
            //}
        }
        cout << "i: " << i << endl;
        cout << "ans: " << ans << endl;
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < 201; j++) {
            cout << dp_w[i][j] << ", ";
        }
        cout << endl;
    }
    cout << ans << endl;
}
