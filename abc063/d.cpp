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
#define cout1(x)            cout << #x << ": " << x << endl;
#define ncout1(n, x)        REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

int main() {
    lli n, a, b;
    cin3(n, a, b);
    lli h[n];
    ncin1(n, h);

    lli ans = 0;
    sort_r(h, h+n);

    lli target = 1;
    lli r_bound = (h[0] + b - 1) / b; // 最高でもこれだけかければいけるはず、のライン
    lli l_bound = 0; // 0回だと絶対倒せない
    while (true) {
        // target回でいけるのかどうかチェック
        bool is_ok = true;
        lli need_cnt = 0;
        REP(i, 0, n) {
            lli rest = h[i] - target * b;
            if (rest <= 0)
                break;
            need_cnt += (rest+a-b-1) / (a-b);
            if (need_cnt > target) {
                is_ok = false;
                break;
            }
        }

        if (is_ok) {
            r_bound = target;
        }
        else {
            l_bound = target;
        }

        lli next = (l_bound + r_bound) / 2;
        if (next == l_bound) {
            if (is_ok)
                ans = target;
            else
                ans = target + 1;
            break;
        }
        target = next;
    }
    cout << ans << endl;
}
