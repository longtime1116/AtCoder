#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;


// dp[i][j][k]
// 左から i 桁(1<=i<=n.length)までの和を D で割った余がj になる個数
// ただし、N よりも大きいとダメなので、k にそれを入れる。
int dp[10002][100];
int main() {
    int d;
    string n;
    cin >> d >> n;
    lli ans = 0;
    dp[0][0] = 1;
    for(int i=1; i<=n.length();i++) {
        int num = n[i-1] - '0';
        for (int j=0; j < 10; j++) {
            for (int k=0; k < 10; k++) {
                int target = (j + k) % d;
                cout << "i: " << i;
                cout << "target: " << target<<endl;
                dp[i][target] += dp[i-1][j];
            }
        }
    }
    for(int i=1; i<=n.length();i++) {
        for (int j=0; j < d; j++) {
            cout << "dp[" <<  i << "]"<< "[" << j << "]: " << dp[i][j] << endl;
        }
    }


    cout << ans << endl;
}
