#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;


// dp[i][j][k]
// 左から i 桁(1<=i<=n.length)までの和を D で割った余がj になる個数
// ただし、N よりも大きいとダメなので、Nよりも大きい可能性があるケースは別で処理する
lli dp[10002][100][2];
lli mod = 1000000007;
int main() {
    bool safe = true;
    int d;
    string n;
    cin >> d >> n;
    lli ans = 0;
    dp[0][0][0] = 1;
    for(int i=1; i<=n.length();i++) {
        for (int j=0; j < d; j++) {
            int num = static_cast<int>(n[i-1] - '0');
            // danger
            for (int k=0; k < num; k++) {
                dp[i][(j+k)%d][safe] = (dp[i][(j+k)%d][safe] + dp[i-1][j][!safe]) % mod;
            }
            dp[i][(j+num)%d][!safe] = (dp[i][(j+num)%d][!safe] + dp[i-1][j][!safe]) % mod;

            // safe
            for (int k=0; k < 10; k++) {
                dp[i][(j+k)%d][safe] = (dp[i][(j+k)%d][safe] + dp[i-1][j][safe]) % mod;
            }
        }
    }
    //for(int i=0; i<=n.length();i++) {
    //    for (int j=0; j < d; j++) {
    //        cout << "dp[" <<  i << "]"<< "[" << j << "][0]: " << dp[i][j][0] << endl;
    //    }
    //}
    //cout << endl;
    //for(int i=0; i<=n.length();i++) {
    //    for (int j=0; j < d; j++) {
    //        cout << "dp[" <<  i << "]"<< "[" << j << "][1]: " << dp[i][j][1] << endl;
    //    }
    //}


    cout << (dp[n.length()][0][0] + dp[n.length()][0][1] - 1) % mod << endl;
}
