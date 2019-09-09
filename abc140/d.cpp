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
typedef pair<bool, lli> P;
typedef tuple<lli, lli, lli> tup;

class CompareDist
{
public:
    bool operator()(P n1, P n2) {
        return n1.second<n2.second;
    }
};

int main() {
    lli n, k;
    cin2(n, k);
    string s;
    cin1(s);

    lli rl = 0;
    lli lr = 0;
    lli ans = 0;
    REP(i, 0, n-1) {
        if (s[i] == s[i+1])
            ans++;
        else if (s[i] == 'R' && s[i+1] == 'L')
            rl++;
        else
            lr++;
    }

    if (s[0] == 'L') {
        if (k > rl) {
           if ( s[n-1] == 'R')
               cout << ans + rl * 2 + 1 << endl;
           else
               cout << ans + rl * 2 << endl;
        }
        else
            cout << ans + k * 2 << endl;
    }
    else {
        if (k > lr) {
            if (s[n-1] == 'L') {
                cout << ans + lr * 2 + 1 << endl;
            }
            else
                cout << ans + lr * 2 << endl;
        }
        else
            cout << ans + k * 2 << endl;

    }

}