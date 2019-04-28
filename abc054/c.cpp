#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

bool ok[28];



int n, m;
int a[28];
int b[28];

int rec(int node) {
    int ans = 0;

    bool done = true;
    REP(i, n) {
        if (!ok[i])
            done = false;
    }
    if (done)
        return 1;

    REP(i, m) {
        if (a[i] == node) {
            if (ok[b[i]])
                continue;
            ok[b[i]] = true;
            ans += rec(b[i]);
            ok[b[i]] = false;
        }
        else if (b[i] == node) {
            if (ok[a[i]])
                continue;
            ok[a[i]] = true;
            ans += rec(a[i]);
            ok[a[i]] = false;
        }
    }
    return ans;
}



int main() {
    cin >> n >> m;
    REP(i, m) {
        cin >> a[i] >> b[i];
        a[i] -= 1;
        b[i] -= 1;
    }
    ok[0] = true;
    cout << rec(0) << endl;
}
