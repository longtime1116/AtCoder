#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

#define MOD 1000000007

lli dp[100001]; // i 段目の通り数
bool x[100001];

int main() {
    lli n, m;
    cin >> n >> m;
    lli a[m];
    REP(i, 0, m) {
        lli ai;
        cin >> ai;
        x[ai] = true;
    }

    lli count = 0;
    dp[0] = 1;
    if (x[1]) {
        dp[1] = 0;
        count++;
    }
    else
        dp[1] = 1;

    REPE(i, 2, n) {
        if (x[i]) {
            count++;
            if (count >= 2) {
                cout << 0 << endl;
                return 0;
            }
            continue;
        }
        else if (count == 1) {
            dp[i] = dp[i-2];
            count = 0;
        }
        else {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
            count = 0;
        }
    }
    cout << dp[n] << endl;
}
