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

int main() {
    lli n, k;
    cin2(n, k);
    lli x[n], y[n];
    ncin2(n, x, y);
    lli ans = LLONG_MAX;
    REP(l_i, 0, n) {
        REP(r_i, 0, n) {
            REP(d_i, 0, n) {
                REP(u_i, 0, n) {
                    lli l = x[l_i];
                    lli r = x[r_i];
                    lli d = y[d_i];
                    lli u = y[u_i];
                    if (l > r || d > u)
                        continue;

                    lli in_bbox_count = 0;
                    REP(i, 0, n) {
                        // この i は bbox に含まれている？
                        if (x[i] >= l && x[i] <= r && y[i] >= d && y[i] <= u)
                            in_bbox_count++;
                    }
                    if (in_bbox_count >= k)
                        ans = min(ans, (r-l)*(u-d));
                }
            }
        }
    }
    cout << ans << endl;
}


//4o
//3  o
//2     o
//1       o
//x12345678
//
//4  o
//3 o
//2       o
//1     o
//x12345678
//
//
//3 => 5*2
//4 => 7*3
