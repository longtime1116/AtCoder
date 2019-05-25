#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(int i=init;i<n;i++)
#define REPE(i,init, n) for(int i=init;i<=n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int main() {
    int a, b;
    cin >> a >> b;

    if (a >= 13)
        cout << b << endl;
    else if (a >= 6)
        cout << b/2 << endl;
    else
        cout << 0 << endl;
}
