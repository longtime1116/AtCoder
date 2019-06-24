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
    REP(i, 0, l.length()) {
        // danger
        if (l[i+1] == '0') {
            dp[i+1][safe] += dp[i][!safe] * 2;
        }
        else {
            // '1' なので、3通りありえる
            dp[i+1][safe] += dp[i][!safe] * 3;
        }

        // safe
        dp[i+1][safe] += dp[i][safe] * 3;

    }
    REPE(i, 1, l.length()) {
        cout << "dp[" << i << "][dang]: " << dp[i][!safe] << ", ";
        cout << "dp[" << i << "][safe]: " << dp[i][safe];
        cout << endl;
    }
}
