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
    lli n, d;
    cin >> n >> d;
    lli x[n][d];
    REP(i, 0, n) {
        REP(j, 0, d) {
            cin >> x[i][j];
        }
    }
    lli ans = 0;
    REP(i, 0, n) {
        REP(j, i+1, n) {
            lli di = 0;
            // i と j の距離
            REP(k, 0, d) {
                di += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            }
            lli ds = (int)sqrt(di);
            //cout << "d:i " << di << endl;
            //cout << "ds: " << ds << endl;
            if (di == ds*ds)
                ans++;
        }
    }
    cout << ans << endl;
}
