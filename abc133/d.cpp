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
    lli a_orig[n];
    REP(i, 0, n) {
        cin >> a[i];
        a_orig[i] = a[i];
        a[i] *= 2;
    }

    // 畳み込んで計算していき、aを出す。
    lli i = 0;
    lli up = 2;
    bool is_minus = true;
    while (true) {
        lli num1 = a[i];
        if (i+(up/2) >= n-1) {
            a[i] = num1;
        }
        else {
            lli num2 = a[i+(up/2)];
            if (is_minus)
                a[i] = num1 - num2;
            else
                a[i] = num1 + num2;

        }

        i+= up;
        if (i >= n-1) {
            // 畳み込みが次のフェーズに行く
            i = 0;
            up *= 2;
            if (i + (up/2) >= n-1) {
                break;
            }
            if (is_minus)
                is_minus = false;
        }
    }
    lli a0;
    a0 = (a[0] + a[n-1]) / 2;
    cout << a0;
    lli cur = a0;
    REP(i, 0, n-1) {
        cout <<" " << a_orig[i]*2 - cur;
        cur = a_orig[i]*2 - cur;
    }
    cout << endl;
}
