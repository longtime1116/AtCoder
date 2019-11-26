#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,from, to) for(unsigned long long int i=from;i<to;i++)
#define REPE(i,from, to) for(unsigned long long int i=from;i<=to;i++)
#define REP_R(i,from, to) for(unsigned long long int i=from;i>to;i--)
#define REPE_R(i,from, to) for(unsigned long long int i=from;i>=to;i--)
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
#define sort_r(x, y)        sort(x, y, greater<unsigned long long int>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;
typedef vector<lli> vlli;


const lli MOD = 1000000007;
const lli MAX = 1000001;
lli fac[MAX];       // fac[i]     := iの階乗 % MOD
lli fac_inv[MAX];   // fac_inv[i] := iの階乗の逆元 % MOD (すなわち、fac[i]*fac_inv[i] % MOD == 1)
lli inv[MAX];       // inv[i]     := iの逆元 (すなわち、i*inv[i] % mod == 1)

void init_comb_base() {
    fac[0] = fac[1] = 1;
    fac_inv[0] = fac_inv[1] = 1;
    inv[1] = 1;
    REP(i,2,MAX) {
        fac[i] = i * fac[i-1] % MOD; // n! = n * (n-1)! % MOD
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD; // ↑の解説参照
        fac_inv[i] = inv[i] * fac_inv[i-1] % MOD; // n! = n * (n-1)! % MOD
    }
}

lli comb(lli n, lli k) {
    if (n<k)
        return 0;
    if (n < 0 || k < 0)
        return 0;

    // nCk = n! / (k! * (n-k)!)
    //     ≡ n! * (k!)^-1 * ((n-k)!)^-1 (mod p)
    return fac[n] * (fac_inv[k] * fac_inv[n-k] % MOD) % MOD;
}

int main() {
    unsigned long long int x,y;
    cin2(x,y);
    // x <= y とする
    if (x > y) {
        swap(x,y);
    }
    if ((x + y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    lli count = (x+y) / 3;
    // n: 1の方の回数、m: 2の方の回数
    lli n = count*2-x;
    lli m = count-n;
    if (n+m*2 != x || n*2+m != y) {
        cout << 0 << endl;
        return 0;
    }

    // n+mCnを出す
    init_comb_base();
    cout << comb(n+m, n) << endl;
}
