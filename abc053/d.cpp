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
    lli a[n];
    REP(i, 0, n) {
        cin >> a[i];
    }
    sort(a, a+n);
    lli dup = 0;
    REP(i, 0, n-1) {
        if (a[i] == a[i+1])
            dup++;
    }
    if (dup % 2 == 1)
        cout << n - (dup/2+1)*2 << endl;
    else
        cout << n - (dup/2)*2 << endl;

}
