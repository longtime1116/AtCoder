#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,from, to) for(lli i=from;i<to;i++)
#define REPE(i,from, to) for(lli i=from;i<=to;i++)
#define REP_R(i,from, to) for(lli i=from;i>to;i--)
#define REPE_R(i,from, to) for(lli i=from;i>=to;i--)
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
#define cout2(x, y)      cout << #x << ": " << x << ", " << #y << ": " << y << endl;
#define cout3(x, y, z)   cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl;;
#define cout4(x, y, z, w)   cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << ", " << #w << ": " << w << endl;;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

#define coutp(p)         cout << #p << ":" <<  " (" << p.first << ", " << p.second << ")" << endl;

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;
typedef vector<lli> vlli;

int main() {
    lli n;
    cin1(n);
    lli f[n][10];
    REP(i,0,n) {
        REP(j,0,10) {
            cin >> f[i][j];
            //cout3(i,j,f[i][j]);
        }
    }
    lli p[n][11];
    REP(i,0,n) {
        REP(j,0,11) {
            cin >> p[i][j];
            //cout3(i,j,p[i][j]);
        }
    }

    lli ans = -LLONG_MAX;
    REPE(state,1,(1<<10)-1) {
        // i の bit が立っている部分が営業している時間
        // その営業時間の時に各店から得られる利益を計算する
        lli benefit = 0;
        REP(shop, 0, n) {
            lli bit = state;
            lli i = 0;
            lli count = 0;
            REP(i,0,10) {
                if (bit == state) {
                    //cout3(shop, i, f[shop][i]);
                }
                if ((bit & 1) & f[shop][i]) {
                    //cout2(bit, i);
                    count++;
                }
                bit >>= 1;
            }
            benefit += p[shop][count];
            //cout4(state, shop, count, p[shop][count]);
        }
        ans = max(ans, benefit);
    }
    cout << ans << endl;
}
