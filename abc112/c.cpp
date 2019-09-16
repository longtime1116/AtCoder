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
#define cout2(x, y)      cout << #x << ": " << x << ", " << #y << ": " << y << endl;
#define cout3(x, y, z)   cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl;;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

#define coutp(p)         cout << #p << ":" <<  " (" << p.first << ", " << p.second << ")" << endl;

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;

int main() {
    lli n;
    cin1(n);
    lli x[n];
    lli y[n];
    lli h[n];
    ncin3(n, x, y, h);

    REP(cx,0,101) {
        REP(cy,0,101) {
            bool is_ans = true;
            // 1つめのケースから、Hを出す
            lli H;
            REP(i,0,n) {
                if (h[i] != 0) {
                    H = h[i] + abs(x[i]-cx) + abs(y[i]-cy);
                    break;
                }
            }
            REP(i,0,n) {
                // 全部の計算結果が H と一致するのであればそれがこたえ
                if (H !=h[i] + abs(x[i]-cx) + abs(y[i]-cy)) {
                    is_ans = false;
                    break;
                }
            }
            if (is_ans) {
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }
    }
}
