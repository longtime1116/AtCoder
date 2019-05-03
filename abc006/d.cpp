#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;


int dp[30001];

int main() {
    int n;
    cin >> n;
    int c[n];
    REP(i, n) {
        cin >> c[i];
        dp[i+1] = 30001;
    }
    // 最長増加部分列(LongestIncreasingSubsequence)
    // dp[i]: i個連続するときの最小のi個目
    int max_i = 0;
    // 1,2,3,...,n 個の最長増加部分列のdp[i]を埋める
    for(int i=0;i<n;i++){
        auto it = lower_bound(dp, dp+n, c[i]);
        int index = distance(dp, it);
        // 1 はどう手に入れるか？ => it - dp
        if (dp[index] > c[i]) {
            dp[index] = c[i];
            max_i = max(max_i, index);
        }
        //REP(i, n) {
        //    cout << dp[i+1] << ",";
        //}
        //cout << endl;
    }
    cout << n-max_i << endl;
}
