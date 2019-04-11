#include <bits/stdc++.h>
using namespace std;




int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    if (n % 2 == 1) {
        if (a[0] != 0) {
            cout << 0 << endl;
            return 0;
        }
        int num = 0;
        for (int i = 1; i < n; i++) {
            if (i % 2 == 1)
                num += 2;
            if (a[i] != num) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    else {
        int num = -1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                num += 2;
            if (a[i] != num) {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    int x ;
    if (n % 2 == 1)
        x = (n-1) / 2;
    else
        x = n / 2;

    int ans = 1;
    for (int i=0; i<x; i++) {
        ans = (ans * 2) % 1000000007;
    }

    cout << ans << endl;
}
