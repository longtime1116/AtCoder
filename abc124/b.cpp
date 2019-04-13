#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int main() {
    int n;
    cin >> n;
    int h[n];
    for (int i=0; i < n; i++) {
        cin >> h[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        bool is_ok = true;
        for (int j = 0; j < n; j++) {
            // i 個目より左にあるやつが全部 i 個目以下かどうかをチェック
            if (j >= i)
                break;
            if (h[i] < h[j])
                is_ok = false;
        }
        if (is_ok)
            ans++;
    }
    cout << ans << endl;
}
