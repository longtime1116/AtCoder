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

int main() {
    lli a,b,c,d;
    lli x1,y1,x2,y2;
    cin2(x1,y1);
    cin2(x2,y2);
    if (x1 < x2) {
        a = x1;
        b = y1;
        c = x2;
        d = y2;
    }
    else if (x1 > x2){
        a = x2;
        b = y2;
        c = x1;
        d = y1;
    }
    else {
        if (y1 >= y2) {
            a = x1;
            b = y1;
            c = x2;
            d = y2;
        }
        else {
            a = x2;
            b = y2;
            c = x1;
            d = y1;
        }

    }

    if (b <= c) {
        cout << 0 << endl;
    }
    else if (b <= d) {
        cout << b - c << endl;
    }
    else {
        cout << d - c << endl;
    }

}
