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
    lli n,k;
    cin2(n, k);
    lli a[n], f[n];
    ncin1(n,a);
    ncin1(n,f);
    sort(a,a+n);
    sort_r(f,f+n);

    //REP(i,0,n)
    //    cout2(i,a[i]);
    //REP(i,0,n)
    //    cout2(i,f[i]);

    lli max_cost = 0;
    REP(i,0,n) {
        max_cost = max(max_cost, a[i] * f[i]);
    }
    lli ans = max_cost;

    lli left = -1;
    lli right = max_cost;
    while (right - left > 1) {
        lli cur = (left+right)/2;
        bool is_ok = true;

        lli count = 0;
        REP(i,0,n) {
            // count を必要な分増やす

            count += max((lli)0, a[i] - (cur/f[i]));
            if (count > k) {
                is_ok = false;
                break;
            }
        }



        //cout3(cur, right, left);
        //cout1(is_ok);
        if (is_ok) {
            right = cur;
        }
        else {
            left = cur;
        }
    }
    ans = right;
    cout << ans << endl;
}
