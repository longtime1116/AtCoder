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
    lli n, x;
    cin >> n >> x;
    lli total = 0;
    lli ans = 0;
    REP(i, 0, n) {
        lli l;
        cin >> l;
        if (total > x) {
            break;
        }
        total += l;
        ans++;
    }
    if (total <= x)
        ans++;
    cout << ans << endl;
}
