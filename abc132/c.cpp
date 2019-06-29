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
    lli d[n];
    REP(i, 0, n) {
        cin >> d[i];
    }
    sort(d, d+n);
    //REP(i, 0, n)
    //    cout << d[i] << " " << endl;

    if (n % 2 == 0) {
        lli a = d[n/2-1];
        lli b = d[n/2];
        if (a == b)
            cout << 0 << endl;
        else
            cout << b - a << endl;
    }
    else {
        cout << 0 << endl;
    }
}
