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
    lli n, k;
    cin >> n >> k;
    lli a[n];
    REP(i, 0, n) {
        lli x;
        cin >> x;
        a[i] = x;
    }
    lli ary[n];
    ary[0] = a[0];
    REP(i, 1, n) {
        ary[i] = ary[i-1] + a[i];
    }

    lli ans = 0;
    lli cur_k = k;
    REP(i, 0, n) {
        if (i != 0)
            cur_k = cur_k + a[i-1];
        // cur_k以上のやつの数を足す
        auto it = lower_bound(ary, ary+n, cur_k);
        ans +=  ary+n - it;
    }
    cout << ans << endl;
}

