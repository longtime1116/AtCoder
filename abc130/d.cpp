
#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

int main() {
    lli n, k;
    cin >> n >> k;
    lli a[n];
    REP(i, 0, n) {
        cin >> a[i];
    }
    lli ans = 0;
    lli sum = 0;
    lli r = 0;
    REP(i, 0, n) {
        while (r < n) {
            if (sum >= k)
                break;
            sum += a[r];
            r++;
        }
        if (sum < k)
            break;
        ans += n - r + 1;
        sum -= a[i];
    }
    cout << ans << endl;

}

