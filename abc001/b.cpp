#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, k, vv;
    bool need_0 = false;
    cin >> m;
    k = m / 1000;

    if (m < 100) {
        vv = 0;
        need_0 = true;
    }
    else if (m <= 5000) {
        vv = m / 100;
        if (vv < 10)
            need_0 = true;
    }
    else if (m <=30000) {
        vv = k + 50;
    }
    else if (m <= 70000) {
        vv = (k - 30) / 5 + 80;
    }
    else
        vv = 89;

    string ans = to_string(vv);
    if (need_0) {
        ans = "0" + ans;
    }

    cout << ans << endl;
}
