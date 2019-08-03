#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

// input
#define cin1(x)             cin >> x
#define cin2(x, y)          cin >> x >> y
#define cin3(x, y, z)       cin >> x >> y >> z
#define ncin1(n, x)         REP(i, 0, n) {cin1(x[i]);}
#define ncin2(n, x, y)      REP(i, 0, n) {cin2(x[i], y[i]);}
#define ncin3(n, x, y, z)   REP(i, 0, n) {cin3(x[i], y[i], z[i]);}

// output
#define cout1(x)         cout << #x << ": " << x << endl;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;


// 時刻 i に チャンネル j で放送されているか？
bool state[100001][31];

int main() {
    lli N, C;
    cin2(N, C);
    lli s[N], t[N], c[N];
    lli min_t = LLONG_MAX, max_t = 0;
    REP(i, 0, N) {
        cin >> s[i] >> t[i] >> c[i];
        min_t = min(min_t, t[i]);
        max_t = max(max_t, t[i]);
    }

    REP(i, 0, N) {
        for (lli j = s[i]; j <= t[i]; j++ ) {
            state[j][c[i]] = true;
        }
    }

    lli ans = 0;
    REPE(i, min_t, max_t) {
        lli count = 0;
        REPE(j, 1, 30) {
            if (state[i][j])
                count++;
        }
        ans = max(ans, count);
    }
    cout << ans << endl;
}
