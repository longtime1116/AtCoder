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
    lli n;
    cin >> n;
    lli p[n];
    REP(i, 0, n) {
        cin >> p[i];
    }
    lli ans = 0;
    REPE(i, 1, n-2) {
        if ((p[i-1] < p[i] && p[i+1] > p[i]) ||
            (p[i-1] > p[i] && p[i+1] < p[i])) {
            ans++;
        }
    }
    cout << ans << endl;
}
