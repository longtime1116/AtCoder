#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cin >> n;
    int t[n];
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        total += t[i];
    }
    cin >> m;
    int p[m];
    int x[m];
    for (int i = 0; i < m; i++) {
        cin >> p[i] >> x[i];
    }

    for (int i = 0; i < m; i++) {
        int index = p[i] - 1;
        int diff = t[index] - x[i];
        cout << total - diff << endl;
    }
};
