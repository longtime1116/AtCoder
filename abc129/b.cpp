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
    lli w[n];
    lli total = 0;
    REP(i, 0, n) {
        lli wi;
        cin >> wi;
        w[i] = wi;
        total += wi;
    }
    lli total2 = 0;
    lli total3 = 0;
    double ave = total / 2;
    lli diff = 0;
    REP(i, 0, n) {
        total2 += w[i];
        if (total2 > ave) {
            total3 = total2 - w[i];
            break;
        }
    }
    //cout << total2 << endl;
    //cout << total3 << endl;
    if (total2 - ave > ave - total3)
        cout << total - total3 - total3 << endl;
    else
        cout << total2 - total + total2 << endl;

}
