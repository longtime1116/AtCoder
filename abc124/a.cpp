#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int main() {
    int a, b;
    cin >> a >> b;
    if (a == b)
        cout << a * 2 << endl;
    else
        cout << max(a, b) * 2 - 1 << endl;
}
