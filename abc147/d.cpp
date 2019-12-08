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
#define ncin1(n, x)         REP(i, 0, n) { cin1(x[i]); }
#define ncin2(n, x, y)      REP(i, 0, n) { cin2(x[i], y[i]); }
#define ncin3(n, x, y, z)   REP(i, 0, n) { cin3(x[i], y[i], z[i]); }
#define ncinp(n, p)         REP(i, 0, n) { lli p1,p2; cin >> p1 >> p2; p[i] = P(p1, p2); }
#define ncin1_1(n, x)       REPE(i, 1, n) { cin1(x[i]); }
#define ncin2_1(n, x, y)    REPE(i, 1, n) { cin2(x[i], y[i]); }
#define ncin3_1(n, x, y, z) REPE(i, 1, n) { cin3(x[i], y[i], z[i]); }
#define ncinp_1(n, p)       REPE(i, 1, n) { lli p1,p2; cin >> p1 >> p2; p[i] = P(p1, p2); }

// output
#define cout1(x)         cout << #x << ": " << x << endl;
#define cout2(x, y)      cout << #x << ": " << x << ", " << #y << ": " << y << endl;
#define cout3(x, y, z)   cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl;;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

#define coutp(p)         cout << #p << ":" <<  " (" << p.first << ", " << p.second << ")" << endl;

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef unsigned long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;
typedef vector<lli> vlli;
// 繰り返し二乗法
// N^p mod m
lli mod_pow(lli n, lli p, lli mod) {
    lli res = 1;
    while (p > 0) {
        if (p & 1) {
            res = res * n % mod;
        }
        n = n * n % mod;
        p >>= 1;
    }
    return res;
}

int main() {
    lli n;
    cin1(n);
    lli a[n];
    ncin1(n,a);

    lli zero_count[61] = {0};
    lli one_count[61] = {0};
    REP(i,0,n) {
        lli x = a[i];
        REP(j,0,61) {
            //// j けため
            //if (a[i] & (1<<j)) {
            //    one_count[j]++;
            //    cout2(j, one_count[j]);
            //}
            //else {
            //    zero_count[j]++;
            //    cout2(j, zero_count[j]);
            //}
            // j けため
            if (x & 1) {
                one_count[j]++;
                //cout2(j, one_count[j]);
            }
            else {
                zero_count[j]++;
                //cout2(j, zero_count[j]);
            }
            x = x>>1;
        }
    }
    //REP(i,0,5) {
    //    cout3(i, zero_count[i], one_count[i]);
    //}

    lli mod = 1000000007;
    lli ans = 0;
    REP(i,0,n) {
        // Ai〜
        lli x = a[i];
        REP(j,0,61) {
            if (x & 1) {
                // その値が1
                one_count[j]--;
                //cout3(i,j,((1<<j)*zero_count[j]));
                //cout2(zero_count[j], one_count[j]);
                //ans += (1<<j)*zero_count[j];
                //ans += (((1<<j) % mod)*zero_count[j]) % mod;
                //cout3(i,j,mod_pow(2, j, mod) * zero_count[j] % mod);
                //cout1(zero_count[j]);
                ans = (ans + mod_pow(2, j, mod) * zero_count[j] % mod) % mod;
            }
            else {
                zero_count[j]--;
                //cout2(zero_count[j], one_count[j]);
                //ans += (1<<j)*one_count[j];
                //ans += (((1<<j) % mod)*one_count[j]) % mod;
                //cout3(i,j,mod_pow(2, j, mod) * one_count[j] % mod);
                //cout1(one_count[j]);
                ans = (ans + mod_pow(2, j, mod) * one_count[j] % mod) % mod;
            }
            x = (x>>1);
        }
    }
    cout << ans << endl;
}
