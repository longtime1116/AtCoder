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
    lli n;
    cin1(n);
    lli x[n];
    lli y[n];
    ncin2(n,x,y);

    vlli a;
    REP(i,0,n) {
        a.push_back(i);
    }
    sort(a.begin(), a.end());

    double ans = 0;
    lli count = 0;
    do {
        //cout << "[" << a[0] << ", " << a[1] << ", " << a[2] << "]" << endl;;
        REP(i,0,n-1) {
            //cout2(a[i], a[i+1]);
            // a[i] と a[i+1] の距離を出す
            ans += sqrt((x[a[i]] - x[a[i+1]])*(x[a[i]] - x[a[i+1]]) +
                (y[a[i]] - y[a[i+1]])*(y[a[i]] - y[a[i+1]]));
            //cout << sqrt((x[a[i]] - x[a[i+1]])*(x[a[i]] - x[a[i+1]]) + (y[a[i]] - y[a[i+1]])*(y[a[i]] - y[a[i+1]]))<<endl;
        }
            count++;

    } while (next_permutation(a.begin(), a.end()));
    cout <<setprecision(14)<< ans/count << endl;
}
