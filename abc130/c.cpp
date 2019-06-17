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
    double w, h, x, y;
    cin >> w >> h >> x >> y;

    double ans2 = 0;
    if (x * 2 == w && y * 2 == h)
        ans2 = 1;
    cout << w * h / 2.0 << " " << ans2 << endl;
}
