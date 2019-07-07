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
    lli l, r;
    cin >> l >>r;
    if ((r / 2019) != (l / 2019)) {
        cout << 0 << endl;
    }
    else {
        lli l1 = l % 2019;
        lli r1 = r % 2019;
        lli ans = LLONG_MAX;
        REP(i, l1, r1) {
            REPE(j, i+1, r1) {
                ans = min(ans, (i * j) % 2019);
                //cout << ans << endl;
            }
        }
        cout << ans << endl;
    }
}
