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
    lli n, k;
    cin2(n,k);
    lli x[n];
    ncin1(n,x);
    lli pos_start=n;
    REP(i,0,n) {
        if (x[i] >= 0) {
            pos_start = i;
            break;
        }
    }

    lli ans = LLONG_MAX;
    REPE(i,0,n-k) {
        if (i < pos_start && pos_start <= i+k-1) {
            lli a = -x[i];
            lli b = x[i+k-1];
            //cout3(i,i+k-1, a+b+min(a,b));
            ans = min(ans, a+b+min(a,b));
        }
        else if (pos_start <= i) {
            //cout3(i,i+k-1, x[i+k-1]);
            ans = min(ans,x[i+k-1]);
        }
        else {
            //cout3(i,i+k-1, -x[i]);
            ans = min(ans,-x[i]);

        }

    }
    cout << ans << endl;
}
