#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;


lli n, ma, mb;
lli a[41];
lli b[41];
lli c[41];
lli rec(lli use_cnt, lli cur_cnt, lli i, lli a_now, lli b_now, lli c_now) {
    if (use_cnt == cur_cnt) {
        if (a_now*mb == b_now*ma)
            return c_now;
        else
            return LLONG_MAX;
    }
    else if (use_cnt > cur_cnt + n - (i))
        return LLONG_MAX;

    lli ans = LLONG_MAX;
    // i を使う
    ans = min(ans, rec(use_cnt, cur_cnt+1, i+1, a_now+a[i], b_now+b[i], c_now+c[i]));
    // i を使わない
    ans = min(ans, rec(use_cnt, cur_cnt, i+1, a_now, b_now, c_now));

    return ans;
}

int main() {
    cin >> n >> ma >> mb;
    REP(i, 0, n) {
        cin >> a[i] >> b[i] >> c[i];
    }

    lli ans = LLONG_MAX;
    REPE(i, 1, n) {
        // i 個使用する
        ans = min(ans, rec(i, 0, 0, 0, 0, 0));
    }
    if (ans == LLONG_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
