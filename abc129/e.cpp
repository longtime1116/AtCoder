#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

lli dp[100002][2]; // i 桁目までで a+b==a xor b となる場合の数(jはsafeかどうか)
lli mod = 1000000007;

int main() {
    string l;
    cin >> l;
    l = "0" + l;
    bool safe = true;
    dp[0][safe] = 0;
    dp[0][!safe] = 1;
    lli len = l.length()-1;
    REP(i, 0, len) {
        // danger
        if (l[i+1] == '0') {
            // 0 のときは、今回の桁は (0, 0) しかありえない
            // なぜなら、少なくともひとつが 1 ならば、L を超えてしまうから
            dp[i+1][!safe] = dp[i][!safe];
        }
        else {
            // 1 のときは、今回の桁は (0, 0), (1, 0), (0, 1) の可能性がある
            // (0, 0) のときのみ、その次以降は safe となる
            dp[i+1][!safe] = (dp[i][!safe] * 2) % mod;
            dp[i+1][safe] = dp[i][!safe];
        }

        // safe
        // (0, 0), (0, 1), (1, 0) のどれかを取れる
        dp[i+1][safe] = (dp[i+1][safe] + (dp[i][safe] * 3) % mod) % mod;

    }
    //REPE(i, 1, len) {
    //    cout << "dp[" << i << "][!safe]: " << dp[i][!safe] << ", ";
    //    cout << "dp[" << i << "][safe]: " << dp[i][safe];
    //    cout << endl;
    //}
    cout << (dp[len][0] + dp[len][1]) % mod << endl;
}
