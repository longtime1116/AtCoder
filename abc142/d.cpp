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

lli gcd(lli a, lli b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    lli r;
    r = a % b;

    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main() {
    lli a,b;
    cin2(a,b);
    // 素因数 key が value 個ある、を表す map
    map<lli, lli> fac;
    lli num = gcd(a,b);

    //cout1(num);
    for(lli i = 2; i*i<=num; i++) {
        while (num % i == 0) {
            fac[i]++;
            num /= i;
        }
    }
    if (num != 1)
        fac[num] = 1;
    lli ans = 1;
    REPIT(it, fac) {
        //cout << it->first << ": " << it->second << endl;
        ans++;
    }
    cout << ans << endl;


}
